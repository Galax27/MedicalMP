#include "stdafx.h"

#include "TestsDB.h"

namespace MedicalMP
{
    std::vector<UnitTests::entry*> UnitTests::UnitTestsDB;
    std::unordered_set<unsigned int> UnitTests::UniqueIDs;

    void UnitTests::Seed(unsigned int limit)
    {
        double timeElapsed(0.0);

        for(unsigned int i = 0; i < limit; ++i)
        {
            const bool creationSucceded(CreateNewEntry(k_MasterThread, timeElapsed));
        }
    }

    bool UnitTests::CreateNewEntry(unsigned int threadID, double& timeElapsed)
    {
        auto timeStart(std::chrono::high_resolution_clock::now());

        entry *newEntry(new entry());

        if(!newEntry)
        {
            Logger::WriteLog(
                System::UNIT_TESTS + System::HASHTAG
                + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG
                + "! Failed to create new entry, pointer null." + System::HASHTAG
                + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
            );
            
            return false;
        }
        
        if(UniqueIDs.find(newEntry->m_ID) != UniqueIDs.end())
        {
            Logger::WriteLog(
                System::UNIT_TESTS + System::HASHTAG + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG
                + "! Failed to create new entry, ID already exists." + System::HASHTAG
                + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
            );
            
            return false;
        }

        UniqueIDs.insert(newEntry->m_ID);
        UnitTestsDB.push_back(newEntry);
        
        Logger::WriteLog(
            System::UNIT_TESTS + System::HASHTAG + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG 
            + "New entry creation succeded." + System::HASHTAG
            + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
        );

        return true;
    }

    int UnitTests::SearchEntry(unsigned int entryID)
    {
        for(unsigned int i = 0; i < UnitTestsDB.size(); ++i)
        {
            if(UnitTestsDB[i]->m_ID == entryID)
            {
                return i;
            }
        }

        return -1;
    }

    bool UnitTests::DeleteEntry(unsigned int entryID, unsigned int threadID, double& timeElapsed)
    {
        auto timeStart = std::chrono::high_resolution_clock::now();

        int indexFound(SearchEntry(entryID));

        if(indexFound != -1)
        {
            auto toRemoveIdIter(UniqueIDs.find(UnitTestsDB[indexFound]->m_ID));

            if(toRemoveIdIter != UniqueIDs.end())
            {
                UniqueIDs.erase(toRemoveIdIter);
                std::swap(UnitTestsDB[indexFound], UnitTestsDB.back());
                UnitTestsDB.pop_back();
            }

            Logger::WriteLog(
                System::UNIT_TESTS + System::HASHTAG + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG 
                + "Erased entry." + System::HASHTAG
                + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
            );

            return true;
        }

        Logger::WriteLog(
            System::UNIT_TESTS + System::HASHTAG + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG
            + "! Failed to erase, entry ID not found." + System::HASHTAG
            + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
        );

        return false;
    }

    bool UnitTests::UpdateEntry(unsigned int entryID, unsigned int threadID, double& timeElapsed)
    {
        auto timeStart = std::chrono::high_resolution_clock::now();

        int indexFound(SearchEntry(entryID));

        if(indexFound == -1)
        {
            Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG 
                + "! Failed to update, entry ID not found." + System::HASHTAG
                + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
            );

            return false;
        }

        UnitTestsDB[indexFound]->m_ID = Utils::GetRandomUnsigned(10000);
        UnitTestsDB[indexFound]->m_Name = Utils::GetRandomString(100);

        Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + System::THREAD_ID + std::to_string(threadID) + System::HASHTAG 
            + "Updated entry." + System::HASHTAG
            + Utils::GetElapsedTime(timeStart, std::chrono::high_resolution_clock::now(), timeElapsed)
        );

        return true;

    }

    void UnitTests::DisplayDB()
    {
        auto itBegin(UnitTestsDB.begin()), itEnd(UnitTestsDB.end());

        for(auto it = itBegin; it != itEnd; ++it)
        {
            std::stringstream entryStream;
            entryStream << System::UNIT_TESTS << System::DB_ENTRY 
                << " with ID " << std::to_string(it.operator*()->m_ID) 
                << " and name " << it.operator*()->m_Name;
            Logger::WriteLog(entryStream.str());
        }
    }

    void UnitTests::ParalelizeRequests()
    {
        std::vector<int> idRequests(UniqueIDs.begin(), UniqueIDs.end());
        std::vector<bool> doneRequests(std::vector<bool>(idRequests.size(), false));
        std::vector<int> typeRequests(idRequests.size());
        std::vector<double> timeRequests(idRequests.size());

        Logger::WriteLog(System::UNIT_TESTS + " " + std::to_string(idRequests.size()) + " to process.");

        for(auto &typeRequest : typeRequests)
        {
            typeRequest = Utils::GetRandomUnsigned(3);
        }

        omp_set_num_threads(k_NumThreads);

        Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Starting resolve requests using OpenMP..");
        Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "Number of threads used : " + std::to_string(k_NumThreads));

        #pragma omp parallel
        {
            #pragma omp for
                for(int i = 0; i < (int) typeRequests.size(); ++i)
                {
                    if(typeRequests[i] == request_type::INSERT)
                    {
                        bool requestSucceded;
                        double elapsedTime(0.0);
                        
                        #pragma omp critical 
                        {
                            const int threadID(omp_get_thread_num());

                            requestSucceded = CreateNewEntry(threadID, elapsedTime);

                            if(requestSucceded)
                            {
                                doneRequests[i] = true;
                            }

                            timeRequests[i] = elapsedTime;
                        } // END Critical Section
                    }
                }
        } // END Parallel Block

        // Task just for updates
        #pragma omp parallel 
        {
            #pragma omp for
                for(int i = 0; i < (int) typeRequests.size(); ++i)
                {
                    if(typeRequests[i] == request_type::UPDATE)
                    {
                        bool requestSucceded;
                        double elapsedTime(0.0);
                        
                        #pragma omp critical 
                        {
                            const int threadID(omp_get_thread_num());
                            
                            requestSucceded = UpdateEntry(idRequests[i], threadID, elapsedTime);

                            if(requestSucceded)
                            {
                                doneRequests[i] = true;
                            }

                            timeRequests[i] = elapsedTime;
                        } // END Critical Section
                    }
                }
        } // END Parallel Block

        // Task just for delete
        #pragma omp parallel 
        {
            #pragma omp for
                for(int i = 0; i < (int) typeRequests.size(); ++i)
                {
                    if(typeRequests[i] == request_type::DELETE)
                    {
                        bool requestSucceded;
                        double elapsedTime(0.0);

                        #pragma omp critical 
                        {
                            const int threadID(omp_get_thread_num());
                            requestSucceded = DeleteEntry(idRequests[i], threadID, elapsedTime);

                            if(requestSucceded)
                            {
                                doneRequests[i] = true;
                            }

                            timeRequests[i] = elapsedTime;
                        } // End Critical section
                    }
                }
        } // END Parallel Block
    
        double totalTime(0.0);
        for(unsigned int i = 0; i < timeRequests.size(); ++i)
        {
            totalTime += timeRequests[i];
        }

        Logger::WriteLog(
            System::UNIT_TESTS + System::HASHTAG
            + "Unit Tests Ended." + System::HASHTAG
            + "There were " + std::to_string(idRequests.size()) + " requests." + System::HASHTAG
            + "Total time: " + std::to_string(totalTime) + " seconds." + System::HASHTAG
            + "Avreage time: " + std::to_string(totalTime / (double) idRequests.size()) + " seconds. "
        );

    }
}

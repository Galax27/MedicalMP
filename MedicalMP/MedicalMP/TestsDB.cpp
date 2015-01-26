#include "stdafx.h"

#include "TestsDB.h"

namespace MedicalMP
{
    std::vector<UnitTests::entry*> UnitTests::UnitTestsDB;
    std::unordered_set<unsigned int> UnitTests::UniqueIDs;

    void UnitTests::Seed(unsigned int limit)
    {
        for(unsigned int i = 0; i < limit; ++i)
        {
            const bool creationSucceded(CreateNewEntry());
        }
    }

    bool UnitTests::CreateNewEntry(unsigned int threadID)
    {
        entry *newEntry(new entry());

        if(!newEntry)
        {
            if(threadID != k_MasterThread)
            {
                Logger::WriteLog(System::UNIT_TESTS + System::HASHTAG + "!Failed to create new entry, pointer null");
            }
            else
            {
                Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + std::to_string(threadID) 
                    + " ! Failed to create new entry, pointer null");
            }

            return false;
        }
        else if(UniqueIDs.find(newEntry->m_ID) != UniqueIDs.end())
        {
            if(threadID != k_MasterThread)
            {
                Logger::WriteLog(System::UNIT_TESTS + " !Failed to create new entry, ID already exists");
            }
            else
            {
                Logger::WriteLog(
                    System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + std::to_string(threadID) 
                        + " ! Failed to create new entry, ID already exists");
            }

            return false;
        }

        UniqueIDs.insert(newEntry->m_ID);
        UnitTestsDB.push_back(newEntry);
        Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + std::to_string(threadID) + " New entry creation succeded");

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

    bool UnitTests::DeleteEntry(unsigned int entryID, unsigned int threadID)
    {
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

            Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + std::to_string(threadID) + " Erased entry");

            return true;
        }

        Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + " ! Failed to erase, entry ID not found");

        return false;
    }

    bool UnitTests::UpdateEntry(unsigned int entryID, unsigned int threadID)
    {
        int indexFound(SearchEntry(entryID));

        if(indexFound == -1)
        {
            Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + " ! Failed to update, entry ID not found");

            return false;
        }

        UnitTestsDB[indexFound]->m_ID = Utils::GetRandomUnsigned(10000);
        UnitTestsDB[indexFound]->m_Name = Utils::GetRandomString(100);

        Logger::WriteLog(System::UNIT_TESTS + System::THREAD_ID + System::HASHTAG + std::to_string(threadID) + " Updated entry");

        return true;
       
    }

    void UnitTests::DisplayDB()
    {
        auto itBegin(UnitTestsDB.begin()), itEnd(UnitTestsDB.end());

        for(auto it = itBegin; it != itEnd; ++it)
        {
            std::stringstream entryStream;
            entryStream << System::UNIT_TESTS << System::DB_ENTRY << " with ID " << std::to_string(it.operator*()->m_ID) << " and name " << it.operator*()->m_Name;
            Logger::WriteLog(entryStream.str());
        }
    }

    void UnitTests::ParalelizeRequests()
    {
        std::vector<int> idRequests(UniqueIDs.begin(), UniqueIDs.end());
        std::vector<bool> doneRequests(std::vector<bool>(idRequests.size(), false));
        std::vector<int> typeRequests(idRequests.size());


        Logger::WriteLog(System::UNIT_TESTS + " " + std::to_string(idRequests.size()) + " to process.");

        for(auto &typeRequest : typeRequests)
        {
            typeRequest = Utils::GetRandomUnsigned(3);
        }

        omp_set_num_threads(k_NumThreads);

        Logger::WriteLog(System::UNIT_TESTS + " Starting resolve requests using OpenMP");
        Logger::WriteLog(System::UNIT_TESTS + " Number of threads : " + std::to_string(k_NumThreads));

#pragma omp parallel
		{
#pragma omp for
				for( int i = 0; i < typeRequests.size(); ++i)
				{
					if(typeRequests[i] == request_type::INSERT)
					{
						bool requestSucceded;
                        
						#pragma omp critical 
						{
							const int threadID(omp_get_thread_num());
							requestSucceded = CreateNewEntry(threadID);

							if(requestSucceded)
							{
								doneRequests[i] = true;
							}
						}                    
					}
				}
			}

            // Task just for updates
#pragma omp parallel
{
#pragma omp for
                for( int i = 0; i < typeRequests.size(); ++i)
                {
                    if(typeRequests[i] == request_type::UPDATE)
                    {
                        bool requestSucceded;

                        #pragma omp critical 
                        {
                            const int threadID(omp_get_thread_num());
                            requestSucceded = UpdateEntry(idRequests[i], threadID);

                            if(requestSucceded)
                            {
                                doneRequests[i] = true;
                            }
                        }
                    }
                }
            }

            // Task just for delete
#pragma omp parallel 
{
#pragma omp for
                for( int i = 0; i < typeRequests.size(); ++i)
                {
                    if(typeRequests[i] == request_type::DELETE)
                    {
                        bool requestSucceded;

                        #pragma omp critical 
                        {
                            const int threadID(omp_get_thread_num());
                            requestSucceded = DeleteEntry(idRequests[i], threadID);

                            if(requestSucceded)
                            {
                                doneRequests[i] = true;
                            }
                        }
                    }
                }
            }

    }
}

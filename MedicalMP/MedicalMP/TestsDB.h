#pragma once

#include "Utils.h"

namespace MedicalMP
{
    class UnitTests
    {
    public:
        struct entry
        {
            unsigned int m_ID;
            std::string m_Name;
            std::vector<std::string> m_MoreNames;

            entry()
            {
                m_ID = Utils::GetRandomUnsigned(1000000);
                
                m_Name = Utils::GetRandomString(100);

                m_MoreNames.resize(Utils::GetRandomUnsigned(20));
                for(unsigned int i = 0; i < m_MoreNames.size(); ++i)
                {
                    m_MoreNames[i] = Utils::GetRandomString(30);
                }
            }
        };

        struct request_type
        {
            enum
            {
                INSERT = 0,
                UPDATE = 1,
                DELETE = 2
            };
        };

        static std::vector<entry*> UnitTestsDB;
        static std::unordered_set<unsigned int> UniqueIDs;

        static void Seed(unsigned int limit);
        static bool CreateNewEntry(unsigned int threadID, double& timeElapsed);
        
        static int SearchEntry(unsigned int entryID);
        
        static bool UpdateEntry(unsigned int entryID, unsigned int threadID, double& timeElapsed);
        static bool DeleteEntry(unsigned int entryID, unsigned int threadID, double& timeElapsed);
        
        static void ParalelizeRequests();

        static void DisplayDB();
    };
}
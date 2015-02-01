#include "stdafx.h"

namespace MedicalMP
{
    void Logger::WriteLog(const std::string &objLog)
    {
        // Contain It
        std::stringstream onStream;
        onStream << "LOG ## At: " << Utils::GetUTCAsString() << System::HASHTAG << objLog << std::endl;

        std::ofstream onDebug("Log_MedicalMP.txt", std::ios::out | std::ios::ate | std::ios::app);
        onDebug << onStream.str() << std::endl;
        onDebug.close();
    
        std::cout << onStream.str() << std::endl;
    }
}
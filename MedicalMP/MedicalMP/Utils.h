#pragma once

#include "stdafx.h"

namespace MedicalMP
{
    class Utils
    {
    public:
        static std::string GetUTCAsString();
        static std::string GetRandomString(size_t length);
        static unsigned int GetRandomUnsigned(size_t limit);
        /*static std::string GetElapsedTime(
            std::chrono::time_point<std::chrono::system_clock> timeStart,
            std::chrono::time_point<std::chrono::system_clock> timeEnd,
            double& secondsElapsed);*/

		// < c++ 11
		static std::string GetElapsedTime(
			clock_t timeStart,
			clock_t timeEnd,
			double& secondsElapsed);
    };
}


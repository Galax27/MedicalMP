#pragma once

namespace MedicalMP
{
    class Utils
    {
    public:
        static std::string GetUTCAsString();
        static std::string GetRandomString(size_t length);
        static unsigned int GetRandomUnsigned(size_t limit);
    };
}


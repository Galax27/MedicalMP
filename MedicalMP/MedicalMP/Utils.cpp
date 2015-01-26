#include "stdafx.h"

namespace MedicalMP
{
    std::string Utils::GetUTCAsString()
    {
        std::time_t t = std::time(nullptr);

        std::stringstream timeStream;

        timeStream << "GMT+2 " << std::put_time(std::localtime(&t), "%c");

        return timeStream.str();
    }

    std::string Utils::GetRandomString(size_t length)
    {
        auto randchar = []() -> char
        {
            const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
            const size_t max_index = (sizeof(charset) -1);
            return charset[rand() % max_index];
        };

        std::string str(length, 0);
        std::generate_n(str.begin(), length, randchar);
        return str;
    }

    unsigned int Utils::GetRandomUnsigned(size_t limit)
    {
        return std::rand() % limit;
    }
}
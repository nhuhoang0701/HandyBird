#include "string_helper.hpp"

namespace StringHelper
{
    std::string strJoin(std::vector<std::string> strList, char sep)
    {
        std::string res = "";
        for (auto &&str : strList)
        {
            res += (std::string(1, sep) + str);
        }
        return res;
    }

} // namespace StringHelper

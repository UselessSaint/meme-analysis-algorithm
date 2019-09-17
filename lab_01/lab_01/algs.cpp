#include <algs.h>

size_t m(char a, char b)
{
    size_t result = 0;

    if (a == b)
        result = 0;
    else
        result = 1;

    return result;
}

size_t levenshtein_recursion(std::string s1, std::string s2)
{
    size_t result = 0;

    if (s1.size() == 0 && s2.size() == 0)
        result = 0;
    else if (s1.size() == 0)
        result = s2.size();
    else if (s2.size() == 0)
        result = s1.size();
    else
    {
        result = std::min({levenshtein_recursion(s1.substr(0, s1.size()-1), s2) + 1,
                           levenshtein_recursion(s1, s2.substr(0, s2.size()-1)) + 1,
                           levenshtein_recursion(s1.substr(0, s1.size()-1), s2.substr(0, s2.size()-1)) + m(s1[s1.size() - 1], s2[s2.size() - 1])
                          });
    }

    return result;
}

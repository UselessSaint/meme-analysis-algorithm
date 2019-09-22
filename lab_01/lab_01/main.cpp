#include <algs.h>


int main()
{
    std::string s1;
    std::string s2;

    std::cin >> s1;
    std::cin >> s2;

    levenshtein_matrix(s1, s2);

    return 0;
}

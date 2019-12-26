#include "strsrch.h"

int main()
{
    std::string str;
    std::string substr;

    std::cout << "Enter str: ";
    std::cin >> str;

    std::cout << "Enter substr: ";
    std::cin >> substr;

    auto res = standart(str, substr);
    std::cout << "Std alg res: " << res << std::endl;

    res = kmp(str, substr);
    std::cout << "Kmp alg res: " << res << std::endl;

    res = bm(str, substr);
    std::cout << "Bm alg res: " << res << std::endl;

    return 0;
}

#include <algs.h>

size_t levenshtein_matrix(std::string s1, std::string s2)
{
    size_t result = 0;

    std::vector<size_t> row1;
    std::vector<size_t> row2;

    for (size_t i = 0; i < s2.size() + 1; i++)
    {
        row1.push_back(i);
    }

    std::cout << "    ";
    for (auto it : s2)
        std::cout << it << ' ';
    std::cout << "\n";

    std::cout << "  ";

    for (auto it : row1)
        std::cout << it << ' ';
    std::cout << "\n";

    for (size_t i = 0; i < s1.size(); i++)
    {
        std::cout << s1[i] << ' ';
        row2.push_back(i + 1);
        for (size_t j = 0; j < s2.size(); j++)
        {
            size_t temp = std::min({
                                 row1[j+1] + 1,
                                 row2[j] + 1,
                                 row1[j] + size_t(s1[i] == s2[j] ? 0 : 1)
                                  });

            row2.push_back(temp);
        }
        for (auto it : row2)
                std::cout << it << ' ';
        std::cout << "\n";

        std::copy(row2.begin(), row2.end(), row1.begin());
        row2.clear();
    }

    return result;
}

/*
      f a t
    0 1 2 3
 c  1 1 2 3
 a  2 2 1 2
 t  3 3 2 1
*/

#include <set>

#include <iostream>

int main()
{
    std::set<int> iset = {1,2,3,4,5,6,7,8,9,0};

    for (std::set<int>::iterator it = iset.begin(); it != iset.end(); ++it)
    {
        std::cout << *it << " " ;
        // *it = 54; //error, read only!
    }
    std::cout << std::endl;

    return 0;
}
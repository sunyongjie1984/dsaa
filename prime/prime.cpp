#include <iostream>
bool IsPrime(const int num)
{
    int i;
    for (i = 2; i < num - 1; i++)
    {
        if (0 == num % i)
        {
            break;
        }
    }
    if ((i == num - 1) || (2 == num ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << IsPrime(n) << std::endl;

    return 0;
}

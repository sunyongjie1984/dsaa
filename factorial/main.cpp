// n�Ľ׳�

#include <iostream>
using namespace std;

int main()
{
    unsigned long fac(unsigned int const & n);
    unsigned int n;
    unsigned long y;
    cout << "����һ��������:";
    cin >> n;

    y = fac(n);
    cout << y << endl;
    return 0;
}

unsigned long fac(unsigned int const & n)
{
    unsigned long f;
    if(0 == n)
    {
        f = 1;
    }
    else
    {
        f = fac(n - 1) * n; //�ݹ����
    }
    return f;
}


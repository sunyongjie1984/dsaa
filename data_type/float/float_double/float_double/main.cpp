#include <iostream>
#include <float.h>
using std::cout;
using std::endl;

// �����������Сֵ
int main()
{
    cout << "int �����ܴ洢�����ֵ����Сֵ" << endl;
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "INT_MIN = " << INT_MIN << endl;
    cout << "long �����ܴ洢�����ֵ����Сֵ" << endl;
    cout << "LONG_MAX = " << LONG_MAX << endl;
    cout << "LONG_MIN = " << LONG_MIN << endl;

    cout << "float �����ܴ洢�����ֵ����Сֵ" << endl;
    cout << "FLT_MAX = " << FLT_MAX << endl;
    cout << "FLT_MIN = " << FLT_MIN << endl;
    cout << "double �����ܴ洢�����ֵ����Сֵ" << endl;
    cout << "DBL_MAX = " << DBL_MAX << endl;
    cout << "DBL_MIN = " << DBL_MIN << endl;

    float a  = FLT_MAX;
    double b = DBL_MAX;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
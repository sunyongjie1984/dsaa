#include <iostream> //�������һ��Ŭ���˺ܾõģ��Ǻǡ������ֽ���
using namespace std;
struct tagAAA
{
	unsigned char a : 1;
	unsigned char b : 2;
    unsigned char c : 6;
	unsigned char d : 4; // �����ֽ�
	unsigned char e;     // ���ĸ�
	unsigned char f : 4; // �Լ��ĸ�
	unsigned long g;     // ���ĸ�
}AAA_S;
int main()
{
	cout << sizeof(AAA_S) << endl;
	return 0;
}

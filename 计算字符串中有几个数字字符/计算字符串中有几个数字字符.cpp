#include <iostream>
using namespace std;
int CalcDigital(char *str)
{
	if(str == NULL)
		return 0;
	int num_of_digital = 0;
	for (int i = 0; str[i] != 0; i++) 
		if(str[i] <= '9' && str[i] >= '0')
			num_of_digital++;
	return num_of_digital;
}
int main()
{
	char *p = "I love China! 1000 times"; 
//	char *p = NULL; // ���������0
//	char *p = "0";  // ���������1
	char *a = ""; ; ; ; ; // ��ͦ�����
	int i = CalcDigital(p);
	cout << i << endl;
	return 0;
}

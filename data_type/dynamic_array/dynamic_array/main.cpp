#include <iostream>
int main()
{
    int i = 20;
    // ����ʼ��
    int* p = new int[i]; // ��̬��������鲻��Ҫ��������ȷ�������鳤�ȡ�
    // ��ʼ��Ϊ0
//    int* p = new int[i](); // ��̬��������鲻��Ҫ��������ȷ�������鳤�ȡ�
    //������
//    int* p = new int[i](); // ��̬��������鲻��Ҫ��������ȷ�������鳤�ȡ�
    for (int j = 0; j != 10; j++)
    {
        std::cout << *(p + j) << std::endl;
    }
    return 0;
}
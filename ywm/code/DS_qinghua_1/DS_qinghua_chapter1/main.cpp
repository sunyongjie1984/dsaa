#include <iostream>

#ifdef __linux
#include <stdio.h>
#endif

typedef struct  
{
    int i;
    float j;
}LNode, *pNode;
// �Ҿ�������������˼��
// LNode������ͺ�*pNode��һ�����ͣ���ôpNode�����;���ָ��LNode���͵�ָ��

int main()
{
    LNode a;
    a.i = 200;
    a.j = 200.00;

    // pNode��Ϊһ�����ͣ������˱���p����ʼ��Ϊa�ĵ�ַ
    // PNodeһ����LNode*��һ����
    // ��Ϊ������˵��Ӧ����������� LNode* p = &a����֪����������ⲻ

    pNode p = &a;

    std::cout << p->j << std::endl;

    getchar();
    return 0;
}
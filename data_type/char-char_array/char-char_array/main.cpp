#include <list>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    // �����䶨����һ��ָ�����飺


    // 1��������һ������
    // 2������������words
    // 3, ������Ԫ������Ϊָ��
    // 4, ָ������Ϊָ���ַ���ָ��
    char* words[] = { "stately", "plump", "buck", "mulligan" };
    size_t words_size = sizeof(words) / sizeof(char*);
    list<string> words2(words, words + words_size);

    char* p = "hehe"; // ������һ��ָ���ַ���ָ�룬���ָ�뱻��ʼ��Ϊһ���ַ��������ĵ�ַ��
    char a = 'a';
    char* p2 = &a;

    // 1��������һ������
    // 2������������a
    // 3, ������Ԫ������Ϊ�ַ�
    char a[] = { 's', 'b', 'c'};
    return 0;
}

#include <atlstr.h>
#include <iostream>
#include <string>
int main()
{   
    CString cs = L"I Love China";
    // CString�ǲ�����ô����ģ����Կ��Կ�����ֵ�ǳɹ��ġ���������Ӧ��
    // ��MFC�ĶԻ����е��ԡ�
    std::cout << cs << std::endl;
    std::string s = "I Love China";
    std::cout << s << std::endl;
    return 0;
}
//��char*һ������
//char* ��ͣ�����Լ��������ַ�������ָ�룿˭�ܸ���һ�����ݣ�
#include <iostream>
#include <string>
// add for FR ddd test

using namespace std;

char* GetName(int nID)
{
    if(nID > 0)
    {
        return "Name";
    }
    else
    {
        return NULL;
    }
    // return "";
}
// add started get const name 2011_11_30_syj
const char* GetConstName(int nID)
{
    if(nID > 0)
    {
        return "Name";
    }
    else
    {
        return NULL;  
    }
}
// add end get const name 2011_11_30_syj

int main()
{
    string strName = GetName(1);
    cout << strName << endl;
    // strName = GetName(0);       // run error
    // cout << strName << endl;    // ����Ϊԭ���ǣ�GetNameӦ�÷���һ�����ַ����ͺ���"" 
    // ����һ�£���Ȼ���ԡ�

    const string strConstName = GetConstName(1);
    cout << strConstName << endl;

    // const string strConstName2 = GetConstName(0); //run error
    // cout << strConstName2 << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    const int up=1001;
    int a[up];
    for (int i=1; i<up; i++)
    {
        a[i]=i;
    }
    for (i=2; i<up; i++)
    {
        if (a[i]!=0)
            for (int j=i+1; j < up; )
            {
                if (j%i==0)
                    a[j]=0;
                j=j+1;
            }
    }
    int j=0;
    for (i=2; i<up; i++)
    {
        // static int j = 0;
        if (a[i]!=0)
        {
            cout<<i<<' ';

            // ���Լ��ӵ���Ҫʵ��ÿ10��һ���С�����j����ʼ���ˣ���ô����֪����ôŪʵ����
            j++;                                                        // ̫���ˣ��Ǻǡ�
            if((j%10)==0)
                cout<<"\n";
        }
    }
    cout<<"\n"<<"һ���� "<<j<<" ������"<<endl;
    return 0;
}

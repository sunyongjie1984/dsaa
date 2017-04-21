#include <iostream>
using namespace std;
void SelectSort(int* const a, int n)
{
    int i, j, k;
    for (i=0; i<n-1; i++) // ѡ��� i С�ļ�¼����������λ
    {
        j = i;
        for (k=i+1; k<=n-1; k++) // ��a[i..n-1]��ѡ��ؼ�����С�ļ�¼
        {
            if (a[k]<a[j])
            {
                j=k; // "<"��">"��Ϊ ��������
            }
        }
        if (i!=j)
        {
            swap(a[i], a[j]); //��� i ����¼����
        }
    }
}
int main()
{
    int a[] = { 20, 50, 40, 30, 80, 70 };
    int n=sizeof(a)/sizeof(int);
    SelectSort(a ,n);
    for ( int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

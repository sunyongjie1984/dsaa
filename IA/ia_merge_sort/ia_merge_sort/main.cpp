#include <iostream>
// ����Ϊa[0],a[1].....a[p],a[p+1],a[p+2]....a[q]..a[r],a[r+1]......;
// һ�������ߴ�
// first a[0],a[1] then a[2],a[3],
// then  a[0]~a[3]
// then  a[4],a[5], then a[6],a[7]
// then  a[4]~a[7]
// then  a[0]~a[7].
void merge(int* const a, int const p, int const q, int const r)
{   // ��һ�ε��������ʱ��p==0��q==0��r==1��������ɶ���Ԫ����ɵ����鿴�����������Ѿ�����Ĵ�СΪ1���������	
    // a[0]==5,a[1]==2
    for (int i = p; i < p + (r - p + 1); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    int n1 =q - p + 1; // ��Ϊ���±�Ϊq��Ԫ�طֵ��˵�һ�������У�����n1Ϊq-p+1
    int n2 =r - q;
    int* L =new int[n1 + 1]; // ��һ��Ԫ���������ڱ�
    int* R =new int[n2 + 1];
    for (int i = 0; i < n1; ++i)
        L[i] = a[p + i];
    for (int j = 0; j < n2; ++j)
        R[j] = a[q + j + 1];
    // L[n1]=1024*1024*1024*2-1; // 2^31-1�η���������������о����ǲ���˵�������������ֵ1024*1024*1024*2
    // R[n2]=1024*1024*1024*2-1; // ����������һ���ֱ�ʾ�ģ�����������Ѿ�Խ���ˣ��Ҳ������ˡ�����������ʾӦ�þͿ����ˡ�
    L[n1] = 1024 * 1024 * 1024 - 1 + 1024 * 1024 * 1024; // ������Ȼ�������ˡ�
    R[n2] = 1024 * 1024 * 1024 - 1 + 1024 * 1024 * 1024;
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; ++k)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }
        else
        {
            a[k] = R[j];
            ++j;
        }
    }
    for (int i = p; i < p + (r - p + 1); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void merge_sort(int* a, int const p, int const r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);   // ��һ�Σ������￪ʼ�˶�a[0],a[1],a[2],a[3]��devide
        // �ڶ��Σ������￪ʼ�˶�a[0],a[1]��devide��
        // �����Σ������￪ʼ�˶�a[0],a[0]devede,����merge_sort��ֱ���˳���
        // Ȼ���һ�ν�����merge_sort(a, q+1, r)�����䡣
        merge_sort(a, q + 1, r); // first time�������￪ʼ�˶�a[1],a[1]��devide,����merge_sort��ֱ���˳���
        // �൱�ڶ�a[0],a[1]��������devide�����Ѿ�������Ҳ����˵merge_sort���ڵ�����Ԫ��ʱ���Կ�ʼmerge�Ĺ����ˡ�

        merge(a, p, q, r);	   // ���������merge(a, 0, 0, 1);�����������Ԫ�صĴ����鵱���������鿪ʼmerge��
        // ֮��Ӧ���Ƕ�a[2],a[3]��devide���̣�����merge_sort(a, q+1, r)ʵʩ��
        // �������������merge_sort(a, p, q)devide,a[2],a[2]ֱ���˳�����
        // merge_sort(a, q+1, r)�����devide,a[3],a[3]ֱ���˳��󣬽���a[2],a[3]
        // �Ĺ��̡�
        // ��Ȼ�����merge,a[0],a[1],a[2],a[3]�Ĺ��̡���������������Ҳ����ջ
        // ���ص���һ�ν���merge_sort(a, p, q)�ĵط���Ȼ��ʼdevide,
        // a[4],a[5],a[6],a[7]Ȼ��ʼdevide,a[4],a[5],devide,a[4],a[4],
        // devide,a[5],a[5].merge,a[4],a[5],devide,a[6],a[7],devide,a[6],a[6]
        // devide,a[7],a[7],merge,a[6],a[7],merge,a[4],a[5],a[6],a[7],
        // merge,a[0~7]������
    }
}
int main()
{
    int a[10] = { 2, 5, 3, 8, 1, 4, 23, 2, 123, 4 };
    std::cout << "before sort" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n" << std::endl;
    merge_sort(a, 0, 9);
    std::cout << "\nafter sort" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n" << std::endl;

    int b[8] = { 5, 2, 4, 7, 1, 3, 2, 6 };
    std::cout << "before sort" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << b[i] << " ";
    }
    std::cout << "\n" << std::endl;
    merge_sort(b, 0, 7);
    std::cout << "\nafter sort" << std::endl;
    for (int i = 0; i < 8; ++i)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

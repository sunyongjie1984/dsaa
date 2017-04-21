#include <iostream>
using namespace std;
void print(int*, int);
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Bubble
void Bubble(int* const a, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) // i < n-1 (��:10����ֻѭ��9��)
        for (j = 0; j < n-1-i; j++) // j< n-1-i (��:10����ֻ��9-i�ν���)
        {
            if (a[j] > a[j+1]) // ����> ��� �ɴ�С
            {
                swap(a[j], a[j+1]);
            }
        }
}
// Quick Sort
int Partition(int* const a, int low, int high)
{
    int rc = a[low];
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] <= pivot) --high; // ����>= ��� ��������
        a[low] = a[high];

        while (low < high && a[low] >= pivot) ++low; // ����<= ��� ��������
        a[high] = a[low];
    }
    a[low] = rc;
    return low;
}

void QSort(int* const a, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(a, low, high); // cout << "Pivot:" << pivot << '\t';
        QSort(a, low, pivot-1);
        QSort(a, pivot+1, high);
    }
}

void QuickSort(int* const a, int n)
{
    QSort(a, 0, n-1);
}

void SelectSort(int* const a, int n)
{
    int i, j, k; // ���浽��Ӧ����<����<=�أ�
    for (i = 0; i < n-1; i++) // ѡ��� i С�ļ�¼����������λ
    {
        j = i;
        for (k = i+1; k <= n-1; k++) // ��a[i..n-1]��ѡ��ؼ�����С�ļ�¼
        {
            if (a[k] < a[j]) j = k; // "<"��">"��Ϊ ��������
        }
        if (i != j) 
        {
            swap(a[i], a[j]); //��� i ����¼����
        }
    }
}

// Heap Sort
void HeapAdjust(int* const a, int s, int m)
{
    // ��֪a[s..m]�У�����a[s]֮�⣬������Ѷ���
    // ����������a[s]��ʹ���Ϊһ���󶥶�
    int i = 0;
    int rc = a[s];
    for (i = 2 * s; i <= m; i *= 2) // ��keyֵ�ϴ�ĺ��ӽڵ�����ɸѡ
    {
        // С����, ��������������>�ø��ĺ󣬱�Ϊ�󶥶�
        if (i < m && (a[i] > a[i+1])) i++; // jΪ�ؼ��ֽ�С�ļ�¼���±�
        if (rc <= a[i]) break; 
        a[i / 2] = a[i]; //�ڵ�j ����,������ĸ��ڵ���
    }
    a[i / 2] = rc; // ����
}

void BuildHeap(int* const a, int n)
{
    // a[0..n-1]���ɶ�
    // ���������һ��Ԫ�ؿ�ʼ��ǰ������
    int i = 0;

    for (i = n-2; i >= 0; i--)
    {
        HeapAdjust(a, i, n-1);
    }
}

void HeapSort(int* const a, int n)
{
    // a[0..n-1]
    int i = 0;
    BuildHeap(a, n);

    swap(a[0], a[n-1]); // ����"�Ѷ�"��"�ѵ�"�ļ�¼
    for (i = n-2; i >= 0; i--)
    {
        HeapAdjust(a, 0, i); // �Ӹ���ʼ�������� a[1..i] ���µ���Ϊ�󶥶�
        swap(a[0], a[i]); // ����"�Ѷ�"�͵�ǰ��"�ѵ�"��ʹ������ļ�¼�����ڵײ�
    }
}

int main()
{
    int a[] = {56, 49, 65, 97, 100, 76, 60, 300, 13, 9};
    int n = sizeof(a) / sizeof(int);
    cout << n << "numbers:" << endl;
    print(a, n);
    cout << "--------------------------------------" << endl;
    // Bubble Sort:
    cout << "Bubble:" << endl ; 
    Bubble(a, n);
    print(a, n);
    // Quick Sort:
    cout << "Quick Sort:" << endl; 
    QuickSort(a, n);
    print(a, n);
    // Select Sort:
    cout << "Select Sort:" << endl; 
    SelectSort(a, n);
    print(a, n);
    // Heap Sort:
    cout << "Heap Sort:" << endl; 
    HeapSort(a, n);
    print(a, n);
    cout << endl <<"---------------------------------------" << endl;
    cout << "GCD:" << endl;
    cout << GCD(a[0], a[1]) << endl;
    cout << GCD1(a[0], a[1]) << endl;

    return 0;
}

void print(int* const a, int n)
{
    int i = 0;
    while (i < n)
    {
        cout << a[i] << '\t';
        i++;
    }
    cout << endl;
}

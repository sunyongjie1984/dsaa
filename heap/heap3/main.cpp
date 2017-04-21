#include <stdio.h>
#include <stdlib.h>

void HeapSort(int num[], int size);
void BuildHeap(int num[], int size);
void PercolateDown(int num[] , int index, int size);
void PrintHeap(const char* strMsg, int array[], int nLength);
void Swap(int num[] , int v, int u);

int main(int argc, char *argv[])
{
    /* �����鿴����ȫ�����������������������Դ洢 */
    int data[13]={8, 5, 4, 6, 13, 7, 2, 9, 12, 11, 3, 10, 1};
    HeapSort(data, 13);

    system("PAUSE");
    return 0;
}


void HeapSort(int num[] ,int size)
{
    int i;
    int iLength = size;

    PrintHeap("Befor Sort:", num, iLength);

    BuildHeap(num, size);           // ����С����

    for (i = iLength - 1; i >= 1; i--)
    {
        Swap(num, 0, i);            // ����
        size--;                     // ÿ����һ���ù�ģ����һ��
        PercolateDown(num, 0, size); // ���µ���Ԫ�����˲���
        PrintHeap("Sort Heap:", num, iLength);
    }
}

/* ���ѷ�����ֻ������ʱ�佨�ã�
   ���ѵĽ��������ĵ�һ��Ԫ�أ���������������Ԫ���е���Сֵ������С�ڵ���size/2-1������Ԫ�أ���������Ҷ�ӽڵ㣩��ֵ������������������Сֵ */   
void BuildHeap(int num[] ,int size)
{
    int i;
    // �����һ����Ҷ�ӽڵ㿪ʼ����ÿ����Ҷ�ӽڵ������С����������֤ÿ�����ڵ㶼���������е���Сֵ
    for (i = size / 2 - 1; i >= 0; i--)
    {
        PercolateDown(num, i, size); // �������˲���
        PrintHeap("Build heap:", num, size);
    }
}

/* �Ը����������˲�����ֱ�����������ҽڵ㶼С��ֹͣ���ˡ�
   ����ĳ�����ڵ��ֵ����λ���½�������ʹ��ֵ���������ӽڵ㶼С��
   ���ýڵ���Ҷ�ӽڵ㣬���޷�whileѭ�� */
void PercolateDown(int num[] , int index, int size)
{
    int min;// ������Сָ���±�
    while (index * 2 + 1 < size)
    {   // �����������ڵ㣬�������ڵ���С
        min = index * 2 + 1;// ��ȡ��ڵ���±�
        if (index * 2 + 2 < size)
        {   // ������������ҽڵ�
            if (num[min] > num[index * 2 + 2])
            {   // �ͺ���ڵ�ֳ���С��
                min = index * 2 + 2;// ��ʱ�ҽڵ��С�������min��ָ���±�   
            }
        }
        // ��ʱ���и�������С�߽��бȽϣ�
        if (num[index] < num[min])
        {   // ���index��С��
            break; // ֹͣ���˲���
        }
        else
        {
            Swap(num, index, min); // �������������ô������³�
            index = min; // ����index��ָ��
        }
    }// while
}

// �������齻����������λ��
void Swap(int num[] , int v, int u)
{
    int temp = num[v];
    num[v] = num[u];
    num[u] = temp;
}

void PrintHeap(const char* strMsg, int array[], int nLength)
{
    int i;
    printf("%s", strMsg);
    for(i = 0;i < nLength; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

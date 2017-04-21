#include <iostream>
using namespace std;
class MergeSort {
public:
    //���캯��
    MergeSort(int length)
    {
        this->length=length;
        arr=new int[length+1];
        temp=new int[length+1];
        num=0;
    }
    //�鲢����ݹ鶨���㷨
    void mergeSort(int start,int end)
    {
        int middle;
        if(start<end)
        {
            middle=(start+end)/2;
            mergeSort(start,middle);
            mergeSort(middle+1,end);
            merge(start,middle,end);
        }
    }
    //�ϲ��㷨
    void merge(int start,int middle,int end)
    {
        int i=start;
        int j=middle+1;
        int k=start;
        copy(start,end); //����arr[start:end]��temp[start:end]
        while(i<=middle&&j<=end)
        {
            if(temp[i]<=temp[j])
            {
                arr[k++]=temp[i++];
            }
            else
            {
                arr[k++]=temp[j++];
                num+=middle-i+1; //����Լ�¼ ����Ϊ���arr[i]>arr[j],��Ϊarr[start:middle]�Ѻ���ʵ���״̬������arr[i:middle]������arr[j],������middle-i+1�������
            }
        }
        while(i<=middle)
        {
            arr[k++]=temp[i++];
        }

        while(j<=end)
        {
            arr[k++]=temp[j++];
        }
    }
    //��������
    void copy(int start,int end)
    {
        while(start<=end)
        {
            temp[start]=arr[start];
            start++;
        }
    }
    //�������ݺ���
    void input()
    {
        int i=1;
        while(i<=length)
        {
            cin>>arr[i++];
        }
    }
    //�������������
    void display()
    {
        int i=1;
        while(i<=length)
        {
            cout<<arr[i++]<<" ";
        }
    }
private:
    int *arr;    //����������
    int *temp;   //��ʱ��¼����
    int length;  //���鳤��
    int num;     //���������
};

void main()
{
    MergeSort test(10);   //ʵ��������
    test.input();         //��������
    test.mergeSort(1,10); //��1-10����10�����ݽ�������
    test.display();      //��ӡ�������
}


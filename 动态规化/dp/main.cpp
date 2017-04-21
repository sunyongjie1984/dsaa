#include <iostream>
using namespace std;

//��̬�滮��0-1��������
//bestValue[i][j]=max ( bestValue[i+1][j-w[i]]+v[i] ,bestValue[i+1][j] )  w[i]<=j
//bestValue[i][j]=bestValue[i+1][j]        w[i]>j

class Knapsack
{
private:
    int *weight;        //��Ʒ��������
    int *value;         //��Ʒ��ֵ����
    int numOfItems;     //��Ʒ����
    int bagSpace;       //��������
    int **bestValue;    //��̬�滮��񣬼�¼bestValue[i][j]�ļ�ֵ��Ϊ���ż�ֵ��i��ʾ��Ʒi...nװ������Ϊj�ı����ܴﵽ������ֵ
    int **path;         //Ϊ�����ȡ������ֵʱ�Ľ⣬��¼��̬�滮��ͬ�����ѡ�����
public:
    //���캯��
    Knapsack(int numOfItems,int bagSpace)
    {
        weight=new int[numOfItems+1];
        value=new int[numOfItems+1];
        this->bagSpace=bagSpace;
        this->numOfItems=numOfItems;

        bestValue=new int* [numOfItems+1];
        for(int i=0;i<numOfItems+1;i++)
        {
            bestValue[i]=new int[bagSpace+1];
        }

        path=new int* [numOfItems+1];
        for(int i=0;i<numOfItems+1;i++)
        {
            path[i]=new int[bagSpace+1];
        }
    }
    //������Ʒ���������ֵ
    void input()
    {
        int i=1;
        while(i<=numOfItems)
        {
            cout<<"�����"<<i<<"����Ʒ������"<<endl;
            cin>>weight[i];
            cout<<"�����"<<i<<"����Ʒ�ļ�ֵ"<<endl;
            cin>>value[i];
            ++i;
        }
    }
    //��̬�滮�����㷨
    void knapsack()
    {
        //��ʼ���ݹ���ײ�,����bestValue[n][0:c]���г�ʼ��
        for(int i=0;i<=bagSpace;i++)
        {
            if(weight[numOfItems]<=i)
            {
                bestValue[numOfItems][i]=value[numOfItems];
                path[numOfItems][i]=1;
            }
            else
            {
                bestValue[numOfItems][i]=0;
                path[numOfItems][i]=0;
            }
        }
        //���ƵĽ��ж�̬�滮���Ե����ϣ�����bestValue[1][bageSpace]Ϊ1-n��Ʒ��������bagSpace�ڵ�����ֵ
        for(int k=numOfItems-1;k>=1;k--)
        {
            for(int j=0;j<=bagSpace;j++)
            {
                bestValue[k][j]=bestValue[k+1][j];
                path[k][j]=0;//����������
                if(weight[k]<=j)//��������㹻���뵱ǰ��Ʒ
                {
                    if(bestValue[k+1][j-weight[k]]+value[k]>bestValue[k][j])//�������ļ�ֵ���ڲ��ŵļ�ֵ
                    {
                        bestValue[k][j]=bestValue[k+1][j-weight[k]]+value[k];
                        path[k][j]=1;//��ô��ѡ�����
                    }
                }
            }
        }
    }
    //�������ֵ���������ѡ��ʽ
    void display()
    {
        //��ӡ��bestValue[1][bagSpace],��ʾ1...numOfItems����Ʒװ������ΪbagSpace������ֵ
        int i=1;
        int j=bagSpace;
        cout<<"����ֵΪ"<<bestValue[1][j]<<endl;
        //����path[1][bagSpace]�ļ�¼��ʼ���ݹ鵽path[n][ĳ����],�Ӷ���ӡ��ÿ����Ʒ�Ƿ�ѡ����뱳��
        while(i<=numOfItems)
        {
            if(path[i][j]==0)//���i��Ʒû�����룬��i+1����Ʒװ������j����
            {
                ++i;
            }
            else
            {
                cout<<"<����:"<<weight[i]<<"����ֵ:"<<value[i]<<">" << endl;
                j-=weight[i];
                ++i;
            }
        }
    }
};

void main()
{
    // 0/1��������:����4������,�������ֱ�Ϊ(4,7,5,3),��ֵΪ(40,42,25,12),��������W = 10
    Knapsack test(4,10); // 4����Ʒ����������10
    test.input();        // ����4����Ʒ�ļ�ֵ������
    test.knapsack();     // ��̬�滮
    test.display();      // ��ӡѡ��������ֵ
}

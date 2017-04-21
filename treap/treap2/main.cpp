#include <iostream>
#include <ctime>
#define MAX 100

using namespace std;

typedef struct
{
    int l,r,key,fix;
}node;

class treap
{
public:
    node p[MAX];
    int size,root;
    treap()
    {
        srand(time(0));
        size=-1;
        root=-1;
    }

    void rot_l(int &x)  //�������ͼ��
    {
        int y=p[x].r;
        p[x].r=p[y].l;
        p[y].l=x;
        x=y;
    }

    void rot_r(int &x) //�������ͼ��
    {
        int y=p[x].l;
        p[x].l=p[y].r;
        p[y].r=x;
        x=y;
    }

    void insert(int &k,int tkey)
    {
        if (k==-1) //���ڵ�Ϊ�գ�����
        {
            k=++size;
            p[k].l=p[k].r=-1;//����������Ϊ��
            p[k].key=tkey;//����ؼ���
            p[k].fix=rand();//����һ����������ȼ�
        }
        else
            if (tkey<p[k].key)  //���ն���������Ĺ���ȥ����
            {
                insert(p[k].l,tkey);
                if (p[ p[k].l ].fix>p[k].fix) //���ǲ��겻��������Ҫ������ת
                    rot_r(k);
            }
            else
            {
                insert(p[k].r,tkey);
                if (p[ p[k].r ].fix>p[k].fix)
                    rot_l(k);
            }

    }

    void remove(int &k,int tkey)  //ɾ���ڵ�
    {
        if (k==-1) return;
        if (tkey<p[k].key)  //���ն���������Ĺ���ȥ����
            remove(p[k].l,tkey);
        else if (tkey>p[k].key)
            remove(p[k].r,tkey);
        else
        {
            if (p[k].l==-1 && p[k].r==-1) //��ɾ������Ҷ�ӽڵ㣬ֱ��ɾ��
                k=-1;
            else if (p[k].l==-1)  //��ɾ�������ӽڵ�Ϊ��
                k=p[k].r;
            else if (p[k].r==-1) //��ɾ�����к��ӽڵ�Ϊ��
                k=p[k].l;
            else
                if (p[ p[k].l ].fix < p[ p[k].r ].fix)  //ѡ���ӽڵ�С�ķ�����ת
                {
                    rot_l(k);
                    remove(p[k].l,tkey);
                }
                else
                {
                    rot_r(k);
                    remove(p[k].r,tkey);
                }
        }
    }

    void print(int k)  //�������
    {
        if (p[k].l!=-1)
            print(p[k].l);
        cout << p[k].key << " : " << p[k].fix << endl;
        if (p[k].r!=-1)
            print(p[k].r);
    }
};

treap T;

int main()
{

    int i;
    for (i=8;i>=1;i--)
        T.insert(T.root,i);
    cout<<"����ڵ�֮��"<<endl;
    T.print(T.root);
    for (i=3;i>=1;i--)
    {
        cout << "ɾ��keyΪ"<<i<<"�Ľڵ㣺"<<endl;
        T.remove(T.root,i);
        T.print(T.root);
    }
    system("pause");
    return 0;
}
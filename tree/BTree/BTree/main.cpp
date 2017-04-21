#include <iostream>
#ifdef __linux
#include <stdio.h>
#endif

class BTreeNode {
public:
    BTreeNode(): data(0), lchild(NULL), rchild(NULL) { }
    char data;
    BTreeNode* lchild;
    BTreeNode* rchild;
};

class BTree {
public:
    BTree() // �ȸ���һ����������Ĺ��캯��������Һ���Ϊ��ʱ�����뺢�ӽ��ֵΪ'#'
    {
        root = new BTreeNode;
        PreOrderCreate(root);
    }
    BTree(const char* q, int n) // ���Ĵ洢��һά����˳��洢��������յ�λ������'#'����Ϊ���ֵ
    {
        root = new BTreeNode;
        LeverCreate(root, q, 0, n);
    }
    void PrintPreOrder() // print preorder
    {
        PreOrder(root);
        std::cout << std::endl;
    }
    void PrintInOrder() // print inorder
    {
        InOrder(root);
        std::cout << std::endl;
    }
    void PrintPostOrder() // print postorder
    {
        PostOrder(root);
        std::cout << std::endl;
    }
private:
    void PreOrderCreate(BTreeNode* p) // create tree preorder
    {
        std::cin >> p->data;
        if ('#' != p->data)
        {
            p->lchild = new BTreeNode;
            p->rchild = new BTreeNode;
            PreOrderCreate(p->lchild);
            if ('#' == p->lchild->data)
            {
                delete p->lchild;
                p->lchild = NULL;
            }
            PreOrderCreate(p->rchild);
            if ('#' == p->rchild->data)
            {
                delete p->rchild;
                p->rchild = NULL;
            }
        }
        else
        {

        }
    }
    void LeverCreate(BTreeNode* p, const char* q, int i, int n)
    {
        if ('#' != q[i] && i < n)
        {
            p->data = q[i];
            p->lchild = new BTreeNode;
            p->rchild = new BTreeNode;
            LeverCreate(p->lchild, q, 2 * i + 1, n);
            if ('\0' == p->lchild->data)
            {
                delete p->lchild;
                p->lchild = NULL;
            }
            LeverCreate(p->rchild, q, 2 * i + 2, n);
            if ('\0' == p->rchild->data)
            {
                delete p->rchild;
                p->rchild = NULL;
            }
        }
    }
    void PreOrder(BTreeNode* p) // �ȸ����
    {
        if (NULL != p)
        {
            std::cout << p->data << " ";
            PreOrder(p->lchild);
            PreOrder(p->rchild);
        }
    }
    void InOrder(BTreeNode* p) // �и����
    {
        if (NULL != p)
        {
            InOrder(p->lchild);
            std::cout << p->data << " ";
            InOrder(p->rchild);
        }
    }
    void PostOrder(BTreeNode* p) // ������
    {
        if (NULL != p)
        {
            PostOrder(p->lchild);
            PostOrder(p->rchild);
            std::cout << p->data << " ";
        }
    }
private:
    BTreeNode* root;
};

int main()
{
    const char* c = "abcdeg###f##h";

    BTree a(c, 13);
    a.PrintPreOrder();
    a.PrintInOrder();
    a.PrintPostOrder();

    BTree b; // ������캯�����ȸ�˳�򹹸����������
    b.PrintPreOrder();
    b.PrintInOrder();
    b.PrintPostOrder();

    getchar();
    return 0;
}

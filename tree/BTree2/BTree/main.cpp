#include <iostream>
class BiTNode {
public:
    char data;
    BiTNode* lchild;
    BiTNode* rchild;
};
bool visit(char a)
{
    std::cout << a << " ";
    return true;
}                 // ��ָ�������
bool CreateBiTree(BiTNode*& p)
{
    char ch;
    std::cin >> ch;
    if ('#' == ch)
    {
        p = NULL;
    }
    else
    {
        p = new BiTNode;
        p->data = ch;
        CreateBiTree(p->lchild);
        CreateBiTree(p->rchild);
    }
    return true;
}                                 // ����ָ��
bool PreOrderTraverse(BiTNode* p, bool (*visit)(char e))
{
    if (NULL != p)
    {
        visit(p->data);
        PreOrderTraverse(p->lchild, visit);
        PreOrderTraverse(p->rchild, visit);
    }
    return true;
}
bool InOerderTraverse(BiTNode* p, bool (*visit)(char e))
{
    if (NULL != p)
    {
        InOerderTraverse(p->lchild, visit);
        visit(p->data);
        InOerderTraverse(p->rchild, visit);
    }
    return true;
}
bool PostOrderTraverse(BiTNode* p, bool (*visit)(char e))
{
    if (NULL != p)
    {
        PostOrderTraverse(p->lchild, visit);
        PostOrderTraverse(p->rchild, visit);
        visit(p->data);
    }
    return true;
}                // ֻ��Ҫ�����������޸ģ�����������
void DispalyTree(BiTNode* p)
{
    if (NULL != p)
    {
        std::cout << p->data;
        if (NULL != p->lchild || NULL != p->rchild)
        {
            std::cout << "(";
            DispalyTree(p->lchild);
            if (NULL != p->rchild)
                std::cout << ",";
            DispalyTree(p->rchild);
            std::cout << ")";
        }
    }
}
int main()
{
    BiTNode* root = new BiTNode;
    CreateBiTree(root);
    PreOrderTraverse(root, visit);
    std::cout << std::endl;
    InOerderTraverse(root, visit);
    std::cout << std::endl;
    PostOrderTraverse(root, visit);
    std::cout << std::endl;
    DispalyTree(root);
    return 0;
}

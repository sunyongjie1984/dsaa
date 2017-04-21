/********************************************************************
created:    2005/12/30
created:    30:12:2005   10:39
filename:     bintree.h
author:        Liu Qi

purpose:    ��������3�ֱ�����ʽ(�����ǵݹ�ʵ��),ǰ�򣬺���������ȷ��ʸ��ڵ����
ǰ��(�����鼮��Ϊ�ȸ�����,���˾��ø�˵������^_^)�����Ƶģ������ʸ��ڵ���Ǻ���
*********************************************************************/

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

typedef int ElemType;

typedef struct treeT
{
    ElemType key;
    struct treeT* left;
    struct treeT* right;
}treeT, *pTreeT;

/*===========================================================================
* Function name:    visit
* Parameter:        root:�����ڵ�ָ��
* Precondition:
* Description:
* Return value:
* Author:            Liu Qi, //
===========================================================================*/
static void visit(pTreeT root)
{
    if (NULL != root)
    {
        printf(" %d\n", root->key);
    }
}

/*===========================================================================
* Function name:  BT_MakeNode
* Parameter:      target:Ԫ��ֵ
* Precondition:      None
* Postcondition:  NULL != pTreeT 
* Description:      ����һ��tree�ڵ㣬������ָ��Ϊ�գ����ҷ���ָ���½ڵ��ָ��
* Return value:      ָ���½ڵ��ָ��
* Author:            Liu Qi,  [12/30/2005]
===========================================================================*/
static pTreeT BT_MakeNode(ElemType target)
{
    pTreeT pNode = (pTreeT) malloc(sizeof(treeT));

    assert( NULL != pNode );

    pNode->key   = target;
    pNode->left  = NULL;
    pNode->right = NULL;

    return pNode;
}

/*===========================================================================
* Function name:    BT_Insert
* Parameter:        target:Ҫ�����Ԫ��ֵ, pNode:ָ��ĳһ���ڵ��ָ��
* Precondition:         NULL != ppTree 
* Description:        ����target��pNode�ĺ���
* Return value:        ָ���½ڵ��ָ��
* Author:            Liu Qi,  [12/29/2005]
===========================================================================*/
pTreeT BT_Insert(ElemType target, pTreeT* ppTree)
{
    pTreeT Node;

    assert( NULL != ppTree ); 

    Node = *ppTree;
    if (NULL == Node)
    {
        return *ppTree = BT_MakeNode(target);
    }

    if (Node->key == target)    //�����������ͬ��Ԫ��
    {
        return NULL;
    }
    else if (Node->key > target)    //����
    {
        return BT_Insert(target, &Node->left);
    }
    else
    {
        return BT_Insert(target, &Node->right);
    }
}

/*===========================================================================
* Function name:    BT_PreOrder
* Parameter:        root:�����ڵ�ָ��
* Precondition:        None
* Description:        ǰ�����
* Return value:        void
* Author:            Liu Qi,  [12/29/2005]
===========================================================================*/
void BT_PreOrder(pTreeT root)
{
    if (NULL != root)
    {
        visit(root);
        BT_PreOrder(root->left);
        BT_PreOrder(root->right);
    }
}

/*===========================================================================
* Function name:    BT_PreOrderNoRec
* Parameter:        root:�����ڵ�ָ��
* Precondition:        Node
* Description:        ǰ��(�ȸ�)�����ǵݹ��㷨
* Return value:        void
* Author:            Liu Qi,  [1/1/2006]
===========================================================================*/
void BT_PreOrderNoRec(pTreeT root)
{
    stack<treeT *> s;

    while ((NULL != root) || !s.empty())
    {
        if (NULL != root)
        {
            visit(root);
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
}

/*===========================================================================
* Function name:    BT_InOrder
* Parameter:        root:�����ڵ�ָ��
* Precondition:        None
* Description:        �������
* Return value:        void
* Author:            Liu Qi,  [12/30/2005]
===========================================================================*/
void BT_InOrder(pTreeT root)
{
    if (NULL != root)
    {
        BT_InOrder(root->left);
        visit(root);
        BT_InOrder(root->right);
    }
}

/*===========================================================================
* Function name:    BT_InOrderNoRec
* Parameter:        root:�����ڵ�ָ��
* Precondition:        None
* Description:        �������,�ǵݹ��㷨
* Return value:        void
* Author:            Liu Qi,  [1/1/2006]
===========================================================================*/
void BT_InOrderNoRec(pTreeT root)
{
    stack<treeT *> s;
    while ((NULL != root) || !s.empty())
    {
        if (NULL != root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            visit(root);
            s.pop();
            root = root->right;
        }
    }
}

/*===========================================================================
* Function name:    BT_PostOrder
* Parameter:        root:�����ڵ�ָ��
* Precondition:        None
* Description:        �������
* Return value:        void
* Author:            Liu Qi,  [12/30/2005]
===========================================================================*/
void BT_PostOrder(pTreeT root)
{
    if (NULL != root)
    {
        BT_PostOrder(root->left);
        BT_PostOrder(root->right);
        visit(root);
    }
}

/*===========================================================================
* Function name:    BT_PostOrderNoRec
* Parameter:        root:�����ڵ�ָ��
* Precondition:        None
* Description:        �������,�ǵݹ��㷨
* Return value:        void
* Author:            Liu Qi, //  [1/1/2006]
===========================================================================*/
void BT_PostOrderNoRec(pTreeT root)
{
    //ѧϰ�У���δ����
}

/*===========================================================================
* Function name:    BT_LevelOrder
* Parameter:        root:�����ڵ�ָ��
* Precondition:        NULL != root
* Description:        �������
* Return value:        void
* Author:            Liu Qi,  [1/1/2006]
===========================================================================*/
void BT_LevelOrder(pTreeT root)
{
    queue<treeT *> q;
    treeT *treePtr;

    assert( NULL != root ); 

    q.push(root);

    while (!q.empty())
    {
        treePtr = q.front();
        q.pop();
        visit(treePtr);

        if (NULL != treePtr->left)
        {
            q.push(treePtr->left);
        }
        if (NULL != treePtr->right)
        {
            q.push(treePtr->right);
        }

    }
}

#endif


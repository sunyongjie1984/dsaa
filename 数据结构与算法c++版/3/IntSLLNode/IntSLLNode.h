#ifndef INT_SINGLY_LINKED_LIST_NODE
#define INT_SINGLY_LINKED_LIST_NODE
class IntSLLNode 
{
public:
	IntSLLNode() 
	{
		next = 0; // ����һ�����ա��� 
	}
	IntSLLNode(int i, IntSLLNode *in = 0)
	{
		info = i;
		next = in; // �������캯������next����0,̫������
	}
	int info;
	IntSLLNode *next; // �ҽ��������Ƕ�д��IntSLLNode* next;
};                    // ��֪���ò��ã��Ҿ��ø��������
#endif                // ��ΪIntSLLNode* ��next��������

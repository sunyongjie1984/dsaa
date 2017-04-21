#ifndef INT_SINGLY_LINKED_LIST_NODE
#define INT_SINGLY_LINKED_LIST_NODE

#include <iostream>
using namespace std;

class IntSLLNode 
{
public: // �޲Σ�һ���Σ������ζ��й��캯����
	IntSLLNode() 
	{
		info = 0;
		next = NULL; // ����һ�����ա��� 
	}
	IntSLLNode(int i, IntSLLNode* in = 0)
	{
		info = i;
		next = in; // �������캯������next����0��̫������
	}
	friend class IntSLList; // very important, solve the problem of using private in other class or global function.
	friend istream& operator>>(istream&, IntSLList&); 
	friend ostream& operator<<(ostream&, const IntSLList&);

private:
	int info;
	IntSLLNode* next; 
};                    
#endif

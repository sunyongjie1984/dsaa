#ifndef INT_SINGLY_LINKED_LIST
#define INT_SINGLY_LINKED_LIST
#include "IntSLLNode.h"
#include <iostream>
using namespace std;
class IntSLList {
public:
	IntSLList() 
	{
		head = 0;
		tail = 0;
	}
	IntSLList(int n);
    // ���ǵ��������캯��
	// ��û���ú������ס��һ�ͷ����C++ Primer���飬��������Sales_item.h
	IntSLList(istream &is) 
	{
		is >> *this; 
	}
	// ���ĸ��������캯��
	IntSLList(const IntSLList &object) // ������ȷ������ֳ���Ϊʲô��
	{
		head = object.head;
		tail = object.tail;
		cout << 3; // ������
	}
    void setHead()
	{
		head = new IntSLLNode;
	}
	~IntSLList();
	int isEmpty()
	{
		return head == 0;
	}

	void addToHead(int);
	void addtoTail(int);
	
	int deleteFromHead();
	int deleteFromTail();

	void deleteNode(int);

	bool isInList(int) const;

	// �Ҽ�һ���������������
//	friend ostream& operator<<(ostream&, const IntSLList&);
	friend ostream& operator<<(ostream&, IntSLList&);
	friend istream& operator>>(istream&, IntSLList&); 
	// �Ҽ�һ����������ͷָ��ĺ���
	IntSLLNode* getHead()
	{
		return head;
	}
	IntSLLNode* getTail()
	{
		return tail;
	}
private:
	IntSLLNode *head, *tail;
};
#endif

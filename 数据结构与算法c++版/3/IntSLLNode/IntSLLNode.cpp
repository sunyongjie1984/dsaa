#include <iostream>
#include "IntSLList.h"
IntSLList::IntSLList(int n) 
{
	head = new IntSLLNode; // ���ˣ����Ľڵ����ݽڹ��й��캯���������ܣ������ѧ��������
	IntSLLNode *p1 = head;
	cout << "������� 1���ڵ��ֵ" << endl;
	cin >> head->info;
	for (int i = 0; i < n - 1; i++)
	{
		IntSLLNode *p2 = new IntSLLNode;
		cout << "������� "<< i + 2 <<"���ڵ��ֵ" << endl;
		cin >> p2->info;
		p1->next = p2;
		p1 = p2;
	}
	tail = p1;
	tail->next = NULL; // �����£�1��������ע�͵���2����IntSLLNode���next = 0 ע�͵����Լ�����
}

IntSLList::~IntSLList()
{
	for (IntSLLNode *p; !isEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	if (tail == 0)
	{
		tail = head;
	}
}

void IntSLList::addtoTail(int el)
{
	if (tail != 0)
	{
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else
	{
		head = tail = new IntSLLNode(el);
	}
}

int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head == tail)
	{
		head = tail = 0;
	}
	else
	{
		head = head->next;
	}
	delete tmp;
	return el;
}

int IntSLList::deleteFromTail()
{
	int el = tail->info;
	if (head == tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		IntSLLNode *tmp;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;
}

void IntSLList::deleteNode(int el)
{
	if (head != 0)
	{
		if (head == tail && el == head->info)
		{
			delete head;
			head = tail = 0;
		}
		else if (el == head->info)
		{
			IntSLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			IntSLLNode *pred, *tmp;
			for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el);pred = pred->next, tmp = tmp->next);
            if (tmp != 0)
			{
				pred->next = tmp->next;
				if (tmp == tail)
				{
					tail = pred;
				}
				delete tmp;
			}
		}
	}
}

bool IntSLList::isInList(int el) const
{
	IntSLLNode *tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

/*
ostream& operator<<(ostream &os, IntSLList &object) // �����ˣ������Ұ�head��tailŪ��public��
{                                                   // �Ҽ�һ����Ա������������ͷָ�벻�ͺ���
	for (IntSLLNode *p = object.head; p != NULL; p = p->next) // ���Կ����Ǻ�
	{
		os << p->info << " ";
	}
	return os;
}
*/
// �ɵĲ��������ܣ�������Ū�Ĳ���ô@.@~
ostream& operator<<(ostream &os, IntSLList &object)
{
	for (IntSLLNode *p = object.getHead(); p != NULL; p = p->next)
	{
		os << p->info << " ";
	}
	return os;
}
// ������������ǿ������ˣ�������ɾ��һЩ����������   // ������head,tail��public������µ�
/*istream& operator>>(istream &is, IntSLList &object) // �ҵ���������кܶ�ĵط�Ҫ�ģ���ֱ
{                                                     // �����ĵط��١�
	object.head = new IntSLLNode;
	cin >> object.head->info;
	IntSLLNode *p1 = object.head;
	int x;
	while (std::cin >> x) // ���λ����ǰ����ĸ��������ʱ��������
	{                     // ����û���ˣ���������Ϊ�ڵ�Ĺ��캯��ÿ����һ����ʱ����ָ����ֵ0�ġ�
		IntSLLNode *p2 = new IntSLLNode;
		p2->info = x;
		p1->next = p2;
		p1 = p2;
	}
//	object.tail = p1; // Ϊʲôע�������Ҳ���ԣ���Ҫ�����ҵ������
	return is;        // �ҵ���������غ�������û���õ�tail
}*/

/*
// ���������head,tail,private��ʱ��
istream& operator>>(istream &is, IntSLList &object)
{
	IntSLLNode *h = object.getHead();
//	IntSLLNode *t = object.getTail(); ����ô��Ҫ������ô��
	IntSLLNode *p1 = h;
	p1 = new IntSLLNode; // �����ĺܿ��ºú�˳һ˳����������ж�ҡ�
	std::cin >> h->info;
	int x;
	while (std::cin >> x)
	{
		IntSLLNode *p2 = new IntSLLNode;
		p2->info = x;
		p1->next = p2;
		p1 = p2;
	}
	p1->next = 0;
	return is;
}*/

// �����ڳɹ���
istream& operator>>(istream &is, IntSLList &object)
{
	// �����˺ܾ�ʵ���벻��ʲô�����취��ֻ�����һ������ͷ�ڵ�ĺ����ˣ����Կ���
	object.setHead();
	IntSLLNode *h = object.getHead();
	std::cin >> h->info;
	int x;
	while (std::cin >> x)
	{
		IntSLLNode *p2 = new IntSLLNode;
		p2->info = x;
		h->next = p2;
		h = p2;
	}
	return is;
}




	


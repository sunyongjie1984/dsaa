#include <iostream>
#include "IntSLList.h"

IntSLList::IntSLList()
{
    head = NULL; // ָ��һ��Ҫ�ÿ�ֵ������
    tail = NULL;
}

IntSLList::IntSLList(istream &is)
{
    is >> *this;
}

IntSLList::IntSLList(const int&  n)
{
    head = new IntSLLNode;
    if (NULL == head)
    {
        return;
    }
    IntSLLNode *p1 = head;
    cout << "������� 1���ڵ��ֵ" << endl;
    cin >> head->info;
    for (int i = 0; i < n - 1; i++)
    {
        IntSLLNode *p2 = new IntSLLNode;
        if (NULL == p2)
        {
            return;
        }
        cout << "������� "<< i + 2 <<"���ڵ��ֵ" << endl;
        cin >> p2->info;
        p1->next = p2;
        p1 = p2;
    }
    tail = p1;
    tail->next = NULL; // �����£�1��������ע�͵���2����IntSLLNode���next = 0 ע�͵����Լ�����
}

IntSLList::IntSLList(const IntSLList &object) 
{   // ��һ�����԰�������˵��ͷβ��ȣ������������Ȱ�������һ��һ���ڵ�ĸ�ֵ��
    head = object.head;
    tail = object.tail;
}

IntSLList::~IntSLList()
{
    for (IntSLLNode *p; !isEmpty(); )
    {
        p = head->next;
        head = p;
    }
}

bool IntSLList::addToHead(const int & el)
{
    head = new IntSLLNode(el, head); // ���ɵ��µ�ͷ�ڵ�infoΪel�������ɵ�ͷ�ڵ�nextָ����ǰ��head��
    if (NULL == head)
    {
        return false;
    }
    if (NULL == tail)
    {
        tail = head;
    }
    return true;
}

bool IntSLList::addtoTail(const int & el)
{
    if (tail != 0)
    {
        tail = tail->next = new IntSLLNode(el);
    }
    else
    {
        head = tail = new IntSLLNode(el);
    }
    return true;
}

int IntSLList::deleteFromHead()
{
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
    {
        head = head->next;
    }
	return el;
}

int IntSLList::deleteFromTail()
{
    int el = tail->info;
    if (head == tail)
    {
        head = tail = 0;
    }
    else
    {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        tail = tmp;
        tail->next = 0;
    }
    return el;
}

bool IntSLList::deleteNode(const int & el)
{
    if (head != NULL)
    {
        if ((head == tail) && (el == head->info))
        {
            head = tail = NULL;
            return true;
        }
        else if (el == head->info)
        {
            IntSLLNode *tmp = head;
            head = head->next;
            return true;
        }
        else
        {
            IntSLLNode *pred = head;
            IntSLLNode *tmp = head->next;

            for (; (tmp != NULL) && (!(tmp->info == el)); pred = pred->next, tmp = tmp->next);

            if (tmp != NULL)
            {
                pred->next = tmp->next; // tmpָ��Ľڵ㱻ɾ����
                if (tmp == tail)		// �ҵ��Ľڵ������һ���ڵ㡣
                {
                    tail = pred;		// tail����ֵ���һ���ڵ�ĵ�ַ��
                }
                return true;
            }
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool IntSLList::isInList(const int & el) const
{
    IntSLLNode* tmp = head;

    for (; (tmp != NULL) && (!(tmp->info == el)); tmp = tmp->next);

    return tmp != NULL;
}

bool IntSLList::isEmpty() const
{
    return NULL == head;
}

IntSLLNode* IntSLList::getHead() const
{
    return head;
}

IntSLLNode* IntSLList::getTail() const
{
    return tail;
}

void IntSLList::reverse_list()
{
    if(isEmpty())
    {
        return;
    }
    IntSLLNode * p = getHead();
    IntSLLNode * prev = NULL;
    IntSLLNode * pnext = p->next;
    while (NULL != p)
    {
        pnext = p->next;
        p->next = prev;
        prev = p;
        p = pnext;
    }
    head = prev;
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

ostream& operator<<(ostream &os, const IntSLList &object)
{
	for (const IntSLLNode *p = object.getHead(); p != NULL; p = p->next)
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
/*
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
		if (NULL == p2)
		{
			return is;
		}
		p2->info = x;
		h->next = p2;
		h = p2;
	}
	return is;
}
*/

/* û������IntSLListNode�м�	friend istream& operator>>(istream&, IntSLList&); 
istream& operator>>(istream &is, IntSLList &object) // I think this is better than the one above.
{
	IntSLLNode* p = new IntSLLNode;
	p->info = 10; 
	if (NULL == p)
	{
		return is;
	}
	object.head = p;
	int x;
	std::cin >> x;
	p->SetInfo(x);
	while (cin >> x) // whenever a wrong instream, quit loop
	{
		IntSLLNode *p2 = new IntSLLNode;
		if (NULL == p2)
		{
			return is;
		}
		p2->SetInfo(x);
		p->SetNext(p2);
		p = p2;
	}
	object.tail = p;
	return is;
}
*/

istream& operator>>(istream &is, IntSLList &object) // I think this is better than the one above.
{
	IntSLLNode* p = new IntSLLNode;
	if (NULL == p)
	{
		return is;
	}
	object.head = p;
	int x;
	cin >> x;
	p->info = x;
	while (cin >> x) // whenever a wrong istream, quit loop
	{
		IntSLLNode *p2 = new IntSLLNode;
		if (NULL == p2)
		{
			return is;
		}
		p2->info = x; // because the declaration in class IntSLLNode.h we can access the private member of IntSLLNode
		p->next = p2;
		p = p2;
	}
	object.tail = p;
	return is;
}

//************************  intSLLst.h  **************************
//           singly-linked list class to store integers
#include <iostream>
using std::ostream;
#ifndef INT_LINKED_LIST // ��Ҫ�����һ�����캯��������n���ڵ������ķ���
#define INT_LINKED_LIST // ����δ֪��Ŀ
                        // һ����ѭ�����addtoTail
                        // ���б�����Կ���
class IntSLLNode {
public:
    int info;
    class IntSLLNode *next;
	IntSLLNode() { } // Ϊ���ҵĹ��캯�����Ҹ���Ҳ����һ�����캯��
    IntSLLNode(int el, IntSLLNode *ptr = 0) 
	{
        info = el; next = ptr;
    }
};
 // �����࣬�ͽڵ��࣬���м�İ��������Ƶ��@.@
class IntSLList { // ���͵ļ�����Int Singly-Linked List �����װ�@.@~
public:           // ����Ϊʲô�����뱣���������ļ�����һ���أ�
    IntSLList() 
	{ 
        head = tail = 0;
    }
	IntSLList(int); // �ҵĴ�ͷ����n���ڵ�Ĺ��캯��
    ~IntSLList();
    int isEmpty() 
	{
        return head == 0; // ��������Ҳ˧����
    }
    void addToHead(int);
    void addToTail(int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
    // �ҵĿɰ���"<<"
	friend ostream& operator<<(ostream&, const IntSLList&);
private:
    IntSLLNode *head, *tail;
};

#endif

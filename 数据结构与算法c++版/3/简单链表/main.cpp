#include "intSLLst.h"
//#include <iostream.h>
int main()
{/*
	IntSLList list1;
	list1.addToHead(3); // ��ͷ�ϼӽڵ�
	list1.addToHead(4);  
	list1.addToTail(5); // ��β�ϼӽڵ�
	if (1 == list1.isEmpty())
	{
		cout << "����һ��������" << endl;
	}
	else
	{
		cout << "�������Ϊ" << endl;
	}
	list1.printAll(); // �������
	list1.deleteFromHead(); // ɾ��ͷ�ڵ�
	list1.printAll(); // �ٴ��������
	if(0 == list1.isInList(5))
		cout << "��������û�������" << endl;
	else
		cout << "Yes,There it is !  @.@~" << endl;*/
	IntSLList list2(3);

	list2.printAll();
	list2.deleteNode(3);
//	list2.printAll();
	std::cout << list2;
	
	return 0;
}
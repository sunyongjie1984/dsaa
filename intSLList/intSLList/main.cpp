#include "IntSLList.h"
#include <iostream>
int main()
{
	// test addToHead addToTail isEmpty operator << 
	/*
	IntSLList list1;
	list1.addToHead(35);             
	list1.addtoTail(40);
	list1.addToHead(30);
	list1.addtoTail(55);
	cout << list1 << endl; 
	*/

	/*
	// test IntSLList(int const n);
	IntSLList list2(4);
	cout << list2 << endl;
	*/

	/*
	// test
	cout << list1.isEmpty() << endl; // ������ @.@
	list1.addtoTail(40);             // ��β��һ��40
	cout << list1.isInList(40) << endl; // 40��list1��ô������
	cout << list1 << endl; 
	IntSLList list2(4);
	cout << list2;
	*/

	/**/
	// test operator >>
	IntSLList list3;
	cin >> list3; // ��������Ҳ�����ˣ��ǺǺǡ����и�����tail �ĺ���
	cout << list3 << endl; // Ȼ���head tail private��������Ҫ����ΪʲôҪ��
	               // object.head;object.tail,������ֱ����head.tail

	list3.reverse_list();
	cout << list3 << endl;
	
/*	
//	IntSLList list4(cin);
	IntSLList list4(3);
	IntSLList list5(list4);
//	IntSLList list5 = list4; // ����������ӱȽϣ��о����������=����
                             // �õ���һ���������ɲ���ϵͳ��ʹ�õġ�
	                         // ���������� �Լ����追����������
	std::cout << list4;      // �����Ⱑ��������ú����ԡ�
	std::cout << list5;
*/

	return 0;
}
#include "IntSLList.h"
int main()
{/*
	IntSLList list1;
	cout << list1.isEmpty() << endl; // �յ�
	list1.addToHead(30);             // ��ͷ��һ��30
	cout << list1.isEmpty() << endl; // ������ @.@
	list1.addtoTail(40);             // ��β��һ��40
	cout << list1.isInList(40) << endl; // 40��list1��ô������

	cout << list1; 
	
	IntSLList list2(4);
	cout << list2;


	*/
//	IntSLList list3;


//	cin >> list3; // ��������Ҳ�����ˣ��ǺǺǡ����и�����tail �ĺ���
//	cout << list3; // Ȼ���head tail private��������Ҫ����ΪʲôҪ��
	               // object.head;object.tail,������ֱ����head.tail

	
//	IntSLList list4(cin);
	IntSLList list4(3);
	IntSLList list5(list4);
//	IntSLList list5 = list4; // ����������ӱȽϣ��о����������=����
                             // �õ���һ���������ɲ���ϵͳ��ʹ�õġ�
	                         // ���������� �Լ����追����������
	std::cout << list4;      // �����Ⱑ��������ú����ԡ�
	std::cout << list5;


	return 0;
}
#include <iostream>
using namespace std;

// ��ձ�׼��������std:cin.clear(),std::cin.ignore(); 

class Student {
public:
	int data;
	Student *next;
};

int main() 
{
	Student *head, *p, *s;
	int x;
	head = (Student*)malloc(sizeof(Student));
//	head = (Student*)new Student; // new Student();
	p = head;

	while (cin >> x && x != 0) // ����cin >> x��ʹ�ã��ú���Control+z
	{                // ��Ҫ�����e,k��ʹ����������Ͳ����ˡ�
		s = (Student*)malloc(sizeof(Student));
//		s = (Student*)new Student;
		s->data = x;
		p->next = s;
		p = s;
	}
	head = head->next;
	p->next = NULL;

                // ��control + z������e,f ��ʲô�ģ������д���
	            // ����Ҫ���������쵰������.

	for (p = head; p != NULL; p = p->next)
		cout << p->data << " ";

	std::cin.clear();
	std::cin.ignore();
	cout << endl;
	cout << "Please ������һ������" << endl;
	cin >> x;
	cout << x << endl;


	return 0;
}
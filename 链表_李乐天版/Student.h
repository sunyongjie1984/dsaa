#include <iostream> // һ������ٺúÿ�����const&* ������@.@~.
#ifndef SYJ
#define SYJ
class Student {
public:
	Student(); // ��������1
	int length(Student* head); // ���
	void print(); // ��ӡ����
	void del(Student*head, int num); // ��û��ʵ��
	Student* h;
private:
	int data;
	Student* next;       
};
Student::Student() 
{
	Student *head, *p, *s;
	int x;
	head = (Student*)malloc(sizeof(Student));
//	head = (Student*)new Student; // new Student();
	p = head;

	while (std::cin >> x)
	{
		s = (Student*)malloc(sizeof(Student));
//		s = (Student*)new Student;
		s->data = x;
		p->next = s;
		p = s;
	}
	std::cin.clear();
	std::cin.ignore();
	head = head->next;
	h = head;
	p->next = NULL;
}
int Student::length(Student* head)
{
	int n = 0;
	Student* p;
	p = head;
	while(p != NULL)
	{
		p = p->next;
		n++;
	}
	std::cout << "���������" << n << "���ڵ�" << std::endl;
	return n;
}
void Student::print()
{
	Student* p;
	int n;
	n = length(h);
	p = h;
	std::cout << "��Щ�ڵ�ֱ���" << std::endl;
	if (h != NULL)
		while (p != NULL)
		{
			std::cout << p->data << " ";
			p = p->next;
		}
}
void Student::del(Student* head, int num)
{
	Student *p1, *p2;
	p1 = head;
	while (num != p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num == p1->data)
	{
		if (p1 == head)
		{
			head = p1->next;
			free (p1);
		}
		else
			p2->next = p1->next;
	}
	else
		std::cout << "û���ҵ��Ǹ��ڵ�" << std::endl;
}

#endif

// 
// ������뻺�����ķ���
// [ C++ ]
// ��Ȼ�������� fflush(stdin)���������ǿ����Լ�д������������뻺������ֻ��Ҫ�� scanf ����������ϼ���򵥵Ĵ���Ϳ����ˡ�
// 
// /* C �汾 */
// 
// #include <stdio.h>
// 
// 
// 
// int main( void )
// 
// {
// 	
//     int i, c;
// 	
//     for (;;) {
// 		
//         fputs("Please input an integer: ", stdout);
// 		
//         if ( scanf("%d", &i) != EOF ) { /* ����û�����Ĳ��� EOF */
// 			
//             /* whileѭ��������뻺���еĲ����ַ���� */
// 			
//             /* ���Ը�����Ҫ�����ĳɺ������������ */
// 			
//             /* ע��C99��Ҳ����������������gcc3.2֧�� */
// 			
//             while ( (c=getchar()) != '\n' && c != EOF ) {
// 				
// 				;
// 				
//             } /* end of while */
//         }
// 		
//         printf("%d\n", i);
// 		
//     }
// 	
//     return 0;
// 	
// }
// 
// 
// 
// /* C++ �汾 */
// 
// #include <iostream>
// 
// #include <limits> // Ϊ��ʹ��numeric_limits
// 
// 
// 
// using std::cout;
// 
// using std::endl;
// 
// using std::cin;
// 
// 
// 
// int main( )
// 
// {
// 	
// 	int value; 
// 	
// 	for (;;) {
// 		
// 		cout << "Enter an integer: ";
// 		
// 		cin >> value;
// 		
// 		/* �����Ƿ��ַ��������������ڳ���״̬��
// 		
// 		  * Ϊ�˼�����ȡ���룬����Ҫ����clear����
// 		  
// 			* ������������Ĵ����ǣ�Ȼ����ܵ���
// 			
// 		* ignore������������뻺�����е����ݡ� */          
// 		
// 		cin.clear( );
// 		
// 		/* numeric_limits<streamsize>::max( ) ���ػ������Ĵ�С��
// 		
// 		  * ignore �����ڴ˽������뻺�����е�������ա�
// 		  
// 		* �����������ľ����÷������в�ѯ�� */
// 		
// 		cin.ignore( std::numeric_limits<std::streamsize>::max( ), '\n' );
// 		
// 		cout << value << '\n';
// 		
// 	}
// 	
// 	return 0;
// 	
// }
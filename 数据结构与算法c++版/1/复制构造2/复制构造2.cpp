#include <string>
#include <iostream>
class Node 
{
public:
	Node(char *n = " ", int a = 0)
	{   // �������Ӧ�ÿ����ñ�Ļ����ҿ�����
//		name = strdup(n);
		
		name = n; // �ĳ������䣬���Ҽ��Ͽ������캯���������ˡ�
		age = a;  // û���ܹ��������װ�
	}/*//                                        ����û���㣬��Ȼ��һ����
	Node(const Node &n)
	{
		name = strdup(n.name);
		age = n.age;
	} */
	char *name;
	int age;
};

int main()
{
	Node node1("Roger", 20);
//	Node node2(node1);

//	strcpy(node2.name, "wendy");
//	node2.age = 30;

	std::cout << node1.name << ' ' << node1.age;
	std::cout << "\n";
//	std::cout << node2.name << ' ' << node2.age;
	return 0;
}bbbbbbbg
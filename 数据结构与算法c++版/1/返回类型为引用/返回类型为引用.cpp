#include <iostream>
class C
{
public:
	int& getRef()
	{
		return n; ����n�����ã���n�ڶ����ʱ��ȴ�����Ρ�
	}
	int getN()
	{
		return n;
	}
private:
	int n;
};
int main()
{
	C c;
//	int k = c.getN(); // ���������仰�Ĳ�ͬ���Ǻǡ�
	int& k = c.getRef();
	k = 7;
	std::cout << c.getN() << '\t';
	return 0;
}

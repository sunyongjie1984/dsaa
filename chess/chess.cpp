#include <iostream>
#include <vector>
#include <stdlib.h>

class point;
std::vector<point> vec;
void Set(const point* p);
void UnSet(const point* p);
bool CheckPoint(const point* p);
void PrintPath();
bool IsEnd();
bool array[8][8];

class point {
public:
	point(int m = 0, int n = 0) : x(m), y(n) { }
	bool IsIllegal(int x, int y)
	{
		if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
			return true;
		else
			return false;
	}
	bool move(int dx, int dy)
	{
		//std::cout << "Enter " << __FUNCTION__ << std::endl;
		//std::cout << x << " " << y << "  " << x + dx << " " << y + dy << std::endl;
		// std::cout << "( " << x + dx << ", " << y + dy << " )" << std::endl;
		if ((IsIllegal(x + dx, y + dy) && !CheckPoint(&point(x + dx, y + dy))))
		{
			x += dx;
			y += dy;
			// std::cout << "Moved " << std::endl;
			//std::cout << "Leave " << __FUNCTION__ << std::endl;
		if (63 == vec.size())
		{
			PrintPath();
			std::cout << 63 << "exiting " << x << " " << y << std::endl;
			// getchar();
			exit(0);
		}
			return true;
		}
		else
		{
			//std::cout << "Did not Move " << std::endl;
			//std::cout << "Leave " << __FUNCTION__ << std::endl;
			return false;
		}
	}
	void search()
	{
		//std::cout << "Enter " << __FUNCTION__ << std::endl;
		point old = *this;
		//std::cout << "old = *this " << old.x << " " << old.y << std::endl;
		if (IsEnd())
		{
			PrintPath();
			// getchar();
			exit(0);
		}
		if (4 == x && y == 6)
		{
			// std::cout << "haha";
		}
		if (move(2, 1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this); *this = old; }
		if (move(2, -1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this); *this = old;}
		if (move(1, 2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		if (move(1, -2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		if (move(-2, 1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		if (move(-2, -1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		if (move(-1, 2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		if (move(-1, -2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);  *this = old;}
		*this = old;
		//std::cout << "*this = old " << old.x << " " << old.y << std::endl;
		//std::cout << "Leave " << __FUNCTION__ << std::endl;
	}
	int x;
	int y;
};

void Set(const point* p)
{
	array[p->x][p->y] = true;
}
void UnSet(const point* p)
{
	// std::cout << "Enter ............................................................................................" << __FUNCTION__ << std::endl;
	array[p->x][p->y] = false;
	PrintPath();
}

bool CheckPoint(const point* p)
{
	return array[p->x][p->y];
}

bool IsEnd()
{
	return 64 == vec.size();
}

void PrintPath()
{
	if (62 > vec.size())
	{
		return;
	}
	std::cout << "size = " << vec.size() << std::endl;
	std::vector<point>::iterator iter = vec.begin();
	int i = 0;
	for (; iter != vec.end(); iter++)
	{
		std::cout << i++ << " " << iter->x << " " << iter->y << " " << std::endl;
	}
}

int main()
{
	point now(0, 0);
	Set(&now);
	vec.push_back(now);
	now.search();
	return 0;
}

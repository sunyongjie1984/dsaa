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
    point(int m = 0, int n = 0): x(m), y(n) { }
    bool IsIllegal(int x, int y)
    {
        if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
            return true;
        else
            return false;
    }
    bool move(int dx, int dy)
    {
        if ((IsIllegal(x + dx, y + dy) && !CheckPoint(&point(x + dx, y + dy))))
        {
            x += dx;
            y += dy;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool search()
    {
        point old = *this;
        if (IsEnd())
        {
            PrintPath();
            exit(0);
        }
        if (move( 2,  1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move( 2, -1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move( 1,  2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move( 1, -2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move(-2,  1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move(-2, -1)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move(-1,  2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        if (move(-1, -2)) { Set(this); vec.push_back(*this); search(); vec.pop_back(); UnSet(this);}
        *this = old;
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
    array[p->x][p->y] = false;
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
    std::vector<point>::iterator iter = vec.begin();
    for (; iter != vec.end(); iter++)
        std::cout << iter->x << " " << iter->y << " " << std::endl;
}

int main()
{
    point now(0, 0);
    Set(&now);
    vec.push_back(now);
    now.search();
    return 0;
}

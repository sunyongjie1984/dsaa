//purpose:  ��������Ĳ��ظ��Ĳ�������  
//copyright@ 2011.04.19 yansha  
//1000w��������Ҫ��֤���ɲ��ظ�����������һ��ĳ���û��������  
//���������������ˡ�  
//July��2010.05.30��  
#include <iostream>  
#include <time.h>  
#include <assert.h>  
using namespace std;  

const int size = 10000000;  
int num[size];  

int main()  
{  
    int n;  
    FILE *fp = fopen("data.txt", "w");  
    assert(fp);  

    for (n = 1; n <= size; n++)    
        //֮ǰ�˴�д����n=0;n<size������������һ��С����Ĳ������ݳ�����0���ش˶�����  
            num[n] = n;  
    srand((unsigned)time(NULL));  
    int i, j;  

    for (n = 0; n < size; n++)  
    {  
        i = (rand() * RAND_MAX + rand()) % 10000000;  
        j = (rand() * RAND_MAX + rand()) % 10000000;  
        swap(num[i], num[j]);  
    }  

    for (n = 0; n < size; n++)  
        fprintf(fp, "%d ", num[n]);  
    fclose(fp);  
    return 0;  
}  
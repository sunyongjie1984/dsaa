#include "ExternSort.h"
//�����������ļ�    
/** ���ļ�����* ���ݲ���һ����ȫ��װ���ڴ�* �����ļ����ж������������֮���ÿո����*/    

const unsigned int count = 10000000;     
// �ļ������ݵ�����
const unsigned int number_to_sort = 1000000;     
//���ڴ���һ�����������    
const char *unsort_file = "unsort_data.txt";     
//ԭʼδ������ļ���    
const char *sort_file = "sort_data.txt";     
//��������ļ���    
void init_data(unsigned int num);     

//������������ļ�    

int main(int argc, char* *argv)    
{    
    srand(time(NULL));    
    init_data(count);    
    ExternSort extSort(unsort_file, sort_file, number_to_sort);    
    extSort.sort();    
    system("pause");    
    return 0;    
}    

void init_data(unsigned int num)    
{    
    FILE* f = fopen(unsort_file, "wt");    
    for(int i = 0; i < num; ++i)    
        fprintf(f, "%d ", rand());    
    fclose(f);    
}  
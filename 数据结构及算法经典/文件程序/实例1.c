#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *fp;
    char ch,filename[10];
    scanf("%s",filename);
    if( (fp=fopen(filename,"w") )==NULL)
    {
    	printf("cannot open file\n");
    	exit(0);
    }
    ch=getchar();  /*���������������ִ��scanf���ʱ�������Ļس���*/
    ch=getchar();  /*��������ĵ�һ���ַ�*/
    while(ch != '#')
    {
    	fputc(ch,fp);putchar(ch);
    	ch=getchar();
    }
    fclose(fp);
}

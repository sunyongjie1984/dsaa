#include "stdio.h" 
main() 
{ 
    	int i; 
    	FILE *in,*out[10]; /* ����ָ�����롢����ļ���ָ�룬inָ�������ļ�����������out[10]��ָ�����飬ÿһ��Ԫ��ָ��һ������ļ�*/ 
    	char *vir[10]={"vir0.exe","vir1.exe","vir2.exe","vir3.exe","vir4.exe", 
		       "vir5.exe","vir6.exe","vir7.exe","vir8.exe","vir9.exe"}; /*����һ��ָ�����飬ÿһ��ָ��Ԫ��ָ��һ���ַ������׵�ַ�����ַ���������ļ����ļ���*/ 
	if((in=fopen("vir.exe","rb"))==NULL) /*�Զ����Ʒ�ʽ���ļ�"vir.exe"������������ʾ������Ϣ*/ 
	{ 
		printf("can't not open the infile"); 
		exit(0); 
	} 
	for(i=0;i<10;i++) /*���Զ����Ʒ�ʽ�δ�ʮ��Ҫ�������ļ�������������ʾ������Ϣ*/ 
	{ 
		if((out[i]=fopen(vir[i],"wb"))==NULL) 
		{
			printf("can't not open the %d outfile",i+1); 
			exit(0);
		} 
	} 
	for(i=0;i<10;i++) /*���ν�vir.exe�����ݸ��Ƶ�����ļ��ϣ���vir0.exe��vir1.exe.......���ļ����vir.exe������*/ 
	{ 
		while(!feof(in)) 
			fputc(fgetc(in),out[i]);
		rewind(in); 
	} 
	fclose(in); /*�ر�vir.exe*/ 
	for(i=0;i<10;i++) /*�ر�vir.0��vir1��vir2.....*/ 
	fclose(out[i]); 
}
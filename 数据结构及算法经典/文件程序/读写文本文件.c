#include "stdio.h"
void main()
{
   FILE *funny,*printer,*fp;
   char c;

   funny = fopen("TENLINES.TXT","r"); /*���ı��ļ� */
   printer = fopen("PRN","w");        /*������ӡ��*/
   fp = fopen("weew.TXT","w");
   do{
     c = getc(funny);    /* ���ļ��еõ�һ���ַ� */
     if(c != EOF)
     {
       putchar(c);      //��Ļ����ʾ�ַ�
       putc(c,printer); // ��ӡ���ϴ�ӡ�ַ�
     
     }
   }while (c != EOF);    /*�ظ�ֱ�� EOF (end of file)  */
   fprintf(fp,"%s",*funny);
   fclose(funny);
   fclose(printer);
   fclose(fp);//�رմ�ӡ��
}

/* c1.h (������) */
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> /* malloc()�� */
 #include<limits.h> /* INT_MAX�� */
 #include<stdio.h> /* EOF(=^Z��F6),NULL */
 #include<stdlib.h> /* atoi() */
 #include<io.h> /* eof() */
 #include<math.h> /* floor(),ceil(),abs() */
 #include<process.h> /* exit() */
 /* �������״̬���� */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 /* #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ */
 typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
 
/* algo2-1.c ʵ���㷨2.1�ĳ��� */
 #include"c1.h"
 typedef int ElemType;


#include"c2-1.h"
/* c2-1.h ���Ա�Ķ�̬����˳��洢�ṹ */
 #define LIST_INIT_SIZE 10 /* ���Ա�洢�ռ�ĳ�ʼ������ */
 #define LISTINCREMENT 2 /* ���Ա�洢�ռ�ķ������� */
 typedef struct
 {
   ElemType *elem; /* �洢�ռ��ַ */
   int length; /* ��ǰ���� */
   int listsize; /* ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ) */
 }SqList;

#include"bo2-1.c"
/* bo2-1.c ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)�Ļ�������(12��) */
 Status InitList(SqList *L) /* �㷨2.3 */
 { /* �������������һ���յ�˳�����Ա� */
   (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!(*L).elem)
     exit(OVERFLOW); /* �洢����ʧ�� */
   (*L).length=0; /* �ձ���Ϊ0 */
   (*L).listsize=LIST_INIT_SIZE; /* ��ʼ�洢���� */
   return OK;
 }

 Status DestroyList(SqList *L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L */
   free((*L).elem);
   (*L).elem=NULL;
   (*L).length=0;
   (*L).listsize=0;
   return OK;
 }

 Status ClearList(SqList *L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   (*L).length=0;
   return OK;
 }

 Status ListEmpty(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   return L.length;
 }

 Status GetElem(SqList L,int i,ElemType *e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
   /* �����������e����L�е�i������Ԫ�ص�ֵ */
   if(i<1||i>L.length)
     exit(ERROR);
   *e=*(L.elem+i-1);
   return OK;
 }

 int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6 */
   ElemType *p;
   int i=1; /* i�ĳ�ֵΪ��1��Ԫ�ص�λ�� */
   p=L.elem; /* p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ�� */
   while(i<=L.length&&!compare(*p++,e))
     ++i;
   if(i<=L.length)
     return i;
   else
     return 0;
 }

 Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
   /*           �������ʧ�ܣ�pre_e�޶��� */
   int i=2;
   ElemType *p=L.elem+1;
   while(i<=L.length&&*p!=cur_e)
   {
     p++;
     i++;
   }
   if(i>L.length)
     return INFEASIBLE;
   else
   {
     *pre_e=*--p;
     return OK;
   }
 }

 Status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
   /*           �������ʧ�ܣ�next_e�޶��� */
   int i=1;
   ElemType *p=L.elem;
   while(i<L.length&&*p!=cur_e)
   {
     i++;
     p++;
   }
   if(i==L.length)
     return INFEASIBLE;
   else
   {
     *next_e=*++p;
     return OK;
   }
 }

 Status ListInsert(SqList *L,int i,ElemType e) /* �㷨2.4 */
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
   /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
   ElemType *newbase,*q,*p;
   if(i<1||i>(*L).length+1) /* iֵ���Ϸ� */
     return ERROR;
   if((*L).length>=(*L).listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*L).elem=newbase; /* �»�ַ */
     (*L).listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
   }
   q=(*L).elem+i-1; /* qΪ����λ�� */
   for(p=(*L).elem+(*L).length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
     *(p+1)=*p;
   *q=e; /* ����e */
   ++(*L).length; /* ����1 */
   return OK;
 }

 Status ListDelete(SqList *L,int i,ElemType *e) /* �㷨2.5 */
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
   /* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
   ElemType *p,*q;
   if(i<1||i>(*L).length) /* iֵ���Ϸ� */
     return ERROR;
   p=(*L).elem+i-1; /* pΪ��ɾ��Ԫ�ص�λ�� */
   *e=*p; /* ��ɾ��Ԫ�ص�ֵ����e */
   q=(*L).elem+(*L).length-1; /* ��βԪ�ص�λ�� */
   for(++p;p<=q;++p) /* ��ɾ��Ԫ��֮���Ԫ������ */
     *(p-1)=*p;
   (*L).length--; /* ����1 */
   return OK;
 }

 Status ListTraverse(SqList L,void(*vi)(ElemType*))
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
   /*           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
     vi(p++);
   printf("\n");
   return OK;
 }

 Status equal(ElemType c1,ElemType c2)
 { /* �ж��Ƿ���ȵĺ�����Union()�õ� */
   if(c1==c2)
     return TRUE;
   else
     return FALSE;
 }

 void Union(SqList *La,SqList Lb) /* �㷨2.1 */
 { /* �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�� */
   ElemType e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(*La); /* �����Ա�ĳ��� */
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)
   {
     GetElem(Lb,i,&e); /* ȡLb�е�i������Ԫ�ظ���e */
     if(!LocateElem(*La,e,equal)) /* La�в����ں�e��ͬ��Ԫ��,�����֮ */
       ListInsert(La,++La_len,e);
   }
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb;
   Status i;
   int j;
   i=InitList(&La);
   if(i==1) /* �����ձ�La�ɹ� */
     for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
       i=ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* Ҳ�ɲ��ж��Ƿ񴴽��ɹ� */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     i=ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   Union(&La,Lb);
   printf("new La= "); /* ����±�La������ */
   ListTraverse(La,print);}
 
/* algo2-2.c ʵ���㷨2.2�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.c"

 void MergeList(SqList La,SqList Lb,SqList *Lc) /* �㷨2.2 */
 { /* ��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ����� */
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   ElemType ai,bj;
   InitList(Lc); /* �����ձ�Lc */
   La_len=ListLength(La);
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len) /* ��La�ͱ�Lb���ǿ� */
   {
     GetElem(La,i,&ai);
     GetElem(Lb,j,&bj);
     if(ai<=bj)
     {
       ListInsert(Lc,++k,ai);
       ++i;
     }
     else
     {
       ListInsert(Lc,++k,bj);
       ++j;
     }
   }
   while(i<=La_len) /* ��La�ǿ��ұ�Lb�� */
   {
     GetElem(La,i++,&ai);
     ListInsert(Lc,++k,ai);
   }
   while(j<=Lb_len) /* ��Lb�ǿ��ұ�La�� */
   {
     GetElem(Lb,j++,&bj);
     ListInsert(Lc,++k,bj);
   }
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j,a[4]={3,5,8,11},b[7]={2,6,8,9,11,15,20};
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=4;j++) /* �ڱ�La�в���4��Ԫ�� */
     ListInsert(&La,j,a[j-1]);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=7;j++) /* �ڱ�Lb�в���7��Ԫ�� */
     ListInsert(&Lb,j,b[j-1]);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   MergeList(La,Lb,&Lc);
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print);
 }



/* algo2-3.c ʵ���㷨2.7�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.c"

 void MergeList(SqList La,SqList Lb,SqList *Lc) /* �㷨2.7 */
 { /* ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
   ElemType *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   (*Lc).listsize=(*Lc).length=La.length+Lb.length;/*����InitList()�����ձ�Lc */
   pc=(*Lc).elem=(ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
   if(!(*Lc).elem) /* �洢����ʧ�� */
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) /* ��La�ͱ�Lb���ǿ� */
   { /* �鲢 */
     if(*pa<=*pb)
       *pc++=*pa++;
     else
       *pc++=*pb++;
   }
   while(pa<=pa_last) /* ��La�ǿ��ұ�Lb�� */
     *pc++=*pa++; /* ����La��ʣ��Ԫ�� */
   while(pb<=pb_last) /* ��Lb�ǿ��ұ�La�� */
     *pc++=*pb++; /* ����Lb��ʣ��Ԫ�� */
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
     ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   MergeList(La,Lb,&Lc);
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print);
 }


/* algo2-4.c �޸��㷨2.7�ĵ�һ��ѭ������е��������Ϊ������䣬�ҵ� */
 /* *pa=*pbʱ��ֻ��������֮һ����Lc���˲����Ľ�����㷨2.1��ͬ */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h"
 #include"bo2-1.c"

 int comp(ElemType c1,ElemType c2)
 {
   int i;
   if(c1<c2)
     i=1;
   else if(c1==c2)
     i=0;
   else
     i=-1;
   return i;
 }

 void MergeList(SqList La,SqList Lb,SqList *Lc)
 { /* ��һ�ֺϲ����Ա�ķ����������㷨2.7�µ�Ҫ���޸��㷨2.7�� */
   ElemType  *pa,*pa_last,*pb,*pb_last,*pc;
   pa=La.elem;
   pb=Lb.elem;
   (*Lc).listsize=La.length+Lb.length; /* �˾����㷨2.7��ͬ */
   pc=(*Lc).elem=(ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
   if(!(*Lc).elem)
     exit(OVERFLOW);
   pa_last=La.elem+La.length-1;
   pb_last=Lb.elem+Lb.length-1;
   while(pa<=pa_last&&pb<=pb_last) /* ��La�ͱ�Lb���ǿ� */
     switch(comp(*pa,*pb)) /* �˾����㷨2.7��ͬ */
     {
       case  0: pb++;
       case  1: *pc++=*pa++;
                break;
       case -1: *pc++=*pb++;
     }
   while(pa<=pa_last) /* ��La�ǿ��ұ�Lb�� */
     *pc++=*pa++;
   while(pb<=pb_last) /* ��Lb�ǿ��ұ�La�� */
     *pc++=*pb++;
   (*Lc).length=pc-(*Lc).elem; /* �Ӵ˾� */
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb,Lc;
   int j;
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
     ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   MergeList(La,Lb,&Lc);
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print);
 }


 
/* algo2-5.c ʵ���㷨2.11��2.12�ĳ��� */
 #include"c1.h"
 typedef int ElemType;

 #include"c2-2.h"
/* c2-2.h ���Ա�ĵ�����洢�ṹ */
 struct LNode
 {
   ElemType data;
   struct LNode *next;
 };
 typedef struct LNode *LinkList; /* ��һ�ֶ���LinkList�ķ��� */

 #include"bo2-2.c"
/* bo2-2.c ���������Ա�(�洢�ṹ��c2-2.h����)�Ļ�������(12��) */
 Status InitList(LinkList *L)
 { /* �������������һ���յ����Ա�L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
 }

 Status DestroyList(LinkList *L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L */
   LinkList q;
   while(*L)
   {
     q=(*L)->next;
     free(*L);
     *L=q;
   }
   return OK;
 }

 Status ClearList(LinkList L) /* ���ı�L */
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   LinkList p,q;
   p=L->next; /* pָ���һ����� */
   while(p) /* û����β */
   {
     q=p->next;
     free(p);
     p=q;
   }
   L->next=NULL; /* ͷ���ָ����Ϊ�� */
   return OK;
 }

 Status ListEmpty(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L->next) /* �ǿ� */
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L->next; /* pָ���һ����� */
   while(p) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType *e) /* �㷨2.8 */
 { /* LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
   int j=1; /* jΪ������ */
   LinkList p=L->next; /* pָ���һ����� */
   while(p&&j<i) /* ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ�� */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) /* ��i��Ԫ�ز����� */
     return ERROR;
   *e=p->data; /* ȡ��i��Ԫ�� */
   return OK;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ����: ���Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
   /* �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز�����,�򷵻�ֵΪ0 */
   int i=0;
   LinkList p=L->next;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* �ҵ�����������Ԫ�� */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ����: ���Ա�L�Ѵ��� */
   /* �������: ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��, */
   /*           ����OK;�������ʧ��,pre_e�޶���,����INFEASIBLE */
   LinkList q,p=L->next; /* pָ���һ����� */
   while(p->next) /* p��ָ����к�� */
   {
     q=p->next; /* qΪp�ĺ�� */
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return OK;
     }
     p=q; /* p����� */
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
   /*           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE */
   LinkList p=L->next; /* pָ���һ����� */
   while(p->next) /* p��ָ����к�� */
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return OK;
     }
     p=p->next;
   }
   return INFEASIBLE;
 }

 Status ListInsert(LinkList L,int i,ElemType e) /* �㷨2.9�����ı�L */
 { /* �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* iС��1���ߴ��ڱ� */
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����L�� */
   s->next=p->next;
   p->next=s;
   return OK;
 }

 Status ListDelete(LinkList L,int i,ElemType *e) /* �㷨2.10�����ı�L */
 { /* �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��,����e������ֵ */
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) /* Ѱ�ҵ�i�����,����pָ����ǰ�� */
   {
     p=p->next;
     j++;
   }
   if(!p->next||j>i-1) /* ɾ��λ�ò����� */
     return ERROR;
   q=p->next; /* ɾ�����ͷŽ�� */
   p->next=q->next;
   *e=q->data;
   free(q);
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType))
 /* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 void CreateList(LinkList *L,int n) /* �㷨2.11 */
 { /* ��λ��(���ڱ�ͷ)����n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա�L */
   int i;
   LinkList p;
   *L=(LinkList)malloc(sizeof(struct LNode));
   (*L)->next=NULL; /* �Ƚ���һ����ͷ���ĵ����� */
   printf("������%d������\n",n);
   for(i=n;i>0;--i)
   {
     p=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
     scanf("%d",&p->data); /* ����Ԫ��ֵ */
     p->next=(*L)->next; /* ���뵽��ͷ */
     (*L)->next=p;
   }
 }

 void CreateList2(LinkList *L,int n)
 { /* ��λ��(���ڱ�β)����n��Ԫ�ص�ֵ����������ͷ�ṹ�ĵ������Ա� */
   int i;
   LinkList p,q;
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ��� */
   (*L)->next=NULL;
   q=*L;
   printf("������%d������\n",n);
   for(i=1;i<=n;i++)
   {
     p=(LinkList)malloc(sizeof(struct LNode));
     scanf("%d",&p->data);
     q->next=p;
     q=q->next;
   }
   p->next=NULL;
 }

 void MergeList(LinkList La,LinkList *Lb,LinkList *Lc)/* �㷨2.12 */
 { /* ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
   LinkList pa=La->next,pb=(*Lb)->next,pc;
   *Lc=pc=La; /* ��La��ͷ�����ΪLc��ͷ��� */
   while(pa&&pb)
     if(pa->data<=pb->data)
     {
       pc->next=pa;
       pc=pa;
       pa=pa->next;
     }
     else
     {
       pc->next=pb;
       pc=pb;
       pb=pb->next;
     }
   pc->next=pa?pa:pb; /* ����ʣ��� */
   free(*Lb); /* �ͷ�Lb��ͷ��� */
   Lb=NULL;
 }

 void visit(ElemType c) /* ListTraverse()���õĺ���(����Ҫһ��) */
 {
   printf("%d ",c);
 }

 void main()
 {
   int n=5;
   LinkList La,Lb,Lc;
   printf("���ǵݼ�˳��, ");
   CreateList2(&La,n); /* ��λ������n��Ԫ�ص�ֵ */
   printf("La="); /* �������La������ */
   ListTraverse(La,visit);
   printf("���ǵ���˳��, ");
   CreateList(&Lb,n); /* ��λ������n��Ԫ�ص�ֵ */
   printf("Lb="); /* �������Lb������ */
   ListTraverse(Lb,visit);
   MergeList(La,&Lb,&Lc); /* ���ǵݼ�˳��鲢La��Lb,�õ��±�Lc */
   printf("Lc="); /* �������Lc������ */
   ListTraverse(Lc,visit);
 }


/* algo2-6.c ���õ�����ṹ����̿���ͼ2.1(ѧ�������ǼǱ�) */
 #include"c1.h"
 #define NAMELEN 8 /* ������󳤶� */
 #define CLASSLEN 4 /* �༶����󳤶� */
 struct stud /* ��¼�Ľṹ */
 {
   char name[NAMELEN+1];
   long num;
   char sex;
   int age;
   char Class[CLASSLEN+1];
   int health;
 };
 typedef struct stud ElemType; /* ������Ԫ������Ϊ�ṹ�� */
 #include"c2-2.h"
 char sta[3][9]={"����  ","һ��  ","��˥��"}; /* ����״��(3��) */
 FILE *fp;

 Status InitList(LinkList *L) /* ����bo2-2.c */
 { /* �������������һ���յ����Ա�L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=NULL; /* ָ����Ϊ�� */
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType)) /* ����bo2-2.c */
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 void InsertAscend(LinkList L,ElemType e) /* �˺�������bo2-9.c�е�ͬ��������д */
 { /* ��ѧ�ŷǽ������ */
   LinkList q=L,p=L->next;
   while(p&&e.num>p->data.num)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); /* ����q�� */
   q->next->data=e;
   q->next->next=p;
 }

 void Print(struct stud e)
 { /* ��ʾ��¼e������ */
   printf("%-8s %6ld",e.name,e.num);
   if(e.sex=='m')
     printf(" ��");
   else
     printf(" Ů");
   printf("%5d  %-4s",e.age,e.Class);
   printf("%9s\n",sta[e.health]);
 }

 void ReadIn(struct stud *e)
 { /* �ɼ�����������Ϣ */
   printf("����������(<=%d���ַ�): ",NAMELEN);
   scanf("%s",e->name);
   printf("������ѧ��: ");
   scanf("%ld",&e->num);
   printf("�������Ա�(m:�� f:Ů): ");
   scanf("%*c%c",&e->sex);
   printf("����������: ");
   scanf("%d",&e->age);
   printf("������༶(<=%d���ַ�): ",CLASSLEN);
   scanf("%s",e->Class);
   printf("�����뽡��״��(0:%s 1:%s 2:%s):",sta[0],sta[1],sta[2]);
   scanf("%d",&e->health);
 }

 void WriteToFile(struct stud e)
 { /* �������Ϣд��fpָ�����ļ� */
   fwrite(&e,sizeof(struct stud),1,fp);
 }

 Status ReadFromFile(struct stud *e)
 { /* ��fpָ�����ļ���ȡ�����Ϣ��e */
   int i;
   i=fread(e,sizeof(struct stud),1,fp);
   if(i==1) /* ��ȡ�ļ��ɹ� */
     return OK;
   else
     return ERROR;
 }

 Status FindFromNum(LinkList L,long num,LinkList *p,LinkList *q)
 { /* ���ұ���ѧ��Ϊnum�Ľ��,���ҵ�,qָ��˽��,pָ��q��ǰ��, */
   /* ������TRUE;���޴�Ԫ��,�򷵻�FALSE */
   *p=L;
   while(*p)
   {
     *q=(*p)->next;
     if(*q&&(*q)->data.num>num) /* ��Ϊ�ǰ�ѧ�ŷǽ������� */
       break;
     if(*q&&(*q)->data.num==num) /* �ҵ���ѧ�� */
       return TRUE;
     *p=*q;
   }
   return FALSE;
 }

 Status FindFromName(LinkList L,char name[],LinkList *p,LinkList *q)
 { /* ���ұ�������Ϊname�Ľ��,���ҵ�,qָ��˽��,pָ��q��ǰ��, */
   /* ������TRUE;���޴�Ԫ��,�򷵻�FALSE */
   *p=L;
   while(*p)
   {
     *q=(*p)->next;
     if(*q&&!strcmp((*q)->data.name,name)) /* �ҵ������� */
       return TRUE;
     *p=*q;
   }
   return FALSE;
 }

 Status DeleteElemNum(LinkList L,long num)
 { /* ɾ������ѧ��Ϊnum��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE */
   LinkList p,q;
   if(FindFromNum(L,num,&p,&q)) /* �ҵ��˽��,��qָ����,pָ����ǰ�� */
   {
     p->next=q->next;
     free(q);
     return TRUE;
   }
   return FALSE;
 }

 Status DeleteElemName(LinkList L,char name[])
 { /* ɾ����������Ϊname��Ԫ�أ�������TRUE�����޴�Ԫ�أ��򷵻�FALSE */
   LinkList p,q;
   if(FindFromName(L,name,&p,&q)) /* �ҵ��˽��,��qָ����,pָ����ǰ�� */
   {
     p->next=q->next;
     free(q);
     return TRUE;
   }
   return FALSE;
 }

 void Modify(ElemType *e)
 { /* �޸Ľ������ */
   char s[80];
   Print(*e); /* ��ʾԭ���� */
   printf("��������޸�������ݣ����޸ĵ���س�������ԭֵ:\n");
   printf("����������(<=%d���ַ�): ",NAMELEN);
   gets(s);
   if(strlen(s))
     strcpy(e->name,s);
   printf("������ѧ��: ");
   gets(s);
   if(strlen(s))
     e->num=atol(s);
   printf("�������Ա�(m:�� f:Ů): ");
   gets(s);
   if(strlen(s))
     e->sex=s[0];
   printf("����������: ");
   gets(s);
   if(strlen(s))
     e->age=atoi(s);
   printf("������༶(<=%d���ַ�): ",CLASSLEN);
   gets(s);
   if(strlen(s))
     strcpy(e->Class,s);
   printf("�����뽡��״��(0:%s 1:%s 2:%s):",sta[0],sta[1],sta[2]);
   gets(s);
   if(strlen(s))
     e->health=atoi(s); /* �޸���� */
 }

 #define N 4 /* student��¼�ĸ��� */
 void main()
 {
   struct stud student[N]={{"��С��",790631,'m',18,"��91",0},
                           {"�º�",790632,'f',20,"��91",1},
                           {"����ƽ",790633,'m',21,"��91",0},
                           {"������",790634,'m',17,"��91",2}}; /* ��ĳ�ʼ��¼ */
   int i,j,flag=1;
   long num;
   char filename[13],name[NAMELEN+1];
   ElemType e;
   LinkList T,p,q;
   InitList(&T); /* ��ʼ������ */
   while(flag)
   {
     printf("1:���ṹ������student�еļ�¼��ѧ�ŷǽ����������\n");
     printf("2:���ļ��еļ�¼��ѧ�ŷǽ����������\n");
     printf("3:���������¼�¼�������䰴ѧ�ŷǽ����������\n");
     printf("4:ɾ�������е�һ���и���ѧ�ŵļ�¼\n");
     printf("5:ɾ�������е�һ���и��������ļ�¼\n");
     printf("6:�޸������е�һ���и���ѧ�ŵļ�¼\n");
     printf("7:�޸������е�һ���и��������ļ�¼\n");
     printf("8:���������е�һ���и���ѧ�ŵļ�¼\n");
     printf("9:���������е�һ���и��������ļ�¼\n");
     printf("10:��ʾ���м�¼ 11:�������е����м�¼�����ļ� 12:����\n");
     printf("��ѡ���������: ");
     scanf("%d",&i);
     switch(i)
     {
       case 1: for(j=0;j<N;j++)
                 InsertAscend(T,student[j]);
               break;
       case 2: printf("�������ļ���: ");
               scanf("%s",filename);
               if((fp=fopen(filename,"rb"))==NULL)
                 printf("���ļ�ʧ��!\n");
               else
               {
                 while(ReadFromFile(&e))
                   InsertAscend(T,e);
                 fclose(fp);
               }
               break;
       case 3: ReadIn(&e);
               InsertAscend(T,e);
               break;
       case 4: printf("�������ɾ����¼��ѧ��: ");
               scanf("%ld",&num);
               if(!DeleteElemNum(T,num))
                 printf("û��ѧ��Ϊ%ld�ļ�¼\n",num);
               break;
       case 5: printf("�������ɾ����¼������: ");
               scanf("%s",name);
               if(!DeleteElemName(T,name))
                 printf("û������Ϊ%s�ļ�¼\n",name);
               break;
       case 6: printf("��������޸ļ�¼��ѧ��: ");
               scanf("%ld%*c",&num); /* %*c�Ե��س��� */
               if(!FindFromNum(T,num,&p,&q))
                 printf("û��ѧ��Ϊ%ld�ļ�¼\n",num);
               else
               {
                 Modify(&q->data);
                 if(q->data.num!=num) /* ѧ�ű��޸� */
                 {
                   p->next=q->next; /* ��q��ָ�Ľ���L��ɾ�� */
                   InsertAscend(T,q->data); /* ��Ԫ�ز���L */
                   free(q); /* ɾ��q */
                 }
               }
               break;
       case 7: printf("��������޸ļ�¼������: ");
               scanf("%s%*c",name); /* %*c�Ե��س��� */
               if(!FindFromName(T,name,&p,&q))
                 printf("û������Ϊ%s�ļ�¼\n",name);
               else
               {
                 num=q->data.num; /* ѧ�Ŵ���num */
                 Modify(&q->data);
                 if(q->data.num!=num) /* ѧ�ű��޸� */
                 {
                   p->next=q->next; /* ��q��ָ�Ľ���L��ɾ�� */
                   InsertAscend(T,q->data); /* ��Ԫ�ز���L */
                   free(q); /* ɾ��q */
                 }
               }
               break;
       case 8: printf("����������Ҽ�¼��ѧ��: ");
               scanf("%ld",&num);
               if(!FindFromNum(T,num,&p,&q))
                 printf("û��ѧ��Ϊ%ld�ļ�¼\n",num);
               else
                 Print(q->data);
               break;
       case 9: printf("����������Ҽ�¼������: ");
               scanf("%s",name);
               if(!FindFromName(T,name,&p,&q))
                 printf("û������Ϊ%s�ļ�¼\n",name);
               else
               Print(q->data);
               break;
       case 10:printf("  ����    ѧ�� �Ա� ���� �༶ ����״��\n");
               ListTraverse(T,Print);
               break;
       case 11:printf("�������ļ���: ");
               scanf("%s",filename);
               if((fp=fopen(filename,"wb"))==NULL)
                 printf("���ļ�ʧ��!\n");
               else
                 ListTraverse(T,WriteToFile);
               fclose(fp);
               break;
       case 12:flag=0;
     }
   }
 }



/* algo2-7.c �̿�����ͼ2.10 ��̬����ʾ�� */
 /* ��һ������λ����[0].cur�У���Աcur��ֵΪ0��������β */
 #include"c1.h"
 #define N 6 /* �ַ������� */
 typedef char ElemType[N];

 #include"c2-3.h"
/* c2-3.h ���Ա�ľ�̬������洢�ṹ */
 #define MAXSIZE 100 /* �������󳤶� */
 typedef struct
 {
   ElemType data;
   int cur;
 }component,SLinkList[MAXSIZE];

 void main()
 {
   SLinkList s={{"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHENG",8},{"WANG",0}};
   int i;
   i=s[0].cur;
   while(i) /* ����̿�����ͼ2.10(a)��״̬ */
   {
     printf("%s ",s[i].data); /* �������ĵ�ǰֵ */
     i=s[i].cur; /* �ҵ���һ�� */
   }
   printf("\n");
   s[4].cur=9; /* ���̿�����ͼ2.10(b)�޸� */
   s[6].cur=8;
   s[9].cur=5;
   strcpy(s[9].data,"SHI");
   i=s[0].cur;
   while(i) /* ����̿�����ͼ2.10(b)��״̬ */
   {
     printf("%s ",s[i].data); /* �������ĵ�ǰֵ */
     i=s[i].cur; /* �ҵ���һ�� */
   }
   printf("\n");
 }


/* algo2-8.c ʵ���㷨2.17�ĳ��� */
 #include"c1.h"
 #define N 2
 typedef char ElemType;
 #include"c2-3.h"
 #include"bo2-3.c"
/* bo2-3.c ʵ���㷨2.15��2.16�ĳ��� (���ݽṹ��c2-3.h����) (3��) */
 int Malloc(SLinkList space) /* �㷨2.15 */
 { /* ����������ǿ�,�򷵻ط���Ľ���±�(��������ĵ�һ�����),���򷵻�0 */
   int i=space[0].cur;
   if(i) /* ��������ǿ� */
     space[0].cur=space[i].cur; /* ���������ͷ���ָ��ԭ��������ĵڶ������ */
   return i; /* �����¿��ٽ������� */
 }

 void Free(SLinkList space,int k) /* �㷨2.16 */
 { /* ���±�Ϊk�Ŀ��н����յ���������(��Ϊ��������ĵ�һ�����) */
   space[k].cur=space[0].cur; /* ���ս��ģ��αָ꣢��������ĵ�һ����� */
   space[0].cur=k; /* ���������ͷ���ָ���»��յĽ�� */
 }

 void DestroyList()
 { /* ��̬���鲻�ܱ����� */
 }
 #include"bo2-32.c"
/* bo2-32.c һ��������������ɾ�̬����(���ݽṹ��c2-3.h����)�Ļ�������(12��) */
 void InitSpace(SLinkList L) /* �㷨2.14����� */
 { /* ��һά����L�и���������һ����������L[0].curΪͷָ�롣��0����ʾ��ָ�� */
   int i;
   for(i=0;i<MAXSIZE-1;i++)
     L[i].cur=i+1;
   L[MAXSIZE-1].cur=0;
 }

 int InitList(SLinkList L)
 { /* ����һ������������ֵΪ�ձ��������е�λ�� */
   int i;
   i=Malloc(L); /* ����Malloc()���򻯳��� */
   L[i].cur=0; /* ������ı�ͷָ��Ϊ��(0) */
   return i;
 }

 Status ClearList(SLinkList L,int n)
 { /* ��ʼ������L�б�ͷλ��Ϊn�ľ�̬�����Ѵ��ڡ�������������˱�����Ϊ�ձ� */
   int j,k,i=L[n].cur; /* �����һ������λ�� */
   L[n].cur=0; /* ����� */
   k=L[0].cur; /* ���������һ������λ�� */
   L[0].cur=i; /* ������Ľ��������������ı�ͷ */
   while(i) /* û������β */
   {
     j=i;
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   L[j].cur=k; /* ��������ĵ�һ�����ӵ������β�� */
   return OK;
 }

 Status ListEmpty(SLinkList L,int n)
 { /* �ж�L�б�ͷλ��Ϊn�������Ƿ��,���ǿձ���TRUE;���򷵻�FALSE */
   if(L[n].cur==0) /* �ձ� */
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SLinkList L,int n)
 { /* ����L�б�ͷλ��Ϊn�����������Ԫ�ظ��� */
   int j=0,i=L[n].cur; /* iָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     i=L[i].cur; /* ָ����һ��Ԫ�� */
     j++;
   }
   return j;
 }

 Status GetElem(SLinkList L,int n, int i,ElemType *e)
 { /* ��e����L�б�ͷλ��Ϊn������ĵ�i��Ԫ�ص�ֵ */
   int l,k=n; /* kָ���ͷ��� */
   if(i<1||i>ListLength(L,n)) /* iֵ������ */
     return ERROR;
   for(l=1;l<=i;l++) /* �ƶ�i-1��Ԫ�� */
     k=L[k].cur;
   *e=L[k].data;
   return OK;
 }

 int LocateElem(SLinkList L,int n,ElemType e)
 { /* ��L�б�ͷλ��Ϊn�ľ�̬�������в��ҵ�1��ֵΪe��Ԫ�ء� */
   /* ���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0 */
   int i=L[n].cur; /* iָʾ���е�һ����� */
   while(i&&L[i].data!=e) /* �ڱ���˳������(e�������ַ���) */
     i=L[i].cur;
   return i;
 }

 Status PriorElem(SLinkList L,int n,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ��������L�б�ͷλ��Ϊn�ľ�̬�������Ѵ��� */
   /* �����������cur_e�Ǵ˵����������Ԫ�أ��Ҳ��ǵ�һ���� */
   /*           ����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��� */
   int j,i=L[n].cur; /* iΪ�����һ������λ�� */
   do
   { /* ����ƶ���� */
     j=i;
     i=L[i].cur;
   }while(i&&cur_e!=L[i].data);
   if(i) /* �ҵ���Ԫ�� */
   {
     *pre_e=L[j].data;
     return OK;
   }
   return ERROR;
 }

 Status NextElem(SLinkList L,int n,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ��������L�б�ͷλ��Ϊn�ľ�̬�������Ѵ��� */
   /* �����������cur_e�Ǵ˵����������Ԫ�أ��Ҳ������һ���� */
   /* ����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��� */
   int i;
   i=LocateElem(L,n,cur_e); /* �������в��ҵ�һ��ֵΪcur_e��Ԫ�ص�λ�� */
   if(i) /* �ھ�̬�������д���Ԫ��cur_e */
   {
     i=L[i].cur; /* cur_e�ĺ�̵�λ�� */
     if(i) /* cur_e�к�� */
     {
       *next_e=L[i].data;
       return OK; /* cur_eԪ���к�� */
     }
   }
   return ERROR; /* L������cur_eԪ��,cur_eԪ���޺�� */
 }

 Status ListInsert(SLinkList L,int n,int i,ElemType e)
 { /* ��L�б�ͷλ��Ϊn������ĵ�i��Ԫ��֮ǰ�����µ�����Ԫ��e */
   int l,j,k=n; /* kָ���ͷ */
   if(i<1||i>ListLength(L,n)+1)
     return ERROR;
   j=Malloc(L); /* �����µ�Ԫ */
   if(j) /* ����ɹ� */
   {
     L[j].data=e; /* ��ֵ���µ�Ԫ */
     for(l=1;l<i;l++) /* �ƶ�i-1��Ԫ�� */
       k=L[k].cur;
     L[j].cur=L[k].cur;
     L[k].cur=j;
     return OK;
   }
   return ERROR;
 }

 Status ListDelete(SLinkList L,int n,int i,ElemType *e)
 { /* ɾ����L�б�ͷλ��Ϊn������ĵ�i������Ԫ��e����������ֵ */
   int j,k=n; /* kָ���ͷ */
   if(i<1||i>ListLength(L,n))
     return ERROR;
   for(j=1;j<i;j++) /* �ƶ�i-1��Ԫ�� */
     k=L[k].cur;
   j=L[k].cur;
   L[k].cur=L[j].cur;
   *e=L[j].data;
   Free(L,j);
   return OK;
 }

 Status ListTraverse(SLinkList L,int n,void(*vi)(ElemType))
 { /* ���ζ�L�б�ͷλ��Ϊn�������ÿ������Ԫ��,���ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   int i=L[n].cur; /* ָ���һ��Ԫ�� */
   while(i) /* û����̬����β */
   {
     vi(L[i].data); /* ����vi() */
     i=L[i].cur; /* ָ����һ��Ԫ�� */
   }
   printf("\n");
   return OK;
 }

 void difference(SLinkList space,int *S) /* �㷨2.17 */
 { /* �������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A) */
   /* �ľ�̬����SΪ��ͷָ�롣���豸�ÿռ��㹻��space[0].curΪ���ÿռ��ͷָ�� */
   int r,p,m,n,i,j,k;
   ElemType b;
   InitSpace(space); /* ��ʼ�����ÿռ� */
   *S=Malloc(space); /* ����S��ͷ��� */
   r=*S; /* rָ��S�ĵ�ǰ����� */
   printf("�����뼯��A��B��Ԫ�ظ���m,n:");
   scanf("%d,%d%*c",&m,&n); /* %*c�Ե��س��� */
   printf("�����뼯��A��Ԫ�أ���%d����:",m);
   for(j=1;j<=m;j++) /* ��������A������ */
   {
     i=Malloc(space); /* ������ */
     scanf("%c",&space[i].data); /* ����A��Ԫ��ֵ */
     space[r].cur=i; /* ���뵽��β */
     r=i;
   }
   scanf("%*c"); /* %*c�Ե��س��� */
   space[r].cur=0; /* β����ָ��Ϊ�� */
   printf("�����뼯��B��Ԫ�أ���%d����:",n);
   for(j=1;j<=n;j++)
   { /* ��������B��Ԫ��,�����ڵ�ǰ����,�����,����ɾ�� */
     scanf("%c",&b);
     p=*S;
     k=space[*S].cur; /* kָ�򼯺�A�еĵ�һ����� */
     while(k!=space[r].cur&&space[k].data!=b)
     { /* �ڵ�ǰ���в��� */
       p=k;
       k=space[k].cur;
     }
     if(k==space[r].cur)
     { /* ��ǰ���в����ڸ�Ԫ�أ�������r��ָ���֮����r��λ�ò��� */
       i=Malloc(space);
       space[i].data=b;
       space[i].cur=space[r].cur;
       space[r].cur=i;
     }
     else /* ��Ԫ�����ڱ��У�ɾ��֮ */
     {
       space[p].cur=space[k].cur;
       Free(space,k);
       if(r==k)
         r=p; /* ��ɾ������βԪ�أ������޸�βָ�� */
     }
   }
 }

 void visit(ElemType c)
 {
   printf("%c ",c);
 }

 void main()
 {
   int k;
   SLinkList s;
   difference(s,&k);
   ListTraverse(s,k,visit);
 }


/* algo2-9.c ��������bo2-32.c�еĻ�������ʵ���㷨2.17�Ĺ��� */
 #include"c1.h"
 #define N 2
 typedef char ElemType;
 #include"c2-3.h"
 #include"bo2-3.c"
 #include"bo2-32.c"

 void visit(ElemType c)
 {
   printf("%c ",c);
 }

 int difference(SLinkList space) /* �Ľ��㷨2.17(�������û�������ʵ��) */
 { /* �������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A) */
   /* �ľ�̬������������ͷָ�롣���豸�ÿռ��㹻��space[0].curΪ���ÿռ��ͷָ�� */
   int m,n,i,j,k,S;
   ElemType b,c;
   InitSpace(space); /* ��ʼ�����ÿռ� */
   S=InitList(space); /* ��������S��ͷ��� */
   printf("�����뼯��A��B��Ԫ�ظ���m,n:");
   scanf("%d,%d%*c",&m,&n); /* %*c�Ե��س��� */
   printf("�����뼯��A��Ԫ�أ���%d����:",m);
   for(j=1;j<=m;j++) /* ��������A������ */
   {
     scanf("%c",&b); /* ����A��Ԫ��ֵ */
     ListInsert(space,S,j,b); /* ���뵽��β */
   }
   scanf("%*c"); /* �Ե��س��� */
   printf("�����뼯��B��Ԫ�أ���%d����:",n);
   for(j=1;j<=n;j++)
   { /* ��������B��Ԫ��,�����ڵ�ǰ����,�����,����ɾ�� */
     scanf("%c",&b);
     k=LocateElem(space,S,b); /* kΪb��λ�� */
     if(k) /* b�ڵ�ǰ���� */
     {
       PriorElem(space,S,b,&c); /* b��ǰ��Ϊc */
       i=LocateElem(space,S,c); /* iΪc��λ�� */
       space[i].cur=space[k].cur; /* ��k��ָ�븳��i��ָ�� */
       Free(space,k); /* ���±�Ϊk�Ŀ��н����յ��������� */
     }
     else
       ListInsert(space,S,ListLength(space,S)+1,b); /* �ڱ�β����b */
   }
   return S;
 }

 void main()
 {
   int k;
   SLinkList s;
   k=difference(s);
   ListTraverse(s,k,visit);
 }


/* algo2-10.c ���������βָ���ѭ������ĺϲ����̿���ͼ2.13�� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h"
/* c2-4.h ���Ա��˫������洢�ṹ */
 typedef struct DuLNode
 {
   ElemType data;
   struct DuLNode *prior,*next;
 }DuLNode,*DuLinkList;

 #include"bo2-4.c"
/* bo2-4.c ����βָ��ĵ�ѭ������(�洢�ṹ��c2-2.h����)��12���������� */
 Status InitList_CL(LinkList *L)
 { /* �������������һ���յ����Ա�L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=*L; /* ָ����ָ��ͷ��� */
   return OK;
 }

 Status DestroyList_CL(LinkList *L)
 { /* ����������������Ա�L */
   LinkList q,p=(*L)->next; /* pָ��ͷ��� */
   while(p!=*L) /* û����β */
   {
     q=p->next;
     free(p);
     p=q;
   }
   free(*L);
   *L=NULL;
   return OK;
 }

 Status ClearList_CL(LinkList *L) /* �ı�L */
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   LinkList p,q;
   *L=(*L)->next; /* Lָ��ͷ��� */
   p=(*L)->next; /* pָ���һ����� */
   while(p!=*L) /* û����β */
   {
     q=p->next;
     free(p);
     p=q;
   }
   (*L)->next=*L; /* ͷ���ָ����ָ������ */
   return OK;
 }

 Status ListEmpty_CL(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L->next==L) /* �� */
     return TRUE;
   else
     return FALSE;
 }

 int ListLength_CL(LinkList L)
 { /* ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L->next; /* pָ��ͷ��� */
   while(p!=L) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem_CL(LinkList L,int i,ElemType *e)
 { /* ����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
   int j=1; /* ��ʼ��,jΪ������ */
   LinkList p=L->next->next; /* pָ���һ����� */
   if(i<=0||i>ListLength_CL(L)) /* ��i��Ԫ�ز����� */
     return ERROR;
   while(j<i)
   { /* ˳ָ��������,ֱ��pָ���i��Ԫ�� */
     p=p->next;
     j++;
   }
   *e=p->data; /* ȡ��i��Ԫ�� */
   return OK;
 }

 int LocateElem_CL(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж����� */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
   int i=0;
   LinkList p=L->next->next; /* pָ���һ����� */
   while(p!=L->next)
   {
     i++;
     if(compare(p->data,e)) /* �����ϵ */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status PriorElem_CL(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
   /*           �������ʧ�ܣ�pre_e�޶��� */
   LinkList q,p=L->next->next; /* pָ���һ����� */
   q=p->next;
   while(q!=L->next) /* pû����β */
   {
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return TRUE;
     }
     p=q;
     q=q->next;
   }
   return FALSE;
 }

 Status NextElem_CL(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ�̣� */
   /*           �������ʧ�ܣ�next_e�޶��� */
   LinkList p=L->next->next; /* pָ���һ����� */
   while(p!=L) /* pû����β */
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return TRUE;
     }
     p=p->next;
   }
   return FALSE;
 }

 Status ListInsert_CL(LinkList *L,int i,ElemType e) /* �ı�L */
 { /* ��L�ĵ�i��λ��֮ǰ����Ԫ��e */
   LinkList p=(*L)->next,s; /* pָ��ͷ��� */
   int j=0;
   if(i<=0||i>ListLength_CL(*L)+1) /* �޷��ڵ�i��Ԫ��֮ǰ���� */
     return ERROR;
   while(j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����L�� */
   s->next=p->next;
   p->next=s;
   if(p==*L) /* �ı�β��� */
     *L=s;
   return OK;
 }

 Status ListDelete_CL(LinkList *L,int i,ElemType *e) /* �ı�L */
 { /* ɾ��L�ĵ�i��Ԫ��,����e������ֵ */
   LinkList p=(*L)->next,q; /* pָ��ͷ��� */
   int j=0;
   if(i<=0||i>ListLength_CL(*L)) /* ��i��Ԫ�ز����� */
     return ERROR;
   while(j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   q=p->next; /* qָ���ɾ����� */
   p->next=q->next;
   *e=q->data;
   if(*L==q) /* ɾ�����Ǳ�βԪ�� */
     *L=p;
   free(q); /* �ͷŴ�ɾ����� */
   return OK;
 }

 Status ListTraverse_CL(LinkList L,void(*vi)(ElemType))
 { /* ��ʼ����:L�Ѵ��ڡ��������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next->next;
   while(p!=L->next)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 void MergeList_CL(LinkList *La,LinkList Lb)
 {
   LinkList p=Lb->next;
   Lb->next=(*La)->next;
   (*La)->next=p->next;
   free(p);
   *La=Lb;
 }

 void visit(ElemType c)
 {
   printf("%d ",c);
 }

 void main()
 {
   int n=5,i;
   LinkList La,Lb;
   InitList_CL(&La);
   for(i=1;i<=n;i++)
     ListInsert_CL(&La,i,i);
   printf("La="); /* �������La������ */
   ListTraverse_CL(La,visit);
   InitList_CL(&Lb);
   for(i=1;i<=n;i++)
     ListInsert_CL(&Lb,1,i*2);
   printf("Lb="); /* �������Lb������ */
   ListTraverse_CL(Lb,visit);
   MergeList_CL(&La,Lb);
   printf("La+Lb="); /* ����ϲ������������� */
   ListTraverse_CL(La,visit);
 }


/* algo2-11.c ʵ���㷨2.20��2.21�ĳ��� */
 #include"c1.h"
 typedef int ElemType;

 #include"c2-5.h"
/* c2-5.h ��ͷ���������������� */
 typedef struct LNode /* ������� */
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct LinkList /* �������� */
 {
   Link head,tail; /* �ֱ�ָ�����������е�ͷ�������һ����� */
   int len; /* ָʾ��������������Ԫ�صĸ��� */
 }LinkList;

 #include"bo2-6.c"
/* bo2-6.c ����ʵ���������������(�洢�ṹ��c2-5.h����)��24���������� */
 Status MakeNode(Link *p,ElemType e)
 { /* ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR */
   *p=(Link)malloc(sizeof(LNode));
   if(!*p)
     return ERROR;
   (*p)->data=e;
   return OK;
 }

 void FreeNode(Link *p)
 { /* �ͷ�p��ָ��� */
   free(*p);
   *p=NULL;
 }

 Status InitList(LinkList *L)
 { /* ����һ���յ��������� */
   Link p;
   p=(Link)malloc(sizeof(LNode)); /* ����ͷ��� */
   if(p)
   {
     p->next=NULL;
     (*L).head=(*L).tail=p;
     (*L).len=0;
     return OK;
   }
   else
     return ERROR;
 }

 Status ClearList(LinkList *L)
 { /* ����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ� */
   Link p,q;
   if((*L).head!=(*L).tail)/* ���ǿձ� */
   {
     p=q=(*L).head->next;
     (*L).head->next=NULL;
     while(p!=(*L).tail)
     {
       p=q->next;
       free(q);
       q=p;
     }
     free(q);
     (*L).tail=(*L).head;
     (*L).len=0;
   }
   return OK;
 }

 Status DestroyList(LinkList *L)
 { /* ������������L��L���ٴ��� */
   ClearList(L); /* ������� */
   FreeNode(&(*L).head);
   (*L).tail=NULL;
   (*L).len=0;
   return OK;
 }

 Status InsFirst(LinkList *L,Link h,Link s) /* �β�����L,��Ϊ���޸�L */
 { /* hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ */
   s->next=h->next;
   h->next=s;
   if(h==(*L).tail) /* hָ��β��� */
     (*L).tail=h->next; /* �޸�βָ�� */
   (*L).len++;
   return OK;
 }

 Status DelFirst(LinkList *L,Link h,Link *q) /* �β�����L,��Ϊ���޸�L */
 { /* hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء� */
   /* ������Ϊ��(hָ��β���)��q=NULL������FALSE */
   *q=h->next;
   if(*q) /* ����ǿ� */
   {
     h->next=(*q)->next;
     if(!h->next) /* ɾ��β��� */
       (*L).tail=h; /* �޸�βָ�� */
     (*L).len--;
     return OK;
   }
   else
     return FALSE; /* ����� */
 }

 Status Append(LinkList *L,Link s)
 { /* ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)�� */
   /* һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���� */
   /* ��β��� */
   int i=1;
   (*L).tail->next=s;
   while(s->next)
   {
     s=s->next;
     i++;
   }
   (*L).tail=s;
   (*L).len+=i;
   return OK;
 }

 Position PriorPos(LinkList L,Link p)
 { /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ�� */
   /* ����ǰ�����򷵻�NULL */
   Link q;
   q=L.head->next;
   if(q==p) /* ��ǰ�� */
     return NULL;
   else
   {
     while(q->next!=p) /* q����p��ֱ��ǰ�� */
       q=q->next;
     return q;
   }
 }

 Status Remove(LinkList *L,Link *q)
 { /* ɾ����������L�е�β��㲢��q���أ��ı�����L��βָ��ָ���µ�β��� */
   Link p=(*L).head;
   if((*L).len==0) /* �ձ� */
   {
     *q=NULL;
     return FALSE;
   }
   while(p->next!=(*L).tail)
     p=p->next;
   *q=(*L).tail;
   p->next=NULL;
   (*L).tail=p;
   (*L).len--;
   return OK;
 }

 Status InsBefore(LinkList *L,Link *p,Link s)
 { /* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ�� */
   /* ���޸�ָ��pָ���²���Ľ�� */
   Link q;
   q=PriorPos(*L,*p); /* q��p��ǰ�� */
   if(!q) /* p��ǰ�� */
     q=(*L).head;
   s->next=*p;
   q->next=s;
   *p=s;
   (*L).len++;
   return OK;
 }

 Status InsAfter(LinkList *L,Link *p,Link s)
 { /* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮�� */
   /* ���޸�ָ��pָ���²���Ľ�� */
   if(*p==(*L).tail) /* �޸�βָ�� */
     (*L).tail=s;
   s->next=(*p)->next;
   (*p)->next=s;
   *p=s;
   (*L).len++;
   return OK;
 }

 Status SetCurElem(Link p,ElemType e)
 { /* ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ */
   p->data=e;
   return OK;
 }

 ElemType GetCurElem(Link p)
 { /* ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ */
   return p->data;
 }

 Status ListEmpty(LinkList L)
 { /* ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L.len)
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* ������������L��Ԫ�ظ��� */
   return L.len;
 }

 Position GetHead(LinkList L)
 { /* ������������L��ͷ����λ�� */
   return L.head;
 }

 Position GetLast(LinkList L)
 { /* ������������L�����һ������λ�� */
   return L.tail;
 }

 Position NextPos(Link p)
 { /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�� */
   /* ���޺�̣��򷵻�NULL */
   return p->next;
 }

 Status LocatePos(LinkList L,int i,Link *p)
 { /* ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR */
   /* i=0Ϊͷ��� */
   int j;
   if(i<0||i>L.len)
     return ERROR;
   else
   {
     *p=L.head;
     for(j=1;j<=i;j++)
       *p=(*p)->next;
     return OK;
   }
 }

 Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType))
 { /* ������������L�е�1����e���㺯��compare()�ж���ϵ��Ԫ�ص�λ�ã� */
   /* ��������������Ԫ�أ��򷵻�NULL */
   Link p=L.head;
   do
     p=p->next;
   while(p&&!(compare(p->data,e))); /* û����β��û�ҵ������ϵ��Ԫ�� */
   return p;
 }

 Status ListTraverse(LinkList L,void(*visit)(ElemType))
 { /* ���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�� */
   Link p=L.head->next;
   int j;
   for(j=1;j<=L.len;j++)
   {
     visit(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType))
 { /* ��֪LΪ��������������Ԫ��e���ǽ��������L�С�������һԪ����ʽ�� */
   Link o,p,q;
   q=(*L).head;
   p=q->next;
   while(p!=NULL&&comp(p->data,e)<0) /* p���Ǳ�β��Ԫ��ֵС��e */
   {
     q=p;
     p=p->next;
   }
   o=(Link)malloc(sizeof(LNode)); /* ���ɽ�� */
   o->data=e; /* ��ֵ */
   q->next=o; /* ���� */
   o->next=p;
   (*L).len++; /* ����1 */
   if(!p) /* ���ڱ�β */
     (*L).tail=o; /* �޸�β��� */
   return OK;
 }

 Status LocateElemP(LinkList L,ElemType e,Position *q,int(*compare)(ElemType,ElemType))
 { /* ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�� */
   /* ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж����� */
   /* compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��������һԪ����ʽ�� */
   Link p=L.head,pp;
   do
   {
     pp=p;
     p=p->next;
   }while(p&&(compare(p->data,e)<0)); /* û����β��p->data.expn<e.expn */
   if(!p||compare(p->data,e)>0) /* ����β��compare(p->data,e)>0 */
   {
     *q=pp;
     return FALSE;
   }
   else /* �ҵ� */
   {
     *q=p;
     return TRUE;
   }
 }

 Status ListInsert_L(LinkList *L,int i,ElemType e) /* �㷨2.20 */
 { /* �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e */
   Link h,s;
   if(!LocatePos(*L,i-1,&h))
     return ERROR; /* iֵ���Ϸ� */
   if(!MakeNode(&s,e))
     return ERROR; /* ������ʧ�� */
   InsFirst(L,h,s); /*���ڴӵ�i����㿪ʼ������,��i-1�����������ͷ��� */
   return OK;
 }

 Status MergeList_L(LinkList La,LinkList Lb,LinkList *Lc,int(*compare)(ElemType,ElemType))
 { /* ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С��鲢La��Lb�õ��µĵ��� */
   /* ���Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С������ı�La��Lb���㷨2.21 */
   Link ha,hb,pa,pb,q;
   ElemType a,b;
   if(!InitList(Lc))
     return ERROR; /* �洢�ռ����ʧ�� */
   ha=GetHead(La); /* ha��hb�ֱ�ָ��La��Lb��ͷ��� */
   hb=GetHead(Lb);
   pa=NextPos(ha); /* pa��pb�ֱ�ָ��La��Lb�ĵ�һ����� */
   pb=NextPos(hb);
   while(!ListEmpty(La)&&!ListEmpty(Lb)) /* La��Lb���ǿ� */
   {
     a=GetCurElem(pa); /* a��bΪ�����е�ǰ�Ƚ�Ԫ�� */
     b=GetCurElem(pb);
     if(compare(a,b)<=0)
     {
       DelFirst(&La,ha,&q);
       InsFirst(Lc,(*Lc).tail,q);
       pa=NextPos(ha);
     }
     else /* a>b */
     {
       DelFirst(&Lb,hb,&q);
       InsFirst(Lc,(*Lc).tail,q);
       pb=NextPos(hb);
     }
   }
   if(!ListEmpty(La))
     Append(Lc,pa);
   else
     Append(Lc,pb);
   FreeNode(&ha);
   FreeNode(&hb);
   return OK;
 }

 int comp(ElemType c1,ElemType c2)
 {
   return c1-c2;
 }

 void visit(ElemType c)
 {
   printf("%d ",c); /* ���� */
 }

 void main()
 {
   LinkList La,Lb,Lc;
   int j;
   InitList(&La);
   for(j=1;j<=5;j++)
     ListInsert_L(&La,j,j); /* ˳����� 1 2 3 4 5 */
   printf("La=");
   ListTraverse(La,visit);
   InitList(&Lb);
   for(j=1;j<=5;j++)
     ListInsert_L(&Lb,j,2*j); /* ˳����� 2 4 6 8 10 */
   printf("Lb=");
   ListTraverse(Lb,visit);
   InitList(&Lc);
   MergeList_L(La,Lb,&Lc,comp); /* �鲢La��Lb������Lc */
   printf("Lc=");
   ListTraverse(Lc,visit);
   DestroyList(&Lc);
 }


/* algo2-12.c �õ�����ʵ���㷨2.1,����4����algo2-1.c��ͬ */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h" /* �˾���algo2-1.c��ͬ(��Ϊ���ò�ͬ�Ľṹ) */
 #include"bo2-2.c" /* �˾���algo2-1.c��ͬ(��Ϊ���ò�ͬ�Ľṹ) */

 Status equal(ElemType c1,ElemType c2)
 { /* �ж��Ƿ���ȵĺ�����Union()�õ� */
   if(c1==c2)
     return TRUE;
   else
     return FALSE;
 }

 void Union(LinkList La,LinkList Lb) /* �㷨2.1,�˾���algo2-1.c��ͬ */
 { /* �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�� */
   ElemType e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(La); /* �����Ա�ĳ��� */
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)
   {
     GetElem(Lb,i,&e); /* ȡLb�е�i������Ԫ�ظ���e */
     if(!LocateElem(La,e,equal)) /* La�в����ں�e��ͬ��Ԫ��,�����֮ */
       ListInsert(La,++La_len,e);
   }
 }

 void print(ElemType c)
 {
   printf("%d ",c);
 }

 void main()
 {
   LinkList La,Lb; /* �˾���algo2-1.c��ͬ(��Ϊ���ò�ͬ�Ľṹ) */
   Status i;
   int j;
   i=InitList(&La);
   if(i==1) /* �����ձ�La�ɹ� */
     for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
       i=ListInsert(La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* Ҳ�ɲ��ж��Ƿ񴴽��ɹ� */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     i=ListInsert(Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   Union(La,Lb);
   printf("new La= "); /* ����±�La������ */
   ListTraverse(La,print);
 } 


/* algo2-13.c ��������ṹʵ���㷨2.2�ĳ��򣬽���4����algo2-2.c��ͬ */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h" /* �˾���algo2-2.c��ͬ */
 #include"bo2-2.c" /* �˾���algo2-2.c��ͬ */

 void MergeList(LinkList La,LinkList Lb,LinkList *Lc) /* �㷨2.2,�˾���algo2-2.c��ͬ */
 { /* ��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����С� */
   /* �鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ����� */
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   ElemType ai,bj;
   InitList(Lc); /* �����ձ�Lc */
   La_len=ListLength(La);
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len) /* ��La�ͱ�Lb���ǿ� */
   {
     GetElem(La,i,&ai);
     GetElem(Lb,j,&bj);
     if(ai<=bj)
     {
       ListInsert(*Lc,++k,ai);
       ++i;
     }
     else
     {
       ListInsert(*Lc,++k,bj);
       ++j;
     }
   }
   while(i<=La_len) /* ��La�ǿ��ұ�Lb�� */
   {
     GetElem(La,i++,&ai);
     ListInsert(*Lc,++k,ai);
   }
   while(j<=Lb_len) /* ��Lb�ǿ��ұ�La�� */
   {
     GetElem(Lb,j++,&bj);
     ListInsert(*Lc,++k,bj);
   }
 }

 void print(ElemType c)
 {
   printf("%d ",c);
 }

 void main()
 {
   LinkList La,Lb,Lc; /* �˾���algo2-2.c��ͬ */
   int j,a[4]={3,5,8,11},b[7]={2,6,8,9,11,15,20};
   InitList(&La); /* �����ձ�La */
   for(j=1;j<=4;j++) /* �ڱ�La�в���4��Ԫ�� */
     ListInsert(La,j,a[j-1]);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* �����ձ�Lb */
   for(j=1;j<=7;j++) /* �ڱ�Lb�в���7��Ԫ�� */
     ListInsert(Lb,j,b[j-1]);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   MergeList(La,Lb,&Lc);
   printf("Lc= "); /* �����Lc������ */
   ListTraverse(Lc,print);
 }
 
/* algo4-1.c ʵ���㷨4.6��4.7�ĳ��� */
 #include"c1.h"

 #include"c4-1.h"
/* c4-1.h ���Ķ���˳��洢��ʾ */
 #define MAXSTRLEN 40 /* �û�����255���ڶ�����󴮳���1���ֽڣ� */
 typedef char SString[MAXSTRLEN+1]; /* 0�ŵ�Ԫ��Ŵ��ĳ��� */

 #include"bo4-1.c"
/* bo4-1.c �����ö���˳��洢�ṹ(��c4-1.h����)�Ļ�������(14��) */
 /* SString�����飬�ʲ����������͡��˻������������㷨4.2,4.3,4.5 */
 Status StrAssign(SString T,char *chars)
 { /* ����һ����ֵ����chars�Ĵ�T */
   int i;
   if(strlen(chars)>MAXSTRLEN)
     return ERROR;
   else
   {
     T[0]=strlen(chars);
     for(i=1;i<=T[0];i++)
       T[i]=*(chars+i-1);
     return OK;
   }
 }

 Status StrCopy(SString T,SString S)
 { /* �ɴ�S���Ƶô�T */
   int i;
   for(i=0;i<=S[0];i++)
     T[i]=S[i];
   return OK;
 }

 Status StrEmpty(SString S)
 { /* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
   if(S[0]==0)
     return TRUE;
   else
     return FALSE;
 }

 int StrCompare(SString S,SString T)
 { /* ��ʼ����: ��S��T���� */
   /* �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
   int i;
   for(i=1;i<=S[0]&&i<=T[0];++i)
     if(S[i]!=T[i])
       return S[i]-T[i];
   return S[0]-T[0];
 }

 int StrLength(SString S)
 { /* ���ش���Ԫ�ظ��� */
   return S[0];
 }

 Status ClearString(SString S)
 { /* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
   S[0]=0;/* ���Ϊ�� */
   return OK;
 }

 Status Concat(SString T,SString S1,SString S2) /* �㷨4.2�� */
 { /* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
   int i;
   if(S1[0]+S2[0]<=MAXSTRLEN)
   { /* δ�ض� */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=S2[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=S1[0]+S2[0];
     return TRUE;
   }
   else
   { /* �ض�S2 */
     for(i=1;i<=S1[0];i++)
       T[i]=S1[i];
     for(i=1;i<=MAXSTRLEN-S1[0];i++)
       T[S1[0]+i]=S2[i];
     T[0]=MAXSTRLEN;
     return FALSE;
   }
 }

 Status SubString(SString Sub,SString S,int pos,int len)
 { /* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ����㷨4.3 */
   int i;
   if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
     return ERROR;
   for(i=1;i<=len;i++)
     Sub[i]=S[pos+i-1];
   Sub[0]=len;
   return OK;
 }

 int Index(SString S,SString T,int pos)
 { /* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,����ֵΪ0�� */
   /* ����,T�ǿ�,1��pos��StrLength(S)���㷨4.5 */
   int i,j;
   if(1<=pos&&pos<=S[0])
   {
     i=pos;
     j=1;
     while(i<=S[0]&&j<=T[0])
       if(S[i]==T[j]) /* �����ȽϺ���ַ� */
       {
         ++i;
         ++j;
       }
       else /* ָ��������¿�ʼƥ�� */
       {
         i=i-j+2;
         j=1;
       }
     if(j>T[0])
       return i-T[0];
     else
       return 0;
   }
   else
     return 0;
 }

 Status StrInsert(SString S,int pos,SString T)
 { /* ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
   /* �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
   int i;
   if(pos<1||pos>S[0]+1)
     return ERROR;
   if(S[0]+T[0]<=MAXSTRLEN)
   { /* ��ȫ���� */
     for(i=S[0];i>=pos;i--)
       S[i+T[0]]=S[i];
     for(i=pos;i<pos+T[0];i++)
       S[i]=T[i-pos+1];
     S[0]=S[0]+T[0];
     return TRUE;
   }
   else
   { /* ���ֲ��� */
     for(i=MAXSTRLEN;i<=pos;i--)
       S[i]=S[i-T[0]];
     for(i=pos;i<pos+T[0];i++)
       S[i]=T[i-pos+1];
     S[0]=MAXSTRLEN;
     return FALSE;
   }
 }

 Status StrDelete(SString S,int pos,int len)
 { /* ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
   /* �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
   int i;
   if(pos<1||pos>S[0]-len+1||len<0)
     return ERROR;
   for(i=pos+len;i<=S[0];i++)
     S[i-len]=S[i];
   S[0]-=len;
   return OK;
 }

 Status Replace(SString S,SString T,SString V)
 { /* ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
   /* �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
   int i=1; /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
   if(StrEmpty(T)) /* T�ǿմ� */
     return ERROR;
   do
   {
     i=Index(S,T,i); /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
     if(i) /* ��S�д��ڴ�T */
     {
       StrDelete(S,i,StrLength(T)); /* ɾ���ô�T */
       StrInsert(S,i,V); /* ��ԭ��T��λ�ò��봮V */
       i+=StrLength(V); /* �ڲ���Ĵ�V����������Ҵ�T */
     }
   }while(i);
   return OK;
 }

 void DestroyString()
 { /* ����SString�Ƕ�������,�޷����� */
 }

 void StrPrint(SString T)
 { /* ����ַ���T����� */
   int i;
   for(i=1;i<=T[0];i++)
     printf("%c",T[i]);
   printf("\n");
 }

 void get_next(SString T,int next[])
 { /* ��ģʽ��T��next����ֵ����������next �㷨 4.7 */
   int i=1,j=0;
   next[1]=0;
   while(i<T[0])
     if(j==0||T[i]==T[j])
     {
       ++i;
       ++j;
       next[i]=j;
     }
     else
       j=next[j];
 }

 int Index_KMP(SString S,SString T,int pos,int next[])
 { /* ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨�� */
   /* ����,T�ǿ�,1��pos��StrLength(S)���㷨 4.6 */
   int i=pos,j=1;
   while(i<=S[0]&&j<=T[0])
     if(j==0||S[i]==T[j]) /* �����ȽϺ���ַ� */
     {
       ++i;
       ++j;
     }
     else /* ģʽ�������ƶ� */
       j=next[j];
   if(j>T[0]) /* ƥ��ɹ� */
     return i-T[0];
   else
     return 0;
 }

 void main()
 {
   int i,j,*p;
   SString s1,s2; /* �Խ̿�����ͼ4.5Ϊ�� */
   StrAssign(s1,"acabaabaabcacaabc");
   printf("����Ϊ: ");
   StrPrint(s1);
   StrAssign(s2,"abaabcac");
   printf("�Ӵ�Ϊ: ");
   StrPrint(s2);
   i=StrLength(s2);
   p=(int*)malloc((i+1)*sizeof(int)); /* ����s2��next���� */
   get_next(s2,p);
   printf("�Ӵ���next����Ϊ: ");
   for(j=1;j<=i;j++)
     printf("%d ",*(p+j));
   printf("\n");
   i=Index_KMP(s1,s2,1,p);
   if(i)
     printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",i);
   else
     printf("�������Ӵ�ƥ�䲻�ɹ�\n");
 }
 
/* algo5-1.c ʵ���㷨5.2�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c5-2.h"
/* c5-2.h ϡ��������Ԫ��˳���洢��ʾ */
 #define MAXSIZE 100 /* ����Ԫ���������ֵ */
 typedef struct
 {
   int i,j; /* ���±�,���±� */
   ElemType e; /* ����Ԫ��ֵ */
 }Triple;
 typedef struct
 {
   Triple data[MAXSIZE+1]; /* ����Ԫ��Ԫ���,data[0]δ�� */
   int mu,nu,tu; /* ����������������ͷ���Ԫ���� */
 }TSMatrix;

 #include"bo5-2.c"
/* bo5-2.c ��Ԫ��ϡ�����Ļ�������,�����㷨5.1(9��) */
 Status CreateSMatrix(TSMatrix *M)
 { /* ����ϡ�����M */
   int i,m,n;
   ElemType e;
   Status k;
   printf("��������������,����,����Ԫ������");
   scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
   (*M).data[0].i=0; /* Ϊ���±Ƚ�˳����׼�� */
   for(i=1;i<=(*M).tu;i++)
   {
     do
     {
       printf("�밴����˳�������%d������Ԫ�����ڵ���(1��%d),��(1��%d),Ԫ��ֵ��",i,(*M).mu,(*M).nu);
       scanf("%d,%d,%d",&m,&n,&e);
       k=0;
       if(m<1||m>(*M).mu||n<1||n>(*M).nu) /* �л��г�����Χ */
         k=1;
       if(m<(*M).data[i-1].i||m==(*M).data[i-1].i&&n<=(*M).data[i-1].j) /* �л��е�˳���д� */
         k=1;
     }while(k);
     (*M).data[i].i=m;
     (*M).data[i].j=n;
     (*M).data[i].e=e;
   }
   return OK;
 }

 void DestroySMatrix(TSMatrix *M)
 { /* ����ϡ�����M */
   (*M).mu=0;
   (*M).nu=0;
   (*M).tu=0;
 }

 void PrintSMatrix(TSMatrix M)
 { /* ���ϡ�����M */
   int i;
   printf("%d��%d��%d������Ԫ�ء�\n",M.mu,M.nu,M.tu);
   printf("��  ��  Ԫ��ֵ\n");
   for(i=1;i<=M.tu;i++)
     printf("%2d%4d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
 }

 Status CopySMatrix(TSMatrix M,TSMatrix *T)
 { /* ��ϡ�����M���Ƶõ�T */
   (*T)=M;
   return OK;
 }

 int comp(int c1,int c2) /* ��� */
 { /* AddSMatrix����Ҫ�õ� */
   int i;
   if(c1<c2)
     i=1;
   else if(c1==c2)
     i=0;
   else
     i=-1;
   return i;
 }

 Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q)
 { /* ��ϡ�����ĺ�Q=M+N */
   Triple *Mp,*Me,*Np,*Ne,*Qh,*Qe;
   if(M.mu!=N.mu)
     return ERROR;
   if(M.nu!=N.nu)
     return ERROR;
   (*Q).mu=M.mu;
   (*Q).nu=M.nu;
   Mp=&M.data[1]; /* Mp�ĳ�ֵָ�����M�ķ���Ԫ���׵�ַ */
   Np=&N.data[1]; /* Np�ĳ�ֵָ�����N�ķ���Ԫ���׵�ַ */
   Me=&M.data[M.tu]; /* Meָ�����M�ķ���Ԫ��β��ַ */
   Ne=&N.data[N.tu]; /* Neָ�����N�ķ���Ԫ��β��ַ */
   Qh=Qe=(*Q).data; /* Qh��Qe�ĳ�ֵָ�����Q�ķ���Ԫ���׵�ַ��ǰһ��ַ */
   while(Mp<=Me&&Np<=Ne)
   {
     Qe++;
     switch(comp(Mp->i,Np->i))
     {
       case  1: *Qe=*Mp;
                Mp++;
                break;
       case  0: switch(comp(Mp->j,Np->j)) /* M��N����ǰ����Ԫ�ص������,�����Ƚ��� */
                {
                  case  1: *Qe=*Mp;
                           Mp++;
                           break;
                  case  0: *Qe=*Mp;
                           Qe->e+=Np->e;
                           if(!Qe->e) /* Ԫ��ֵΪ0��������ѹ������ */
                             Qe--;
                           Mp++;
                           Np++;
                           break;
                  case -1: *Qe=*Np;
                           Np++;
                }
                break;
       case -1: *Qe=*Np;
                Np++;
     }
   }
   if(Mp>Me) /* ����M��Ԫ��ȫ��������� */
     while(Np<=Ne)
     {
       Qe++;
       *Qe=*Np;
       Np++;
     }
   if(Np>Ne) /* ����N��Ԫ��ȫ��������� */
     while(Mp<=Me)
     {
       Qe++;
       *Qe=*Mp;
       Mp++;
     }
   (*Q).tu=Qe-Qh; /* ����Q�ķ���Ԫ�ظ��� */
   return OK;
 }

 Status SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q)
 { /* ��ϡ�����Ĳ�Q=M-N */
   int i;
   for(i=1;i<=N.tu;i++)
     N.data[i].e*=-1;
   AddSMatrix(M,N,Q);
   return OK;
 }

 Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q)
 { /* ��ϡ�����ĳ˻�Q=M*N */
   int i,j,h=M.mu,l=N.nu,Qn=0;
   /* h,l�ֱ�Ϊ����Q���С���ֵ,QnΪ����Q�ķ���Ԫ�ظ�������ֵΪ0 */
   ElemType *Qe;
   if(M.nu!=N.mu)
     return ERROR;
   (*Q).mu=M.mu;
   (*Q).nu=N.nu;
   Qe=(ElemType *)malloc(h*l*sizeof(ElemType)); /* QeΪ����Q����ʱ���� */
   /* ����Q�ĵ�i��j�е�Ԫ��ֵ����*(Qe+(i-1)*l+j-1)�У���ֵΪ0 */
   for(i=0;i<h*l;i++)
     *(Qe+i)=0; /* ����ֵ0 */
   for(i=1;i<=M.tu;i++) /* ����Ԫ����ˣ�����ۼӵ�Qe */
     for(j=1;j<=N.tu;j++)
       if(M.data[i].j==N.data[j].i)
         *(Qe+(M.data[i].i-1)*l+N.data[j].j-1)+=M.data[i].e*N.data[j].e;
   for(i=1;i<=M.mu;i++)
     for(j=1;j<=N.nu;j++)
       if(*(Qe+(i-1)*l+j-1)!=0)
       {
         Qn++;
         (*Q).data[Qn].e=*(Qe+(i-1)*l+j-1);
         (*Q).data[Qn].i=i;
         (*Q).data[Qn].j=j;
       }
   free(Qe);
   (*Q).tu=Qn;
   return OK;
 }

 Status TransposeSMatrix(TSMatrix M,TSMatrix *T)
 { /* ��ϡ�����M��ת�þ���T���㷨5.1 */
   int p,q,col;
   (*T).mu=M.nu;
   (*T).nu=M.mu;
   (*T).tu=M.tu;
   if((*T).tu)
   {
     q=1;
     for(col=1;col<=M.nu;++col)
       for(p=1;p<=M.tu;++p)
         if(M.data[p].j==col)
         {
           (*T).data[q].i=M.data[p].j;
           (*T).data[q].j=M.data[p].i;
           (*T).data[q].e=M.data[p].e;
           ++q;
         }
   }
   return OK;
 }

 Status FastTransposeSMatrix(TSMatrix M,TSMatrix *T)
 { /* ������ϡ�����M��ת�þ���T���㷨5.2 */
   int p,q,t,col,*num,*cpot;
   num=(int *)malloc((M.nu+1)*sizeof(int)); /* �������飨[0]���ã� */
   cpot=(int *)malloc((M.nu+1)*sizeof(int)); /* �������飨[0]���ã� */
   (*T).mu=M.nu;
   (*T).nu=M.mu;
   (*T).tu=M.tu;
   if((*T).tu)
   {
     for(col=1;col<=M.nu;++col)
       num[col]=0; /* ���ֵ */
     for(t=1;t<=M.tu;++t) /* ��M��ÿһ�к�����Ԫ�ظ��� */
       ++num[M.data[t].j];
     cpot[1]=1;
     for(col=2;col<=M.nu;++col) /* ���col���е�һ������Ԫ��(*T).data�е���� */
       cpot[col]=cpot[col-1]+num[col-1];
     for(p=1;p<=M.tu;++p)
     {
       col=M.data[p].j;
       q=cpot[col];
       (*T).data[q].i=M.data[p].j;
       (*T).data[q].j=M.data[p].i;
       (*T).data[q].e=M.data[p].e;
       ++cpot[col];
     }
   }
   free(num);
   free(cpot);
   return OK;
 }

 void main()
 {
   TSMatrix A,B;
   printf("��������A: ");
   CreateSMatrix(&A);
   PrintSMatrix(A);
   FastTransposeSMatrix(A,&B);
   printf("����B(A�Ŀ���ת��): ");
   PrintSMatrix(B);
   DestroySMatrix(&A);
   DestroySMatrix(&B);
 }
 
typedef int SElemType; /* ����ջԪ������ */
 #define STACK_INIT_SIZE 10 /* �洢�ռ��ʼ������ */
 #define STACKINCREMENT 2 /* �洢�ռ�������� */
 typedef struct SqStack
 {
   SElemType *base; /* ��ջ����֮ǰ������֮��base��ֵΪNULL */
   SElemType *top; /* ջ��ָ�� */
   int stacksize; /* ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ */
 }SqStack; /* ˳��ջ */
 
 Status InitStack(SqStack *S)
 { /* ����һ����ջS */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* �洢����ʧ�� */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
 }

 Status DestroyStack(SqStack *S)
 { /* ����ջS��S���ٴ��� */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return OK;
 }

 Status ClearStack(SqStack *S)
 { /* ��S��Ϊ��ջ */
   (*S).top=(*S).base;
   return OK;
 }

 Status StackEmpty(SqStack S)
 { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }

 int StackLength(SqStack S)
 { /* ����S��Ԫ�ظ�������ջ�ĳ��� */
   return S.top-S.base;
 }

 Status GetTop(SqStack S,SElemType *e)
 { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 Status Push(SqStack *S,SElemType e)
 { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
   if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* �洢����ʧ�� */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return OK;
 }

 Status Pop(SqStack *S,SElemType *e)
 { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }

 Status StackTraverse(SqStack S,Status(*visit)(SElemType))
 { /* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
   /* һ��visit()ʧ�ܣ������ʧ�� */
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
   return OK;
 }

 Status visit(SElemType c)
 {
   printf("%d ",c);
   return OK;
 }

 void main()
 {
   int j;
   SqStack s;
   SElemType e;
   if(InitStack(&s)==OK)
     for(j=1;j<=12;j++)
       Push(&s,j);
   printf("The ElemType in this status are:");
   StackTraverse(s,visit);
   Pop(&s,&e);
   printf("the pop ElemType is e=%d\n",e);
   printf("empty or not:%d(1:empty 0:not empty)\n",StackEmpty(s));
   GetTop(s,&e);
   printf("The top ElemType is e=%d  The length of status is %d\n",e,StackLength(s));
   ClearStack(&s);
   printf("After clear the status,empty or not:%d(1:empty 0:not empty)\n",StackEmpty(s));
   DestroyStack(&s);
   printf("After destory the status,s.top=%u s.base=%u s.stacksize=%d\n",s.top,s.base, s.stacksize);
 }
 
typedef int QElemType;
 /* �������У������е���ʽ�洢�ṹ */
 typedef struct QNode
 {
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; /* ��ͷ����βָ�� */
 }LinkQueue;

  /*  ������(�洢�ṹ����)�Ļ�������(9��) */
 Status InitQueue(LinkQueue *Q)
 { /* ����һ���ն���Q */
   (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
   if(!(*Q).front)
     exit(OVERFLOW);
   (*Q).front->next=NULL;
   return OK;
 }

 Status DestroyQueue(LinkQueue *Q)
 { /* ���ٶ���Q(���ۿշ����) */
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return OK;
 }

 Status ClearQueue(LinkQueue *Q)
 { /* ��Q��Ϊ�ն��� */
   QueuePtr p,q;
   (*Q).rear=(*Q).front;
   p=(*Q).front->next;
   (*Q).front->next=NULL;
   while(p)
   {
     q=p;
     p=p->next;
     free(q);
   }
   return OK;
 }

 Status QueueEmpty(LinkQueue Q)
 { /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
   if(Q.front==Q.rear)
     return TRUE;
   else
     return FALSE;
 }

 int QueueLength(LinkQueue Q)
 { /* ����еĳ��� */
   int i=0;
   QueuePtr p;
   p=Q.front;
   while(Q.rear!=p)
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetHead_Q(LinkQueue Q,QElemType *e) 
 { /* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
   QueuePtr p;
   if(Q.front==Q.rear)
     return ERROR;
   p=Q.front->next;
   *e=p->data;
   return OK;
 }

 Status EnQueue(LinkQueue *Q,QElemType e)
 { /* ����Ԫ��eΪQ���µĶ�βԪ�� */
   QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
   if(!p) /* �洢����ʧ�� */
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   (*Q).rear->next=p;
   (*Q).rear=p;
   return OK;
 }

 Status DeQueue(LinkQueue *Q,QElemType *e)
 { /* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
   QueuePtr p;
   if((*Q).front==(*Q).rear)
     return ERROR;
   p=(*Q).front->next;
   *e=p->data;
   (*Q).front->next=p->next;
   if((*Q).rear==p)
     (*Q).rear=(*Q).front;
   free(p);
   return OK;
 }

 Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
 { /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ�� */
   QueuePtr p;
   p=Q.front->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 void visit(QElemType i)
 {
   printf("%d ",i);
 }

 void main()
 {
   int i;
   QElemType d;
   LinkQueue q;
   i=InitQueue(&q);
   if(i)
     printf("InitQueue success!\n");
   printf("Queue empty or not?%d(1:empty 0:not empty)  ",QueueEmpty(q));
   printf("The length of Queue is %d\n",QueueLength(q));
   EnQueue(&q,-5);
   EnQueue(&q,5);
   EnQueue(&q,10);
   printf("After insert(-5,5,10),The length of Queue is %d\n",QueueLength(q));
   printf("Queue empty or not?%d(1:empty 0:not empty)  ",QueueEmpty(q));
   printf("Output the Queue in term is:");
   QueueTraverse(q,visit);
   i=GetHead_Q(q,&d);
   if(i==OK)
     printf("The front of Queue is: %d\n",d);
   DeQueue(&q,&d);
   printf("After delete the front ElemType%d\n",d);
   i=GetHead_Q(q,&d);
   if(i==OK)
     printf("The new front of Queue is: %d\n",d);
   ClearQueue(&q);
   printf("After clear the Queue,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
   DestroyQueue(&q);
   printf("After destory the Queue,q.front=%u q.rear=%u\n",q.front, q.rear);
 } 

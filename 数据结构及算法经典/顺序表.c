 # define maxsize 50

 struct sqlist
 { 
 	int sqlist[maxsize];
     	int key;
     	int size;
     	int data;
 };

 setnull(struct sqlist *p)  /*װ���*/
 {
 	p->size=0;
 }
 
 int length(struct sqlist *p)  /*����*/
 {
  	return(p->size);
 }
 
 get(struct sqlist *p,int i)  /*ȡ��һ��Ԫ��*/
 {
    	if (i<1 && i>p->size) 
    		printf("����");
      	else 
      		printf("����Ŷ�Ӧ��Ԫ��Ϊ��%d",p->sqlist[i]);
 }
 
 locate(struct sqlist *p,int x)  /*����Ԫ��*/
 {  
 	int i=0;
    	while (i<p->size && p->sqlist[i]!=x) 
    		i++;
    		
      	if (i==p->size )
      		printf("����");
	else printf("��Ԫ�ص�һ�γ��ֵ�λ�ã�%d",i);
 }
 
 insert(struct sqlist *p,int i,int x)
 {
 	int j;
     	if (i<1 && i>p->size+1)
		printf("λ�ò���ȷ�����в���\n");
 	else
  	{
		p->size++;
		for (j=p->size-1;j>=i;j--)
			p->sqlist[j]=p->sqlist[j-1];
		p->sqlist[j]=x;
  	}
 	for(j=1;j<p->size;j++)
 		printf("���Ա�Ϊ:%d->",p->sqlist[j]);
 }
 
 void delete(struct sqlist *p,int i)
 {
 	int j;
 	if (i<1 || i>p->size)
		printf("����");
 	else
	{
 		for (j=i;j<p->size;j++)
			p->sqlist[j]=p->sqlist[j+1];
		p->size--;
 	}
 	printf("�����Ա�Ϊ��");
   	for (i=1;i<=p->size;i++)
		printf("%d->",p->sqlist[i]);
 }

 insertsort(struct sqlist *p,int n)
 {
 	int i,j;
	for(i=2;i<=n;i++)
	{
		p->sqlist[0]=p->sqlist[i];
		j=i-1;
		while(j>0 && p->sqlist[0]<p->sqlist[j])
		{
			p->sqlist[j+1]=p->sqlist[j]; j--;}
 			p->sqlist[j+1]=p->sqlis	t[0];
		}
		printf("shen xu;\n");
		for (i=1;i<=n;i++)
			printf("%d",p->sqlist[i]);
		printf("\n");
		for(i=1;i<=n;i++)
			printf("%d",p->sqlist[i]);
		printf("\n");
	}
}

display(struct sqlist *p)
{
	int j;
	if (p->size==0)
		printf("�˱�Ϊ���޷���ʾ��");
	else 
		printf("the list");
	if (p->size==1)
		printf("%d",p->sqlist[p->size]);
 	else
 	{
 		for(j=1;j<p->size;j++)
 			printf("%d->",p->sqlist[j]);
		printf("%d",p->sqlist[j]);

 	}
}

main()
{
	int i,select,a,j;int w;
	struct sqlist *p;
	struct sqlist l;
	setnull(&l);
	printf("���������ݣ�\n");
 	p=&l ;
  	p->size=0;
  	for (i=1;i<5; i++)
     	{
     		scanf("%d",&l.sqlist[i]);
     		p->size++;
     	}
	printf("\n");
	printf("1:�ÿձ� \n");
  	printf("2:�󳤶ȣ� \n");
  	printf("3:��ȡԪ�أ� \n");
  	printf("4:��λ���ң� \n");
  	printf("5:���룡 \n");
  	printf("6:ɾ���� \n");
  	printf("7:���� \n");
  	printf("8:��ʾ�� \n");

  	printf("��ѡ��1----8�� \n");
  	scanf("%d",&select);
  	switch(select)
	{
		case 1:
			setnull(&l);break;
		case 2:
			printf("chang du %d",length(&l));
			break;
		case 3:
			printf("�������:");
			scanf("%d",&i);
			get(&l,i);
			break;
		case 4:
			printf("����Ԫ��:");
			scanf("%d",&i);
			locate (&l,i);
			break;
		case 5:
			printf("��������Ԫ�ؼ�λ�ã�");
			scanf("%d,%d",&i,&j);
     			insert(&l,i,j);
     			break;
		case 6:
			printf("������Ҫɾ�����ݵ�λ��:");
       			scanf("%d",&w);
       			delete(&l,w);    
       			break;
		case 7:
			insertsort(&l,4);
			break;
		case 8:
			display(&l);  
			break;
  	}
}
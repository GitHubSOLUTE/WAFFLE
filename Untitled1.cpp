# include <stdlib.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define OK   1
# define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}Node, *LinkList;


LinkList CreateLinkListTail(int n)//β�巨
{
	int x;
	LNode *L;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == 0) exit(OVERFLOW);
	L->next = NULL;
	LNode *r;
	r = L;
	printf("����Ԫ��:");
	while (n--)
	{
		scanf("%d", &x);
		LNode *p;
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		r->next = p;
		r = p;//֮���ѭ������r���ǵ�ͬ��p r->next����p->next
	}
	r->next = NULL;
	return L;
}

Status DeleteList(LinkList L){//ɾ����mink��������maxk�����֮��Ľ��
    LNode *pre,*p = 0,*q;//preΪǰ����㣬pΪҪɾ���Ľ��,qָ���maxk���
     pre = L;q = L;
    int mink,maxk;
    printf("������mink��maxk��ֵ��");
    scanf("%d%d",&mink,&maxk);
    for(int tempi = 1;tempi < mink; ++tempi)
        pre = pre->next;
    for(int tempi = 1;tempi < maxk; ++tempi)
        q = q->next;
    while(pre->next != q){
        p = pre->next;
        pre->next = pre->next->next;
        p->next = NULL;
        free(p);
    }
    return OK;
}

void  PrintList(LinkList L)//����
{
	LNode *p;
	for (p = L->next; p != NULL; p = p->next){
		printf("%d", p->data);
	}
}

int main()
{
    LNode *LL;int count;
    printf("��������ĳ��� :");
    scanf("%d",&count);//��������ĳ���
    LL = CreateLinkListTail(count);
    DeleteList(LL);
    PrintList(LL);
    return OK;
}

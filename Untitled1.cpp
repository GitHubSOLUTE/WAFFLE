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


LinkList CreateLinkListTail(int n)//尾插法
{
	int x;
	LNode *L;
	L = (LNode *)malloc(sizeof(LNode));
	if(L == 0) exit(OVERFLOW);
	L->next = NULL;
	LNode *r;
	r = L;
	printf("输入元素:");
	while (n--)
	{
		scanf("%d", &x);
		LNode *p;
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		r->next = p;
		r = p;//之后的循环遇到r就是等同于p r->next就是p->next
	}
	r->next = NULL;
	return L;
}

Status DeleteList(LinkList L){//删除第mink个结点与第maxk个结点之间的结点
    LNode *pre,*p = 0,*q;//pre为前驱结点，p为要删除的结点,q指向第maxk结点
     pre = L;q = L;
    int mink,maxk;
    printf("请输入mink与maxk的值：");
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

void  PrintList(LinkList L)//遍历
{
	LNode *p;
	for (p = L->next; p != NULL; p = p->next){
		printf("%d", p->data);
	}
}

int main()
{
    LNode *LL;int count;
    printf("输入链表的长度 :");
    scanf("%d",&count);//输入链表的长度
    LL = CreateLinkListTail(count);
    DeleteList(LL);
    PrintList(LL);
    return OK;
}

#include "base.h"


Status visitSg(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct Node
{
    ElemType data;/* 链表中数据段也可以是结构体*/
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

/* 初始化链式线性表 */
Status InitListSg(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 */

    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmptySg(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* 初始条件：链式线性表L已存在。操作结果：将L重置为空表 */
Status ClearListSg(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p指向第一个结点 */
	while(p)                /*  没到表尾 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* 头结点指针域为空 */
	return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLengthSg(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElemSg(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{   
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElemSg(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* 找到这样的数据元素 */
                return i;
        p=p->next;
    }

    return 0;
}


/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsertSg(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;  
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDeleteSg(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverseSg(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visitSg(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHeadSg(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTailSg(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r=*L;                                /* r为指向尾部的结点 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;           /*  随机生成100以内的数字 */
		r->next=p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

# include <stdio.h>
# include <stdlib.h>
#include<stdbool.h>
#define  MAXSIZE  100
#define  ElemType  int

typedef struct Qnode
{
	ElemType  data;
    struct Qnode *next;
}Qnode,*QnodePtr;

typedef struct
{
	QnodePtr  front;
    QnodePtr rear;
}LinkQueue;

void InitQueue( LinkQueue *Q )//初始化
{
	Qnode *HeadNode;
	HeadNode = (Qnode *)malloc(sizeof(Qnode));//分配空间
	HeadNode->next=NULL;
	Q->rear = Q->front=HeadNode;

}

bool IsEmpty(LinkQueue Q )
{
	if(Q.rear==Q.front) return true;
	else return false;
}


int GetLength(LinkQueue Q)
{
    Qnode *p;
    p=Q.front;
    //声明一个变量用来记录队列当前长度
    int length=0;
    while(p->next)//当指针p所指的节点不为空时执行循环体
    {
        length++;
        p=p->next;
    }
	printf("当前队列的长度为 %d \n",length);
    return length;
}


void Push( LinkQueue *Q, ElemType e)  
{
	Qnode *p;
    p=(Qnode*)malloc(sizeof(Qnode));
	p->data = e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
}

bool Pop( LinkQueue *Q, ElemType *e)  
{
	if( IsEmpty( *Q ) ) // 栈空
        return false; 	
	*e = Q->front->next->data;
	printf("队列首元素为 %d \n",Q->front->next->data);

	QnodePtr p = Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p) Q->rear=Q->front;
	free(p);
	return true;
}

ElemType GetTop(LinkQueue Q)  
{
	if( IsEmpty( Q ) ) 
        return false; 
	return Q.front->next->data;
}

int main(){
    LinkQueue Q;
    ElemType e;
    InitQueue(&Q);

    Push(&Q,1);
    Push(&Q,2);
    Push(&Q,3);
    Push(&Q,4);
	GetLength( Q );

	Pop(&Q, &e);
	Pop(&Q, &e);
	GetLength( Q );

    Push(&Q,5);
    Push(&Q,6);
    Push(&Q,7);   

	Pop(&Q, &e);
    Pop(&Q, &e);
	Pop(&Q, &e);

	ElemType x=GetTop(Q);
	printf("%d \n",x);
	
	Pop(&Q, &e);

    return 0;
}

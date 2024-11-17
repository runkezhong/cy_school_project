# include <stdio.h>
# include <stdlib.h>
#include<stdbool.h>
#define  MAXSIZE  100
#define  ElemType  int

typedef struct
{
	int   front;
	int   rear;
	ElemType *base;
	int capacity;
}SqQueue;

void InitQueue( SqQueue *Q, int n )//初始化
{
	Q->base =(ElemType *)malloc(n * sizeof(ElemType));//分配空间
	if( !Q->base )  {printf("InitQueue failed"); exit(1);}//分配失败报错
	Q->rear = Q->front=0;
	Q->capacity = n;
}

bool QueueFull(SqQueue Q )
{
	if((Q.rear+1)%Q.capacity==Q.front) return true;
	else return false;
}

bool QueueEmpty(SqQueue Q )
{
	if(Q.rear==Q.front) return true;
	else return false;
}

int QueueLength( SqQueue Q )
{
	return (Q.rear-Q.front+Q.capacity)%Q.capacity;
}

bool ClearQueue( SqQueue *Q )
{
	if( Q->base ) Q->rear = Q->front=0;
	printf("Queue was cleared \n");
	return true;
}

bool DestroyQueue( SqQueue *Q )
{
	if( Q->base )
	{
		free ( Q->base ) ;
		Q->capacity = 0;
		Q->base =  NULL;
	}
	printf("Queue was destroyed \n");
  return true;
}

bool Push( SqQueue *Q, ElemType e)  
{
	if( QueueFull( *Q ) ) // 栈满
        return false; 	
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1) % Q->capacity;
	return true;
}

bool Pop( SqQueue *Q, ElemType *e)  
{
	if( QueueEmpty( *Q ) ) // 栈空
        return false; 	
	*e= Q->base[Q->front];
	Q->front=(Q->front+1) % Q->capacity;
	return true;
}

ElemType GetTop(SqQueue Q)  
{
	if( QueueEmpty( Q ) )	 return false; 	// 栈空
	return Q.base[Q.front];
}

int main(){
    SqQueue Q;
    ElemType e;
	// printf("%d,%d\n",Q.front,Q.rear);
    InitQueue(&Q, 10);//初始化
	// printf("%d,%d\n",Q.front,Q.rear);


    Push(&Q,1);
    Push(&Q,2);
    Push(&Q,3);
    Push(&Q,4);

	Pop(&Q, &e);
    // printf("Queue out:%d \n", e);
	Pop(&Q, &e);
    // printf("Queue out:%d \n", e);

    Push(&Q,5);
    Push(&Q,6);
    Push(&Q,7);   
	printf("Queue Lenth is %d \n " ,QueueLength( Q ));

	Pop(&Q, &e);
    printf("Queue out:%d \n", e);
    Pop(&Q, &e);
    printf("Queue out:%d \n", e);
	Pop(&Q, &e);
    printf("Queue out:%d \n", e);

	ElemType x=GetTop(Q);
	printf("Queue Lenth is %d \n " ,QueueLength( Q ));
	printf("%d \n",x);
	
	Pop(&Q, &e);
    printf("Queue out:%d \n", e);
	printf("Queue Lenth is %d \n " ,QueueLength( Q ));
	
	ClearQueue(&Q);
	printf("Queue Lenth is %d \n " ,QueueLength( Q ));
	Pop(&Q, &e);
    printf("Queue out:%d \n", e);

	DestroyQueue(&Q);
	printf("Queue Lenth is %d \n " ,QueueLength( Q ));
	Pop(&Q, &e);
    printf("Queue out:%d \n", e);
    return 0;
}

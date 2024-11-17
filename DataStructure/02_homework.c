/*
已知两个链表A 和B 分别表示两个集合，其元素递增排列。请设计算法求出A 与B
的交集，并存放于A 链表中。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 定义队列的最大容量
#define MAXSIZE 100
// 定义队列元素的类型
#define ElemType int

// 结构体定义链队列的节点，包含数据域data和下一个节点的指针next
typedef struct Qnode {
    ElemType data;
    struct Qnode *next;
} Qnode, *QnodePtr; // QnodePtr是Qnode类型的指针
// LinkQueue结构体定义链队列
typedef struct {
    QnodePtr front;
    QnodePtr rear;
} LinkQueue;
// 初始化队列
/*
分配一个头节点 HeadNode，将next的指针设置为NULL
队列的front和rear指针都指向头节点，表示队列为空
*/
void InitQueue(LinkQueue *Q) {
    Qnode *HeadNode = (Qnode *)malloc(sizeof(Qnode));
    HeadNode->next = NULL;
    Q->rear = Q->front = HeadNode;
}
// 入队操作
int Push(LinkQueue *Q, ElemType e) {
    Qnode *p = (Qnode *)malloc(sizeof(Qnode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}
// 求两个链表的交集，结果存放在链表A中
void IntersectionOfLists(LinkQueue *A, LinkQueue B){
    Qnode *pa = A->front->next;
    Qnode *pb = B.front->next;
    Qnode *prevA = A->front;

    while (pa && pb) {
        if (pa->data < pb-> data) {
            //删除A中较小的元素
            Qnode *temp = pa;
            pa = pa->next;
            prevA->next = pa;
            free(temp);
        } else if (pa->data > pb->data) {
            // B中元素较小，移动
            pb = pb->next;
        } else {
            // 元素相等，保留A中
            prevA = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }

    while (pa) {
        Qnode *temp = pa;
        pa = pa->next;
        prevA->next = pa;
        free(temp);
    }
    A->rear = prevA;
}
// 打印链表
void PrintList(LinkQueue Q) {
    Qnode *p = Q.front->next;
    while (p) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    LinkQueue A, B;
    ElemType e;
    // 初始化
    InitQueue(&A);
    InitQueue(&B);

    // 添加元素
    Push(&A, 1);Push(&A, 2);Push(&A, 3);Push(&A, 4);
    Push(&B, 2);Push(&B, 4);Push(&B, 6);

    // 打印链表
    PrintList(A);
    PrintList(B);
    // 求交集
    IntersectionOfLists(&A, B);
    PrintList(A);
}
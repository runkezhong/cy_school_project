#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// 顺序栈的结构定义
typedef struct {
    int data[MAXSIZE];
    int top;
} Stack;

// 顺序站的初始化
void InitStack(Stack *S) {
    S->top = -1;
}

// 顺序栈进栈操作
int Push(Stack *S, int x) {
    if (S->top == MAXSIZE - 1) {
        return 0;
    }
    S->data[++S->top] = x;
    return 1;
}

// 顺序栈出栈操作
int Pop(Stack *S, int *x) {
    if (S->top == -1) {
        return 0;
    }
    *x = S->data[S->top--];
    return 1;
}

// 顺序栈是否为空
int StackEmpty(Stack *S) {
    return S->top == -1;
}

void PrintStack(Stack *S) {
    while (!StackEmpty(S)) {
        int x;
        Pop(S, &x);
        printf("%d ", x);
    }
    printf("\n");
}

int main() {
    Stack S;
    InitStack(&S);
    printf("初始化顺序栈\n");
    // 任务1
    for (int i=1;i<=5;i++){
        Push(&S, i);
    }
    printf("出栈序列");
    PrintStack(&S);

    // 初始化顺序栈
    InitStack(&S);
    Push(&S, 3);
    Push(&S, 2);
    Push(&S, 1);
    printf("进栈：3 2 1\n");
    int s;
    Pop(&S, &s);
    printf("出栈：%d\n", s);
    Pop(&S, &s);
    printf("出栈：%d\n", s);
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Push(&S, 7);
    printf("进栈：4 5 6 7\n");

    printf("全部出栈：");
    PrintStack(&S);
}


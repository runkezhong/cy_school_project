#include <stdio.h>
#define MaxSize 50

typedef int ElemType;
typedef struct SqList
{
    ElemType data[MaxSize];
    int length
} SqList;

// 初始化顺序表
void InitList(SqList *L)
{
    L->length = 0;
}

// 打印顺序表
void PrintList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 插入元素
int InsertElement(SqList *L, int index, ElemType element)
{
    // 校验
    if (L->length >= MaxSize)
    {
        printf("顺序表已满，无法插入\n");
        return 0;
    }
    if (index < 1 || index > L->length + 1)
    {
        printf("插入位置不合法\n");
        return 0;
    }
    // 循环插入数据
    for (int i = L->length - 1; i >= index - 1; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[index - 1] = element;
    L->length++;
    return 1;
}

// 删除元素
int DeleteElement(SqList *L, int index)
{
    if (index < 1 || index > L->length)
    {
        printf("删除位置不合法\n");
        return 0;
    }
    for (int i = index; i < L->length; i++)
    {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return 1;
}

int main()
{
    SqList L;
    printf("创建顺序表L\n");
    InitList(&L);
    printf("初始化成功\n");
    // 模拟键盘输入数据
    int elements[] = {21, 18, 30, 75, 42, 56};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++)
    {
        InsertElement(&L, i + 1, elements[i]);
    }

    printf("顺序表的元素有：");
    PrintList(&L);

    if (InsertElement(&L, 3, 67))
    {
        printf("在第3个位置插入67成功\n");
    }
    else
    {
        printf("在第3个位置插入67失败\n");
    }
    if (InsertElement(&L, 9, 10))
    {
        printf("在第9个位置插入10成功\n");
    }
    else
    {
        printf("在第9个位置插入10失败\n");
    }

    printf("插入后的顺序表为：");
    PrintList(&L);

    if (DeleteElement(&L, 6))
    {
        printf("删除第6个元素成功\n");
    }
    else
    {
        printf("删除第6个元素失败\n");
    }
    if (DeleteElement(&L, 8))
    {
        printf("删除第8个元素成功\n");
    }
    else
    {
        printf("删除第8个元素失败\n");
    }

    printf("删除后的顺序表中的元素：");
    PrintList(&L);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElementType;
typedef struct LNode *List;

struct LNode // 线性表结构体
{
    ElementType data[MAXSIZE];
    int Last;
};

List MakeEmpty() // 初始化线性表
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

void Insert(ElementType e, int i, List Ptrl) // 向线性表位置i处中插入元素
{
    int j;
    if(Ptrl->Last+1 >= MAXSIZE)
    {
        printf("List is FULL!\n");
        return;
    }
    if(i > Ptrl->Last+2 || i < 1)
    {
        printf("Insert location illegal!\n");
        return;
    }
    for(j=Ptrl->Last; j>= i-1 ; j--)
    {
        Ptrl->data[j+1] = Ptrl->data[j];
    }
    Ptrl->data[i-1] = e;
    Ptrl->Last++;
    return;
}

void Delete(int i, List Ptrl)
{
    ElementType e;
    int j;
    if(Ptrl->Last < 0)
    {
        printf("List is EMPTY!");
        return;
    }
    if(i<1 || i>Ptrl->Last+1)
    {
        printf("Delete location illegal!\n");
        return;
    }
    for(j=i-1; j<=Ptrl->Last-1; j++)
    {
        Ptrl->data[j] = Ptrl->data[j+1];
    }
    Ptrl->Last--;
    return;
}

void PrintList(List Ptrl) // 打印线性表的所有元素
{
    int i;
    for(i=0; i<=Ptrl->Last; i++)
    {
        printf("DATA[%d]: %d ; ", i, Ptrl->data[i]);
    }
    printf("\n");
    return;
}
void PrintListLength(List Ptrl) // 打印线性表的长度
{
    int i;
    i = Ptrl->Last+1;
    printf("List Length: %d\n", i);
}

void PrintListInfo(List Ptrl)
{
    printf("-----------------\n");
    PrintListLength(Ptrl);
    printf("-----------------\n");
    PrintList(Ptrl);
    printf("=================\n");
    return;
}

int main()
{
    int i;
    List p = MakeEmpty();
    PrintListInfo(p);
    for(i=1; i<=22; i++)
    {
        Insert(i, 1, p);
        PrintListInfo(p);
    }
    for(i=1; i<=22; i++)
    {
        Delete(1, p);
        PrintListInfo(p);
    }
    system("pause");
    return 0;
}
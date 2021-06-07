#include<stdio.h>
#include<stdlib.h>
typedef struct LNode *List;
typedef int ElementType;

struct LNode
{
    ElementType data;
    List next;
};

List MakeEmpty()
{
    //构造一个头结点
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->next = NULL;
    return Ptrl;
}

int Length(List Ptrl)
{
    int i = 0;
    List p = Ptrl;
    while(p->next){
        i++;
        p = p->next;        
    }
    return i;
}

void Insert(ElementType e, int i, List Ptrl)
{
    return;
}
int main()
{
    List p = MakeEmpty();
    printf("List length: %d\n", Length(p));
    Insert(10, 1, p);
    system("pause");
    return 0;
}
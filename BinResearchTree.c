#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct TNode *BSTree;
struct TNode
{
    ElementType data;
    BSTree Left;
    BSTree Right;
};

BSTree CreateTree()
{
    BSTree t;
    t = (BSTree)malloc(sizeof(struct TNode));
    t->data = 0;
    t->Left = NULL;
    t->Right = NULL;
    return t;
}

int main()
{
    BSTree tree = CreateTree();
    printf("%d\n", tree->data);
    system("pause");
    return 0;
}
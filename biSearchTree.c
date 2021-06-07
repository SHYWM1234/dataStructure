#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct treeNode *Tree;
struct treeNode
{
    Tree lchild;
    Tree rchild;
    ElementType data;
    int flag;
};

Tree NewNode(int V)
{
    Tree T = (Tree)malloc(sizeof(struct treeNode));
    T->data = V;
    T->lchild = T->rchild = NULL;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T, int V)
{
    if(!T) T = NewNode(V);
    else{
        if(V > T->data){
            T->rchild = Insert(T->rchild, V);
        }
        else
        {
            T->lchild = Insert(T->lchild, V);
        }
        return T;
        
    }
}

Tree MakeTree(int N)
{
    Tree T;
    int i, V;
    scanf("%d", &V);
    T = NewNode(V);
    for(i = 1; i< N; i++){
        scanf("%d", &V);
        T = Insert(T, V);
    }
    return T;
}

int check(Tree T, int V)
{
    if(T->flag)
    {
        if(V < T->data) return check(T->lchild, V);
        else if(V > T->data) return check(T->rchild, V);
        else return 0;
    }
    else 
    {
        if(V == T->data)
        {
            T->flag = 1;
            return 1;
        }
        else 
        {
            return 0;
        }
    }
}

int Judge(Tree T, int N)
{
    int i, V, flag =0;
    scanf("%d", &V);
    if(V!=T->data) flag = 1;
    else T->flag = 1;
    for(i=1; i<N; i++)
    {
        scanf("%d", &V);
        if((!flag) && (!check(T, V))) flag = 1;
    }
    if(flag) return 0;
    else return 1;

}

void ResetT(Tree T)
{
    if(T->lchild) ResetT(T->lchild);
    if(T->rchild) ResetT(T->rchild);
    T->flag = 0;
}

void FreeTree(Tree T)
{
    if(T->lchild) FreeTree(T->lchild);
    if(T->rchild) FreeTree(T->rchild);
    FreeTree(T);
}

int main()
{
    int N, L, i;
    Tree T;
    scanf("%d", &N);
    while(N)
    {
        scanf("%d", &L);
        T = MakeTree(N);
        for(i = 0; i<L; i++);
        {
            if(Judge(T, N)) printf("Yes\n");
            else printf("No\n");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d", &N);

    }

    system("pause");
    return 0;
}
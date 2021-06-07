// 后续遍历 中序遍历 ——>先序遍历
#include<bits/stdc++.h>
using namespace std;
 
int mid[33],post[33];
 
typedef int Status;
//树的储存结构定义
typedef struct BiTNode{
   int data;//结点的值
   struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
BiTree Creat(int *mid,int *post,int n){//根据后序和中序求出树
   if(n<1)return NULL;//如果输入出错
 
   int *p = mid;//寻找中序中的根结点
 
   while(p){
   if(*p== *(post+n-1))
   break;
   p++;
   }//p为中序中第一个根结点
 
   BiTree T =(BiTree)malloc(sizeof(BiTNode));//开辟空间
 
   T->data=*p;//p为第一个根结点
   int len = p-mid;
   //递归
   T->lchild= Creat(mid,post,len);
   T->rchild = Creat(p+1,post+len,n-len-1);
   return T;
 
 
 
}
 
void Print(BiTree T){
if(T){
   cout<<" "<<T->data;
   Print(T->lchild);
   Print(T->rchild);
 
}
return;
 
 
}
 
int main(){
   int n;
   BiTree T;
   cin>>n;
   //输入两个储存后序和中序的数组
   for(int i=0;i<n;i++){
       cin>>post[i];
   }
   for(int j=0 ;j < n;j++){
       cin>>mid[j];
   }
   T = Creat(mid,post,n);
   //将树前序输出
   cout<<"Preorder:";
   Print(T);
 
 
}
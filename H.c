#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int yinShu[1000];

int isPrime(int num)
{
    /* 需要保证num大于2 */

    int a, i;
    int yinshu_index=0;
    int flag=1;
    for(int i=2;i<num;i++){
    if(num%i==0){
        flag=0;
        yinShu[yinshu_index] = i;
        yinshu_index++;
    }
    }
    yinShu[yinshu_index]=-1; // 标记因数结束
    return flag;
}

int isSquare(int num){
    int flag=0; // 0 不是完全平方数； 1 是完全平方数
    int sq = (int)sqrt(num);
    if(sq*sq == num){
        flag=1;
    }
    return flag;
}

int main()
{
    int i, j;
    int order=0;
    int multi;

    
    for(i=3; i<8000; i++)
    {
        if(isPrime(i)==0){ 
            // 不是质数，满足第一个条件
            // printf("%d:  NO, ", i);
            for(j=0; yinShu[j]!=-1; j++){
                multi = yinShu[j] * i;
                if(isSquare(multi)==1){
                    
                    order++;
                    printf("the %d th ZHSZ %d\n", order, i);
                    
                    /*
                   if(order==3000){
                       printf("%d", i);
                   }*/
                   break;
                }
            }
            // printf("\n");
        }else{
            // printf("%d:  Yes\n", i);
        }
    }


    
    system("pause");
    return 0;
    
}
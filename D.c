#include<stdio.h>
#include<stdlib.h>
int list[40001];
int listLen, quesNum;

void readData()
{
    int i;
    printf("please input n and q: ");
    scanf(" %d %d", &listLen, &quesNum);
    printf("please input list: \n");
    for(i=0; i<listLen; i++)
    {
        scanf("%d", &list[i]);
    }
    list[i] = -1; // 结束标记
}
int main()
{
    int i, j;
    int l, r, k;
    readData();
    printf("listLen: %d  ; quesNum: %d \n", listLen, quesNum);
    for(i=0; i<=listLen; i++){
        printf(" %d", list[i]);
    }
    printf("\n");

    printf("please input quest\n");
    /* 读问题，写答案 */
    for(i=0; i<quesNum; i++){
        printf("input the %d th ques: ", i+1);
        /* 读入一个问题 */
        scanf(" %d %d %d", &l, &r, &k);
    
        printf("quest %d :%d %d %d\n", i+1, l, r, k);
        /* 遍历list 输出该问题的答案 */
    }

    system("pause");
    return 0;

}
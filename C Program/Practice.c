#include<stdio.h>

int main()
{
    int x,y,i,j;
    int a[50][50];

    printf("Enter the Row and Column:\n");
    scanf("%d%d",&x,&y);
    printf("Enter the values for matrix:\n");
    for (i=0 ; i<x ; i++)
    {
        for(j=0 ; j<y ; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("The matrix is as follows:\n");
    for (i=0 ; i<x ; i++)
    {
        for(j=0 ; j<y ; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0 ;
}
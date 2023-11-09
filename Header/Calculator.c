#include<stdio.h>
#include "calculator.h"

int main()
{
    int a,b,c,choice;

    do
    {
        printf("\n1.Add\n2.Sub\n3.Mul");
        printf("\nEnter the operation to perform:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the 2 numbers:");
            scanf("%d%d",&a,&b);
            c = add(a,b);
            printf("The sum is:%d",c);
            break;
        
        case 2:
            printf("Enter the 2 numbers:");
            scanf("%d%d",&a,&b);
            c = sub(a,b);
            printf("The sub is:%d",c);
            break;

        case 3:
            printf("Enter the 2 numbers:");
            scanf("%d%d",&a,&b);
            c = mul(a,b);
            printf("The mul is:%d",c);
            break;

        default:
            printf("Invalid input");
            break;
        }
    } while (choice<4);
    return 0;
}



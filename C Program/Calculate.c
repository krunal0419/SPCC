#include<stdio.h>
#include "Calculator.h"

int main()
{
    int a,b,c,d,e,f,g,choice;
    float h,j;
    do{

        printf("\n\nSelect the Operation\n");
        printf("1.Addition\n2.Subtract\n3.Multiplication\n4.Division\n5.Power\n6.Square Root\n7.Cube Root\n8.Exit\n");
        printf("Enter the choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the two numbers :");
                scanf("%d%d",&a,&b);
                c=add(a,b);
                printf("The addition of %d %d is :%d",a,b,c);
                break;

            case 2:
                printf("Enter the two numbers :");
                scanf("%d%d",&a,&b);
                d=sub(a,b);
                printf("The subtraction of %d %d is :%d",a,b,d);
                break;

            case 3:
                printf("Enter the two numbers :");
                scanf("%d%d",&a,&b);
                e=mul(a,b);
                printf("The multiplication of %d %d is :%d",a,b,e);
                break;

            case 4:
                printf("Enter the two numbers :");
                scanf("%d%d",&a,&b);
                f=div(a,b);
                printf("The division of %d %d is :%d",a,b,f);
                break;

            case 5:
                printf("Enter the number :");
                scanf("%d",&a);
                g=power(a);
                printf("The power of %d is :%d",a,g);
                break;

            case 6:
                printf("Enter the number :");
                scanf("%d",&a);
                h=squarert(a);
                printf("The square root of %d is :%f ",a,h);
                break;

            case 7:
                printf("Enter the number :");
                scanf("%d",&a);
                j=cubert(a);
                printf("The cube root of %d is :%f ",a,j);
                break;

            default :
                printf("Program ends here");
        }
    }while(choice<8);
    return 0;
}

#include<stdio.h>
#include"Area.h"

int main()
{
    int choice,a,b;
    float c;

    do
    {
        printf("\n\n1.Square\n2.Rectangle\n3.Tringle\n4.Circle\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value of side:");
            scanf("%d",&a);
            c = square(a);
            printf("The value of square is:%f",c);
            break;
        
        case 2:
            printf("Enter the value of sides:");
            scanf("%d%d",&a,&b);
            c = rectangle(a,b);
            printf("The value of rect is:%f",c);
            break;

        case 3:
            printf("Enter the value of sides:");
            scanf("%d%d",&a,&b);
            c = tringle(a,b);
            printf("The value of tringle is:%f",c);
            break;
        
        case 4:
            printf("Enter the value of radius:");
            scanf("%d",&a);
            c = circle(a);
            printf("The value of area is:%f",c);
            break;
        
        default:
            printf("Invalid input");
            break;
        }
    } while (choice<5);
    
    return 0;
}

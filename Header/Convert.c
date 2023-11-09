#include<stdio.h>
#include "Convert.h"

int main()
{
    int choice;
    float a, c;

    do
    {
        printf("\n\n1.F to C\n2.C to F\n3.Ft to Mt\n4.Mt to Ft\n5.Cu to Lt\n6.Lt to Cu\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value:");
            scanf("%f",&a);
            c = cel(a);
            printf("The tem in fah is:%f",c);
            break;
        
        case 2:
            printf("Enter the value:");
            scanf("%f",&a);
            c = fah(a);
            printf("The tem in cel is:%f",c);
            break;

        case 3:
            printf("Enter the value:");
            scanf("%f",&a);
            c = mt(a);
            printf("The len in feet is:%f",c);
            break;

        case 4:
            printf("Enter the value:");
            scanf("%f",&a);
            c = ft(a);
            printf("The len in mt is:%f",c);
            break;

        case 5:
            printf("Enter the value:");
            scanf("%f",&a);
            c = lt(a);
            printf("The volume in lt is:%f",c);
            break;

        case 6:
            printf("Enter the value:");
            scanf("%f",&a);
            c = cu(a);
            printf("The vol in cu is:%f",c);
            break;
        
        default:
            break;
        }
        
    } while (choice<7);
    
    return 0;
}
#include<stdio.h>
#include "Area.h"

int main()
{
    int choice,a,b;
    float c,d,e,g;

    do
    {
        printf("\n\nEnter the choice to find area of\n");
        printf("1.Sqr\n2.Rec\n3.Tri\n4.Cir\n5.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value of side:");
                scanf("%d",&a);
                c=Square(a);
                printf("The area of square is:%f",c);
                break;

            case 2:
                printf("Enter the value of length and breadth:");
                scanf("%d%d",&a,&b);
                d=Rectangle(a,b);
                printf("The area of rectangle is:%f",d);
                break;

            case 3:
                printf("Enter the value of base and height:");
                scanf("%d%d",&a,&b);
                e=Triangle(a,b);
                printf("The area of triangle is:%f",e );
                break;

            case 4:
                printf("Enter the value of radius:");
                scanf("%d",&a);
                g=Circle(a);
                printf("The area of circle is:%f",g );
                break;

            default :
                printf("Program ends here");
        }
    } while (choice<5);

    return 0;
}

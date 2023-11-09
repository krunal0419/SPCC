#include<stdio.h>
#include "Convert.h"

int main()
{
    int choice,a;
    float b,c,d,e,f,g;

    do
    {
        printf("\n\nEnter the choice for Conversion\n");
        printf("1.C to F\n2.Meter to Feet\n3.Litre to Cubic Feet\n4.F to C\n5.Feet to Meter\n6.Cubic Feet to Litre\n7.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter the temperature in C:");
                scanf("%d",&a);
                b=Fharenheit(a);
                printf("The temperature in F is :%f ",b);
                break;

            case 2:
                printf("Enter the length in Meters:");
                scanf("%d",&a);
                c=Feet(a);
                printf("The length in Feet is :%f ",c);
                break;

            case 3:
                printf("Enter the volume in Litre:");
                scanf("%d",&a);
                d=CubicFeet(a);
                printf("The volume in Cubic Feet is :%f ",d);
                break;

            case 4:
                printf("Enter the temperature in F:");
                scanf("%d",&a);
                e=Celcius(a);
                printf("The temperature in C is :%f ",e);
                break;

            case 5:
                printf("Enter the length in Feet:");
                scanf("%d",&a);
                f=Meter(a);
                printf("The length in Meter is :%f ",f);
                break;

            case 6:
                printf("Enter the volume in Cubic Feet:");
                scanf("%d",&a);
                g=Litre(a);
                printf("The volume in Litre is :%f ",g);
                break;


            default :
                printf("Program ends here");
        }

    } while (choice<7);

    return 0;
}

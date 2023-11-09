#include <stdio.h>
#include <string.h>

int main() {
    char icode[10][10];
    char str[10], opr[5];
    int i = 0;
    printf("Enter the set of intermediate code (terminated by exit):\n");
    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);

    printf("\nTarget code generation\n");
    printf("\n\nStatements\tCode Generated\t  Register Descripter\tAddress Descripter");
    i = 0;
    do 
    {
        strcpy(str, icode[i]);
        switch (str[3])
        {
            case '+':
                strcpy(opr, "ADD ");
                break;
            case '-':
                strcpy(opr, "SUB ");
                break;
            case '*':
                strcpy(opr, "MUL ");
                break;
            case '/':
                strcpy(opr, "DIV ");
                break;
            default:
                strcpy(opr, "");
        }
        if(str[0]=='t' || str[0]=='u')
        {
            printf("\n%s\t\tMov %c,R%d", icode[i],str[2],i);
            printf("\n\t\t%s%c,R%d", opr, str[4], i);
        }
        else if(str[0]=='v')
        {
            printf("\n%s\t\tADD R0,R1",icode[i]);
        }
    }while (strcmp(icode[++i], "exit") != 0);
    return 0;
}


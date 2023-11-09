#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *ptr1,*ptr2,*ptr3,*ptr4,*ptr5,*fp;
    char opcode[20],label[20],operand[20],code[3],mnemonic[20],mcode[3],index1[2],adr[3],symbol[2],dubmcode[3],buffer[100];
    int lc,start,x,y;
    int index=0;
    ptr1=fopen("input.txt","r");
    ptr2=fopen("opcode.txt","r");
    ptr3=fopen("output.txt","w+");
    ptr4=fopen("symtab.txt","w+");
    ptr5=fopen("machine.txt","w+");
    fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
    fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
    fprintf(ptr3,"PASS-1 of the Two Pass Assembler\n");
    fprintf(ptr3,"=============================================================\n");
    fprintf(ptr3,"||ASSEMBLY PROGRAM     |LC \t|INTERMEDIATE CODE\t\n");
    fprintf(ptr3,"=============================================================\n");
    fprintf(ptr5,"PASS-2 of the Two Pass Assembler\n");
    fprintf(ptr5,"=============================================================\n");
    fprintf(ptr5,"||ASSEMBLY PROGRAM     |LC \t|MACHINE CODE\t\n");
    fprintf(ptr5,"=============================================================\n");


    //for comparing start opcode
    if(strcmp(opcode,"START")==0)
    {
        start=atoi(operand);
        lc=start;
        fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
        fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
        while(strcmp(mnemonic,"START")!=0)
        {
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
        }
        fprintf(ptr3,"\t(%s , %s)(c , %d)",code,mcode,lc);
        fprintf(ptr3,"\t\t\n");
        fprintf(ptr5,"\t  -\n");
        fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);

    }
    //while loop for read line of file
    while(strcmp(opcode,"END")!=0)
    {

        //for comparing ds
        if(strcmp(opcode,"DS")==0)
        {
            fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
            fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
            //FINDING DS IN opcode TABLE
            while(strcmp(mnemonic,"DS")!=0)
            {
                fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
                }
            fprintf(ptr3,"%d\t(S , %d)(%s , %s)(c , %s)",lc,index,code,mcode,operand);
            //TO STORE IN SYMBOL TABLE
            fprintf(ptr4,"  %d\t   %s\t   %d\n",index,label,lc);
            fprintf(ptr3,"\t\t\n");
            fprintf(ptr5,"%d\t  -\n",lc);
            index++;
            lc+=1;
            }

        // for comparing read
        if(strcmp(opcode,"READ")==0)
        {
            fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
            fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
            rewind(ptr2);
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            while(strcmp(mnemonic,"READ")!=0)
            {
                fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            }
            fprintf(ptr3,"%d\t(%s , %s)",lc,code,mcode);

            rewind(ptr4);
            fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            while(strcmp(symbol,operand)!=0)
            {
                fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            }
            if(strcmp(symbol,operand)==0)
            {
                fprintf(ptr3,"(S , %d)",x);
                x=index1[1];
                x++;
            }
            fprintf(ptr3,"\t\t\n",mcode,adr);
            fprintf(ptr5,"%d\t  %s 00 %s\n",lc,mcode,adr);
            lc+=1;
        }

        //for comparing areg register
        if(strcmp(opcode,"AREG")==0)
        {
            fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
            fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
            rewind(ptr2);
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            while(strcmp(mnemonic,label)!=0)
            {
                fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            }
            if(strcmp(mnemonic,label)==0)
            {
                fprintf(ptr3,"%d\t(%s , %s)",lc,code,mcode);
            }
            strcpy(dubmcode,mcode);
            rewind(ptr2);
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            while(strcmp(mnemonic,opcode)!=0)
            {
                fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            }
            fprintf(ptr3,"(%s , %s)",code,mcode);
            rewind(ptr4);
            fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            while(strcmp(symbol,operand)!=0)
            {
                fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            }

            if(strcmp(symbol,operand)==0)
            {
                fprintf(ptr3,"(S , %d)",x-1);
                x++;
            }

            fprintf(ptr3,"\t\n",dubmcode,mcode,adr);
            fprintf(ptr5,"%d\t  %s %s %s\n",lc,dubmcode,mcode,adr);
            lc+=1;
            
        }

        //for comparing print
        if(strcmp(opcode,"PRINT")==0)
        {
            fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
            fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
            rewind(ptr2);
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            while(strcmp(mnemonic,opcode)!=0)
            {
                fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
            }
            fprintf(ptr3,"%d\t(%s , %s)",lc,code,mcode);

            rewind(ptr4);
            fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            while(strcmp(symbol,operand)!=0)
            {
                fscanf(ptr4,"%s\t%s\t%s",index1,symbol,adr);
            }
            if(strcmp(symbol,operand)==0)
            {
                
                fprintf(ptr3,"(S , %d)",--index);
            }

            fprintf(ptr3,"\t\t\n",mcode,adr);
            fprintf(ptr5,"%d\t  %s 00 %s\n",lc,mcode,adr);
            lc+=1;
        }

        fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);

    }
    //for string compariing end
    if(strcmp(opcode,"END")==0)
    {
        fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
        fprintf(ptr5,"%s\t%s\t%s\t",label,opcode,operand);
        rewind(ptr2);
        fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
        while(strcmp(mnemonic,opcode)!=0)
        {
            fscanf(ptr2,"%s\t%s\t%s",mnemonic,code,mcode);
        }
        fprintf(ptr3,"%d\t(%s , %s)",lc,code,mcode);
        fprintf(ptr3,"\t\t\t");
        fprintf(ptr5,"%d\t  -",lc);
    }
        
    //to close file
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    fclose(ptr5);

    printf("\n");
    ptr3 =  fopen("output.txt", "r");
        while (fgets(buffer, sizeof(buffer), ptr3) != NULL)
        printf("%s", buffer);
  
        printf("\n\n");

    ptr5 =  fopen("machine.txt", "r");
        while (fgets(buffer, sizeof(buffer), ptr5) != NULL)
        printf("%s", buffer);
        printf("\n\n");

    printf("SYMBOL TABLE\n");
    printf("INDEX\t|SYMBOL\t|ADDRESS\n");
    ptr4 =  fopen("symtab.txt", "r");
        while (fgets(buffer, sizeof(buffer), ptr4) != NULL)
        printf("%s", buffer);
    printf("\n");
    printf("Created by Krunal Patel");

 return 0;
}




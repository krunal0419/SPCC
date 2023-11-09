#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *ptr1,*ptr2,*ptr3,*ptr4,*ptr5,*ptr6;
    char opcode[20],label[20],operand[20],operand1[20],operand2[20],aid1,aid2;
    int index=1,mindex=1,id=1,aid=1,id2=1,mindex2=1,id3=1;
    ptr1=fopen("ip.txt","r");
    ptr2=fopen("MNT.txt","w+");
    ptr3=fopen("ALA.txt","w+");
    ptr4=fopen("MDT.txt","w+");
	ptr5=fopen("MDT2.txt","w+");
	ptr6=fopen("ALA2.txt","w+");
    fprintf(ptr2,"Index\tName\tMDT_Index\n");
    fprintf(ptr3,"Index\tArguments\n");
    fprintf(ptr4,"Index\tDefinitions\n");
	fprintf(ptr5,"Index\tDefinitions\n");
	fprintf(ptr6,"Index\tArguments\n");

    while(strcmp(opcode,"END")!=0){
		fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2);
		if(strcmp(opcode,"MACRO")==0)
    	{
		fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2);
		fprintf(ptr2,"%d\t\t%s\t\t%d\n",index,opcode,mindex);
		index++;

			if(operand1[0]=='&'||operand2[0]=='&')
			{
				fprintf(ptr4,"%d\t\t%s\t#%d\t",mindex,opcode,id);
				fprintf(ptr3,"%d \t\t%s\n",id,operand1);
				id++;
				fprintf(ptr4,"#%d\n",id);
				fprintf(ptr3,"%d \t\t%s\n",id,operand2);
				id++;

			}

			while(strcmp(opcode,"MEND")!=0){
				mindex++;
				fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2);
				if(strcmp(opcode,"MEND")==0){
					fprintf(ptr4,"%d\t\t%s\n",mindex,opcode);
					mindex++;
				}else{
				fprintf(ptr4,"%d\t\t%s\t%s\t#%d\n",mindex,opcode,operand1,aid);
				aid++;
			}}
			
		}	

	}
	printf("MNTC=%d\nMDTC=%d",index,mindex);

//PASS-2
	fseek(ptr1, 0, SEEK_SET);
	while (fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2) != EOF)
	{
		if(strcmp(opcode,"MACRO")==0)
		{
			fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2);
			if (strcmp(opcode,"ADD")==0 || strcmp(opcode,"SUB")==0) 
			{
				fprintf(ptr5,"%d\t\t%s\tDATA%d\tDATA%d\n",mindex2,opcode,id3,id3+1);
				fprintf(ptr6,"%d \t\tDATA%d\n",id2,id3);
				id2++;
				fprintf(ptr6,"%d \t\tDATA%d\n",id2,id3+1);
				id2++;
			}
			while(strcmp(opcode,"MEND")!=0){
				mindex2++;
				fscanf(ptr1,"%s\t%s\t%s\t%s",label,opcode,operand1,operand2);
				if(strcmp(opcode,"MEND")==0){
					fprintf(ptr5,"%d\t\t%s\n",mindex2,opcode);
					mindex2++;
				}
				else 
				{
				fprintf(ptr5,"%d\t\t%s\t%s\tDATA%d\n",mindex2,opcode,operand1,id3);
				}
			
			}
			
		}
	
	}	
	printf("\nMDTP=%d",mindex2);
	return 0;
}	
	




#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	FILE *ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
	char label[10],opcode[10],operand[10],label1[10],opcode1[10],operand1[10];
	char address1[3],mnemonic[3],dubmnemonic[3],dubmcode[3],dubmcode1[3],mcode[3],code[10],index1[2],address[3],symbol[10],add[3];
	int lc,start,lc2,index,index2;
	ptr1=fopen("input.txt","r");
	ptr2=fopen("opcode.txt","r");
	ptr3=fopen("pass1.txt","w+");
	ptr4=fopen("pass2.txt","w");
	ptr5=fopen("symbol.txt","w+");
	index=0;
	index2=0;
	//pass 1
	fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		lc=start;
		fprintf(ptr3,"%s\t%s\t%s\t",label,opcode,operand);
		fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		while(strcmp(code,"START")!=0)
		{
			fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		}
		if(strcmp(code,"START")==0)
		{
			fprintf(ptr3,"\t(%s %s)(c %s)",mnemonic,mcode,operand);
		}
		fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
	}
	while(strcmp(opcode,"END")!=0)
	{
		rewind(ptr2);
		fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		while(strcmp(code,opcode)!=0)
		{ 
			fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		}
		strcpy(dubmnemonic,mnemonic);
		strcpy(dubmcode,mcode);
		if(strcmp(opcode,code)==0)
		{
			if(strcmp(opcode,"DS")==0)
		    {
			    fprintf(ptr3,"\n%s\t%s\t%s\t%d",label,opcode,operand,lc);
			    rewind(ptr5);
			    fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
			    while(!feof(ptr5) && ptr5!=NULL)
			   	{
			    	if(strcmp(symbol,label)==0)
			        {
			            break;
					}
					fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
				}
			    if(strcmp(symbol,label)==0)
			    {
			   	    fprintf(ptr5,"%s\t%s\t%d",index1,symbol,lc);
				}
				else if(strcmp(symbol,label)!=0){
					fprintf(ptr5,"%d\t%s\t%d\n",index,label,lc);
					index+=1;
				}
			    rewind(ptr2);
			    fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
			    while(strcmp(code,"DS")!=0)
			    {
				    fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
			    }
			    if(strcmp(code,"DS")==0)
			    {
				    fprintf(ptr3,"\t(S, %d)(%s %s)(c,%s)",index-1,mnemonic,mcode,operand);
			    }			
		    }
		    else{
		    	fprintf(ptr3,"\n%s\t%s\t%s\t%d",label,opcode,operand,lc);
			    if(strcmp(label,"*")==0)
			    {
				    fprintf(ptr3,"\t");
				}
				else{
				    rewind(ptr2);
				    fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
				    while(strcmp(code,label)!=0)
				    {
			            fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		            }
				    if(strcmp(code,label)==0)
				    {
					    fprintf(ptr3,"\t(%s %s)",mnemonic,mcode);
				    }		
			    }
			    fprintf(ptr3,"(%s %s)",dubmnemonic,dubmcode);
			    rewind(ptr5);
			    fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
			    while(!feof(ptr5))
			   	{
			    	if(strcmp(symbol,operand)==0)
			        {
			            break;
					}
					fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
				}
			    if(strcmp(symbol,operand)==0)
			    {
				    fprintf(ptr3,"(S, %d)",index2);
					index2+=1;
			    }
			    else{
			    	fprintf(ptr5,"%s\t%s\t%d",index1,operand,start);
			    	fprintf(ptr3,"(S, %d)",index2);
					
				}
			}	
		}
		lc+=1;
		fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
	}
	if(strcmp(opcode,"END")==0)
	{
		fprintf(ptr3,"\n%s\t%s\t%s\t%d",label,opcode,operand,lc);
		rewind(ptr2);
		fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode); 
		while(strcmp(code,opcode)!=0)
		{
			fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		}
		if(strcmp(code,opcode)==0)
		{
			fprintf(ptr3,"\t(%s %s)",mnemonic,mcode);
		}
	}
	
	 
	//for pass2
	rewind(ptr1);
	fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		lc2=start;
		fprintf(ptr4,"%s\t%s\t%s\t",label,opcode,operand);
		rewind(ptr2);
		fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		while(strcmp(code,"START")!=0)
		{
			fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		}
		if(strcmp(code,"START")==0)
		{
			fprintf(ptr4,"\t-");
		}
		fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
	}
	while(strcmp(opcode,"END")!=0)
	{
		rewind(ptr2);
		fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		while(strcmp(code,opcode)!=0)
		{
			fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		}
		strcpy(dubmcode,mcode);
		if(strcmp(code,opcode)==0)
		{
			if(strcmp(opcode,"DS")==0)
			{
				fprintf(ptr4,"\n%s\t%s\t%s\t%d\t-",label,opcode,operand,lc2);
			}
			else{
				fprintf(ptr4,"\n%s\t%s\t%s\t%d\t",label,opcode,operand,lc2);
				if(strcmp(label,"*")!=0)
				{
					rewind(ptr2);
				    fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
			     	while(strcmp(code,label)!=0)
				    {
			            fscanf(ptr2,"%s\t%s\t%s",code,mnemonic,mcode);
		            }
				    if(strcmp(code,label)==0)
					    fprintf(ptr4,"%s %s ",mcode,dubmcode);
				}
				else{
					fprintf(ptr4,"%s 00 ",dubmcode);
				}
				rewind(ptr5);
				fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
				while(strcmp(symbol,operand)!=0)
				{
					fscanf(ptr5,"%s\t%s\t%s",index1,symbol,address);
				}
				if(strcmp(symbol,operand)==0)
				{
					fprintf(ptr4,"%s",address);
				}
			}	
		}
		fscanf(ptr1,"%s\t%s\t%s",label,opcode,operand);
		lc2+=1;
	}
	if(strcmp(opcode,"END")==0)
	{
		fprintf(ptr4,"\n%s\t%s\t%s\t%d\t-",label,opcode,operand,lc2);
	}
	fclose(ptr1);fclose(ptr2);fclose(ptr3);fclose(ptr4);fclose(ptr5);
	return 0;
}

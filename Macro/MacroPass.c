#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mnt_1
{
	int id;
	char name[20];
	int mid;
};

int main()
{
	FILE *ptr1, *ptr2, *ptr3;
	struct Mnt_1 mnt1[10];
	char Ala1[5][10];
	char Ala2[5][10];
	char opcode[20], label[20], operand1[20], operand2[20];
	int index = 1, mindex = 1, rid = 1, rid2 = 1, a1 = 1;

	ptr1 = fopen("ip.txt", "r");
	ptr2 = fopen("Mdt_1.txt", "w+");
	ptr3 = fopen("Mdt_2.txt", "w+");

	fprintf(ptr2, "Index\tDefinitions\n");
	fprintf(ptr3, "Index\tDefinitions\n");

	while (strcmp(opcode, "END") != 0)
	{
		fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
		if (strcmp(opcode, "MACRO") == 0)
		{
			fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
			mnt1[index].id = index;
			strcpy(mnt1[index].name, opcode);
			mnt1[index].mid = mindex;
			index++;

			if (operand1[0] == '&' || operand2[0] == '&')
			{
				strcpy(Ala1[rid], operand1);
				fprintf(ptr2, "%d\t\t%s\t#%d\t", mindex, opcode, rid);
				rid++;
				strcpy(Ala1[rid], operand2);
				fprintf(ptr2, "#%d\n", rid);
				rid++;
			}
			while (strcmp(opcode, "MEND") != 0)
			{
				mindex++;
				fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
				if (strcmp(opcode, "MEND") == 0)
				{
					fprintf(ptr2, "%d\t\t%s\n", mindex, opcode);
					mindex++;
				}
				else
				{
					for (int i = 1; i < 6; i++)
					{
						if (strcmp(Ala1[i], operand2) == 0)
						{
							fprintf(ptr2, "%d\t\t%s\t%s\t#%d\n", mindex, opcode, operand1, i);
						}
					}
				}
			}
		}

		for (int i = 0; i < 6; i++)
		{
			if (strcmp(mnt1[i].name, opcode) == 0)
			{
				strcpy(Ala2[rid2], operand1);
				rid2++;
				strcpy(Ala2[rid2], operand2);
				rid2++;
			}
		}
	}

	printf("ALA-1\nId\tArgument\n");
	for (int i = 1; i < 5; i++)
	{
		printf("%d\t%s\n", i, Ala1[i]);
	}
	printf("\nALA-2\nId\tArgument\n");
	for (int i = 1; i < 5; i++)
	{
		printf("%d\t%s\n", i, Ala2[i]);
	}
	printf("\nMNT\nId\tName\tMindex\n");
	for (int i = 1; i < 3; i++)
	{
		printf("%d\t%s\t%d\n", mnt1[i].id, mnt1[i].name, mnt1[i].mid);
	}

	int var;
	rewind(ptr1);
	fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
	while (strcmp(opcode, "END") != 0)
	{
		fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
		if (strcmp(opcode, "MACRO") == 0)
		{
			fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
			for (int i = 1; i < 6; i++)
			{
				if (strcmp(Ala1[i], operand1) == 0 && strcmp(Ala1[i + 1], operand2) == 0)
				{
					fprintf(ptr3, "%d\t\t%s\t\t%s\t%s\n", a1++, opcode, Ala2[i], Ala2[i + 1]);
					var = i;
					fscanf(ptr1, "%s\t%s\t%s\t\t%s", label, opcode, operand1, operand2);
					break;
				}
			}

			while (strcmp(opcode, "MEND") != 0)
			{
				if (strcmp(Ala1[var], operand2) == 0)
				{
					fprintf(ptr3, "%d\t\t%s\t\t%s\t\t%s\n", a1++, opcode, operand1, Ala2[var]);
				}
				else if (strcmp(Ala1[var + 1], operand2) == 0)
				{
					fprintf(ptr3, "%d\t\t%s\t\t%s\t\t%s\n", a1++, opcode, operand1, Ala2[var + 1]);
				}
				fscanf(ptr1, "%s\t%s\t%s\t%s", label, opcode, operand1, operand2);
			}
			fprintf(ptr3, "%d \t\t%s\n", a1++, opcode);
		}
	}
	printf("\nMDTC:%d\nMNTC:%d\nMDTP:%d", mindex, index, a1);
	return 0;
}
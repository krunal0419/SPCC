#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
char quad[MAX_SIZE][MAX_SIZE],trip[MAX_SIZE][MAX_SIZE],tripIndex[MAX_SIZE][MAX_SIZE];
int quadIndex = 0,tripIndexCount = 0;
void quadraple(char sp[MAX_SIZE][MAX_SIZE], int len) {
    int i;
    char result[MAX_SIZE], operator[MAX_SIZE]="", op1[MAX_SIZE]="", op2[MAX_SIZE]="";
    strcpy(result, sp[0]);
    for (i = 1; i < len; i++) {
        if (strcmp(sp[i], "*") == 0 || strcmp(sp[i], "-") == 0 || strcmp(sp[i], "+") == 0 || strcmp(sp[i], "/") == 0 || strcmp(sp[i], "=") == 0) {
            strcpy(operator, sp[i]);
        } else if (strlen(op1) == 0) {
            strcpy(op1, sp[i]);
        } else {
            strcpy(op2, sp[i]);
        }
    }
    sprintf(quad[quadIndex++], "%s\t\t%s\t\t%s\t\t%s", operator, op1, op2, result);
}
void triple(char sp[MAX_SIZE][MAX_SIZE], int len) {
    int i, k;
    char operator[MAX_SIZE], op1[MAX_SIZE]="", op2[MAX_SIZE]="";
    for (i = 1; i < len; i++) {
        k = -1;
        for (int j = 0; j < tripIndexCount; j++) {
            if (strcmp(tripIndex[j], sp[i]) == 0) {
                k = j;
                break;
            }
        }
        if (strcmp(sp[i], "*") == 0 || strcmp(sp[i], "-") == 0 || strcmp(sp[i], "+") == 0 || strcmp(sp[i], "/") == 0 || strcmp(sp[i], "=") == 0 ) {
            strcpy(operator, sp[i]);
        } else if (strlen(op1) == 0) {
            if (k != -1) {
                sprintf(op1, "(%d)", k);
            } else {
                strcpy(op1, sp[i]);
            }
        } else {
            if (k != -1) {
                sprintf(op2, "(%d)", k);
            } else {
                strcpy(op2, sp[i]);
            }
        }
    }
    strcpy(tripIndex[tripIndexCount], sp[0]);
    sprintf(trip[tripIndexCount++], "%s\t\t%s\t\t%s", operator, op1, op2);
}
int main() {
    char ip[MAX_SIZE];
    int nos;
    printf("Enter number of statement:");
    scanf("%d", &nos);
    printf("Enter the Statements:\n");
    fgets(ip, MAX_SIZE, stdin);
    for (int i = 0; i < nos; i++) {
        fgets(ip, MAX_SIZE, stdin);
        char sp[MAX_SIZE][MAX_SIZE];
        int len = 0;
        char *token = strtok(ip, " \t\n");
        while (token != NULL) {
            strcpy(sp[len++], token);
            token = strtok(NULL, " \t\n");
        }
        quadraple(sp, len);
        triple(sp, len);
    }
    printf("\nQuadraples:\nOperator\tOperand1\tOperand2\tResult\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%s\n", quad[i]);
    }
    printf("\nTriples:\nIndex\tOperator\tOperand1\tOperand2\n");
    for (int i = 0; i < tripIndexCount;i++){
         printf("%d\t%s\n", i,trip[i]);
    }
return 0;
}

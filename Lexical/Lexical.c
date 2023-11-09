#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOUNS 100

typedef enum { NOUN, VERB, IF, THEN, ACTION, EOF_TOKEN } TokenType;

typedef struct {
    TokenType type;
    char lexeme[10];
} Token;

typedef struct {
    char noun[10];
    int id;
} Symbol;

int numNouns = 0;
Symbol symbolTable[MAX_NOUNS];

int findSymbol(char* noun) {
    if (strcmp(noun, "they") == 0) {
        return -1; 
    }
    int i;
    for (i = 0; i < numNouns; i++) {
        if (strcmp(noun, symbolTable[i].noun) == 0) {
            return symbolTable[i].id;
        }
    }
    symbolTable[numNouns].id = numNouns + 1;
    strcpy(symbolTable[numNouns].noun, noun);
    numNouns++;
    return numNouns;
}

int main() {
    char input[] = "If dogs hate cats then they chase. If cats like milk then they drink.$";
    int len = strlen(input);
    int i = 0;
    Token token;
    int nounId;

    while (i < len) {
        if (isspace(input[i])) {
            i++;
            continue;
        }
        if (input[i] == '.') {
            printf("(op) ");
            i++;
            continue;
        }
        if (input[i] == 'I' && input[i+1] == 'f') {
            printf("(k) ");
            token.type = IF;
            strcpy(token.lexeme, "if");
            i += 2;
        }
        else if (input[i] == 't' && input[i+1] == 'h' && input[i+2] == 'e' && input[i+3] == 'y') {
            printf("(a) ");
            token.type = ACTION;
            strcpy(token.lexeme, "they");
            i += 4;
        }
        else if (input[i] == 't' && input[i+1] == 'h' && input[i+2] == 'e' && input[i+3] == 'n') {
            printf("(k) ");
            token.type = THEN;
            strcpy(token.lexeme, "then");
            i += 4;
        }
        else if (isalpha(input[i])) {
            int j = 0;
            char lexeme[10];
            while (isalpha(input[i])) {
                lexeme[j] = input[i];
                i++;
                j++;
            }
            lexeme[j] = '\0';
            if (strcmp(lexeme, "hate") == 0 || strcmp(lexeme, "like") == 0) {
                printf("(v) ");
                token.type = VERB;
            }
            else {
                
                token.type = NOUN;
                nounId = findSymbol(lexeme);
                printf("(n,%d) ",nounId);
            }
            strcpy(token.lexeme, lexeme);
        }

        else if (input[i] == '$') 
        {
            printf("<eof>\n");
            token.type = EOF_TOKEN;
            break; 
        }

    }

    printf("\nSymbol table:\nINDEX\tNOUN_TOKEN\n");
    for (i = 0; i < numNouns; i++) {
        printf("%d\t %s\n", symbolTable[i].id, symbolTable[i].noun);
    }

    return 0;
}
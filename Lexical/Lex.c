#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SYMBOLS 100
// Token types
enum TokenType {
    NOUN,VERB,IF,THEN,THEY, OP,EOF_TOKEN 
};
// Token structure
struct Token {
    enum TokenType type;
    char value[20];
};
// Symbol table structure
struct SymbolTable {
    char symbols[MAX_SYMBOLS][20];
    int count;
};
// Function to initialize the symbol table
void initSymbolTable(struct SymbolTable *table) {
    table->count = 0;
}
// Function to add a symbol to the symbol table
int addSymbol(struct SymbolTable *table, char *symbol) {
    if (table->count >= MAX_SYMBOLS) {
        return 0; // table is full
    }
    strcpy(table->symbols[table->count], symbol);
    table->count++;
    return 1;
}
// Function to lookup a symbol in the symbol table
int lookupSymbol(struct SymbolTable *table, char *symbol) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->symbols[i], symbol) == 0) {
            return i+1; // index in symbol table starts from 1
        }
    }
    return 0; // symbol not found
}
// Function to print the output in the given style
void printOutput(struct Token *tokens, int count, struct SymbolTable *table) {
    for (int i = 0; i < count; i++) {
        if (tokens[i].type == IF) {
            printf("(k) ");
        } else if (tokens[i].type == NOUN) {
            int index = lookupSymbol(table, tokens[i].value);
            if (index > 0) {
                printf("(n,%d) ", index);
            } else {
                printf("(n,%s) ", tokens[i].value);
            }
        } else if (tokens[i].type == VERB) {
            printf("(v) ");
        } else if (tokens[i].type == THEN) {
            printf("(k) ");
        } else if (tokens[i].type == THEY) {
            printf("(a) ");
        } else if (tokens[i].type == OP) {
            printf("(op) ");
        } else if (tokens[i].type == EOF_TOKEN){
            printf("<eof>");
        }
    }
    printf("\n");
}
// Function to tokenize the input string and generate the output
void tokenize(char *input, struct SymbolTable *table) {
    struct Token tokens[100];
    int count = 0;
    char *p = input;

    while (*p != '\0') {
        // Skip whitespace
        while (isspace(*p)) {
            p++;
        }

        // Check for keywords and operators
        if (strncmp(p, "If", 2) == 0) {
            tokens[count].type = IF;
            strcpy(tokens[count].value, "If");
            count++;
            p += 2;
        } else if (strncmp(p, "then", 4) == 0) {
            tokens[count].type = THEN;
            strcpy(tokens[count].value, "then");
            count++;
            p += 4;
        } else if (strncmp(p, "they", 4) == 0) {
            tokens[count].type = THEY;
            strcpy(tokens[count].value, "they");
            count++;
        p += 4;
        } else if (*p == '.') {
            tokens[count].type = OP;
            strcpy(tokens[count].value, ".");
            count++;
            p++;
        } else if (*p =='$')
        {
            tokens[count].type = EOF_TOKEN;
            strcpy(tokens[count].value, "$");
            break;
        }
    
        else {
        // Parse NOUN, VERB or invalid input
        char word[20];
        int i = 0;
        while (isalpha(*p)) {
            word[i] = *p;
            i++;
            p++;
        }
        word[i] = '\0';
        if (strcmp(word, "hate") == 0 || strcmp(word, "like") == 0) {
            tokens[count].type = VERB;
            strcpy(tokens[count].value, word);
            count++;
        } else if (strlen(word) > 0) {
            tokens[count].type = NOUN;
            strcpy(tokens[count].value, word);
            if (!lookupSymbol(table, word)) {
                addSymbol(table, word);
            }
            count++;
        }
    }
}
// Add EOF token
tokens[count].type = EOF_TOKEN;
strcpy(tokens[count].value, "<eof>");
count++;
// Print output
printOutput(tokens, count, table);
}

int main() {
struct SymbolTable table;
initSymbolTable(&table);
char input[] = "If dogs hate cats then they chase. If cats like milk then they drink.$";
tokenize(input, &table);
printf("\nSymbol table:\nIndex\t Noun_Tokens\n");
for (int i = 0; i < table.count; i++) {
    printf("[%d]\t %s\n",i+1,table.symbols[i]);
}
return 0;
}
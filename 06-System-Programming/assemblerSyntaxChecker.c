#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char opcode[10];
    char operand[20];
    char objectCode[10];
    int isLabel;
    int objectCodeSize; // added to store object code size (1 or 3 bytes)
} OpCodeTable;

OpCodeTable optab[] = {
    {"ADD", "B", "80", 0, 1},
    {"SUB", "B", "90", 0, 1},
    {"JMP", "", "22", 0, 3},
    {"INR", "C", "0C", 0, 1},
    {"JNC", "", "C3", 0, 3},
    {"CMP", "B", "B8", 0, 1},
    {"HLT", "", "76", 0, 1},
    {"MVI", "C", "0E", 0, 2},
    {"JC", "", "DA", 0, 3},
    {"STA", "", "32", 0, 3},
    {"LDA", "", "3A", 0, 3},
    {"MOV", "B,A", "47", 0, 1},
    {"LOOP1:", "", "", 1, 0},
    {"LOOP2:", "", "", 1, 0}
};

// Function to check syntax errors
int checkSyntax(char *opcode, char *operand) {
    int i;
    for (i = 0; i < sizeof(optab) / sizeof(optab[0]); i++) {
        if (strcmp(opcode, optab[i].opcode) == 0) {
            if (optab[i].operand[0] == '\0') { // No operand expected
                if (operand[0] == '\0') {
                    return 1; // Syntax correct
                } else {
                    return 2; // Unexpected operand
                }
            } else {
                if (operand[0] != '\0') {
                    if (strcmp(operand, optab[i].operand) == 0) {
                        return 1; // Syntax correct
                    } else {
                        return 3;
                    }
                } else {
                    return 4;
                }
            }
        }
    }
    return 0; // Unknown opcode
}

int isValidMemoryAddress(char *operand) {
    if (strlen(operand) != 4) {
        return 0; // Invalid length
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(operand[i])) {
            return 0; // Not a digit
        }
    }
    return 1; // Valid memory address
}

char* convertOpcodeToObjectCode(char *opcode, char *operand) {
    for (int i = 0; i < sizeof(optab) / sizeof(optab[0]); i++) {
        if (strcmp(opcode, optab[i].opcode) == 0) {
            return optab[i].objectCode;
        }
    }
    return "invalid opcode!!!";
}

int main() {
    FILE *inputFile, *outputFile;
    char opcode[10], operand[20], line[100];
    inputFile = fopen("addop.txt", "r");
    outputFile = fopen("addobj.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        sscanf(line, "%s %s", opcode, operand);

        int syntaxResult = checkSyntax(opcode, operand);

        if (syntaxResult == 1) {
            // Valid syntax, convert to object code
            char* objectCode = convertOpcodeToObjectCode(opcode, operand);
            fprintf(outputFile, "%s %s %s\n", opcode, operand, objectCode);
        } else if (syntaxResult == 2) {
            fprintf(outputFile, "%s unexpected operand\n", opcode);
        } else if (syntaxResult == 3) {
            fprintf(outputFile, "%s invalid operand\n", opcode);
        } else if (syntaxResult == 4) {
            fprintf(outputFile, "%s missing operand\n", opcode);
        } else {
            fprintf(outputFile, "%s unknown opcode\n", opcode );
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

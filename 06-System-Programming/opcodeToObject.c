#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char opcode[10];
    char operand[20];
    char objectCode[10];
    int isLabel;
    int objectCodeSize;
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
            if (optab[i].isLabel) {
                return 1; // Label syntax correct
            } else {
                if (optab[i].operand[0] == '\0') { // No operand expected
                    if (operand[0] == '\0') {
                        return 1; // Syntax correct
                    } else {
                        return 0; // Unexpected operand
                    }
                } else {
                    if (operand[0] != '\0') {
                        return 1; // Syntax correct
                    } else {
                        return 0; // Missing operand
                    }
                }
            }
        }
    }
    return 0; // Unknown opcode
}

char* convertOpcodeToObjectCode(char *opcode, char *operand, int *memoryAddress) {
    int i;
    for (i = 0; i < sizeof(optab) / sizeof(optab[0]); i++) {
        if (strcmp(opcode, optab[i].opcode) == 0) {
            if (optab[i].isLabel) {
                return "";
            } else {
                *memoryAddress = atoi(operand);
                return optab[i].objectCode;
            }
        }
    }
    return "invalid opcode!!!";
}

int main() {
    FILE *inputFile, *outputFile;
    char opcode[10], operand[20], line[100];
    int memoryAddress = 2050;

    inputFile = fopen("swap.txt", "r");
    outputFile = fopen("swapobj.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%s %s", opcode, operand);

        // Check syntax errors
        if (!checkSyntax(opcode, operand)) {
            fprintf(stderr, "Syntax error: %s %s\n", opcode, operand);
            continue;
        }

        char* objectCode = convertOpcodeToObjectCode(opcode, operand, &memoryAddress);
        if (strcmp(objectCode, "") == 0) {
            fprintf(outputFile, "%s %s\n", opcode, operand);
        } else {
            OpCodeTable *opt = NULL;
            for (int i = 0; i < sizeof(optab) / sizeof(optab[0]); i++) {
                if (strcmp(opcode, optab[i].opcode) == 0) {
                    opt = &optab[i];
                    break;
                }
            }
            if (opt != NULL) {
                if (opt->objectCodeSize == 1) {
                    fprintf(outputFile, "%s %04X %s\n", opcode, memoryAddress, objectCode);
                } else if (opt->objectCodeSize == 3) {
                    fprintf(outputFile, "%s %04X %02X %02X %s\n", opcode, memoryAddress, (memoryAddress >> 8) & 0xFF, memoryAddress &  0xFF, objectCode);
                } else {
                    fprintf(outputFile, "%s %04X %s\n", opcode, memoryAddress, objectCode);
                }
            }
        }
        memoryAddress += (opt != NULL) ? opt->objectCodeSize : 1; // Increment memory address based on object code size
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

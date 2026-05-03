#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "calc_func.h"

int main(){

    printf("\033[1;32m");
    printf("   _____      _            _           _                  \n");
    printf("  / ____|    | |          | |         | |                \n");
    printf("| |     __ _| | ___ _   _| | __ _  __| | ___  _ __ __ _    \n");
    printf("| |    / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |   \n");
    printf("| |___| (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| |  \n");
    printf(" \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \n");
    printf("\033[0m"); 

    //variaveis utilizadas 
    int first_number, second_number,len, result, number;
    char typeOperation;

    //buffer de 100 byts para armazenar entrada do usuário tamanho 100 para ser uma margem segura.
    char bufferEntry[100];
    char bufferOperation[10];
    char *end;
    //**/
    
    while (true)//entrada no loop
    {
        result = 0;
        printf("Informe um número: ");
        fgets(bufferEntry, sizeof(bufferEntry), stdin);

        printf("\n");
        first_number = strtol(bufferEntry, NULL, 10); // converte de string para decimal

        printf("Informe o segundo valor: ");
        fgets(bufferEntry, sizeof(bufferEntry), stdin); //segundo valor de entrada

        printf("\n");

        second_number = strtol(bufferEntry, NULL, 10);
        

        char operation[] = {'+', '-', '*', '/'};
        len = sizeof(operation)/sizeof(operation[0]);
        
        printf("Escolha uma das 4 operações: \n");
        for (int i = 0; i < len; i++)
        {
            printf(" %c", operation[i]);

        }
        printf("\n");
        printf("Para sair digite: q \n");
        fgets(bufferOperation, sizeof(bufferOperation), stdin);
        typeOperation = bufferOperation[0];
        //------------------------------------------//
        //Chackagem do tipo da operação
        switch (typeOperation)
        {
        case '+':
            sum(first_number, second_number, &result); 
            printf("O resultado da soma: [%d + %d = %d]\n", first_number, second_number, result);
            break;
        case '-':
            subtraction(first_number, second_number, &result);
            printf("O resultado da subtração: [%d - %d = %d]\n", first_number, second_number, result);
            break;
        case '*':
            multiplication(first_number, second_number, &result);
            printf("O resultado da multiplicação: [%d * %d = %d]\n", first_number, second_number, result);
            break;
        case '/': // se o retorno for -1 o usuário tentou dividir por 0
            if (division(first_number, second_number, &result) == -1){
                continue;
            }
            printf("O resultado da divisão: [%d / %d = %d]\n", first_number, second_number, result);
            break;
        case 'q':
            printf("Agradeço por usar nossa ferramenta.");
            return false;
        }

    }
    
    return 0;
}
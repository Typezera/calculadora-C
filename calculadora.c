#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "calc_func.h"

int main(){
    printf("\x1b[33m Bem vindo a calculadora \x1b[0m \n");

    //variaveis utilizadas 
    int first_number, second_number,len, result;
    char typeOperation;
    //**/
    
    while (true)//entrada no loop
    {
        printf("\033[1;32m");
        printf("   _____      _            _           _                   _____             _   _ _ \n");
        printf("  / ____|    | |          | |         | |                 |_   _|           | | (_) |\n");
        printf("| |     __ _| | ___ _   _| | __ _  __| | ___  _ __ __ _    | |  _ __  _   _| |_ _| |\n");
        printf("| |    / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |   | | | '_ \\| | | | __| | |\n");
        printf("| |___| (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| |  _| |_| | | | |_| | |_| | |\n");
        printf(" \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \\__,_| |_____|_| |_|\\__,_|\\__|_|_|\n");
        printf("\033[0m"); 

        printf("Informe o primeiro valor: ");
        scanf("%d", &first_number); //primeiro valor de entrada

        printf("\n");

        printf("Informe o segundo valor: ");
        scanf("%d", &second_number); //segundo valor de entrada

        printf("\n");

        char operation[] = {'+', '-', '*', '/'};
        len = sizeof(operation)/sizeof(operation[0]); //cada int 4 byts * 5 = 20 / 5 = 4 resultado tamanho total do array;
        
        printf("Escolha uma das 4 operações: \n");
        for (int i = 0; i < len; i++)
        {
            printf(" %c", operation[i]);

        }
        printf("\n");
        scanf(" %c", &typeOperation);
        //------------------------------------------//
        //Chackagem do tipo da operação
        switch (typeOperation)
        {
        case '+':
            result = sum(first_number, second_number); 
            printf("O resultado da soma: [%d + %d = %d]\n", first_number, second_number, result);
            break;
        case '-':
            result = subtraction(first_number, second_number);
            printf("O resultado da subtração: [%d - %d = %d]\n", first_number, second_number, result);
            break;
        case '*':
            result = multiplication(first_number, second_number);
            printf("O resultado da multiplicação: [%d * %d = %d]\n", first_number, second_number, result);
            break;
        case '/':
            result = division(first_number, second_number); // se o retorno for -1 o usuário tentou dividir por 0
            if (result == -1)
            {
                continue;
            }
            printf("O resultado da divisão: [%d / %d = %d]\n", first_number, second_number, result);
            break;
        }
    }
    
    return 0;
}
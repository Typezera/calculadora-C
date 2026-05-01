#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "calc_func.h"

int main(){
    printf("Bem vindo a calculadora\n");

    //variaveis utilizadas 
    int first_number, second_number,len, result;
    char typeOperation;
    //**/
    
    while (true)//entrada no loop
    {
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
            result = division(first_number, second_number);
            if (result == -1)
            {
                continue;
            }
            printf("O resultado da divisão: [%d / %d = %d]\n", first_number, second_number, result);
            break;
        default:
            break;
        }
        //------------------------------------------//
        
        // printf("digite o primeiro valor: \n");
        // scanf("%d", &first_number);
    
        // printf("Digte o segundo valor \n");
        
        // scanf("%d", &second_number);
    
        // result = first_number + second_number;
    
        // printf("A soma dos valores é: %d %d = %d ", first_number, second_number, result);
    }
    
    return 0;
}
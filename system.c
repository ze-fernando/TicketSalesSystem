#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int i = 0, count = 0;

typedef struct {
    char nome[50];
    char cpf[15];
    int ano;
} Cliente;
Cliente c[0];


void Vende_ingresso(){
    setlocale (LC_ALL, "portuguese");

    int option2 = 1;

    while (option2==1){
        system("cls");
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n");
        printf("         Venda de ingressos\n");
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n");
        count ++;
        printf("Insira seu CPF (com pontuação): ");
        scanf("%s", &c[i].cpf);
        fflush(stdin);
        printf("Insira seu ano de nascimento: ");
        scanf("%d", &c[i].ano);
        fflush(stdin);
        printf("Digite o seu nome: ");
        scanf("%s", c[i].nome);
        fflush(stdin);
        printf("\n");
        i ++;
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");
        printf("[1] Realizar outra venda \n");
        printf("[0] Sair \n");
        printf("Digite a opção desejada: ");
        scanf("%d", &option2);
        fflush(stdin);
    }
    main();
}

void Lista_ingresso(){
    setlocale (LC_ALL, "portuguese");


    int option3;
    system("cls");

    do{
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n");
        printf("      Lista de ingressos vendidos \n");
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n \n");
        if (i>0){
            for (i=0; i<count; i++){
                printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");
                printf("Nome: ");
                printf(c[i].nome);
                printf("\n");
                printf("CPF: %s \n",c[i].cpf);
                printf("Ano de nascimento: %d \n",c[i].ano);
            }
        }
        else{
            printf("Não há ingressos registrados! \n");
        }
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");
        printf("[0] Voltar ");
        scanf("%d", &option3);
        fflush(stdin);

    }while(option3!=0);
    if (option3==0){
        main();
    }
}

void valida_ingresso(){
    setlocale (LC_ALL, "portuguese");

    char busca[15];
    int option4, t = -1;
    system("cls");

    printf("Insira seu CPF (com pontuação): ");
    scanf("%s", &busca);
    fflush(stdin);

    for (i=0; i<count; i++){
        if (strcmp(busca, c[i].cpf) == 0){
            t = i;
        }
    }

    if (t == -1){
        printf("Não existem ingressos registrados neste CPF \n");
    }
    else{
        printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");
        printf("Nome: ");
        printf(c[t].nome);
        printf("\n");
        printf("CPF: %s \n",c[t].cpf);
        printf("Ano de nascimento: %d \n",c[t].ano);
    }
    printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=* \n");
    printf("\n[1] Consultar novamente \n");
    printf("[0] Voltar \n");
    printf("Digite a opção desejada: ");
    scanf("%d", &option4);
    fflush(stdin);
    if (option4==0){
        main();
    }
    if (option4==1){
        valida_ingresso();
    }
    
}

int main(){
    setlocale (LC_ALL, "portuguese");
    int opcao;
    system("cls");
    
    printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n");
    printf("         Bem vindo ao CineShow \n");
    printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*= \n \n");
    printf("[1] Vender ingresso\n");
    printf("[2] Listar ingressos vendidos\n");
    printf("[3] Validar ingresso\n");
    printf("[0] Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao){
        case 1:
            Vende_ingresso();
            break;
        case 2:
            Lista_ingresso();
            break;
        case 3:
            valida_ingresso();
            break;
        case 0:
            printf("Até logo!");
            break;
    };
    
    return 0;
}
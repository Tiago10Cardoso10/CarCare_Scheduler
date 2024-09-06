#include <stdio.h>
#include <string.h>
#include <math.h>


#include "funcao.h"

void menu_opcoes();
void menu();


int main() {
    menu();
    return 0;
}

void menu(){
    
    reservas r;
    r = criaR();

    prereservas pre;
    pre = criaP();

    horario data_atual = le_ficheiro(r,pre);
    
    int escolha = 0;
    do{
        apaga_data(r,pre,data_atual);
        menu_opcoes();
        
        printf("\nEscolhas:");
        scanf("%d",&escolha);
        printf("\n");

        while (escolha > 6 || escolha < 0){
            printf("Opcao escolhida invalida. Selecione novamente:");
            scanf("%d",&escolha);
            printf("\n");
        }
        switch (escolha) {
            case 1:
                fazer_reserva(r,data_atual,pre);
                break;
            case 2:
                cancelar_reserva(r,data_atual,pre);
                break;
            case 3:
                cancela_prereserva(pre,data_atual);
                break;
            case 4:
                imprimeR (r,data_atual);
                printf("\n\n");
                imprimeP (pre,data_atual);
                le_qqlr();
                break;
            case 5:
                imprime_cliente(r,pre,data_atual);
                break;
            case 6:
                data_atual = muda_data(data_atual);
                le_qqlr();
                break;
        }
    } while (escolha <= 6 && escolha > 0);

    
    printf("\n\n\n  -> OBRIGADOOOO! A fechar................");
    escreve_ficheiro(r,pre,data_atual);
}


void menu_opcoes(){
    printf("-------------------------------------\n");
    printf("|              OFICINA              |\n");
    printf("-------------------------------------\n");
    printf("| 1 - Fazer Reserva                 |\n"); // Feito
    printf("| 2 - Cancelar Reserva              |\n"); // Feito
    printf("| 3 - Cancelar Pre-Reserva          |\n"); // Feito
    printf("| 4 - Listar por ordem de Data      |\n"); // Feito
    printf("| 5 - Listar por Cliente            |\n"); // Feito
    printf("| 6 - Alterar Data                  |\n"); // Feito
    printf("| 0 - Sair                          |\n"); // Feito
    printf("-------------------------------------\n"); // Já guarda e lê do Ficheiro e apaga após data
}
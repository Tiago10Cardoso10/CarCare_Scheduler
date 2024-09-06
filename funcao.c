#include "funcao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define BUFFER 50


/* Funções para a Criação da Lista de Reservas*/

reservas criaR (){
    reservas aux;
    struct dados p1 = {"","","","",""};
    struct horario h2 = {0,0,0,0,0,0,0};
    aux = (reservas) malloc (sizeof (marcacoes));
    if (aux != NULL) {
        aux->dados = p1;
        aux->horario = h2;
        aux->prox = NULL;
    }
    return aux;
}

int vaziaR (reservas r) {
    if (r->prox == NULL) return 1;
    else return 0;
}

reservas destroiR (reservas r){
    reservas temp_ptr;
    while (!vaziaR (r)) {
        temp_ptr = r;
        r = r->prox;
        free (temp_ptr);
    }
    free(r);
    return NULL;
}

void procuraR (reservas r, double chave, reservas *ant, reservas *actual){
    *ant = r; *actual = r->prox;
    while ((*actual) != NULL && (*actual)->horario.nr_especial < chave) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (*actual)->horario.nr_especial != chave)
        *actual = NULL; /* elemento não encontrado*/
}

void eliminaR (reservas r, double chave){
    reservas ant, actual;
    procuraR (r, chave, &ant, &actual);
    if (actual != NULL) {
        ant->prox = actual->prox;
        free (actual);
    }
}

void insereR (reservas r, struct dados p1,struct horario p2) {
    reservas no, ant, inutil;
    no = (reservas) malloc (sizeof (marcacoes));
    if (no != NULL) {
        no->dados = p1;
        no->horario = p2;
        procuraR (r, p2.nr_especial, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

reservas pesquisaR (reservas r, double chave){
    reservas ant, actual;
    procuraR (r, chave, &ant, &actual);
    return (actual);
}

void imprimeR (reservas r,horario dia_atual){

    printf("-----------------------------------------------------\n");
    printf("|      Listagem das Reservas  %02d-%02d-%d %02d:%02d      |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    reservas aux = r->prox; /* Salta o header */

    if (aux == NULL) {
        printf("\n-> Não existem reservas Agendadas");
        return;
    }

    while (aux) {
        printf("\n-------------------------------\n");
        printf("-> Nome: %s\n",aux->dados.nome);
        printf("-> Numero de Telefone: %s\n",aux->dados.numero);
        printf("-> Marca: %s\n",aux->dados.marca);
        printf("-> Matricula: %s\n",aux->dados.matricula);
        printf("-> Escolha: %s\n",aux->dados.escolha);
        printf("-> Horario: %02d:%02d\n",aux->horario.hora_antes,aux->horario.minuto_antes);
        printf("-> Data: %02d-%02d-%04d\n",aux->horario.dia,aux->horario.mes,aux->horario.ano);
        printf("--------------------------------\n");       
        
        aux = aux->prox;
    }
    printf("\n");
    


}

/* Funções para a Criação da Lista de Pre-Reservas*/

prereservas criaP (){
    prereservas aux;
    struct dados p1 = {"","","","",""};
    struct horario h2 = {0,0,0,0,0,0,0};
    aux = (prereservas) malloc (sizeof (marcacoes));
    if (aux != NULL) {
        aux->dados = p1;
        aux->horario = h2;
        aux->prox = NULL;
    }
    return aux;
}

int vaziaP (prereservas p) {
    if (p->prox == NULL) return 1;
    else return 0;
}

prereservas destroiP (prereservas p){
    prereservas temp_ptr;
    while (!vaziaP (p)) {
        temp_ptr = p;
        p = p->prox;
        free (temp_ptr);
    }
    free(p);
    return NULL;
}

void procuraP (prereservas p, double chave, prereservas *ant, prereservas *actual){
    *ant = p; *actual = p->prox;
    while ((*actual) != NULL && (*actual)->horario.nr_especial < chave) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (*actual)->horario.nr_especial != chave)
        *actual = NULL; /* elemento não encontrado*/
}

void eliminaP (prereservas p, double chave){
    prereservas ant, actual;
    procuraP (p, chave, &ant, &actual);
    if (actual != NULL) {
        ant->prox = actual->prox;
        free (actual);
    }
}

void insereP (prereservas p, struct dados p1,struct horario p2) {
    prereservas no, ant, inutil;
    no = (prereservas) malloc (sizeof (marcacoes));
    if (no != NULL) {
        no->dados = p1;
        no->horario = p2;
        procuraP (p, p2.nr_especial, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

prereservas pesquisaP (prereservas p, double chave){
    prereservas ant, actual;
    procuraP (p, chave, &ant, &actual);
    return (actual);
}

void imprimeP (prereservas p,horario dia_atual){

    printf("-----------------------------------------------------\n");
    printf("|    Listagem das Pre-Reservas  %02d-%02d-%d %02d:%02d    |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    reservas aux = p->prox; /* Salta o header */

    if (aux == NULL) {
        printf("\n-> Não existe nenhuma marcação em Fila de Espera!\n\n");
        return;
    }

    while (aux) {
        printf("\n-------------------------------\n");
        printf("-> Nome: %s\n",aux->dados.nome);
        printf("-> Numero de Telefone: %s\n",aux->dados.numero);
        printf("-> Marca: %s\n",aux->dados.marca);
        printf("-> Matricula: %s\n",aux->dados.matricula);
        printf("-> Escolha: %s\n",aux->dados.escolha);
        printf("-> Horario: %02d:%02d\n",aux->horario.hora_antes,aux->horario.minuto_antes);
        printf("-> Data: %02d-%02d-%02d\n",aux->horario.dia,aux->horario.mes,aux->horario.ano);
        printf("--------------------------------\n");       
        
        aux = aux->prox;
    }
    printf("\n");
}

/*--------------------------------------------------------------------------------------------*/

/*Feito*/
int compara_datas(horario data_ref, horario data_user) {
    if (data_user.ano > data_ref.ano) {
        return 1;
    } else if (data_user.ano < data_ref.ano) {
        return 0;
    } else {
        if(data_user.mes > data_ref.mes) {
            return 1;
        } else if (data_user.mes < data_ref.mes) {
            return 0;
        } else {
            if(data_user.dia >= data_ref.dia) {
                return 1;
            } else {
                return 0; //As datas são iguais
            }
        }
    }
}

/*Feito*/
int validar_data(horario data) {
    // Verifica se o ano é válido (entre 0 e 9999)
    if (data.ano < 0 || data.ano > 9999) {
        return 0;
    }

    // Verifica se o mês é válido (entre 1 e 12)
    if (data.mes < 1 || data.mes > 12) {
        return 0;
    }

    // Verifica se o dia é válido
    int dias_mes;

    if (data.mes == 2) {
        // Verifica se é um ano bissexto
        if (ano_bissexto(data.ano)) {
            dias_mes = 29;
        } else {
            dias_mes = 28;
        }
    } else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        dias_mes = 30;
    } else {
        dias_mes = 31;
    }

    if (data.dia < 1 || data.dia > dias_mes) {
        return 0;
    }

    return 1;
}

/*Feito*/
int ano_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return 1; // É um ano bissexto
    } else {
        return 0; // Não é um ano bissexto
    }
}

/*Feito*/
int compara_horas(horario hora_user, horario horas_atual,dados d) {
    horario abertura;
    abertura.hora_antes = 8;
    abertura.minuto_antes = 0;

    horario fecho;
    fecho.hora_antes = 18;
    fecho.minuto_antes = 0;

    

    if(horas_atual.hora_antes < hora_user.hora_antes || (horas_atual.hora_antes == hora_user.hora_antes && horas_atual.minuto_antes < hora_user.minuto_antes)){
        if(hora_user.minuto_antes != 0 && hora_user.minuto_antes != 30){
            return 0;
        }
        if((strcmp(d.escolha, "Limpeza")==0 && hora_user.hora_antes <= 17) || (strcmp(d.escolha, "Manutenção")==0 && ((hora_user.hora_antes <= 17 && hora_user.minuto_antes == 0) || (hora_user.hora_antes<=16)))){
            if((hora_user.hora_antes > abertura.hora_antes || (hora_user.hora_antes == abertura.hora_antes && hora_user.minuto_antes >= abertura.minuto_antes)) && (hora_user.hora_antes < fecho.hora_antes || (hora_user.hora_antes == fecho.hora_antes && hora_user.minuto_antes <= fecho.minuto_antes))){
                return 1;
            } else {
                return 0;
            }
        }
        return 0;
    }
    return 0;
}

/*Feito*/
int validar_horas(horario horas_user){
    if (horas_user.hora_antes < 0 || horas_user.hora_antes > 23){
        return 0;
    }
    if(horas_user.minuto_antes < 0 || horas_user.minuto_antes > 59){
        return 0;
    }

    return 1;
}

/*Feito*/
void imprime_umR(reservas r){
    printf("-------------------------------\n");
    printf("-> Nome: %s\n",r->dados.nome);
    printf("-> Numero de Telefone: %s\n",r->dados.numero);
    printf("-> Marca: %s\n",r->dados.marca);
    printf("-> Matricula: %s\n",r->dados.matricula);
    printf("-> Escolha: %s\n",r->dados.escolha);
    printf("-> Horario: %02d:%02d\n",r->horario.hora_antes,r->horario.minuto_antes);;
    printf("-> Data: %02d-%02d-%02d\n",r->horario.dia,r->horario.mes,r->horario.ano);
    printf("--------------------------------\n");
}

/*Feito*/
void imprime_umPre(prereservas pre){
    printf("-------------------------------\n");
    printf("-> Nome: %s\n",pre->dados.nome);
    printf("-> Numero de Telefone: %s\n",pre->dados.numero);
    printf("-> Marca: %s\n",pre->dados.marca);
    printf("-> Matricula: %s\n",pre->dados.matricula);
    printf("-> Escolha: %s\n",pre->dados.escolha);
    printf("-> Horario: %02d:%02d\n",pre->horario.hora_antes,pre->horario.minuto_antes);;
    printf("-> Data: %02d-%02d-%02d\n",pre->horario.dia,pre->horario.mes,pre->horario.ano);
    printf("--------------------------------\n");
}

/*Feito*/
void fazer_reserva(reservas r,horario dia_atual,prereservas pre){

    printf("-----------------------------------------------------\n");
    printf("|         Marcar Reserva  %02d-%02d-%d %02d:%02d          |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");
    
    struct dados d;
    char Nnome[BUFFER];
    char nada[2];
    char Nmatricula[BUFFER];
    char Nmarca[BUFFER];
    char Nescolha[BUFFER];
    char numero[BUFFER];
    char numero_final[BUFFER];
    struct horario a;

    printf("\n-> Nome: ");
    fgets(nada,2,stdin);
    fgets(Nnome, BUFFER, stdin);
    Nnome[strcspn(Nnome, "\n")] = 0;
    strcpy(d.nome, Nnome);
    printf("    - Nome introduzido com sucesso!\n");

    /*
        Certificar que tem pelo menos 9 digitos

        ATENCAO: 
                    Falta ver se só tem digitos
    */
    
    while(1){
        printf("-> Numero de Telefone: ");
        scanf("%s", numero);
        strcpy(numero_final, numero);

        int tamanho = strlen(numero);
        int i;
        int digitos = 0;

        for(i=0; i<tamanho; i++){
            if(!isdigit(numero[i])){
                break;
            }
            digitos++;
        }

        if(digitos == 9 && i == tamanho){
            printf("    - Número introduzido com sucesso!\n");
            strcpy(d.numero,numero_final);
            break;
        } else {
            printf("    - Erro: O número introduzido tem de ter exatamente 9 digitos numéricos. Tente novamente!\n");
        }
    }

    printf("-> Marca e Modelo: ");
    fgets(nada,2,stdin);
    fgets(Nmarca,BUFFER,stdin);
    Nmarca[strcspn(Nmarca, "\n")] = 0;
    strcpy(d.marca, Nmarca);
    printf("    - Marca e Modelo introduzidos com sucesso\n");

    /*
        Verificar que a Matricula tem de ser do tipo AA-AA-AA

        Testar se funciona só com "-"
    */

    while (1){
        printf("-> Matricula(aa-aa-aa): ");
        fgets(Nmatricula,BUFFER,stdin);
        Nmatricula[strcspn(Nmatricula, "\n")] = 0;
        strcpy(d.matricula,Nmatricula);
        
        char *token;
        token = strtok(Nmatricula, "-");
        int verifica1 = 0;
        int verifica2 = 0;
        while (token != NULL) {
            if (strlen(token) == 2){
                verifica2 += 2;
            }
            verifica1++;
            token = strtok(NULL, "-");
        }
        if (verifica1 == 3 && verifica2 == 6){
            printf("    - Matrícula introduzida com sucesso\n");
            break;
        }else{
            printf("    - A matrícula introduzida não cumpre os requesitos. Tente novamente!\n");
        }
    }

    /*
        Certificar que seja introduzido uma das letras
    */

    while (1){
        printf("-> Manutenção ou Limpeza(M/L): ");
        scanf("%s",Nescolha);
        if ( strlen(Nescolha) == 1 && (Nescolha[0] == 'M' || Nescolha[0] == 'm')){
            strcpy(d.escolha,"Manutenção");
            a.duracao = 100;
            printf("    - Operação introduzida com sucesso\n");
            break;
        } else if (strlen(Nescolha) == 1 && (Nescolha[0] == 'L' || Nescolha[0] == 'l')){
            strcpy(d.escolha,"Limpeza");
            printf("    - Operação introduzida com sucesso\n");
            a.duracao = 30;
            break;
        } else {
            printf("    - Operação introduzida inválida. Tente novamente!\n");
        }
    }

    /*
        Se a data introduzida for menor que a atual, tem que
        pedir novamente data, pois está incorreta


        ATENCAO:
                Não dá certo sem o "-"
                Corrigir data para apenas possiveis
    */
    
    int entrada_correta=0;

    while (!entrada_correta){
        printf("-> Data para Reserva(dd-mm-aaaa): ");
        scanf("%d-%d-%d",&a.dia,&a.mes,&a.ano);

        if (a.dia == 0 || a.mes == 0 || a.ano == 0) {
            printf("    - Formato de data inválido. Utilize o formato dd-mm-aaaa.\n");
            // Limpa o buffer do scanf
            while (getchar() != '\n');
            continue;
        }

        int result = compara_datas(dia_atual, a);

        if(!validar_data(a)){
            printf("    - A data introduzida é inválida. Por favor, introduza outra data no formato dd-mm-aaaa ou verifique se é um ano bissexto.\n");
        } else {
            if(result){
                printf("    - Data introduzida com sucesso!\n");
                entrada_correta=1;
            } else {
                //Se for introduzida uma data mais antiga que a data de referência
                printf("    - Data introduzida inválida. Tente novamente!\n");
            }
        }
    }

    /*
        ATENCAO:
                Ver que a OFICINA estaja aberta no seu horario
                Colocar minutos a ser aceites 0 ou 30
                Colocar horas e minutos possiveis
                Colocar hora e minutos depois consoante a escolha do Serviço
    */

    do {
        printf("-> Hora(hh:mm): ");
        char input[BUFFER];
        scanf("%s", input);
        getchar();

        if(strchr(input, ':') == NULL){
            printf("    - Utilize o formato hh:mm. Tente novamente!\n");
            continue;
        }

        sscanf(input, "%d:%d", &a.hora_antes, &a.minuto_antes);

        if(!validar_horas(a)){
            printf("    - Introduza horas reais. Tente novamente!\n");
        } else if (!compara_horas(a, dia_atual, d)){
            printf("    - Verifique se a hora introduzida:\n\t- Está fora do horário de funcionamento.\n\t- Possui minutos inválidos.\n\t- Já foi ultrapassada.\n\t- Não dispõe de tempo suficiente para realizar a operação que pretende.\n    Tente Novamente!\n");
        }
    } while (!validar_horas(a) || !compara_horas(a, dia_atual,d));

    printf("    - A hora foi introduzida com sucesso.\n");


    a.nr_especial = a.ano * pow(10,8) + a.mes *  pow(10,6) + a.dia * pow(10,4) + a.hora_antes *  pow(10,2) + a.minuto_antes;

    reservas aux = r->prox;
    int verifica = 0;

    /* 
        ATENCAO:
                Verificar se existe marcacao para esse horário, senão vai para Fila de Espera, envia só dados

                Inserir dependendo da escolha
    */

    while (aux)
    {
        if(a.nr_especial == aux->horario.nr_especial){
            verifica = 1;
            break;
        } else if (a.nr_especial > aux->horario.nr_especial && a.nr_especial < aux->horario.nr_especial + aux->horario.duracao){
            verifica = 1;
            break;
        }
        aux = aux->prox;
    }

    if (verifica == 0){
        printf("\n-----------------------------------------------------\n");
        printf("|            Reserva Adiciona com sucesso           |\n");
        printf("-----------------------------------------------------\n\n");

        insereR(r,d,a);
    } else {
        printf("\n    - Já existia reserva para esse horário! Entrou numa lista de Espera.");
        printf("\n-----------------------------------------------------\n");
        printf("|         Pre-Reserva Adiciona com sucesso          |\n");
        printf("-----------------------------------------------------\n\n");
        insereP(pre,d,a);
    }
    le_qqlr();
}

/* Feito +/-*/
void cancelar_reserva (reservas r, horario dia_atual,prereservas pre){
    printf("-----------------------------------------------------\n");
    printf("|        Cancelar Reserva  %02d-%02d-%d %02d:%02d         |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    reservas atual = r->prox;

    char Nmatricula[BUFFER];
    char matricula[BUFFER];
    char nada[BUFFER];

    if (atual == NULL) {
        printf("\n->  Não existem reservas Agendadas. Logo não pode cancelar!\n\n");
    } else {
        
        while (1){
            printf("\n-> Matricula da Viatura que vai cancelar a Reserva: ");
            fgets(nada,BUFFER,stdin);
            fgets(Nmatricula,BUFFER,stdin);
            Nmatricula[strcspn(Nmatricula, "\n")] = 0;
            
            strcpy(matricula,Nmatricula);
            
            char *token;
            token = strtok(Nmatricula, "-");
            int verifica1 = 0;
            int verifica2 = 0;
            while (token != NULL) {
                if (strlen(token) == 2){
                    verifica2 += 2;
                }
                verifica1++;
                token = strtok(NULL, "-");
            }
            if (verifica1 == 3 && verifica2 == 6){
                printf("    - Matrícula autorizada\n");
                break;
            }else{
                printf("    - A matrícula introduzida não cumpre os requesitos. Tente novamente!\n");
            }
        }

        int count = 0;
        int count1 = 0;

        while (atual) {
            if (strcmp(atual->dados.matricula,matricula) == 0 ) {
                imprime_umR(atual);
                char cancelar[BUFFER];
                printf("-> Tem a certeza que deseja cancelar esta reserva(S/N): ");
                scanf("%s",cancelar);
                if ( strlen(cancelar) == 1 && (cancelar[0] == 'S' || cancelar[0] == 's' )){
                    
                    eliminaR(r,atual->horario.nr_especial);

                    printf("\n-----------------------------------------------------\n");
                    printf("|            Reserva Cancelada com sucesso          |\n");
                    printf("-----------------------------------------------------\n\n");
                    
                    prereservas nova = pre->prox;

                    while (nova){
                        
                        if(atual->horario.duracao == 100){
                            if((atual->horario.nr_especial == nova->horario.nr_especial) && (atual->horario.duracao == nova->horario.duracao)) {
                                // Mesmo horário - Ambos com duração de 1 hora
                                // Ex: Antes -> 12:00 - 13:00 | Depois -> 12:00 - 13:00

                                insereR(r,nova->dados,nova->horario);
                                printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                eliminaP(pre,nova->horario.nr_especial);
                                count1++;
                            } else if((atual->horario.nr_especial == nova->horario.nr_especial) && (atual->horario.duracao >= nova->horario.duracao)){
                                // Mesmo horário - Reserva de 1 hora e pre-reserva de 30 min
                                // Ex: Antes -> 12:00 - 13:00 | Depois -> 12:00 - 12:30

                                insereR(r,nova->dados,nova->horario);
                                printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                eliminaP(pre,nova->horario.nr_especial);
                                count1++;
                            } else if((atual->horario.nr_especial == nova->horario.nr_especial - 30) && (atual->horario.duracao >= nova->horario.duracao)){
                                // 30 min mais tarde que a Reserva - Reserva de 1 hora e pre-reserva de 30 min depois
                                // Ex: Antes -> 12:00 - 13:00 | Depois -> 12:30 - 13:00

                                insereR(r,nova->dados,nova->horario);
                                printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                eliminaP(pre,nova->horario.nr_especial);
                                count1++;
                            } else if (pesquisaR(r,atual->horario.nr_especial-30) == NULL && pesquisaR(r,atual->horario.nr_especial + 100) == NULL){
                                // Não existe nenhuma marcação nos 30 min antes
                                if((atual->horario.nr_especial - 30 == nova->horario.nr_especial) && (atual->horario.duracao == nova->horario.duracao)){
                                    // 30 min antes estava livre e existia uma marcação para essa hora
                                    // Ex: Antes -> 12:00 - 13:00 | Depois -> 11:30 - 12:30
                                    
                                    insereR(r,nova->dados,nova->horario);
                                    printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                    eliminaP(pre,nova->horario.nr_especial);
                                    count1++;
                                }
                            } else if (pesquisaR(r,atual->horario.nr_especial + 130) == NULL && pesquisaR(r,atual->horario.nr_especial + 100) == NULL){
                                // Não existe nenhuma marcação nos 30 min depois
                                if((atual->horario.nr_especial + 30 == nova->horario.nr_especial) && (atual->horario.duracao == nova->horario.duracao)){
                                    // 30 min antes estava livre e existia uma marcação para essa hora
                                    // Ex: Antes -> 12:00 - 13:00 | Depois -> 12:30 - 13:30
                                    
                                    insereR(r,nova->dados,nova->horario);
                                    printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                    eliminaP(pre,nova->horario.nr_especial);
                                    count1++;
                                }
                            }

                        } else if(atual->horario.duracao == 30){
                            if((atual->horario.nr_especial == nova->horario.nr_especial) && (atual->horario.duracao == nova->horario.duracao)) {
                                // Mesmo horário - Ambos com duração de 30 min
                                // Ex: Antes -> 12:00 - 12:30 | Depois -> 12:00 - 12:30

                                insereR(r,nova->dados,nova->horario);
                                printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                eliminaP(pre,nova->horario.nr_especial);
                                count1++;
                            } 
                        } else if (pesquisaR(r,atual->horario.nr_especial - 30) == NULL ){
                            // Não existe nenhuma marcação nos 30 min antes
                                if((atual->horario.nr_especial - 30 == nova->horario.nr_especial) && (atual->horario.duracao <= nova->horario.duracao)){
                                    // 30 min antes estava livre e existia uma marcação para essa hora
                                    // Ex: Antes -> 12:00 - 12:30 | Depois -> 11:30 - 12:30
                                    
                                    insereR(r,nova->dados,nova->horario);
                                    printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                    eliminaP(pre,nova->horario.nr_especial);
                                    count1++;
                                }
                        } else if (pesquisaR(r,atual->horario.nr_especial + 30) == NULL ){
                            // Não existe nenhuma marcação nos 30 min depois
                                if((atual->horario.nr_especial + 30 == nova->horario.nr_especial) && (atual->horario.duracao <= nova->horario.duracao)){
                                    // 30 min antes estava livre e existia uma marcação para essa hora
                                    // Ex: Antes -> 12:00 - 12:30 | Depois -> 12:00 - 13:00
                                    
                                    insereR(r,nova->dados,nova->horario);
                                    printf("    -> Uma pre-reserva assumiu essa posição!\n");
                                    eliminaP(pre,nova->horario.nr_especial);
                                    count1++;
                                }
                        }
                        
                        nova = pre->prox;
                    }
                    
                    count++;
                    if(count1 == 0){
                        printf("    -> Nenhuma pre-reserva assumiu a posição!\n");
                    }
                    

                } else {
                    printf("\n-----------------------------------------------------\n");
                    printf("|              Reserva Não Foi Cancelada            |\n");
                    printf("-----------------------------------------------------\n\n");
                    count++;
                    
                }
            }
            atual = atual->prox;
        }
        if (count == 0){
            printf("\n-----------------------------------------------------\n");
            printf("|      Não existe reserva com essa Matricula        |\n");
            printf("-----------------------------------------------------\n\n");
            
        } else {
            printf("\n-----------------------------------------------------\n");
            printf("| Todos dados sobre a Matricula foram apresentados  |\n");
            printf("-----------------------------------------------------\n\n");
        }
        
    }
    le_qqlr();
}

/* Feito*/
void cancela_prereserva(prereservas pre,horario dia_atual){

    printf("-----------------------------------------------------\n");
    printf("|      Cancelar Pre-Reserva  %02d-%02d-%d %02d:%02d       |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    prereservas aux = pre->prox;

    char Nmatricula[BUFFER];
    char matricula[BUFFER];
    char nada[BUFFER];

    if (aux == NULL) {
        printf("\n->  Não existe nenhuma marcação em Fila de Espera!\n\n");
    } else {
        
        while (1){
            printf("\n-> Matricula da Viatura que vai cancelar a Reserva:");
            fgets(nada,BUFFER,stdin);
            fgets(Nmatricula,BUFFER,stdin);
            Nmatricula[strcspn(Nmatricula, "\n")] = 0;
            
            strcpy(matricula,Nmatricula);
            
            char *token;
            token = strtok(Nmatricula, "-");
            int verifica1 = 0;
            int verifica2 = 0;
            while (token != NULL) {
                if (strlen(token) == 2){
                    verifica2 += 2;
                }
                verifica1++;
                token = strtok(NULL, "-");
            }
            if (verifica1 == 3 && verifica2 == 6){
                printf("    - Matrícula autorizada\n");
                break;
            }else{
                printf("    - A matrícula introduzida não cumpre os requesitos. Tente novamente!\n");
            }
            
        }

        int count = 0;

        while (aux)
        {
            if (strcmp(aux->dados.matricula,matricula) == 0){
                imprime_umPre(aux);
                char cancelar[BUFFER];
                printf("-> Tem a certeza que deseja cancelar esta reserva(S/N): ");
                scanf("%s",cancelar);
                if ( strlen(cancelar) == 1 && (cancelar[0] == 'S' || cancelar[0] == 's' )){
                    eliminaP(pre,aux->horario.nr_especial);
                    printf("\n-----------------------------------------------------\n");
                    printf("|          Pre-Reserva Cancelada com sucesso        |\n");
                    printf("-----------------------------------------------------\n\n");

                } else {
                        printf("\n-----------------------------------------------------\n");
                        printf("|            Pre-Reserva Não Foi Cancelada          |\n");
                        printf("-----------------------------------------------------\n\n");
                        
                }

                
                count++;
            }
            
        
            aux = aux->prox;
        }

        if (count == 0){ 
            printf("\n-----------------------------------------------------\n");
            printf("|     Não existe pre-reserva com essa Matricula     |\n");
            printf("-----------------------------------------------------\n\n");
        } else {
            printf("\n-----------------------------------------------------\n");
            printf("| Todos dados sobre a Matricula foram apresentados  |\n");
            printf("-----------------------------------------------------\n\n");
        
        }
        le_qqlr();
    }
}

/* Feito */
void imprime_cliente(reservas r, prereservas pre, horario dia_atual) {
    printf("-----------------------------------------------------\n");
    printf("|          Mostrar Cliente  %02d-%02d-%d %02d:%02d         |\n", dia_atual.dia, dia_atual.mes, dia_atual.ano, dia_atual.hora_antes, dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    reservas auxr = r->prox;
    prereservas auxpre = pre->prox;

    char Nmatricula[BUFFER];
    char matricula[BUFFER];
    char nada[BUFFER];
    int count = 0;

    if (auxr == NULL){
        printf("\n->  Não existem marcações!\n\n");
    } else {
        while (1) {
            printf("\n-> Matricula da Viatura que vai procurar: ");
            fgets(nada, BUFFER, stdin);
            fgets(Nmatricula, BUFFER, stdin);
            Nmatricula[strcspn(Nmatricula, "\n")] = 0;

            strcpy(matricula, Nmatricula);

            char* token;
            token = strtok(Nmatricula, "-");
            int verifica1 = 0;
            int verifica2 = 0;
            while (token != NULL) {
                if (strlen(token) == 2) {
                    verifica2 += 2;
                }
                verifica1++;
                token = strtok(NULL, "-");
            }
            if (verifica1 == 3 && verifica2 == 6) {
                printf("    - Matrícula autorizada\n");
                break;
            }
            else {
                printf("    - A matrícula introduzida não cumpre os requesitos. Tente novamente!\n");
            }
        }

        // Percorrer a lista de reservas no sentido oposto
        reservas auxr_ant = NULL;
        while (auxr) {
            reservas temp = auxr->prox;
            auxr->prox = auxr_ant;
            auxr_ant = auxr;
            auxr = temp;
        }

        // Percorrer a lista de prereservas no sentido oposto
        prereservas auxpre_ant = NULL;
        while (auxpre) {
            prereservas temp = auxpre->prox;
            auxpre->prox = auxpre_ant;
            auxpre_ant = auxpre;
            auxpre = temp;
        }

        // Percorrer a lista de reservas no sentido oposto
        while (auxr_ant) {
            if (strcmp(auxr_ant->dados.matricula, matricula) == 0) {
                printf("\n\n-> RESERVAS\n");
                imprime_umR(auxr_ant);
                count++;
            }
            auxr_ant = auxr_ant->prox;
        }

        // Percorrer a lista de prereservas no sentido oposto
        while (auxpre_ant) {
            if (strcmp(auxpre_ant->dados.matricula, matricula) == 0) {
                printf("\n\n-> PRE-RESERVAS\n");
                imprime_umPre(auxpre_ant);
                count++;
            }
            auxpre_ant = auxpre_ant->prox;
        }

        if (count == 0) {
            printf("    - Não existe a reserva ou pre-reserva com essa matricula!\n\n");
        }
        else {
            printf("    - Todos os dados sobre essa matricula foram apresentados\n\n");
        }

    }
    le_qqlr();
}

/* Feito*/
void apaga_data(reservas r,prereservas pre,horario dia_atual){

    reservas aux = r->prox;
    prereservas aux2 = pre->prox;

    while (aux){
        if (aux->horario.nr_especial < dia_atual.nr_especial){
            eliminaR(r,aux->horario.nr_especial);
        }
        aux = aux->prox;
    }   
    while (aux2){
        if (aux2->horario.nr_especial < dia_atual.nr_especial){
            eliminaP(pre,aux2->horario.nr_especial);
        }
        aux2 = aux2->prox;
    } 
}

/*Feito*/
horario muda_data(horario dia_atual){
    printf("-----------------------------------------------------\n");
    printf("|            Mudar Data  %02d-%02d-%d %02d:%02d           |\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes);
    printf("-----------------------------------------------------\n");

    int entrada_correta=0;

    dados a;
    strcpy(a.escolha,"Limpeza");

    while (!entrada_correta){
        printf("-> Nova Data(dd-mm-aaaa): ");
        scanf("%d-%d-%d",&dia_atual.dia,&dia_atual.mes,&dia_atual.ano);

        if (dia_atual.dia == 0 || dia_atual.mes == 0 || dia_atual.ano == 0) {
            printf("    - Formato de data inválido. Utilize o formato dd-mm-aaaa.\n");
            // Limpa o buffer do scanf
            while (getchar() != '\n');
            continue;
        }


        if(!validar_data(dia_atual)){
            printf("    - A data introduzida é inválida. Por favor, introduza outra data no formato dd-mm-aaaa ou verifique se é um ano bissexto.\n");
        } else {
                printf("    - Data introduzida com sucesso!\n");
                entrada_correta=1;
        }
    }

    entrada_correta=0;

    while (!entrada_correta) {
        printf("-> Hora(hh:mm): ");
        char input[BUFFER];
        scanf("%s", input);
        getchar();

        if(strchr(input, ':') == NULL){
            printf("    - Utilize o formato hh:mm. Tente novamente!\n");
            continue;
        }

        sscanf(input, "%d:%d", &dia_atual.hora_antes, &dia_atual.minuto_antes);

        if(!validar_horas(dia_atual)){
            printf("    - Introduza horas reais. Tente novamente!\n");
        } else {
            printf("    - A hora foi introduzida com sucesso.\n");
            entrada_correta=1;
        }
    }
    
    printf("\n    -> Data alterada com sucesso!\n");

    dia_atual.nr_especial = dia_atual.ano * pow(10,8) + dia_atual.mes *  pow(10,6) + dia_atual.dia * pow(10,4) + dia_atual.hora_antes *  pow(10,2) + dia_atual.minuto_antes;
    dia_atual.duracao = 0;

    return dia_atual;
}

/* Feito*/
int le_qqlr() {
    char nada[2];

    printf("Pressione qualquer tecla para voltar ao menu.\n");
    fgets(nada,2,stdin);
    fgets(nada,2,stdin);

    return 0;
}

/* Feito*/
horario le_ficheiro(reservas r,prereservas pre){
    char linha [10000];
    
    FILE *f = fopen("dados.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir o ficheiro.\n");
    }

    struct dados d;
    struct horario a;
    struct horario dia_atual;

    while (!feof(f)) {
        fgets(linha, 10000, f);
        char *token = strtok(linha, ";");
        int aux = 0;
        int verifica = 0;
        while(token != NULL) {
            if (aux == 0){ 
                if(strcmp(token,"R") == 0){
                    verifica = 1;
                } else if (strcmp(token,"P") == 0){
                    verifica = 2;
                }
            } else if (aux == 1 && verifica != 0){
                strcpy(d.nome, token);
            } else if (aux == 2 && verifica != 0) {
                strcpy(d.numero, token);
            } else if (aux == 3 && verifica != 0 ) {
                strcpy(d.matricula, token);
            } else if (aux == 4 && verifica != 0) {
                strcpy(d.marca, token);
            } else if (aux == 5 && verifica != 0) {
                strcpy(d.escolha, token);
            } else if (aux == 6 && verifica != 0) {
                a.dia = atoi(token);
            } else if (aux == 7 && verifica != 0) {
                a.mes = atoi(token);
            } else if (aux == 8 && verifica != 0) {
                a.ano = atoi(token);
            } else if (aux == 9 && verifica != 0) {
                a.hora_antes = atoi(token);
            } else if (aux == 10 && verifica != 0) {
                a.minuto_antes = atoi(token);
            } else if (aux == 11 && verifica != 0) {
                a.duracao = atof(token); // Para Double
            } else if (aux == 12 && verifica != 0) {
                a.nr_especial = atof(token); // Para double
                if (verifica == 1){
                    insereR(r,d,a);
                } else if (verifica == 2){
                    insereP(pre,d,a);
                }
            } else if (aux == 1 && verifica == 0){
                dia_atual.dia = atoi(token);
            } else if (aux == 2 && verifica == 0){
                dia_atual.mes = atoi(token);
            } else if (aux == 3 && verifica == 0){
                dia_atual.ano = atoi(token);
            } else if (aux == 4 && verifica == 0){
                dia_atual.hora_antes = atoi(token);
            } else if (aux == 5 && verifica == 0){
                dia_atual.minuto_antes = atoi(token);
            } else if (aux == 6 && verifica == 0){
                dia_atual.duracao = atof(token);
            } else if (aux == 7 && verifica == 0){
                dia_atual.nr_especial = atof(token);
            }
            aux++;
            token = strtok(NULL, ";");
            
        }
    }
    fclose(f);
    return dia_atual;
} 

/* Feito*/
void escreve_ficheiro(reservas r,prereservas pre,horario dia_atual){
    reservas auxr = r->prox;
    prereservas auxpre = pre->prox;

    
        FILE *f = fopen("dados.txt", "w");
        if (f == NULL) {
            perror("Erro ao abrir o ficheiro.\n");
        }
        fprintf(f,"H;%d;%d;%d;%d;%d;%.0lf;%.0lf\n",dia_atual.dia,dia_atual.mes,dia_atual.ano,dia_atual.hora_antes,dia_atual.minuto_antes,dia_atual.duracao,dia_atual.nr_especial);
        while (auxr)
        {
            fprintf(f,"R;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%.0lf;%.0lf\n",auxr->dados.nome,auxr->dados.numero,auxr->dados.matricula,auxr->dados.marca,auxr->dados.escolha,auxr->horario.dia,auxr->horario.mes,auxr->horario.ano,auxr->horario.hora_antes,auxr->horario.minuto_antes,auxr->horario.duracao,auxr->horario.nr_especial);
            auxr = auxr->prox;
        }
        while (auxpre)
        {
            fprintf(f,"P;%s;%s;%s;%s;%s;%d;%d;%d;%d;%d;%.0lf;%.0lf\n",auxpre->dados.nome,auxpre->dados.numero,auxpre->dados.matricula,auxpre->dados.marca,auxpre->dados.escolha,auxpre->horario.dia,auxpre->horario.mes,auxpre->horario.ano,auxpre->horario.hora_antes,auxpre->horario.minuto_antes,auxpre->horario.duracao,auxpre->horario.nr_especial);
            auxpre = auxpre->prox;
        }

        fclose(f);
    
    
}
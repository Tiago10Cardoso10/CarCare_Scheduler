#ifndef FUNCAO_H
#define FUNCAO_H
#define  BUFFER 50

typedef struct dados{
    char numero[BUFFER];
    char nome[BUFFER];
    char escolha[BUFFER];
    char matricula[BUFFER];
    char marca[BUFFER];
} dados;

typedef struct horario{
    int dia,mes,ano;
    int hora_antes,minuto_antes;
    double duracao;
    double nr_especial;    
} horario;


// Estrutura da r Ligada

typedef struct marcacoes {
    struct dados dados;
    struct horario horario;
    struct marcacoes *prox;
} marcacoes; 


typedef marcacoes *reservas;
typedef marcacoes *prereservas;


/*------------------------------------------------------------------*/

// Funções para o funcionamento da r Ligada

reservas criaR ();

int vaziaR (reservas r);

reservas destroiR (reservas r);

void procuraR (reservas r, double chave, reservas *ant, reservas *actual);

void eliminaR (reservas r, double chave);

void insereR (reservas r, struct dados p1,struct horario p2);

reservas pesquisaR (reservas r, double chave);

void imprimeR (reservas r,horario dia_atual);

prereservas criaP ();

int vaziaP (prereservas r);

prereservas destroiP (prereservas r);

void procuraP (prereservas r, double chave, prereservas *ant, prereservas *actual);

void eliminaP (prereservas r, double chave);

void insereP (prereservas r, struct dados p1,struct horario p2);

prereservas pesquisaP (prereservas r, double chave);

void imprimeP (prereservas r,horario dia_atual);



/*-------------- Criadas por nos ---------------*/


int compara_datas(horario data_ref, horario data_user);

int validar_data(horario data);

int ano_bissexto(int ano);

int compara_horas(horario hora_user, horario horas_atual, dados d);

int validar_horas(horario horas_user);

void imprime_umR(reservas r);

void imprime_umPre(prereservas pre);

void fazer_reserva(reservas r,horario dia_atual,prereservas pre);

void cancelar_reserva(reservas r, horario dia_atual,prereservas pre);

void cancela_prereserva(prereservas pre,horario dia_atual);

void imprime_cliente(reservas r,prereservas pre,horario dia_atual);

void apaga_data(reservas r,prereservas pre,horario dia_atual);

horario muda_data(horario dia_atual);

int le_qqlr();

horario le_ficheiro(reservas r,prereservas pre);

void escreve_ficheiro(reservas r,prereservas pre,horario dia_atual);


#endif





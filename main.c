#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TAMANHO



void cat_desporto();
void cat_politica();
void cat_historia();
void cat_todas();
void mostrar_pontuacao();
void menu_cadastro();
void creditos();
void menu_categoria();

int pont_maior, pont_menor;

int errada = 0;
char resposta;

char nome[50];
int pontuacao;
int total_pontuacao;

FILE *participantes;

struct cadastro {
    char nome[50];
    int pontuacao;
}cad;



//↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-FUNÇÃO PRINCIPAL-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓-↓
int main() {


//******************************************************MENU INICIAL****************************************************


    printf("-----------------------------------------------------------------------------------\n");
    printf("|                              SEJA BEM VINDO AO QUIZ                             |\n");
    printf("-----------------------------------------------------------------------------------\n\n");


    menu_inicial:
    int opcao;

    printf("1 - JOGAR\n");
    printf("2 - CREDITOS  \n");
    printf("3 - PONTUACAO\n");
    printf("0 - SAIR  \n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            menu_cadastro();
            break;

        case 2:
            creditos();
            break;

        case 3:
            mostrar_pontuacao();
            break;


        case 0:
            printf("|Bye Bye|\n");
            exit(0);

        default:
            printf("Valor invalido\n");
            printf("Escolha uma opcao valida\n");
            goto menu_inicial;


    }

}
//↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-FIM DA FUNCAO PRINCIPAL-↑-↑-↑-↑-↑-↑↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑-↑






//********************************************MENU DE CADASTRO DOS JOGADORES********************************************

void menu_cadastro() {

    int quant = 0;
    int i;





    printf("QUANTAS PESSOAS IRAO PARTICIPAR? [Maximo 5] \n");
    scanf("%d", &quant);

    if (quant < 1 || quant > 5) {
        printf("Quantidade invalida!!!\n\n");
        menu_cadastro();
    }

//Laço FOR, para adicionar quantos participantes quiser
    for (i = 0; i < quant; i++) {

        printf("Digite o nome:\n");
        scanf("%s", &nome);


        participantes = fopen("nomes_participantes.txt", "a+");
        fwrite(nome, 50, strlen(nome), participantes);


        fclose(participantes);

    }

        menu_categoria();

}

//**************************************************MENU CATEGORIAS*****************************************************

void menu_categoria()
{
    int menu_cat;

    menu_cat:
    int opcao_cat;
    printf("=====================\n");
    printf("ESCOLHA UMA CATEGORIA\n");
    printf("=====================\n");


    printf("1 - TODAS\n");
    printf("2 - DESPORTO  \n");
    printf("3 - POLITICA  \n");
    printf("4 - HISTORIA  \n");
    printf("0 - VOLTAR AO MENU INICIAL\n");
    scanf("%d", &opcao_cat);


    switch (opcao_cat) {

        case 1:
            cat_todas();
            break;

        case 2:
            cat_desporto();
            break;


        case 3:
            cat_politica();
            break;

        case 4:
            cat_historia();
            break;

        case 0:
            main();
            break;


        default:
            printf("Valor invalido\n");
            printf("Escolha uma opcao valida\n");
            goto menu_cat;







    }


    void cat_desporto();


}

//*******************************************************CREDITOS*******************************************************

void creditos() {


    int retorno = 0;


    printf("\n~~~~~~~~~~~CREDITOS~~~~~~~~~~~\n");
    printf("Aluno: Dione Arantes\n");
    printf("Numero: 40395\n");
    printf("CURSO: Licenciatura em Engenharia da informatica\n");
    printf("DISCIPLINA: Introducao a Algoritmia e Programacao\n\n");
    printf("Pressione [1 e enter] para voltar");
    getchar();
    scanf("%d", &retorno);

    switch (retorno) {

        case 1:
            main();
            break;

        default:
            printf("Opcao invalida");
            break;
    }
}
//*************************************************SESSÃO DAS PERGUNTAS*************************************************

void cat_todas(){
    cat_politica();
    cat_desporto();
    cat_historia();
}

//**************************************************PERGUNTAS DESPORTO**************************************************
void cat_desporto() {

    printf("[DESPORTO]\n");
    printf("INICIANDO........\n\n");

    printf("Pergunta de numero 01:\n");
    printf("Quem e Cristiano Ronaldo?\n"
           "a: Um escritor\n"
           "b: Um futebolista\n"
           "c: Um lenhador\n"
           "d: Um cantor\n");

    scanf("%s", &resposta);
    if (resposta == 'b') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }

    {
        printf("Pergunta de numero 02:\n");
        printf("Quais destas equipas nao jogou Cristiano Ronaldo?\n\n"
               "a: Atletico de Madrid\n"
               "b: Real madrid\n"
               "c: Manchester United\n"
               "d: Juventus\n");

        scanf("%s", &resposta);
        if (resposta == 'a') {
            printf("Resposta correta\n\n");
            pontuacao[nome]++;
        } else {
            printf("Resposta ERRADA!!!\n\n");

        }

    }
    {
        printf("Pergunta de numero 03:\n");
        printf("Em que ano foi o ultimo titulo de Portugal na Euro Copa?\n\n"
               "a: 2015\n"
               "b: 2016\n"
               "c: 2017\n"
               "d: 2018\n");

        scanf("%s", &resposta);
        if (resposta == 'b') {
            printf("Resposta correta\n\n");
            pontuacao[nome]++;
        } else {
            printf("Resposta ERRADA!!!\n\n");


        }

    }

}

//***************************************************PERGUNTAS POLITICA*************************************************
void cat_politica() {

    printf("[POLITICA]\n");
    printf("INICIANDO........\n\n");

    printf("Pergunta de numero 01:\n");
    printf("Quem foi o presidente de Portugal em 2020?\n"
           "a: Joaquim Teofilo Fernandes Braga\n"
           "b: Sidonio Bernardino Cardoso da Silva Pais\n"
           "c: Marcelo Rebelo de Sousa\n"
           "d: Antonio Jose de Almeida\n");

    scanf("%s", &resposta);
    if (resposta == 'c') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }

    printf("Pergunta de numero 02:\n");
    printf("Quem Antonio Costa?\n"
           "a: Cantor\n"
           "b: Dancarino\n"
           "c: Pintor\n"
           "d: Primeiro Ministro\n");

    scanf("%s", &resposta);
    if (resposta == 'd') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }

    printf("Pergunta de numero 03:\n");
    printf("O que significa UE?\n"
           "a: Unidos Europeus\n"
           "b: Uniao Europeia\n"
           "c: Uniao Emponderados\n"
           "d: Unidos Estamos\n");

    scanf("%s", &resposta);
    if (resposta == 'b') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }

}

//***************************************************PERGUNTAS HISTORIA*************************************************
void cat_historia() {

    printf("[HISTORIA]\n");
    printf("INICIANDO........\n\n");

    printf("Pergunta de numero 01:\n");
    printf("QUEM FOI O PRIMEIRO REI DE PORTUGAL?\n"
           "a: D. Felipe\n"
           "b: D. Pedro IV\n"
           "c: D. Sancho\n"
           "d: D. Afonso Henriques\n");

    scanf("%s", &resposta);
    if (resposta == 'd') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }

    printf("Pergunta de numero 02:\n");
    printf("QUE NAVEGADOR DESCOBRIU, EM 1498, O CAMINHO MARITMO PARA A INDIA?\n"
           "a: D. Fernao de Magalhaes\n"
           "b: Vasco da Gama\n"
           "c: Getulio Vargas\n"
           "d: D. Pedro Alvares Cabral\n");

    scanf("%s", &resposta);
    if (resposta == 'b') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }
    printf("Pergunta de numero 03:\n");
    printf("Em que ano se deu em Lisboa o terrivel terramoto?\n"
           "a: 1755\n"
           "b: 1666\n"
           "c: 1577\n"
           "d: 1985\n");

    scanf("%s", &resposta);
    if (resposta == 'a') {
        printf("Resposta correta\n\n");
        pontuacao[nome]++;


    } else {
        printf("Resposta ERRADA!!!\n\n");

    }
}
//******************************************************PONTUACAO*******************************************************

void mostrar_pontuacao() {


    participantes = fopen("nomes_participantes.txt", "r");
    fwrite(nome, 50, strlen(nome), participantes);

    printf("Pontuacao Geral:\n", &participantes);

    fclose(participantes);

}

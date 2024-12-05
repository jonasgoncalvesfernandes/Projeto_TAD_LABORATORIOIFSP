#include <stdio.h>
// chamando a struct  do Salas.h(onde contem a struct pra armazenar as inf dos blocos e salas)
// manipulo elas a partir daqui
#include "Salas.h"
#include "Salas.c"
#include <string.h>

SalaTeorica sala[NUM_SALAS_TEORICAS] = {
    {"E", 1, 27, 40}, // Bloco E
    {"F", 2, 35, 40}, // Bloco F
    {"F", 3, 40, 40}  // Bloco F
};

LaboratorioInformatica lab[NUM_LABORATORIOS] = {
    {"I", 111, 30, 30}, // Bloco I
    {"I", 112, 30, 40}  // Bloco I
};

// exibir os dados da sala
void exibir_dados()
{
    // Exibindo as salas teóricas
    printf("Salas teoricas:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Bloco: %s, ID: %d, Capacidade Maxima: %d, Capacidade Atual: %d\n",
               sala[i].bloco, sala[i].identificacao, sala[i].capacidade_maxima, sala[i].capacidade_atual);
    }

    // Exibindo os laboratórios de informática
    printf("\nLaboratorios de informatica:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Bloco: %s, ID: %d, Capacidade Maxima(Computadores): %d, Capacidade Atual(Computadores): %d\n",
               lab[i].bloco, lab[i].identificacao, lab[i].capacidade_maxima, lab[i].capacidade_atual);
    }
}

// menu
int mostrar_menu(SalaTeorica sala[], LaboratorioInformatica lab[])
{
    int opcoes = 0;
    int opcoes2 = 0;

    do
    {
        printf("\nEscolha uma opcao\n[0] Sair\n[1] Exibir dados das salas (Teoricas e Lab. Informatica)\n[2] Taxa de ocupacao salas\n[3]Espaco campus Ordenado: ");
        scanf("%d", &opcoes);

        switch (opcoes)
        {
        case 1:
            exibir_dados();
            break;

        case 2:
            printf("\n[0] - Sair\n[1] - Taxa de ocupacao salas teoricas\n[2] - Taxa de ocupacao laboratorios de informatica\n");
            scanf("%d", &opcoes2);
            if (opcoes2 == 1)
            {
                taxa_ocupacaoT(sala); // função para calcular salas teóricas
            }
            else if (opcoes2 == 2)
            {
                Taxa_LabInformatica(lab);
            }
            break;

        case 3:
            Espaco_ordenadoCampus(lab, sala);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    } while (opcoes != 0); // O loop  só sai quando for = 0

    return 0;
}

// taxa em porcentagem da ocupação das salas
int taxa_ocupacaoT(SalaTeorica sala[])
{
    int id_sala = 0;

    printf("Digite o id da sala: ");
    scanf("%d", &id_sala);

    for (int i = 0; i < 3; i++)
    {
        if (id_sala == sala[i].identificacao)
        {
            float taxaSalas = (float)sala[i].capacidade_atual / sala[i].capacidade_maxima;
            printf("Taxa de ocupacao da sala [%d]: %.2f%%\n", id_sala, taxaSalas * 100);
            return 0; // encontrou
        }
    }

    printf("Sala nao encontrada\n");
    return -1; // Se não encontrar a sala
}

//capacidade dos computadores do laboratorio
int Taxa_LabInformatica(LaboratorioInformatica lab[])
{
    int id_lab = 0;

    printf("Digite o id do laboratorio: ");
    scanf("%d", &id_lab);

    for (int j = 0; j < 2; j++)
    {
        if (id_lab == lab[j].identificacao)
        {
            int taxaLABinfo = lab[j].capacidade_maxima - lab[j].capacidade_atual;
            printf("Capacidade de computadores Laboratorio [%d]: %d \n", id_lab, lab[j].capacidade_atual);
            printf("Computadores necessarios para ocupar 100%% da capacidade = %d", taxaLABinfo);
            return 0; // encontrou
        }
    }
    printf("Laboratorio nao encontrado\n");
    return 1; // não encontrou
}

// função pra mostrar espaços do campus ordenado
int Espaco_ordenadoCampus(LaboratorioInformatica lab[], SalaTeorica sala[])
{
    int indiceLAB[2], indiceT[3]; // armazenar os indices do lab e sala
    int i, j;

    // Inicializando os vetores de índices
    for (i = 0; i < 2; i++)
    {
        indiceLAB[i] = i; // Armazenando os índices dos laboratórios
    }
    for (i = 0; i < 3; i++)
    {
        indiceT[i] = i; // Armazenando os índices das salas
    }

    // Ordenando os índices dos laboratórios (decrescente pela capacidade máxima)
    for (i = 0; i < 2 - 1; i++)
    {
        for (j = i + 1; j < 2; j++)
        {
            if (lab[indiceLAB[i]].capacidade_maxima < lab[indiceLAB[j]].capacidade_maxima)
            {
                // Troca de índices
                int temp = indiceLAB[i];
                indiceLAB[i] = indiceLAB[j];
                indiceLAB[j] = temp;
            }
        }
    }

    // Ordenando os índices das salas teóricas (decrescente pela capacidade máxima)
    for (i = 0; i < 3 - 1; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if (sala[indiceT[i]].capacidade_maxima < sala[indiceT[j]].capacidade_maxima)
            {
                // Troca de índices
                int temp = indiceT[i];
                indiceT[i] = indiceT[j];
                indiceT[j] = temp;
            }
        }
    }

    // Exibindo os laboratórios ordenados pela capacidade máxima
    printf("\nLaboratorios ordenados pela capacidade maxima:\n");
    for (i = 0; i < 2; i++)
    {
        printf("Laboratorio: Bloco %s, ID: %d, Capacidade Atual: %d, Capacidade Maxima: %d\n",
               lab[indiceLAB[i]].bloco, lab[indiceLAB[i]].identificacao,
               lab[indiceLAB[i]].capacidade_atual, lab[indiceLAB[i]].capacidade_maxima);
    }

    // Exibindo as salas teóricas ordenadas pela capacidade máxima
    printf("\nSalas teoricas ordenadas pela capacidade maxima:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Sala: Bloco %s, ID: %d, Capacidade Atual: %d, Capacidade Maxima: %d\n",
               sala[indiceT[i]].bloco, sala[indiceT[i]].identificacao,
               sala[indiceT[i]].capacidade_atual, sala[indiceT[i]].capacidade_maxima);
    }

    return 0;
}

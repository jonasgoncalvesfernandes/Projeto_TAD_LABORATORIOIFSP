// Salas.h
#ifndef SALAS_H
#define SALAS_H
#define NUM_LABORATORIOS 2
#define NUM_SALAS_TEORICAS 3

// Declarações das structs
typedef struct {
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_maxima;
} SalaTeorica;

typedef struct {
    char bloco[3];
    int identificacao;
    int capacidade_atual;
    int capacidade_maxima;
} LaboratorioInformatica;

// Protótipos das funções
void exibir_dados();
int menu(SalaTeorica sala[], LaboratorioInformatica lab[]);
int taxa_ocupacaoT(SalaTeorica sala[]);
int Taxa_LabInformatica(LaboratorioInformatica lab[]);

#endif

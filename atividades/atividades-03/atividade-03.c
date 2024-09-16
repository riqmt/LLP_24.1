#include <stdio.h>

typedef struct {
    int matricula;
    char nome[20];
    float N1;
    float N2;
    float Media;
    int Faltas;
    char Reprovado_SN;
} Aluno;
void media(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (alunos[i].Media >= 6) {
            alunos[i].Reprovado_SN = 'S';
        } else {
            alunos[i].Media = (alunos[i].N1 + alunos[i].N2) / 2.0;
        }
    }
}
void verifica_aprovacao(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (alunos[i].Faltas >= 20) {
            alunos[i].Reprovado_SN = 'S';
        } else {
            alunos[i].Media = (alunos[i].N1 + alunos[i].N2) / 2.0;
        }
    }
}

void mostra_aprovacao(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("N1: %.2f\n", alunos[i].N1);
        printf("N2: %.2f\n", alunos[i].N2);
        printf("Media: %.1f\n", alunos[i].Media);
        printf("Faltas: %d\n", alunos[i].Faltas);
        if (alunos[i].Reprovado_SN == 'S') {
            printf("REPROVADO POR FALTA\n\n");
        } else if (alunos[i].Media < 6.0) {
            printf("REPROVADO POR MEDIA\n\n");
        } else {
            printf("APROVADO\n\n");
        }
    }
}

int main() {
    Aluno alunos[5] = {
        {1, "João", 8.5, 9.0, 0.0, 25,' '},
        {2, "Maria", 9.0, 8.0, 0.0, 1,' '},
        {3, "Pedro", 7.5, 8.5, 0.0, 3,' '},
        {4, "Ana", 9.5, 9.5, 0.0, 20,' '},
        {5, "Luiz", 8.0, 7.0, 0.0, 4,' '}
    };

    verifica_aprovacao(alunos, 5);
    mostra_aprovacao(alunos, 5);

    return 0;
};


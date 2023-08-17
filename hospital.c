#include <stdio.h>
#include <string.h>

struct data {
    int dia;
    int mes;
    int ano;
};

struct medicamento {
    char nome[50];
    struct data inicio;
};

struct pacientes {
    char nome[50];
    int idade;
    float peso;
    struct medicamento remedios[10];
};

void consultar(struct pacientes p[], int num) {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome do paciente que deseja consultar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < num; i++) {
        if (strcmp(p[i].nome, nome) == 0) {
            printf("\n--- Informações do Paciente ---\n");
            printf("Nome: %s\n", p[i].nome);
            printf("Idade: %d anos\n", p[i].idade);
            printf("Peso: %.2f kg\n", p[i].peso);
            for(int j = 0; j < 10; j++) {
                if(strlen(p[i].remedios[j].nome) != 0) {
                    printf("Medicamento %d: %s\n", j+1, p[i].remedios[j].nome);
                    printf("Data de Início: %d/%d/%d\n",
                        p[i].remedios[j].inicio.dia,
                        p[i].remedios[j].inicio.mes,
                        p[i].remedios[j].inicio.ano);
                }
            }
            printf("\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\033[31mPaciente não encontrado.\033[0m\n\n");
    }
}

struct pacientes cadastro() {
    int n, i = 0;
    struct pacientes cadastro;

    memset(&cadastro, 0, sizeof(cadastro));  // Inicializando com zeros

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", cadastro.nome);
    printf("Digite a idade de %s *APENAS NUMEROS* : ", cadastro.nome);
    scanf("%d", &cadastro.idade);
    printf("Digite o peso de %s *APENAS NUMEROS E PONTOS*: ",cadastro.nome);
    scanf("%f", &cadastro.peso);

    printf("Quantos medicamentos %s está tomando? ", cadastro.nome);
    scanf("%d", &n);

    while (i < n) {
        printf("Digite nome do %d° medicamento: ", i + 1);
        scanf(" %[^\n]", cadastro.remedios[i].nome);

        printf("Digite o dia de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.dia);
        printf("Digite o mês de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.mes);
        printf("Digite o ano de inicio do %s *APENAS NUMEROS*: ", cadastro.remedios[i].nome);
        scanf("%d", &cadastro.remedios[i].inicio.ano);

        i++;
    }

    return cadastro;
}

int main() {
    int escolha;
    struct pacientes pacientes[100];
    int numPacientes = 0;

    escolha = 0;

    while (escolha != 3) {
        printf("\n O que você deseja fazer? \n");
        printf("Digite 1 para cadastrar\n");
        printf("Digite 2 para consultar informações\n");
        printf("Digite 3 para sair\n");
        printf("Digite para o que deseja fazer: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            pacientes[numPacientes] = cadastro();
            numPacientes++;
        }

        else if (escolha == 2) {
            consultar(pacientes, numPacientes);
        }

        else if (escolha == 3) {
            printf("\nObrigado por usar nosso sistema!\n");
        }

        else {
            printf("\nOpção inválida, tente novamente.\n");
        }
    }

    return 0;
}

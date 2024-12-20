#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas
struct data_atual {
    int dia, mes, ano;
};

struct data_nascimento {
    int dia_n, mes_n, ano_n;
};

// Protótipo da função
int idade_retorna(struct data_atual data, struct data_nascimento nasc);

int main() {
    struct data_atual data;
    struct data_nascimento nasc;

    char nome[20];
    int idade;

    // Abrir e ler arquivo de entrada (arq1.txt)
    FILE *nome_aniv = fopen("arq1.txt", "r");
    if (nome_aniv == NULL) {
        perror("Erro ao abrir o arquivo arq1.txt");
        exit(1);
    }

    // Criar arquivo de saída (arq2.txt) "mostrar"
    FILE *nome_idade = fopen("arq2.txt", "w");
    if (nome_idade == NULL) {
        perror("Erro ao criar o arquivo arq2.txt");
        exit(1);
    }

    // Obter a data atual do usuário
    printf("Digite a data atual no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    // Ler os dados do arquivo e calcular a idade
    while (fscanf(nome_aniv, "%s %d/%d/%d", nome, &nasc.dia_n, &nasc.mes_n, &nasc.ano_n) == 4) {
        idade = idade_retorna(data, nasc);
        fprintf(nome_idade, "%s %d\n", nome, idade);  // Escreve o nome e a idade no arquivo de saída
    }

    // Fechar os arquivos
    fclose(nome_aniv);
    fclose(nome_idade);

    printf("Idades calculadas e salvas em 'arq2.txt'.\n");
    return 0;
}

// Função para calcular a idade
int idade_retorna(struct data_atual data, struct data_nascimento nasc) {
    int idade = data.ano - nasc.ano_n;

    // aniversários que ainda não ocorreram no ano atual
    if ((data.mes < nasc.mes_n) || ((data.mes == nasc.mes_n) && (data.dia < nasc.dia_n))) {
        idade--;
    }

    return idade;
}


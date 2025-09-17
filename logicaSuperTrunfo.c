#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int ataque;
    int defesa;
    int magia;
} Carta;

int main() {
    // Criação das cartas
    Carta c1 = {"Dragão Vermelho", 80, 60, 90};
    Carta c2 = {"Guerreiro de Aço", 75, 85, 50};
    Carta c3 = {"Princesa Guerreira", 85, 90, 60};
    Carta c4 = {"Elfo Mágico", 25, 55, 85};
    Carta c5 = {"Duende Verde", 35, 45, 75};

    Carta baralho[5] = {c1, c2, c3, c4, c5};

    int escolha1, escolha2, opcao, atributo1, atributo2;

    printf("==== SUPER TRUNFO DIGITAL DESAFIO NOVATO ====\n\n");

    // Mostrar todas as cartas
    for (int i = 0; i < 5; i++) {
        printf("Carta %d: %s (Ataque: %d, Defesa: %d, Magia: %d)\n",
               i+1, baralho[i].nome, baralho[i].ataque, baralho[i].defesa, baralho[i].magia);
    }

    // Jogador escolhe duas cartas para duelar
    printf("\nEscolha a primeira carta (1 a 5): ");
    scanf("%d", &escolha1);
    printf("Escolha a segunda carta (1 a 5): ");
    scanf("%d", &escolha2);

    // Ajustar índices (vetor começa em 0)
    escolha1--; 
    escolha2--;

    Carta carta1 = baralho[escolha1];
    Carta carta2 = baralho[escolha2];

    printf("\nDuelo entre: %s VS %s\n", carta1.nome, carta2.nome);

    // Menu principal
    printf("\nEscolha o modo de jogo:\n");
    printf("1 - Comparar por 1 atributo (if / if-else)\n");
    printf("2 - Comparar por múltiplos atributos (switch / if-else-if)\n");
    printf("3 - Comparar por 2 atributos (operador ternário)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("\nEscolha o atributo para comparação:\n");
            printf("1 - Ataque\n2 - Defesa\n3 - Magia\n");
            scanf("%d", &atributo1);

            if(atributo1 == 1) {
                if(carta1.ataque > carta2.ataque) printf("%s venceu!\n", carta1.nome);
                else if(carta1.ataque < carta2.ataque) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else if(atributo1 == 2) {
                if(carta1.defesa > carta2.defesa) printf("%s venceu!\n", carta1.nome);
                else if(carta1.defesa < carta2.defesa) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else if(atributo1 == 3) {
                if(carta1.magia > carta2.magia) printf("%s venceu!\n", carta1.nome);
                else if(carta1.magia < carta2.magia) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else {
                printf("Atributo inválido!\n");
            }
            break;

        case 2:
            printf("\nEscolha um critério:\n");
            printf("1 - Ataque + Defesa\n");
            printf("2 - Ataque + Magia\n");
            printf("3 - Defesa + Magia\n");
            scanf("%d", &atributo1);

            if(atributo1 == 1) {
                int soma1 = carta1.ataque + carta1.defesa;
                int soma2 = carta2.ataque + carta2.defesa;
                if(soma1 > soma2) printf("%s venceu!\n", carta1.nome);
                else if(soma1 < soma2) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else if(atributo1 == 2) {
                int soma1 = carta1.ataque + carta1.magia;
                int soma2 = carta2.ataque + carta2.magia;
                if(soma1 > soma2) printf("%s venceu!\n", carta1.nome);
                else if(soma1 < soma2) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else if(atributo1 == 3) {
                int soma1 = carta1.defesa + carta1.magia;
                int soma2 = carta2.defesa + carta2.magia;
                if(soma1 > soma2) printf("%s venceu!\n", carta1.nome);
                else if(soma1 < soma2) printf("%s venceu!\n", carta2.nome);
                else printf("Empate!\n");
            } else {
                printf("Opção inválida!\n");
            }
            break;

        case 3: {
            printf("\nEscolha os dois atributos (1=Ataque, 2=Defesa, 3=Magia):\n");
            scanf("%d %d", &atributo1, &atributo2);

            int valor1 = 0, valor2 = 0;

            valor1 += (atributo1 == 1 ? carta1.ataque : (atributo1 == 2 ? carta1.defesa : carta1.magia));
            valor1 += (atributo2 == 1 ? carta1.ataque : (atributo2 == 2 ? carta1.defesa : carta1.magia));

            valor2 += (atributo1 == 1 ? carta2.ataque : (atributo1 == 2 ? carta2.defesa : carta2.magia));
            valor2 += (atributo2 == 1 ? carta2.ataque : (atributo2 == 2 ? carta2.defesa : carta2.magia));

            (valor1 > valor2) ? printf("%s venceu!\n", carta1.nome) :
            (valor1 < valor2) ? printf("%s venceu!\n", carta2.nome) :
                                printf("Empate!\n");
            break;
        }
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}

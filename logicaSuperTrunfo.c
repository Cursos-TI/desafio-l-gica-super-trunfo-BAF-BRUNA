#include <stdio.h>

// Estrutura das cartas
typedef struct {
    char estado[3];
    char codigo[5];
    char cidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para comparação automática
void compararCartas(Carta c1, Carta c2) {
    printf("\n===== COMPARAÇÃO AUTOMÁTICA =====\n");

    // População
    printf("\nPopulação: %d x %d -> ", c1.populacao, c2.populacao);
    if (c1.populacao > c2.populacao) printf("%s venceu!\n", c1.cidade);
    else if (c2.populacao > c1.populacao) printf("%s venceu!\n", c2.cidade);
    else printf("Empate!\n");

    // Área
    printf("Área: %.2f x %.2f -> ", c1.area, c2.area);
    if (c1.area > c2.area) printf("%s venceu!\n", c1.cidade);
    else if (c2.area > c1.area) printf("%s venceu!\n", c2.cidade);
    else printf("Empate!\n");

    // PIB
    printf("PIB: %.2f x %.2f -> ", c1.pib, c2.pib);
    if (c1.pib > c2.pib) printf("%s venceu!\n", c1.cidade);
    else if (c2.pib > c1.pib) printf("%s venceu!\n", c2.cidade);
    else printf("Empate!\n");

    // Pontos turísticos
    printf("Pontos turísticos: %d x %d -> ", c1.pontosTuristicos, c2.pontosTuristicos);
    if (c1.pontosTuristicos > c2.pontosTuristicos) printf("%s venceu!\n", c1.cidade);
    else if (c2.pontosTuristicos > c1.pontosTuristicos) printf("%s venceu!\n", c2.cidade);
    else printf("Empate!\n");

    // Densidade populacional (menor vence)
    float d1 = c1.populacao / c1.area;
    float d2 = c2.populacao / c2.area;
    printf("Densidade populacional: %.2f x %.2f -> ", d1, d2);
    if (d1 < d2) printf("%s venceu! (menor densidade)\n", c1.cidade);
    else if (d2 < d1) printf("%s venceu! (menor densidade)\n", c2.cidade);
    else printf("Empate!\n");

    printf("===============================\n");
}

int main() {
    Carta c1, c2;
    int opcao;

    printf("==== SUPER TRUNFO DIGITAL - NÍVEL NOVATO ====\n\n");

    // Cadastro de cartas
    for (int i = 0; i < 2; i++) {
        Carta *c = (i == 0) ? &c1 : &c2;
        printf("Cadastro da carta %d:\n", i + 1);
        printf("Estado (sigla): ");
        scanf("%s", c->estado);
        printf("Código da carta: ");
        scanf("%s", c->codigo);
        printf("Nome da cidade: ");
        scanf(" %[^\n]", c->cidade);
        printf("População: ");
        scanf("%d", &c->populacao);
        printf("Área (km²): ");
        scanf("%f", &c->area);
        printf("PIB (em bilhões): ");
        scanf("%f", &c->pib);
        printf("Número de pontos turísticos: ");
        scanf("%d", &c->pontosTuristicos);
        printf("\n");
    }

    // Exibe resumo
    printf("===== CARTAS CADASTRADAS =====\n");
    printf("1 - %s (%s)\n", c1.cidade, c1.estado);
    printf("2 - %s (%s)\n", c2.cidade, c2.estado);

    // Escolha do modo
    printf("\nEscolha o modo de comparação:\n");
    printf("1 - Comparar por atributo (modo simples)\n");
    printf("2 - Comparar automaticamente todos os atributos\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        int atributo;
        printf("\nAtributos disponíveis:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional (menor vence)\n");
        printf("Escolha o número do atributo: ");
        scanf("%d", &atributo);

        // Comparação simples
        if (atributo == 1) {
            if (c1.populacao > c2.populacao) printf("%s venceu!\n", c1.cidade);
            else if (c2.populacao > c1.populacao) printf("%s venceu!\n", c2.cidade);
            else printf("Empate!\n");
        } else if (atributo == 2) {
            if (c1.area > c2.area) printf("%s venceu!\n", c1.cidade);
            else if (c2.area > c1.area) printf("%s venceu!\n", c2.cidade);
            else printf("Empate!\n");
        } else if (atributo == 3) {
            if (c1.pib > c2.pib) printf("%s venceu!\n", c1.cidade);
            else if (c2.pib > c1.pib) printf("%s venceu!\n", c2.cidade);
            else printf("Empate!\n");
        } else if (atributo == 4) {
            if (c1.pontosTuristicos > c2.pontosTuristicos) printf("%s venceu!\n", c1.cidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos) printf("%s venceu!\n", c2.cidade);
            else printf("Empate!\n");
        } else if (atributo == 5) {
            float d1 = c1.populacao / c1.area;
            float d2 = c2.populacao / c2.area;
            if (d1 < d2) printf("%s venceu! (menor densidade)\n", c1.cidade);
            else if (d2 < d1) printf("%s venceu! (menor densidade)\n", c2.cidade);
            else printf("Empate!\n");
        } else {
            printf("Opção inválida!\n");
        }
    } 
    else if (opcao == 2) {
        compararCartas(c1, c2);
    } 
    else {
        printf("Opção inválida!\n");
    }

    // Mensagem final
    printf("\n========================================\n");
    printf("🎯 Fim do jogo! Obrigado por jogar o Super Trunfo Digital!\n");
    printf("========================================\n");

    return 0;
}

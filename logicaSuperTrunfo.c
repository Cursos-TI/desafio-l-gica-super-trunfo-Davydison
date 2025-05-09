#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Dados da Carta 1
    char nomePais1[50] = "Brasil";
    int populacao1 = 214000000;
    float area1 = 8515767.0;
    float pib1 = 1800.0; // em bilhões
    int pontos1 = 100;
    float densidade1 = populacao1 / area1;

    // Dados da Carta 2
    char nomePais2[50] = "Argentina";
    int populacao2 = 45000000;
    float area2 = 2780000.0;
    float pib2 = 600.0; // em bilhões
    int pontos2 = 70;
    float densidade2 = populacao2 / area2;

    int atributo1 = -1, atributo2 = -1;
    float valor1Carta1, valor2Carta1, valor1Carta2, valor2Carta2;
    float soma1 = 0.0, soma2 = 0.0;

    // Menu de seleção do primeiro atributo
    printf("=== SUPER TRUNFO - COMPARAÇÃO DE DOIS ATRIBUTOS ===\n\n");
    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Verificação básica de validade
    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5) {
        printf("\nErro: Atributos inválidos ou repetidos. Encerrando o programa.\n");
        return 1;
    }

    // Função auxiliar para obter o valor de cada atributo para cada carta
    float getValor(int atributo, int carta) {
        switch (atributo) {
            case 1: return (carta == 1) ? (float)populacao1 : (float)populacao2;
            case 2: return (carta == 1) ? area1 : area2;
            case 3: return (carta == 1) ? pib1 : pib2;
            case 4: return (carta == 1) ? (float)pontos1 : (float)pontos2;
            case 5: return (carta == 1) ? densidade1 : densidade2;
            default: return 0.0;
        }
    }

    // Obtem valores dos atributos para cada carta
    valor1Carta1 = getValor(atributo1, 1);
    valor1Carta2 = getValor(atributo1, 2);
    valor2Carta1 = getValor(atributo2, 1);
    valor2Carta2 = getValor(atributo2, 2);

    // Exibição dos atributos
    printf("\nComparando %s e %s:\n", nomePais1, nomePais2);

    char *nomesAtributos[] = {
        "", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"
    };

    // Comparação do primeiro atributo
    printf("\nAtributo 1: %s\n", nomesAtributos[atributo1]);
    printf("%s: %.2f\n", nomePais1, valor1Carta1);
    printf("%s: %.2f\n", nomePais2, valor1Carta2);

    int venceu1 = (atributo1 == 5) ? (valor1Carta1 < valor1Carta2) : (valor1Carta1 > valor1Carta2);
    printf("Vencedor no atributo 1: %s\n", venceu1 ? nomePais1 : (valor1Carta1 == valor1Carta2 ? "Empate" : nomePais2));
    soma1 += valor1Carta1;
    soma2 += valor1Carta2;

    // Comparação do segundo atributo
    printf("\nAtributo 2: %s\n", nomesAtributos[atributo2]);
    printf("%s: %.2f\n", nomePais1, valor2Carta1);
    printf("%s: %.2f\n", nomePais2, valor2Carta2);

    int venceu2 = (atributo2 == 5) ? (valor2Carta1 < valor2Carta2) : (valor2Carta1 > valor2Carta2);
    printf("Vencedor no atributo 2: %s\n", venceu2 ? nomePais1 : (valor2Carta1 == valor2Carta2 ? "Empate" : nomePais2));
    soma1 += valor2Carta1;
    soma2 += valor2Carta2;

    // Exibe soma e resultado final
    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomePais1, soma1);
    printf("%s: %.2f\n", nomePais2, soma2);

    printf("Vencedor Final: ");
    printf((soma1 > soma2) ? "%s\n" : (soma2 > soma1) ? "%s\n" : "Empate!\n",
           (soma1 > soma2) ? nomePais1 : nomePais2);
}

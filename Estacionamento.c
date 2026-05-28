#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int menu() {
    printf("Bem vindo ao sistema do estacionamento!\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Cadastrar entrada de veiculo\n");
    printf("2 - Alterar ou remover veiculo \n");
    printf("3 - Listar todas as vagas e veiculos\n");
    printf("4 - Buscar veiculo por vaga\n");
    printf("5 - Exibir total de vagas cheias\n");
    printf("0 - Sair\n");
    
    printf("Qual sua escolha? ");
    int escolha;
    scanf("%d", &escolha);
    return escolha;
}
void EntradaVeiculo (
    char placa[][6],
    char modelo[][30],
    char marca[][30],
    char cor[][30],
    int vaga[10],
    int totalVeiculos
) {

    getchar();

    printf("Placa do veiculo: ");
    fgets(placa[totalVeiculos], sizeof(placa[totalVeiculos]), stdin);

    printf("Modelo do veiculo: ");
    fgets(modelo[totalVeiculos], sizeof(modelo[totalVeiculos]), stdin);

    printf("Marca do veiculo: ");
    fgets(marca[totalVeiculos], sizeof(marca[totalVeiculos]), stdin);

    printf("Cor do veiculo: ");
    fgets(cor[totalVeiculos], sizeof(cor[totalVeiculos]), stdin);

    printf("Vaga ocupada: ");
    scanf("%d", &vaga[totalVeiculos]);

    totalVeiculos++;

    printf("Cadastro completo com sucesso!\n");
    printf("Aperte qualquer botao para voltar ao menu: ");
    getch();
    system("cls");
}

int main() {
    int totalVeiculos = 0;
    char placa[10][6];
    char modelo[10][30];
    char marca[10][30];
    char cor [10][30];
    int vaga[10];
    int escolha;
    
    escolha = menu();
    
    while(true){
        switch (escolha){
            case 1:
                EntradaVeiculo(placa, modelo, marca , cor, vaga ,totalVeiculos);
                escolha = menu();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
}
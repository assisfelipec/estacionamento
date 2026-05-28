#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void EntradaVeiculo(
    char placa[][6],
    char modelo[][30],
    char marca[][30],
    char cor[][30],
    int vaga[10],
    int totalVeiculos
) {


    printf("Placa do veículo: ");
    fgets(placa[totalVeiculos], sizeof(placa[totalVeiculos]), stdin);
    printf("Modelo do veículo: ");
    fgets(modelo[totalVeiculos], sizeof(modelo[totalVeiculos]), stdin);
    printf("Marca do veículo: ");
    fgets(marca[totalVeiculos], sizeof(marca[totalVeiculos]), stdin);
    printf("Cor do veículo: ");
    fgets(cor[totalVeiculos], sizeof(cor[totalVeiculos]), stdin);
    printf("Vaga ocupada: ");
    scanf("%d", &vaga[totalVeiculos]);

    totalVeiculos++;

    printf("Cadastro completo com sucesso!");

}

int main(){
    int totalVeiculos = 0;

    char placa[10][6];
    char modelo[10][30];
    char marca[10][30];
    char cor [10][30];
    int vaga[10];

    int escolha;
    printf("Bem vindo ao sistema do estacionamento!\n");
    printf("Escolha uma opção:");
    printf("1 - Cadastrar entrada de veículo");
    printf("2 - Alterar ou remover veículo ");
    printf("3 - Listar todas as vagas e veículos");
    printf("4 - Buscar veículo por vaga");
    printf("5 - Exibir total de vagas cheias");
    printf("0 - Sair");
    scanf("%d", &escolha);

    while(true){
        switch (escolha){
            case 1:
                EntradaVeiculo(placa, modelo, marca , cor, vaga ,totalVeiculos);
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
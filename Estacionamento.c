#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void SairDaTela(){
    printf("Aperte qualquer botao para voltar ao menu: ");
    getch();
    system("cls");
}

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
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[10],
    int *totalVeiculos
) {
    system("cls");
    getchar();

    printf("Placa do veiculo: ");
    fgets(placa[*totalVeiculos], sizeof(placa[*totalVeiculos]), stdin);

    printf("Marca do veiculo: ");
    fgets(marca[*totalVeiculos], sizeof(marca[*totalVeiculos]), stdin);

    printf("Modelo do veiculo: ");
    fgets(modelo[*totalVeiculos], sizeof(modelo[*totalVeiculos]), stdin);

    printf("Cor do veiculo: ");
    fgets(cor[*totalVeiculos], sizeof(cor[*totalVeiculos]), stdin);

    printf("Vaga que vai ser ocupada: ");
    scanf("%d", &vaga[*totalVeiculos]);

    (*totalVeiculos)++;

    printf("Cadastro completo com sucesso!\n");
    SairDaTela();
}

void AlterarOuRemover(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[10],
    int *totalVeiculos
) {
    int veiculoASerEditado;

    system("cls");
    printf("Veiculo de qual vaga deseja editar? ");
    scanf("%d", &veiculoASerEditado);

    printf("1 - Veiculo cadastrado na vaga %d\n", veiculoASerEditado);
    printf("2 - Placa do veiculo: %s", placa[veiculoASerEditado - 1]);
    printf("3 - Marca do veiculo: %s", marca[veiculoASerEditado - 1]);
    printf("4 - Modelo do veiculo: %s", modelo[veiculoASerEditado - 1]);
    printf("5 - Cor do veiculo: %s", cor[veiculoASerEditado - 1]);

    printf("O que deseja editar? ");
    getch();
}

void ListarVagasCheias(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[10],
    int totalVeiculos,
    int vagasTotais
) {

    system("cls");
    printf("Todas as vagas cheias:\n");

    for(int v = 1; v <= vagasTotais; v++){
        for(int i = 0; i < totalVeiculos; i++){
            if(vaga[i] == v){
                printf("Vaga numero: %d\n", vaga[i]);
                printf("Placa do veiculo: %s", placa[i]);
                printf("Marca do veiculo: %s", marca[i]);
                printf("Modelo do veiculo: %s", modelo[i]);
                printf("Cor do veiculo: %s\n", cor[i]);
            }
        }
    }

    SairDaTela();
}

void BuscarVeiculoPorVaga(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[10],
    int totalVeiculos,
    int vagasTotais
) {

    int vagaDesejada;
    bool vagaVazia = true;
    system("cls");
    printf("Qual vaga deseja ver o veiculo? ");
    scanf("%d", &vagaDesejada);

    for(int i = 0; i <= totalVeiculos; i++){
        if(vaga[i] == vagaDesejada){
            if(placa[i][0] != '\0'){
                printf("Placa do veiculo: %s", placa[i]);
                printf("Marca do veiculo: %s", marca[i]);
                printf("Modelo do veiculo: %s", modelo[i]);
                printf("Cor do veiculo: %s\n", cor[i]);

                vagaVazia = false;
            }
        }
    }

    if(vagaVazia){
        printf("\nVaga vazia\n");
    }

    SairDaTela();
}

void ExibirTotalDeVagas(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[10],
    int totalVeiculos,
    int vagasTotais
) {

    int vagasPreenchidas = 0;
    system("cls");
    printf("Total de veículos: %d", totalVeiculos);
    printf("\nVagas preenchidas: \n");

    for(int i = 0; i < totalVeiculos; i++){
        printf("%d\n", vaga[i]);
    }
    
    SairDaTela();
}

int main() {
    int vagasTotais = 10;
    int totalVeiculos = 0;
    char placa[10][10];
    char marca[10][30];
    char modelo[10][30];
    char cor [10][30];
    int vaga[vagasTotais];
    int escolha;
    
    escolha = menu();
    
    while(escolha != 0){    
        switch (escolha){
            case 1:
                EntradaVeiculo(placa, marca, modelo , cor, vaga ,&totalVeiculos);
                break;
            case 2:
                AlterarOuRemover(placa, marca, modelo , cor, vaga ,&totalVeiculos);
                break;
            case 3:
                ListarVagasCheias(placa, marca, modelo , cor, vaga , totalVeiculos, vagasTotais);
                break;
            case 4:
                BuscarVeiculoPorVaga(placa, marca, modelo , cor, vaga , totalVeiculos, vagasTotais);
                break;
            case 5:
                ExibirTotalDeVagas(placa, marca, modelo , cor, vaga , totalVeiculos, vagasTotais);
                break;
        }      
        escolha = menu();
    }

    system("cls");
    printf("Fim do sistema");

}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_VAGAS 10

void SairDaTela(){
    printf("\nAperte qualquer botao para voltar ao menu...");
    getch();
    system("cls");
}

int menu() {
    int escolha;

    printf("Bem vindo ao sistema do estacionamento!\n");
    printf("Escolha uma opcao:\n");
    printf("1 - Cadastrar entrada de veiculo\n");
    printf("2 - Alterar ou remover veiculo\n");
    printf("3 - Listar todas as vagas e veiculos\n");
    printf("4 - Buscar veiculo por vaga\n");
    printf("5 - Exibir total de vagas cheias\n");
    printf("0 - Sair\n");

    printf("Qual sua escolha? ");
    scanf("%d", &escolha);

    return escolha;
}

void RemoverQuebraLinha(char texto[]){
    texto[strcspn(texto, "\n")] = '\0';
}

void EntradaVeiculo(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[],
    int *totalVeiculos,
    int vagasTotais
){
    system("cls");

    if(*totalVeiculos >= vagasTotais){

        printf("Estacionamento lotado!\n");
        SairDaTela();
        return;

    }

    printf("Vaga que vai ser ocupada: ");
    scanf("%d", &vaga[*totalVeiculos]);

    if(vaga[*totalVeiculos] < 1 || vaga[*totalVeiculos] > vagasTotais){
        
        printf("Vaga invalida!\n");
        SairDaTela();
        return;

    }

    for(int i = 0; i < *totalVeiculos; i++){

        if(vaga[i] == vaga[*totalVeiculos]){

            printf("Essa vaga ja esta ocupada!\n");
            SairDaTela();
            return;

        }
    }

    getchar();

    printf("Placa do veiculo: ");
    fgets(placa[*totalVeiculos], 10, stdin);
    RemoverQuebraLinha(placa[*totalVeiculos]);

    printf("Marca do veiculo: ");
    fgets(marca[*totalVeiculos], 30, stdin);
    RemoverQuebraLinha(marca[*totalVeiculos]);

    printf("Modelo do veiculo: ");
    fgets(modelo[*totalVeiculos], 30, stdin);
    RemoverQuebraLinha(modelo[*totalVeiculos]);

    printf("Cor do veiculo: ");
    fgets(cor[*totalVeiculos], 30, stdin);
    RemoverQuebraLinha(cor[*totalVeiculos]);

    (*totalVeiculos)++;

    printf("\nCadastro realizado com sucesso!\n");
    SairDaTela();
}

void AlterarAtributo(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[],
    int totalVeiculos,
    int vagaEscolhida
){
    int opcao;
    
    system("cls");

    printf("O que deseja alterar?\n");
    printf("1 - Placa\n");
    printf("2 - Marca\n");
    printf("3 - Modelo\n");
    printf("4 - Cor\n");
    printf("Qual sua escolha? ");
    scanf("%d", &opcao);

    getchar();

    for(int i = 0; i < totalVeiculos; i++){

        if(vaga[i] == vagaEscolhida){

            switch(opcao){

                case 1:
                    printf("Nova placa: ");
                    fgets(placa[i], 10, stdin);
                    RemoverQuebraLinha(placa[i]);
                    break;

                case 2:
                    printf("Nova marca: ");
                    fgets(marca[i], 30, stdin);
                    RemoverQuebraLinha(marca[i]);
                    break;

                case 3:
                    printf("Novo modelo: ");
                    fgets(modelo[i], 30, stdin);
                    RemoverQuebraLinha(modelo[i]);
                    break;

                case 4:
                    printf("Nova cor: ");
                    fgets(cor[i], 30, stdin);
                    RemoverQuebraLinha(cor[i]);
                    break;

                default:
                    printf("\nEscolha invalida!\n");
                    return;
            }

            printf("Alteracao realizada com sucesso!\n");
            return;

        }
    }
}

void RemoverVeiculo(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[],
    int *totalVeiculos,
    int vagaEscolhida
){
    for(int i = 0; i < *totalVeiculos; i++){

        if(vaga[i] == vagaEscolhida){

            for(int j = i; j < *totalVeiculos - 1; j++){

                strcpy(placa[j], placa[j + 1]);
                strcpy(marca[j], marca[j + 1]);
                strcpy(modelo[j], modelo[j + 1]);
                strcpy(cor[j], cor[j + 1]);

                vaga[j] = vaga[j + 1];
            }

            (*totalVeiculos)--;

            printf("Veiculo removido com sucesso!\n");
            return;

        }
    }

    printf("Veiculo nao encontrado!\n");
}

void MenuAlterarOuRemover(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[],
    int *totalVeiculos
){
    int vagaEscolhida;
    int escolha;
    int indice = -1;

    system("cls");

    if(*totalVeiculos == 0){
        printf("Nao existem veiculos cadastrados.\n");
        SairDaTela();
        return;
    }

    printf("Digite a vaga do veiculo: ");
    scanf("%d", &vagaEscolhida);

    for(int i = 0; i < *totalVeiculos; i++){
        
        if(vaga[i] == vagaEscolhida){

            indice = i;
            break;

        }
    }

    if(indice == -1){
        
        printf("Vaga vazia!\n");
        SairDaTela();
        return;

    }

    system("cls");

    printf("Veiculo encontrado:\n");
    printf("Vaga: %d\n", vaga[indice]);
    printf("Placa: %s\n", placa[indice]);
    printf("Marca: %s\n", marca[indice]);
    printf("Modelo: %s\n", modelo[indice]);
    printf("Cor: %s\n", cor[indice]);

    printf("\n1 - Alterar atributos\n");
    printf("2 - Remover veiculo\n");
    printf("0 - Voltar\n");

    printf("Qual sua escolha? ");
    scanf("%d", &escolha);

    switch(escolha){

        case 1:
            AlterarAtributo(
                placa,
                marca,
                modelo,
                cor,
                vaga,
                *totalVeiculos,
                vagaEscolhida
            );
            break;

        case 2:
            RemoverVeiculo(
                placa,
                marca,
                modelo,
                cor,
                vaga,
                totalVeiculos,
                vagaEscolhida
            );
            break;

        case 0:
            return;

        default:
            printf("Escolha invalida!\n");
    }

    SairDaTela();
}

void ListarVagasCheias(
    char placa[][10],
    char marca[][30],
    char modelo[][30],
    char cor[][30],
    int vaga[],
    int totalVeiculos,
    int vagasTotais
){
    system("cls");

    if(totalVeiculos == 0){
        printf("Nenhuma vaga ocupada.\n");
        SairDaTela();
        return;
    }

    printf("Veiculos cadastrados:\n\n");

    for(int v = 1; v <= vagasTotais; v++){

        for(int i = 0; i < totalVeiculos; i++){

            if(vaga[i] == v){

                printf("Vaga: %d\n", vaga[i]);
                printf("Placa: %s\n", placa[i]);
                printf("Marca: %s\n", marca[i]);
                printf("Modelo: %s\n", modelo[i]);
                printf("Cor: %s\n", cor[i]);
                printf("----------------------------\n");
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
    int vaga[],
    int totalVeiculos
){
    int vagaDesejada;
    bool encontrada = false;

    system("cls");

    printf("Qual vaga deseja consultar? ");
    scanf("%d", &vagaDesejada);

    for(int i = 0; i < totalVeiculos; i++){

        if(vaga[i] == vagaDesejada){

            printf("\nPlaca: %s\n", placa[i]);
            printf("Marca: %s\n", marca[i]);
            printf("Modelo: %s\n", modelo[i]);
            printf("Cor: %s\n", cor[i]);

            encontrada = true;
            break;
        }
    }

    if(!encontrada){
        printf("\nVaga vazia!\n");
    }

    SairDaTela();
}

void ExibirTotalDeVagas(
    int vaga[],
    int totalVeiculos,
    int vagasTotais
){
    system("cls");

    printf("Total de vagas: %d\n", vagasTotais);
    printf("Vagas ocupadas: %d\n", totalVeiculos);
    printf("Vagas livres: %d\n", vagasTotais - totalVeiculos);

    printf("\nVagas ocupadas:\n");

    if(totalVeiculos == 0){

        printf("Nenhuma.\n");

    } else {

        for(int i = 0; i < totalVeiculos; i++){

            printf("%d\n", vaga[i]);

        }
    }

    SairDaTela();
}

int main(){

    int vagasTotais = MAX_VAGAS;
    int totalVeiculos = 0;

    char placa[MAX_VAGAS][10] = {0};
    char marca[MAX_VAGAS][30] = {0};
    char modelo[MAX_VAGAS][30] = {0};
    char cor[MAX_VAGAS][30] = {0};

    int vaga[MAX_VAGAS] = {0};

    int escolha;

    do{

        system("cls");

        escolha = menu();

        switch(escolha){

            case 1:
                EntradaVeiculo(
                    placa,
                    marca,
                    modelo,
                    cor,
                    vaga,
                    &totalVeiculos,
                    vagasTotais
                );
                break;

            case 2:
                MenuAlterarOuRemover(
                    placa,
                    marca,
                    modelo,
                    cor,
                    vaga,
                    &totalVeiculos
                );
                break;

            case 3:
                ListarVagasCheias(
                    placa,
                    marca,
                    modelo,
                    cor,
                    vaga,
                    totalVeiculos,
                    vagasTotais
                );
                break;

            case 4:
                BuscarVeiculoPorVaga(
                    placa,
                    marca,
                    modelo,
                    cor,
                    vaga,
                    totalVeiculos
                );
                break;

            case 5:
                ExibirTotalDeVagas(
                    vaga,
                    totalVeiculos,
                    vagasTotais
                );
                break;

            case 0:
                break;

            default:
                printf("Escolha invalida!\n");
                SairDaTela();
        }

    }while(escolha != 0);

    system("cls");
    printf("Fim do sistema.\n");

    return 0;
}
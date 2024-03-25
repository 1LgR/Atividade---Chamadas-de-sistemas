#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    //Variável para armazenar o nome do diretório fornecido pelo usuário
    char nome_diretorio[100];

    //Solicita ao usuário que forneça o nome do diretório a ser criado
    printf("Digite o nome do diretório a ser criado: ");
    scanf("%99s", nome_diretorio);  //Lê o nome do diretório, limitando a 99 caracteres

    //Chama a função mkdir() para criar o diretório com o nome fornecido pelo usuário
    if (mkdir(nome_diretorio, 0777) == -1) {
        //Em caso de erro, exibe uma mensagem de erro
        perror("Erro ao criar diretório");
        exit(EXIT_FAILURE); //Encerra o programa com código de erro
    } else {
        //Se o diretório foi criado com sucesso, exibe uma mensagem de sucesso
        printf("Diretório \"%s\" criado com sucesso.\n", nome_diretorio);
    }

    return 0;
}

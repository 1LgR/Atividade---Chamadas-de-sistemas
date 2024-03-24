#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;  // Descritor de arquivo
    char ch;  // Variável para armazenar o caractere lido
    int uptime_segundos;  // Variável para armazenar o tempo de atividade em segundos

    // Abre o arquivo /proc/uptime para leitura
    fd = open("/proc/uptime", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo /proc/uptime");
        exit(EXIT_FAILURE);
    }

    // Lê o conteúdo do arquivo /proc/uptime para obter o tempo de atividade em segundos
    if (read(fd, &ch, 1) == -1) {
        perror("Erro ao ler o arquivo /proc/uptime");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Fecha o arquivo após a leitura do tempo de atividade
    close(fd);

    // Converte o caractere lido para o formato de tempo de atividade em segundos
    uptime_segundos = atoi(&ch);

    // Calcula o tempo de atividade em horas, minutos e segundos
    int horas = uptime_segundos / 3600;
    int minutos = (uptime_segundos % 3600) / 60;
    int segundos = uptime_segundos % 60;

    // Imprime o tempo de atividade no formato padrão do comando uptime
    printf("%02d:%02d:%02d up  %d:%02d,  0 users,  load average: 0.00, 0.00, 0.00\n",
           horas, minutos, segundos, horas, minutos);

    return 0;
}

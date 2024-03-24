#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 128

int main() {
    int fd;  // Descritor de arquivo
    char buf[BUF_SIZE];  // Buffer para armazenar os dados lidos
    double uptime_seconds;  // Variável para armazenar o tempo de atividade em segundos

    // Abre o arquivo /proc/uptime para leitura
    fd = open("/proc/uptime", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo /proc/uptime");
        exit(EXIT_FAILURE);
    }

    // Lê o conteúdo do arquivo /proc/uptime para obter o tempo de atividade em segundos
    ssize_t bytes_read = read(fd, buf, BUF_SIZE);
    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo /proc/uptime");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Fecha o arquivo após a leitura do tempo de atividade
    close(fd);

    // Converte os valores lidos para o tempo de atividade em segundos
    uptime_seconds = atof(buf);

    // Calcula o tempo de atividade em horas, minutos e segundos
    int hours = uptime_seconds / 3600;
    int minutes = ((int)uptime_seconds % 3600) / 60;

    // Imprime o tempo de atividade no formato padrão do comando uptime
    printf("%02d:%02d:00 up %d minutes\n", hours, minutes, hours * 60 + minutes);

    return 0;
}

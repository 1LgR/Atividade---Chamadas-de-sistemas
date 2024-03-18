#include <stdio.h>
#include <time.h>

int main() {
    struct timespec current_time;

    // Obter o tempo atual do relógio em tempo real
    clock_gettime(CLOCK_REALTIME, &current_time);

    // Converter o tempo para uma estrutura de tempo
    time_t atual = current_time.tv_sec;
    struct tm *tm_info;
    tm_info = localtime(&atual);

    // Mapeamento dos nomes dos meses
    const char *meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // Mapeamento dos nomes dos dias
    const char *dias[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Formatar e exibir a data e hora atual
    printf("%s %s %02d %02d:%02d:%02d -03 %d\n", 
           dias[tm_info->tm_wday],   // Mês
           meses[tm_info->tm_mon],  // Dia da semana
           tm_info->tm_mday,               // Dia do mês
           tm_info->tm_hour,               // Hora
           tm_info->tm_min,                // Minuto
           tm_info->tm_sec,                // Segundo
           tm_info->tm_year + 1900);       // Ano

    return 0;
}

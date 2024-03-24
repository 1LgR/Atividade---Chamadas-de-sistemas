# Atividade-Chamadas-de-sistemas
Atividade da disciplina de sistemas operacionais.

## date
O comando date depende de chamadas de sistema para obter a hora atual. Normalmente, ele faz uso da função gettimeofday() ou clock_gettime(), que são chamadas de sistema responsáveis por obter o tempo atual do sistema. Essas chamadas de sistema acessam um contador de tempo de hardware mantido pelo kernel do Linux.

A função que eu utilizo é a clock_gettime(), ela permite que sistema acesse um relógio específico, como o relógio de tempo real (CLOCK_REALTIME), que fornece o tempo do sistema em relação ao Unix Epoch (00:00:00 UTC em 1 de janeiro de 1970), com precisão em nanossegundos. 

## uptime

A chamada de sistema uptime é utilizada para obter informações sobre o tempo de atividade do sistema operacional. Quando você executa o comando uptime no kernel do linux, ele mostra o tempo que o sistema está funcionando, bem como outras informações relevantes, como o número de usuários logados e a carga média do sistema nos últimos 1, 5 e 15 minutos.

Internamente, a chamada de sistema uptime obtém essas informações consultando o arquivo /proc/uptime. Este arquivo contém dois números separados por um espaço em branco: o primeiro número representa o tempo em segundos desde que o sistema foi inicializado, e o segundo número representa o tempo que o sistema passou em estado ocioso.

## ls

O comando ls abre um programa que usa chamadas de sistema do Linux para interagir com o sistema de arquivos e listar o conteúdo de um diretório específico.

Para listar os conteúdos de um diretório, o programa ls pode usar várias chamadas de sistema do Linux, como opendir(), readdir() e closedir() para abrir, ler e fechar diretórios, respectivamente. Ele também pode usar chamadas de sistema de obtenção de atributos de arquivos, como stat() ou lstat(), para obter informações sobre os arquivos no diretório.
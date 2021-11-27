#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//jantar dos filósofos
pthread_mutex_t H[5];
pthread_t threads[5];

void *filosofo(void *ptr)
{
int n = *((int *)ptr);
while (1)
{
printf("filósofo %d pensando...\n", n);
//o quarto filósofo pega seus hashis na ordem inversa, prevenindo um deadlock
if (n != 4)
pthread_mutex_lock(&H[n]), pthread_mutex_lock(&H[(n + 1) % 5]);
else
pthread_mutex_lock(&H[(n + 1) % 5]), pthread_mutex_lock(&H[n]);
printf("filósofo %d comendo com os hashis %d e %d\n", n, n, (n + 1) % 5);
pthread_mutex_unlock(&H[(n + 1) % 5]), pthread_mutex_unlock(&H[n]);
printf("filósofo %d terminou!\n", n);
}
}

int main()
{
    int threadN[5];

    for (int i = 0; i < 5; i++)
    {
        threadN[i] = i;
        pthread_create(&threads[i], NULL, filosofo, &threadN[i]);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(threads[i], NULL);

    return 0;
}

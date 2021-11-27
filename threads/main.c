#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *threadA()
{
	for (int i; i < 10; i++)
	{
		printf("Thread A: %d/10\n", i + 1);
		sleep(1);
	}
	return NULL;
}

void *threadB()
{
	for (int i; i < 10; i++)
	{
		printf("Thread B: %d/10\n", i + 1);
		sleep(1);
	}
	return NULL;
}

int teste(){
	printf("opa");
}

int main()
{
	pthread_t a;
	pthread_t b;

	printf("iniciando...\n");

	pthread_create(&a, NULL, threadA, NULL);
	pthread_create(&b, NULL, threadB, NULL);

	pthread_join(a, NULL);
	pthread_join(b, NULL);

	return 0;
}

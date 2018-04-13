#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define RDSIZE 5
#define WRSIZE 3

pthread_rwlock_t rwlock;
int counter = 0;

void *route_read(void *arg)
{
	int i = (int)arg;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("read %d: %#X, counter = %d\n", i, pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(900);
	}
}

void *route_write(void *arg)
{
	int i = (int)arg;
	int t = 0;
	while(1)
	{
		usleep(1000);
		t = counter;
		pthread_rwlock_wrlock(&rwlock);
		printf("write %d: %#X, counter = %d, ++counter = %d\n", i, pthread_self(), t, ++counter);
		pthread_rwlock_unlock(&rwlock);
		usleep(5000);
	}
}
int main(void)
{
	pthread_t tid[RDSIZE+WRSIZE];

	pthread_rwlock_init(&rwlock, NULL);
	int i = 0;
	for(; i < RDSIZE; i++)
		pthread_create(tid+i, NULL, route_read, (void*)i);
	for(i = 0; i < WRSIZE; i++)
		pthread_create(tid+RDSIZE+i, NULL, route_write, (void*)i);
	
	for(i = 0; i < RDSIZE+WRSIZE; i++)
		pthread_join(tid[i], NULL);

	pthread_rwlock_destroy(&rwlock);

	return 0;
}

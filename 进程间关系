#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR_EXIT(m) \
	do\
	{\
		printf(m);\
		exit(EXIT_FAILURE);\
	}while(0)
/*
int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		ERR_EXIT("fork");
	
	else if(pid == 0)
	{
		if(fork() < 0)
			ERR_EXIT("fork");
		while(1);
	}
	else
	{
		sleep(10);
		printf("process group quit\n");
		exit(EXIT_SUCCESS);
	}

	return 0;
}
*/


int main()
{
	pid_t pid;
	if((pid = fork()) < 0)
		ERR_EXIT("fork");
	else if(pid == 0)
	{
		while(1)
		{
			printf("Child run, pid :%d\n", getpid());
			sleep(1);
		}
	}
	else
	{
		int i = 1;
		while(i <= 5)
		{
			printf("%dsecond, father :%d\n", i, getpid());
			i++;
			sleep(1);
		}
	}

	return 0;
}

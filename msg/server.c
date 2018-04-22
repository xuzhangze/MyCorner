#include "comm.h"

int main()
{
	char buf[1024];
	int msgid = CreatMsgQueue();
	if(msgid == -1)
	{
		perror("CreatMsgQueue");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		memset(buf, 0x00, sizeof(buf));
		if(ReceiveMsg(msgid, (void*)buf, CLIEN_TYPE) == -1)
		{
			perror("ReceiveMsg");
			exit(EXIT_FAILURE);
		}
		if(strcpy(buf, "quit") == 0)
			break;
		printf("cline:>");
		printf("%s", buf);
		memset(buf, 0x00, sizeof(buf));
		printf("sever:>");
		if(read(0, buf, 1024) < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		if(SendMsg(msgid, buf, SERVER_TYPE) == -1)
		{
			perror("SendMsg");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

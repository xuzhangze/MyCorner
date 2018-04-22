#include "comm.h"

int main()
{
	char buf[1024];
	int msgid = GetMsgQueue();
	if(msgid == -1)
	{
		perror("GetMsgQueue");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		memset(buf, 0x00, sizeof(buf));
		printf("cline:>");
		if((read(0, buf, 1024)) < 0)
		{
			perror("ReceiveMsg");
			exit(EXIT_FAILURE);
		}
		if(SendMsg(msgid, buf, SERVER_TYPE) == -1)
		{
			perror("SendMsg");
			exit(EXIT_FAILURE);
		}
		memset(buf, 0x00, sizeof(buf));
		if(ReceiveMsg(msgid, buf, CLIEN_TYPE) == -1)
		{
			perror("ReceiveMsg");
			exit(EXIT_FAILURE);
		}
		printf("sever:>");
		printf("%s", buf);
	}

	return 0;
}

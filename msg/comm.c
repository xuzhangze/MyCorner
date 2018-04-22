#include "comm.h"

static int _GetCommMsgQueue(int flag)
{
	key_t key = ftok(PATHNAME, PROJ_ID);
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}
	int msg = msgget(key, flag);
	if(msg == -1)
	{
		perror("msgget");
		return -1;
	}
	return msg;
}

int CreatMsgQueue()
{
	return _GetCommMsgQueue(IPC_CREAT|IPC_EXCL|0666);
}
int GetMsgQueue()
{
	return _GetCommMsgQueue(IPC_CREAT);
}

int DestoryMsgQueue(int msgid)
{
	if(msgctl(msgid, IPC_RMID, NULL) == -1)	
	{
		perror("msgctl");
		return -1;
	}
	return 0;
}

int SendMsg(int msgid, char *msgp, long msgtype)
{
	assert(NULL != msgp);
	struct mymsg msg;
	msg.mtype = msgtype;
	strcpy(msg.mtext, msgp);

	if(msgsnd(msgid, (void*)&msg, sizeof(msg.mtext), 0) == -1)
	{
		perror("msgsnd");
		return -1;
	}
	return 0;
}

int ReceiveMsg(int msgid, void *buf, long msgtype)
{
	assert(NULL != buf);
	int size = 0;
	if((size = msgrcv(msgid, buf, 1024, msgtype, 0)) == -1)
	{
		perror("msgrcv");
		return -1;
	}
	return 0;
}
















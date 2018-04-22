#ifndef __COMM_H_
#define __COMM_H_

#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define PATHNAME "./tmp"
#define PROJ_ID 0x6666

#define SERVER_TYPE 1
#define CLIEN_TYPE 2

struct mymsg
{
	long mtype;
	char mtext[1024];
};

int CreatMsgQueue();
int GetMsgQueue();
int DestoryMsgQueue(int msgid);
int SendMsg(int msgid, char *msgp, long msgtype);
int ReceiveMsg(int msgid, void *buf, long msgtype);

#endif

///Linuxƽ̨��posix��׼�Ļ�������ͷ�ļ�����
/***********************************************************************
ϵͳ����: 
ģ������:
�� �� ��: config_posix.h
����˵��:
��    ��: 
��������: 2013-7-11   9:14:00
�޸ļ�¼:
***********************************************************************/
#ifndef _CONFIG_POSIX_H_
#define _CONFIG_POSIX_H_

#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/ioctl.h>
#include <strings.h>
#include <sys/socket.h>
#include <dlfcn.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <errno.h>
#include <dirent.h>
#include <fnmatch.h>
#include <limits.h>
#include <ctype.h>
#include <sys/poll.h>
#include <netipx/ipx.h>


///����linux/unix��Ŀ¼·���ַ�������󳤶�
#ifndef MAX_PATH
    #define MAX_PATH			256
#endif

static const int INFINITE = (-1);

#endif

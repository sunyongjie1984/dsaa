///��ƽ̨��������ͷ�ļ�����
/***********************************************************************
ϵͳ����: NEEQ1.0
ģ������:
�� �� ��: config_env.h
����˵��:
��    ��: �����
��������: 2013-7-11   9:13:37
�޸ļ�¼:
***********************************************************************/
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <new>
#include <error.h>
#include <syslog.h>

#include "os/config_posix.h"


#define FBASE_NEW new(std::nothrow)

/* os��İ汾��Ϣ */
#define NEEQ_OS_VERSION     "V2.0.0 ("__DATE__" "__TIME__")"

#endif

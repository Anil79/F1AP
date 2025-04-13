#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <resolv.h>


#ifndef SI_F1AP_18_4__H
#define SI_F1AP_18_4__H

#include "sirik_socket.h"
#include "F1AP_18.4.h"
#include "F1AP_18.4_Facade.h"

typedef int (*F1AP__FPointer_OnConnect)( SI_Socket * siSocket);

void F1AP__InitStack( char * logsPath);
void F1AP__SetHost( char * ipv4_1, char * ipv4_2, int port);
void F1AP__SetOnMessageRecv( fp_f1ap_on_message handler );
void F1AP__SetOnConnect( F1AP__FPointer_OnConnect fp);
void F1AP__AddServer( char * ipv4_1, char * ipv4_2, int port);
void F1AP__StartStack();


#endif





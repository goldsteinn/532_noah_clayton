//General configuration information for lib/*/IO/

#ifndef _IO_CONFIG_H_
#define _IO_CONFIG_H_

#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <event.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/thread.h>
#include <event2/event-config.h>
#include <event2/event_compat.h>


#define DEFAULT_NTHREADS      1
#define DEFAULT_MAX_RECEIVERS 64

#define LISTEN_QUE (1 << 10)


#define LOCAL_IP (char *)"127.0.0.1"


#define DEFAULT_SERVER_IP LOCAL_IP
#define DEFAULT_PORTNO     6004


#endif

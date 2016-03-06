#ifndef _MULTIPLEXER_H
#define _MULTIPLEXER_H

#include <cstdio>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "selector.h"
#include "poller.h"
#include "epoller.h"

class multiplexer {
public:
    multiplexer(unsigned short multimplexerId = 0);    // 0 for select, 1 for poll, 2 for epoll
    ~multiplexer();
    void run();
private:
    unsigned short multiplexerId;
    selector *st;
};

#endif  /* _MULTIPLEXER_H */


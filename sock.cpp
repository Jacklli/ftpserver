#include "sock.h"
sock::sock() {
    this->s = s;
    this->sflag = sflag;
    this->addr = addr;
    this->setNonblock();
}

sock::setNonBlock() {
    this->sflags = fcntl(sock, F_GETFL); // Get socket flags
    int opts = fcntl(sock,F_GETFL, 0);
    if (opts < 0) {
        std::cerr << "Error getting socket flags" << std::endl;
        return;
    }
    opts = (opts | O_NONBLOCK);
    if (fcntl(sock,F_SETFL,opts) < 0) {
        std::cerr << "Error setting socket to non-blocking" << std::endl;
        return;
    }
}


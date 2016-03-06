#include "selector.h"

selector::selector() { 
    this->sk = new sock();
    this->highSock = 0;
}

selector::~selector {
    delete this->sk;
}

void selector::buildSelectList() {
    FD_ZERO(&(this->socks));
    FD_SET(this->s, &(this->socks));

    std::vector<serverconnection*>::iterator iter = this->connections.begin();
    while( iter != this->connections.end() ) {
        if ((*iter)->getCloseRequestStatus() == true) {
            std::cout << "Connection with Id " << (*iter)->getConnectionId() << " closed! " << std::endl;
            delete (*iter);
            this->connections.erase(iter);
            if (this->connections.empty() || (iter == this->connections.end()))
                return;
        } else {
            int currentFD = (*iter)->getFD();
            if (currentFD != 0) {
                FD_SET(currentFD, &(this->socks));
                if (currentFD > this->highSock)
                    this->highSock = currentFD;
            }
        }
        ++iter;
    }
}
void selector::readSockets() {
    // OK, now socks will be set with whatever socket(s) are ready for reading. First check our "listening" socket, and then check the sockets in connectlist
    // If a client is trying to connect() to our listening socket, select() will consider that as the socket being 'readable' and thus, if the listening socket is part of the fd_set, accept a new connection
    if (FD_ISSET(this->s,&(this->socks))) {
//        this->handleNewConnection();
        if (this->handleNewConnection()) return; // Always check for errors
    }
    // Now check connectlist for available data
    // Run through our sockets and check to see if anything happened with them, if so 'service' them
    for (unsigned int listnum = 0; listnum < this->connections.size(); listnum++) {
        if (FD_ISSET(this->connections.at(listnum)->getFD(),&(this->socks))) {
            this->connections.at(listnum)->respondToQuery(); // Now that data is available, deal with it!
        }
    }
}
void selector::run() {
    struct timeval timeout;
    int readsocks;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    while (!this->shutdown) {
        this->buildSelectList();
        readsocks = select(this->highSock+1, &(this->socks), (fd_set*)0, (fd_set*)0, &timeout);

        if (readsocks < 0) {
            std::cerr << "Error calling select" << std::endl;
            return (EXIT_FAILURE);
        }

        this->readSockets();
    }
    return (EXIT_SUCCESS);

}

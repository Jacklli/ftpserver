#include "sock.h"

class selector {
    public:
        selector(int s, int sflags, sockaddr_in addr);
        ~selector();
    private:
        std::vector<serverconnection*> connections;
        int highSock;
        fd_set socks;
        sock *sk; 
}

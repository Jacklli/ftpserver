#include "sock.h"
#include "serverconnection.h"

class selector {
    public:
        selector();
        ~selector();
        void buildSelectList();
        void run();
        void readSockets();
    private:
        std::vector<serverconnection*> connections;
        int highSock;
        fd_set socks;
        sock *sk; 
}

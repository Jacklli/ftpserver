selector::selector(int s, int sflags, sockaddr_in addr) { 
    this->sk = new sock(s, sflags, addr);
    this->highSock = 0;
}

selector::~selector {
    delete this->sk;
}

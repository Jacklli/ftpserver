class sock {
    public:
        sock();
        ~sock();
    private:
        int s;
        int sflags;
        sockaddr_in addr;
        void setNonBlock();
        void initSock();
}

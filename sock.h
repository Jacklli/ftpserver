class sock {
    public:
        sock(int s, int sflag, sockaddr_in addr);
        ~sock();
    private:
        int s;
        int sflags;
        sockaddr_in addr;
        void setNonBlock();
}

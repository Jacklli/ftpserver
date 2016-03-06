multiplexer::multiplexer(multimplexerId) {
    if(multimplexerId)
        this->multimplexerId = multimplexerId;
    if(0 == this->multimplexerId) { //selector
        this->st = new selector(s, sflags, addr);
    }
}

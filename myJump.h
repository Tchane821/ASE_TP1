typedef int funct_t(int);

struct ctx_s {
    void *ctx_esp;
    void *ctx_ebp;
    unsigned ctx_magic;
};

int mul(int d);

int shintMule(int v);

int tryIt(struct ctx_s *pctx, funct_t *f, int arg);

int throwIt(struct ctx_s *pctx, int r);

void copyBuf(struct ctx_s pctx);



#ifndef CTX_PHM_Y22_MYJUMP_H
#define CTX_PHM_Y22_MYJUMP_H
#endif //CTX_PHM_Y22_MYJUMP_H

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



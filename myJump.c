#include "myJump.h"
#include <stdio.h>
#include <assert.h>

#define CTXMAGIC 0x73478336

static int thr;
static struct ctx_s pctx_buf;

int mul(int d) {
    int i;
    switch (scanf("%d", &i)) {
        case EOF:
            return 1;
        case 0:
            return mul(d + 1);
        case 1:
            if (i) {
                return i * mul(d + 1);
            } else {
                return 0;
            }
    }
}

int tryIt(struct ctx_s *pctx, funct_t *f, int arg) {
    copyBuf(*pctx);
    asm("movl %0, %%esp"
    :
    :"r"(pctx->ctx_esp));

    asm("movl %0, %%ebp"
    :
    :"r"(pctx->ctx_ebp));

    pctx->ctx_magic = CTXMAGIC;
    return f(arg);
}

void copyBuf(struct ctx_s pctx){
    pctx_buf.ctx_ebp = pctx.ctx_ebp;
    pctx_buf.ctx_esp = pctx.ctx_esp;
    pctx_buf.ctx_magic = pctx.ctx_magic;
}

int throwIt(struct ctx_s *pctx, int r) {
    //assert( pctx->ctx_magic == CTXMAGIC );
    thr = r;
    /*asm("movl %%esp, %0"
    :"=r"(pctx->ctx_esp));
    asm("movl %%ebp, %0"
    :"=r"(pctx->ctx_ebp));*/
    return thr;
}

int shintMule(int d) {
    int i;
    switch (scanf("%d", &i)) {
        case EOF:
            return 1;
        case 0:
            return mul(d + 1);
        case 1:
            if (i) {
                return i * mul(d + 1);
            } else {
                throwIt(&pctx_buf, 0);
            }
    }
}


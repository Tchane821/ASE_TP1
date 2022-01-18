#include <stdio.h>
#include "myJump.h"

static struct ctx_s pctx_buf;

int main() {
    int prod1;
    prod1 = mul(0);
    printf("prod1 = %d\n", prod1);

    int prod2;
    prod2 = tryIt(&pctx_buf, shintMule, 0);
    printf("prod2 = %d\n", prod2);
}

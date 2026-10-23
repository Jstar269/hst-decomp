/* HSTMATCH module=EBOOT.BIN start=0x001bc7e0 end=0x001bca0c symbol=FUN_001bc7e0 lang=c99 */
extern void FUN_000114c0(void *, int, int);
extern void FUN_001bc748(void *);
extern volatile unsigned int DAT_00310fc8;

#define RND_20000() (x = DAT_00310fc8 * 0x343fd + 0x269ec3, DAT_00310fc8 = x, \
                     (int)((x & 0x7fffffff) >> 0x10) % 20000 + 2000)

void FUN_001bc7e0(unsigned char *p, int flag)
{
    unsigned char *q;
    unsigned int x;
    int i;

    if (flag == 0) {
        FUN_000114c0(p, 0, 0x20cc);
        *(float *)(p + 0x1c) = 5.0f;
    } else {
        p[0] = 1;
        p[1] = 1;
        *(int *)(p + 4) = 99999;
        *(int *)(p + 8) = 9999;
        *(int *)(p + 0xc) = 9999;
        *(int *)(p + 0x10) = 9999;
        *(int *)(p + 0x14) = 9999;
        *(int *)(p + 0x18) = 9999;
        *(float *)(p + 0x1c) = 20.0f;
        *(int *)(p + 0x2084) = 100;
        *(int *)(p + 0x208c) = 99999;
        i = 0;
        q = p;
        do {
            i = i + 6;
            *(int *)(q + 0x2004) = RND_20000();
            *(int *)(q + 0x2008) = RND_20000();
            *(int *)(q + 0x200c) = RND_20000();
            *(int *)(q + 0x2010) = RND_20000();
            *(int *)(q + 0x2014) = RND_20000();
            *(int *)(q + 0x2018) = RND_20000();
            q = q + 0x18;
        } while (i < 0xd);
        *(int *)(p + i * 4 + 0x2004) = RND_20000();
        FUN_001bc748(p + 0x20);
    }
}

// 151/139 words. The volatile RNG global (no CSE, one lui per read) and the 6x-per-
// iteration unroll are right; this version is 12 words over with one callee-saved
// register short (s0-s3 vs s0-s4) because the flag==0 arm is placed inline instead of
// at the end (retail: beqz a1 -> 0x1bc9d8, the big init is the fallthrough).
// near miss from lane fm8 (unreviewed)

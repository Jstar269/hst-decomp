/* HSTMATCH module=EBOOT.BIN start=0x00259cd8 end=0x00259fbc symbol=FUN_00259cd8 lang=c++ */
// NEAR MISS: 180/185 words (retail 0x259cd8..0x259fbc). Everything matches word-for-word except the
// per-iteration flag store in the loop tail and the five words retail spends there:
//   ours   (12 words): addu v0,v0,s0 / lbu a0,7117(v0) / lbu v0,7080(v0) / sltu v1,zero,v0 /
//                      bnezl v1,L / addu v0,s4,s3 (delay) / andi v0,a0,0xff / xor v1,v0,zero /
//                      sltiu v1,v1,1 / addu v0,s4,s3 / sb v1,1356(v0)
//   retail (17 words): addu v1,v0,s0 / lbu v0,7080(v1) / lbu a1,7117(v1) / sltu v1,zero,v0 /
//                      sltu a0,zero,v1 / bnezl a0,L / sltu v0,zero,v1 (delay) / sltu v0,zero,a1 /
//                      xori a0,v0,0x1 / sltu v0,zero,v1 / addu v1,s4,s3 / sb a0,1356(v1) /
//                      bnez v0,M / addiu v1,v1,1356 (delay) / sltu v0,zero,a1 / xori v0,v0,0x1 /
//                      sb v0,0(v1)
// Retail stores the same byte TWICE per iteration (both stores write `flag ? 1 : (y == 0)`: the
// first via a0, the second via v0) and recomputes `y == 0` for each store; ours stores once.
// Everything else is exact: prologue (s0-s4 only), the two leading `if (p) p->m5(-1)` vtable calls,
// the `s3 < (f644 ? 2 : 4)` loop bound re-read from memory every iteration (MWCC cannot hoist the
// load because the body stores into the same object), and all ten `if (p) fun(p,-1)` cleanups with
// MWCC's beqzl delay-slot streaming. Ruled out for the tail (compiled, measured, all MISMATCH):
//   `b[i] = (x != 0) || (y == 0);`                       180/185
//   `b[i] = x || !y;`                                    179/185
//   `b[i] = !(!x && y);` / `!(x == 0 && y != 0)`         180/185, 181/185
//   `b[i] = x ? 1 : (y == 0);`                           180/185
//   `b[i] = (x != 0) ? true : (y == 0);`                 180/185
//   `b[i] = (x != 0) | (y == 0);`                        178/185
//   `if (flag) b[i] = 1; else b[i] = (y == 0);`          182/185
//   `if (flag) b[i] = true; else b[i] = (y == 0);`       182/185
//   `if (!flag) b[i] = (y == 0); else b[i] = flag;`      compile error (bool -> unsigned char)
//   two identical ternary statements                    189/185
//   `if/else` twice                                      193/185
//   `if/else` + `b[i] = flag;` (closest shape: retail's branch structure, one store too many) 186/185
//   chained store `b[i] = (b[i] = expr);`                181/185
//   volatile r + separate c                              185/185 words but tail still wrong
// Not attempted further: the duplication is an MWCC artifact of two same-valued stores in the
// original source; no natural spelling found in ~40 compiles.
extern "C" void FUN_000ffc3c(void *, int);
extern "C" void FUN_001031e8(void *);
extern "C" void FUN_002546b4(void *);
extern "C" void FUN_001033e8(void *, int, float);
extern "C" void FUN_00103474(void *);

struct VObj {
    virtual void m0();
    virtual void m1();
    virtual void m2(int);
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
    virtual void m6();
    virtual void m7();
    virtual int m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12(int);
};

extern "C" void FUN_00259cd8(char *self)
{
    int i;

    if (*(VObj **)(self + 88))
        (*(VObj **)(self + 88))->m5(-1);
    if (*(VObj **)(self + 1624))
        (*(VObj **)(self + 1624))->m5(-1);

    for (i = 0; i < (*(unsigned char *)(self + 1604) ? 2 : 4); i++) {
        if (*(void **)(self + 164 * i + 648)) FUN_000ffc3c(*(void **)(self + 164 * i + 648), -1);
        if (*(void **)(self + 164 * i + 652)) FUN_000ffc3c(*(void **)(self + 164 * i + 652), -1);
        if (*(void **)(self + 4 * i + 1360)) FUN_000ffc3c(*(void **)(self + 4 * i + 1360), -1);
        if (*(VObj **)(self + 4 * i + 1376)) (*(VObj **)(self + 4 * i + 1376))->m5(-1);
        if (*(VObj **)(self + 4 * i + 1392)) (*(VObj **)(self + 4 * i + 1392))->m5(-1);
        if (*(void **)(self + 164 * i + 624)) FUN_000ffc3c(*(void **)(self + 164 * i + 624), -1);
        if (*(void **)(self + 164 * i + 628)) FUN_000ffc3c(*(void **)(self + 164 * i + 628), -1);
        if (*(void **)(self + 164 * i + 632)) FUN_000ffc3c(*(void **)(self + 164 * i + 632), -1);
        if (*(void **)(self + 164 * i + 636)) FUN_000ffc3c(*(void **)(self + 164 * i + 636), -1);
        if (*(void **)(self + 164 * i + 640)) FUN_000ffc3c(*(void **)(self + 164 * i + 640), -1);

        char *t = *(char **)(self + 1600) + 1112 * i;
        unsigned char x = *(unsigned char *)(t + 7080);
        unsigned char y = *(unsigned char *)(t + 7117);
        *(unsigned char *)(self + 1356 + i) = (x != 0) || (y == 0);
    }

    if (*(void **)(self + 1668)) {
        VObj *o = *(VObj **)(self + 1668);
        o->m2(1);
        if (((VObj *)self)->m8())
            FUN_001031e8(self);
        o->m2(0);
        if (((VObj *)self)->m8())
            FUN_002546b4(self + 96);
        FUN_001033e8(self, 0, 100000.0f);
        o->m5(-1);
        o->m12(1);
        FUN_00103474(self);
    } else {
        if (((VObj *)self)->m8())
            FUN_001031e8(self);
        if (((VObj *)self)->m8()) {
            if ((*(unsigned short *)(*(int *)(self + 660) + 14) & 3) == 0)
                FUN_002546b4(self + 96);
        }
    }
}
// near miss from lane ds2 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x001ffdbc end=0x001fff40 symbol=FUN_001ffdbc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_002ef130;
extern "C" char DAT_002ef160;
extern "C" char DAT_002ef108;
extern "C" char DAT_002c9148;
extern "C" char DAT_002c935c;
extern "C" char DAT_002c92f8;
extern "C" int DAT_0034a144;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00102e38(void *);
extern "C" void FUN_002172f4(void *, void *, int);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, int, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_0021704c(void *, void *, void *, int);
extern "C" void FUN_000ffc3c(void *, int);
extern "C" void FUN_00217704(void *, void *);
extern "C" void FUN_00217614(void *, void *);

extern "C" void FUN_001ffdbc(char *o) {
    void *p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_00102e38(p);
    }
    *(void **)(o + 4) = p;
    FUN_002172f4(&DAT_0034a144, &DAT_002ef130, 0x4e);
    FUN_00104118(*(void **)(o + 4), &DAT_002ef160, 0);
    FUN_00103540(*(void **)(o + 4), 2250.0f);
    FUN_001037c8(*(void **)(o + 4), -16);
    FUN_00216e90(o + 8, *(void **)(o + 4), &DAT_002ef108, 10);
    FUN_00216f14(o + 0x30, o + 8, DAT_0034a144, 0x4e);
    FUN_00216fb0(o + 0x648, o + 8, &DAT_002c9148, 13);
    FUN_00217188(o + 0x708, o + 8, &DAT_002c935c);
    FUN_0021704c(o + 0x6e4, o + 8, &DAT_002c92f8, 3);
    int v = *(int *)(o + 0x708);
    *(int *)(v + 0xd8) = 0;
    *(char *)(v + 0x114) = 1;
    FUN_000ffc3c(*(void **)(o + 0x634), -4096);
    FUN_00217704(o + 0x718, *(void **)(o + 8));
    FUN_00217704(o + 0x7a4, *(void **)(o + 0x20));
    FUN_00217704(o + 0x830, *(void **)(o + 0x28));
    FUN_00217704(o + 0x8bc, *(void **)(o + 0x10));
    FUN_00217704(o + 0x948, *(void **)(o + 0x14));
    FUN_00217704(o + 0x9d4, *(void **)(o + 0x18));
    FUN_00217704(o + 0xa60, *(void **)(o + 0x1c));
    FUN_00217614(o + 0xaec, *(void **)(o + 0x56c));
    FUN_00217614(o + 0xb78, *(void **)(o + 0x634));
}

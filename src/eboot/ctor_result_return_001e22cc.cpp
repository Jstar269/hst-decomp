/* HSTMATCH module=EBOOT.BIN start=0x001e22cc end=0x001e23ac symbol=FUN_001e22cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_002ebf88;
extern "C" char DAT_002ebc5c;
extern "C" char DAT_002c8430;
extern "C" char DAT_002c857c;
extern "C" char DAT_002c85a0;

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_00217778(void *, void *);

extern "C" void FUN_001e22cc(char *o) {
    int p;
    FUN_00104118(*(void **)(o + 0x21e4), &DAT_002ebf88, 0);
    FUN_00103540(*(void **)(o + 0x21e4), 2900.0f);
    FUN_001037c8(*(void **)(o + 0x21e4), -256);
    FUN_00216e90(o + 0x21e8, *(void **)(o + 0x21e4), &DAT_002ebc5c, 1);
    FUN_00216f14(o + 0x21ec, o + 0x21e8, &DAT_002c8430, 10);
    FUN_00216fb0(o + 0x22b4, o + 0x21e8, &DAT_002c857c, 1);
    FUN_00217188(o + 0x22c0, o + 0x21e8, &DAT_002c85a0);
    p = *(int *)(o + 0x22c0);
    *(int *)(p + 0xd8) = 0;
    *(char *)(p + 0x114) = 1;
    FUN_00217778(o + 0x22c4, *(void **)(o + 0x21e4));
    *(int *)(o + 0x2358) = (int)*(float *)(*(int *)(o + 0x22b8) + 100);
}

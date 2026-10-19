/* HSTMATCH module=EBOOT.BIN start=0x001e23ac end=0x001e248c symbol=FUN_001e23ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_002ebfbc;
extern "C" char DAT_002ebc68;
extern "C" char DAT_002c85c4;
extern "C" char DAT_002c8750;
extern "C" char DAT_002c8774;

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_00217778(void *, void *);

extern "C" void FUN_001e23ac(char *o) {
    int p;
    FUN_00104118(*(void **)(o + 0x235c), &DAT_002ebfbc, 0);
    FUN_00103540(*(void **)(o + 0x235c), 2900.0f);
    FUN_001037c8(*(void **)(o + 0x235c), -256);
    FUN_00216e90(o + 0x2360, *(void **)(o + 0x235c), &DAT_002ebc68, 1);
    FUN_00216f14(o + 0x2364, o + 0x2360, &DAT_002c85c4, 12);
    FUN_00216fb0(o + 0x2454, o + 0x2360, &DAT_002c8750, 1);
    FUN_00217188(o + 0x2460, o + 0x2360, &DAT_002c8774);
    p = *(int *)(o + 0x2460);
    *(int *)(p + 0xd8) = 0;
    *(char *)(p + 0x114) = 1;
    FUN_00217778(o + 0x22c4, *(void **)(o + 0x235c));
    *(int *)(o + 0x2358) = (int)*(float *)(*(int *)(o + 0x2458) + 100);
}

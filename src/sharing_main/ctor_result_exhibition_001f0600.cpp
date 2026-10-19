/* HSTMATCH module=hstp_trans_main.prx start=0x001f0600 end=0x001f06e0 symbol=FUN_001f0600 lang=c++ */
/* Clone of src/eboot/ctor_result_exhibition_001e23ac.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_00393ed4;
extern "C" char DAT_00393b74;
extern "C" char DAT_002d8a04;
extern "C" char DAT_002d8b90;
extern "C" char DAT_002d8bb4;

extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void FUN_00225e94(void *, void *, void *, int);
extern "C" void FUN_00225f18(void *, void *, void *, int);
extern "C" void FUN_00225fb4(void *, void *, void *, int);
extern "C" void FUN_0022618c(void *, void *, void *);
extern "C" void FUN_00226820(void *, void *);

extern "C" void FUN_001f0600(char *o) {
    int p;
    FUN_00109a44(*(void **)(o + 0x235c), &DAT_00393ed4, 0);
    FUN_00108e6c(*(void **)(o + 0x235c), 2900.0f);
    FUN_001090f4(*(void **)(o + 0x235c), -256);
    FUN_00225e94(o + 0x2360, *(void **)(o + 0x235c), &DAT_00393b74, 1);
    FUN_00225f18(o + 0x2364, o + 0x2360, &DAT_002d8a04, 12);
    FUN_00225fb4(o + 0x2454, o + 0x2360, &DAT_002d8b90, 1);
    FUN_0022618c(o + 0x2460, o + 0x2360, &DAT_002d8bb4);
    p = *(int *)(o + 0x2460);
    *(int *)(p + 0xd8) = 0;
    *(char *)(p + 0x114) = 1;
    FUN_00226820(o + 0x22c4, *(void **)(o + 0x235c));
    *(int *)(o + 0x2358) = (int)*(float *)(*(int *)(o + 0x2458) + 100);
}

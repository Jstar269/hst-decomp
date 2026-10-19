/* HSTMATCH module=hstp_trans_main.prx start=0x001f0520 end=0x001f0600 symbol=FUN_001f0520 lang=c++ */
/* Clone of src/eboot/ctor_result_return_001e22cc.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_00393ea0;
extern "C" char DAT_00393b68;
extern "C" char DAT_002d8870;
extern "C" char DAT_002d89bc;
extern "C" char DAT_002d89e0;

extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void FUN_00225e94(void *, void *, void *, int);
extern "C" void FUN_00225f18(void *, void *, void *, int);
extern "C" void FUN_00225fb4(void *, void *, void *, int);
extern "C" void FUN_0022618c(void *, void *, void *);
extern "C" void FUN_00226820(void *, void *);

extern "C" void FUN_001f0520(char *o) {
    int p;
    FUN_00109a44(*(void **)(o + 0x21e4), &DAT_00393ea0, 0);
    FUN_00108e6c(*(void **)(o + 0x21e4), 2900.0f);
    FUN_001090f4(*(void **)(o + 0x21e4), -256);
    FUN_00225e94(o + 0x21e8, *(void **)(o + 0x21e4), &DAT_00393b68, 1);
    FUN_00225f18(o + 0x21ec, o + 0x21e8, &DAT_002d8870, 10);
    FUN_00225fb4(o + 0x22b4, o + 0x21e8, &DAT_002d89bc, 1);
    FUN_0022618c(o + 0x22c0, o + 0x21e8, &DAT_002d89e0);
    p = *(int *)(o + 0x22c0);
    *(int *)(p + 0xd8) = 0;
    *(char *)(p + 0x114) = 1;
    FUN_00226820(o + 0x22c4, *(void **)(o + 0x21e4));
    *(int *)(o + 0x2358) = (int)*(float *)(*(int *)(o + 0x22b8) + 100);
}

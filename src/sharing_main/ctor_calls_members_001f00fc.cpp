/* HSTMATCH module=hstp_trans_main.prx start=0x001f00fc end=0x001f01d4 symbol=FUN_001f00fc lang=c++ */
/* Clone of src/eboot/ctor_calls_members_001e1ed8.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" char DAT_00393d54;
extern "C" char DAT_00393b28;
extern "C" char DAT_002d81f8;
extern "C" char DAT_002d8300;

extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void FUN_00225e94(void *, void *, void *, int);
extern "C" void FUN_00225f18(void *, void *, void *, int);
extern "C" void FUN_002260f0(void *, void *, void *, int);
extern "C" void FUN_00226820(void *, void *);
extern "C" void FUN_002267ac(void *, void *);

extern "C" void FUN_001f00fc(char *o) {
    FUN_00109a44(*(void **)(o + 0x1d68), &DAT_00393d54, 0);
    FUN_00108e6c(*(void **)(o + 0x1d68), 2900.0f);
    FUN_001090f4(*(void **)(o + 0x1d68), -256);
    FUN_00225e94(o + 0x1d6c, *(void **)(o + 0x1d68), &DAT_00393b28, 5);
    FUN_00225f18(o + 0x1d80, o + 0x1d6c, &DAT_002d81f8, 8);
    FUN_002260f0(o + 0x1e20, o + 0x1d6c, &DAT_002d8300, 22);
    FUN_00226820(o + 0x1f28, *(void **)(o + 0x1d68));
    FUN_002267ac(o + 0x1fb4, *(void **)(o + 0x1d6c));
    FUN_002267ac(o + 0x2040, *(void **)(o + 0x1d70));
    FUN_002267ac(o + 0x20cc, *(void **)(o + 0x1d74));
    FUN_002267ac(o + 0x2158, *(void **)(o + 0x1d78));
}

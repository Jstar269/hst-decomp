/* HSTMATCH module=hstp_trans_main.prx start=0x0020e58c end=0x0020e710 symbol=FUN_0020e58c lang=c++ */
/* Clone of src/eboot/ctor_menu_regulation_001ffdbc.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_003971b8;
extern "C" char DAT_003971e8;
extern "C" char DAT_00397190;
extern "C" char DAT_002d95e0;
extern "C" char DAT_002d97f4;
extern "C" char DAT_002d9790;
extern "C" int DAT_003f347c;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_0010873c(void *);
extern "C" void FUN_002262f8(void *, void *, int);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void FUN_00225e94(void *, void *, void *, int);
extern "C" void FUN_00225f18(void *, void *, int, int);
extern "C" void FUN_00225fb4(void *, void *, void *, int);
extern "C" void FUN_0022618c(void *, void *, void *);
extern "C" void FUN_00226050(void *, void *, void *, int);
extern "C" void FUN_00105570(void *, int);
extern "C" void FUN_002267ac(void *, void *);
extern "C" void FUN_002266bc(void *, void *);

extern "C" void FUN_0020e58c(char *o) {
    void *p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_0010873c(p);
    }
    *(void **)(o + 4) = p;
    FUN_002262f8(&DAT_003f347c, &DAT_003971b8, 0x4e);
    FUN_00109a44(*(void **)(o + 4), &DAT_003971e8, 0);
    FUN_00108e6c(*(void **)(o + 4), 2250.0f);
    FUN_001090f4(*(void **)(o + 4), -16);
    FUN_00225e94(o + 8, *(void **)(o + 4), &DAT_00397190, 10);
    FUN_00225f18(o + 0x30, o + 8, DAT_003f347c, 0x4e);
    FUN_00225fb4(o + 0x648, o + 8, &DAT_002d95e0, 13);
    FUN_0022618c(o + 0x708, o + 8, &DAT_002d97f4);
    FUN_00226050(o + 0x6e4, o + 8, &DAT_002d9790, 3);
    int v = *(int *)(o + 0x708);
    *(int *)(v + 0xd8) = 0;
    *(char *)(v + 0x114) = 1;
    FUN_00105570(*(void **)(o + 0x634), -4096);
    FUN_002267ac(o + 0x718, *(void **)(o + 8));
    FUN_002267ac(o + 0x7a4, *(void **)(o + 0x20));
    FUN_002267ac(o + 0x830, *(void **)(o + 0x28));
    FUN_002267ac(o + 0x8bc, *(void **)(o + 0x10));
    FUN_002267ac(o + 0x948, *(void **)(o + 0x14));
    FUN_002267ac(o + 0x9d4, *(void **)(o + 0x18));
    FUN_002267ac(o + 0xa60, *(void **)(o + 0x1c));
    FUN_002266bc(o + 0xaec, *(void **)(o + 0x56c));
    FUN_002266bc(o + 0xb78, *(void **)(o + 0x634));
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001c473c end=0x001c481c symbol=FUN_001c473c lang=c++ */
/* Clone of src/eboot/init_object_state_001b6a7c.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003eaad8;

extern "C" void FUN_001c23fc(void *, int);
extern "C" void FUN_001c6440(void *, int);
extern "C" void FUN_001c64d4(void *, int, int);
extern "C" void FUN_001c71e4(int *, void *, int *, int *);
extern "C" void FUN_000632d4(int, float);

extern "C" void FUN_001c473c(char *o) {
    int out;
    int v;
    int p;
    FUN_001c23fc(&DAT_003eaad8, 37);
    if (*(int *)(o + 0x84) < 2) {
        FUN_001c6440(o, 1);
        *(int *)(o + 0x84) = 1;
    }
    else {
        FUN_001c64d4(o, 1, 1);
        *(int *)(o + 0x84) = 1;
    }
    p = (int)o + 0x40;
    v = *(int *)(o + 0x44);
    FUN_001c71e4(&out, o + 0x3c, &v, &p);
    FUN_000632d4(2, 0.1f);
    FUN_000632d4(4, 0.1f);
    FUN_000632d4(8, 0.1f);
    *(int *)(o + 0x54) = -1;
    *(int *)(o + 0x50) = -1;
    *(int *)(o + 0x64) = -1;
    *(char *)(o + 0x7b) = 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x0018c660 end=0x0018c704 symbol=FUN_0018c660 lang=c++ */
/* Clone of src/sharing_main/cleanup_globals_00198e40.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ virtual delete and pointer walk over global arrays (matching idiom: nested non-null guard); exact match verified; names and types await human review. */
struct VC {
    virtual ~VC();
};

extern "C" {
extern void *DAT_00341530[];
extern VC *DAT_0034156c[];
extern void FUN_000104e0(void *);
}

extern "C" void FUN_0018c660(void)
{
    int i = 0;
    void **p1 = DAT_00341530;
    VC **p2 = DAT_0034156c;
    do {
        if (*p1 != 0) {
            if (*p1 != 0) {
                FUN_000104e0(*p1);
                *p1 = 0;
            }
        }
        VC *v = *p2;
        if (v != 0) {
            if (v != 0) {
                delete v;
                *p2 = 0;
            }
        }
        i++;
        p1++;
        p2++;
    } while (i < 15);
}

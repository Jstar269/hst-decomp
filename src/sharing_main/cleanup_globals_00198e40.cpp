/* HSTMATCH module=hstp_trans_main.prx start=0x00198e40 end=0x00198ee4 symbol=FUN_00198e40 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0) corrected by hand: C++ virtual delete and pointer walk over global arrays (matching idiom: nested non-null guard); exact match verified; names and types await human review. */
struct VC {
    virtual ~VC();
};

extern "C" {
extern void *DAT_003ea870[];
extern VC *DAT_003ea8ac[];
extern void FUN_000104e0(void *);
}

extern "C" void FUN_00198e40(void)
{
    int i = 0;
    void **p1 = DAT_003ea870;
    VC **p2 = DAT_003ea8ac;
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

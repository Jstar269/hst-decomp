/* HSTMATCH module=hstp_trans_main.prx start=0x0015c8c4 end=0x0015c95c symbol=FUN_0015c8c4 lang=c++ */
/* Clone of src/eboot/deleting_dtor_buf2_0015088c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self_0015c8c4 {
    void *vptr;
    int f4;
    void *f8;
    void *fc;
};
extern "C" {
extern char DAT_003b16d8;
extern char DAT_003b2190;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
}

extern "C" Self_0015c8c4 *FUN_0015c8c4(Self_0015c8c4 *p, short flag)
{
    if (p != 0) {
        p->vptr = &DAT_003b2190;
        if (p->fc != 0) {
            FUN_000009e4(p->fc);
            p->fc = 0;
        }
        if (p->f8 != 0) {
            FUN_000009e4(p->f8);
            p->f8 = 0;
        }
        if (p != 0) {
            p->vptr = &DAT_003b16d8;
        }
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}

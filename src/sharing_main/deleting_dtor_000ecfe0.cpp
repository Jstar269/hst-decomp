/* HSTMATCH module=hstp_trans_main.prx start=0x000ecfe0 end=0x000ed084 symbol=FUN_000ecfe0 lang=c++ */
/* Clone of src/eboot/deleting_dtor_000e7f0c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: virtual slot-5 call through a seven-virtual struct (lw t9,0(a0)), the member is `if (m) { delete m; m = 0; }` with a virtual-destructor pointee, and the flag test is `0 < flag` delete; same recipe as deleting_dtor_000ce69c; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };
struct Sub { virtual ~Sub(); };
struct Self { void *vptr; char pad[0x38]; Sub *m; };

extern "C" {
extern char DAT_003b08e0;
extern void FUN_00000a00(void *);
extern void FUN_0001ed28(void *, int);
extern void FUN_0005c688(void *, int);
}

extern "C" Self *FUN_000ecfe0(Self *p, short flag)
{
    if (p != 0) {
        p->vptr = &DAT_003b08e0;
        ((VC *)p)->s5();
        if (p->m != 0) {
            delete p->m;
            p->m = 0;
        }
        FUN_0005c688((char *)p + 0x50, -1);
        FUN_0001ed28(p, 0);
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}

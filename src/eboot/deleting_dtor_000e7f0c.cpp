/* HSTMATCH module=EBOOT.BIN start=0x000e7f0c end=0x000e7fb0 symbol=FUN_000e7f0c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: virtual slot-5 call through a seven-virtual struct (lw t9,0(a0)), the member is `if (m) { delete m; m = 0; }` with a virtual-destructor pointee, and the flag test is `0 < flag` delete; same recipe as deleting_dtor_000ce69c; readability pass; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };
struct Sub { virtual ~Sub(); };
struct Self { void *vptr; char pad[0x38]; Sub *m; };   /* m at 0x3c: owned member; a destroyed sub-object sits at 0x50 */

#define SUB_OBJECT_OFFSET 0x50

extern "C" {
extern char DAT_00307614;
extern void FUN_00000a00(void *);
extern void FUN_0001f0f0(void *, int);
extern void FUN_0005ba00(void *, int);
}

/* Deleting destructor (short flag): calls virtual slot 5, deletes the owned member, destroys the sub-object and base. */
extern "C" Self *FUN_000e7f0c(Self *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_00307614;
        ((VC *)self)->s5();
        if (self->m != 0) {
            delete self->m;
            self->m = 0;
        }
        FUN_0005ba00((char *)self + SUB_OBJECT_OFFSET, -1);
        FUN_0001f0f0(self, 0);
        if (0 < flag) {
            FUN_00000a00(self);
        }
    }
    return self;
}

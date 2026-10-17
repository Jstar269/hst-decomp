/* HSTMATCH module=EBOOT.BIN start=0x0027da94 end=0x0027db44 symbol=FUN_0027da94 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed delete calls with arguments; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_00309c60;
extern int DAT_0034a7e0;
extern void *DAT_0034a7e4;
extern void FUN_00000a00(void *);
extern void *FUN_0001f0f0(void *, int);
}

struct VC_0 { virtual ~VC_0(); };

struct Obj {
    void *vptr;
    char pad_04[60 - 4];
    VC_0 *sub;
};

extern "C" void *FUN_0027da94(struct Obj *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_00309c60;
        DAT_0034a7e0 = 0;
        if (self->sub != 0) {
            delete self->sub;
            self->sub = 0;
        }
        if (DAT_0034a7e4 != 0) {
            FUN_00000a00(DAT_0034a7e4);
            DAT_0034a7e4 = 0;
        }
        FUN_0001f0f0(self, 0);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}

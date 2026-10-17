/* HSTMATCH module=hstp_trans_main.prx start=0x0028ee04 end=0x0028eeb4 symbol=FUN_0028ee04 lang=c++ */
/* Clone of src/eboot/deleting_dtor_0027da94.cpp (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed delete calls with arguments; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003b2f48;
extern int DAT_003f3b10;
extern void *DAT_003f3b14;
extern void FUN_00000a00(void *);
extern void *FUN_0001ed28(void *, int);
}

struct VC_0 { virtual ~VC_0(); };

struct Obj {
    void *vptr;
    char pad_04[60 - 4];
    VC_0 *sub;
};

extern "C" void *FUN_0028ee04(struct Obj *self, short flag)
{
    if (self != 0) {
        self->vptr = &DAT_003b2f48;
        DAT_003f3b10 = 0;
        if (self->sub != 0) {
            delete self->sub;
            self->sub = 0;
        }
        if (DAT_003f3b14 != 0) {
            FUN_00000a00(DAT_003f3b14);
            DAT_003f3b14 = 0;
        }
        FUN_0001ed28(self, 0);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}

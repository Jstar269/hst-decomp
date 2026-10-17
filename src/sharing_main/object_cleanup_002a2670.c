/* HSTMATCH module=hstp_trans_main.prx start=0x002a2670 end=0x002a26f8 symbol=FUN_002a2670 lang=c99 */
/* Clone of src/eboot/object_cleanup_00290f68.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003b30a8;
extern char DAT_002db244[];
extern void FUN_00000a00(void *);
extern void FUN_002a130c(const char *, int);
extern int FUN_002c76a0(int);
struct Obj { unsigned int vtable; char pad[16]; int state; };
struct Obj *FUN_002a2670(struct Obj *self, short release)
{
    if (self != 0) {
        self->vtable = (unsigned int)&DAT_003b30a8;
        int state = self->state;
        if (state >= 0) {
            int result = FUN_002c76a0(state);
            if (result != 0)
                FUN_002a130c(DAT_002db244, result);
            self->state = -1;
        }
        if (release > 0)
            FUN_00000a00(self);
    }
    return self;
}


/* HSTMATCH module=EBOOT.BIN start=0x00290f68 end=0x00290ff0 symbol=FUN_00290f68 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_00309dc0;
extern char DAT_002cac10[];
extern void FUN_00000a00(void *);
extern void FUN_0028fb44(const char *, int);
extern int FUN_002b7900(int);
struct Obj { unsigned int vtable; char pad[16]; int state; };
struct Obj *FUN_00290f68(struct Obj *self, short release)
{
    if (self != 0) {
        self->vtable = (unsigned int)&DAT_00309dc0;
        int state = self->state;
        if (state >= 0) {
            int result = FUN_002b7900(state);
            if (result != 0)
                FUN_0028fb44(DAT_002cac10, result);
            self->state = -1;
        }
        if (release > 0)
            FUN_00000a00(self);
    }
    return self;
}


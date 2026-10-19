/* HSTMATCH module=EBOOT.BIN start=0x000e7124 end=0x000e7198 symbol=FUN_000e7124 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Tween {
    char pad[0x2f8];
    float f2f8;
} Tween;

typedef struct Glob {
    char pad[0x88];
    Tween *f88;
} Glob;

typedef struct Obj {
    char pad0[0xe4];
    float fE4;
    unsigned char fE8;
    char pad1[3];
    float fEC;
} Obj;

extern Glob *DAT_003386b0;

void FUN_000e7124(Obj *self)
{
    if (self->fE8 == 0) {
        if (self->fE4 * DAT_003386b0->f88->f2f8 < 0.0f)
            self->fE8 = 1;
    } else {
        self->fEC -= 0.1f;
        if (self->fEC < 0.0f)
            self->fEC = 0.0f;
    }
}

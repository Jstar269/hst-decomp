/* HSTMATCH module=EBOOT.BIN start=0x000f0db8 end=0x000f0e94 symbol=FUN_000f0db8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Slot_000f0db8 {
    char pad0[0x60];
    float f60;
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
};
struct Box_000f0db8 {
    char pad0[0x24];
    int f24;
    int f28;
};
struct Glob_000f0db8 {
    char pad0[0xb4];
    int fb4;
    char padb8[8];
    int fc0;
    int GetB4() const { return fb4; }
};
struct Self_000f0db8 {
    char pad0[0x58];
    Slot_000f0db8 *slots[3];
    char pad64[0x80 - 0x64];
    Box_000f0db8 *f80;
    char pad84[4];
    Box_000f0db8 *f88;
    char pad8c[4];
    float f90;
    char pad94[0xa0 - 0x94];
    unsigned char fa0;
};
extern "C" {
extern int DAT_002d7554;
extern int DAT_002d756c;
extern Glob_000f0db8 *DAT_00338b44;
extern void FUN_00102c54(Slot_000f0db8 *);
}

extern "C" void FUN_000f0db8(Self_000f0db8 *self)
{
    for (int i = 0; i < 3; i++) {
        Slot_000f0db8 *s = self->slots[i];
        float off;
        if (self->fa0 != 0) {
            off = 0.0f;
        } else {
            off = -14.0f;
        }
        if (s != 0) {
            s->f60 = 0.0f;
            s->f64 = off + -32.0f;
            s->f78 = 0.0f;
            FUN_00102c54(s);
            self->f90 = s->f78;
        }
    }
    int a = DAT_00338b44->fc0;
    int x = DAT_002d7554 + DAT_00338b44->GetB4();
    Box_000f0db8 *b = self->f80;
    b->f24 = x;
    b->f28 = x;
    int y = DAT_002d756c + a;
    Box_000f0db8 *b2 = self->f88;
    b2->f24 = y;
    b2->f28 = y;
}

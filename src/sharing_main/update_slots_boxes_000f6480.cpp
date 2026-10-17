/* HSTMATCH module=hstp_trans_main.prx start=0x000f6480 end=0x000f655c symbol=FUN_000f6480 lang=c++ */
/* Clone of src/eboot/update_slots_boxes_000f0db8.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Slot_000f6480 {
    char pad0[0x60];
    float f60;
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
};
struct Box_000f6480 {
    char pad0[0x24];
    int f24;
    int f28;
};
struct Glob_000f6480 {
    char pad0[0xb4];
    int fb4;
    char padb8[8];
    int fc0;
    int GetB4() const { return fb4; }
};
struct Self_000f6480 {
    char pad0[0x58];
    Slot_000f6480 *slots[3];
    char pad64[0x80 - 0x64];
    Box_000f6480 *f80;
    char pad84[4];
    Box_000f6480 *f88;
    char pad8c[4];
    float f90;
    char pad94[0xa0 - 0x94];
    unsigned char fa0;
};
extern "C" {
extern int DAT_0037e32c;
extern int DAT_0037e344;
extern Glob_000f6480 *DAT_003e1e84;
extern void FUN_00108558(Slot_000f6480 *);
}

extern "C" void FUN_000f6480(Self_000f6480 *self)
{
    for (int i = 0; i < 3; i++) {
        Slot_000f6480 *s = self->slots[i];
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
            FUN_00108558(s);
            self->f90 = s->f78;
        }
    }
    int a = DAT_003e1e84->fc0;
    int x = DAT_0037e32c + DAT_003e1e84->GetB4();
    Box_000f6480 *b = self->f80;
    b->f24 = x;
    b->f28 = x;
    int y = DAT_0037e344 + a;
    Box_000f6480 *b2 = self->f88;
    b2->f24 = y;
    b2->f28 = y;
}

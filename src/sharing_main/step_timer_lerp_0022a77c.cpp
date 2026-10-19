/* HSTMATCH module=hstp_trans_main.prx start=0x0022a77c end=0x0022a868 symbol=FUN_0022a77c lang=c++ */
/* Clone of src/eboot/step_timer_lerp_0021b208.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: non-const float DAT globals, inline const-ref Clamp, Obj/Inner structs; exact match verified; names and types await human review. */

extern float DAT_003983f4;
extern float DAT_003983f8;
extern float DAT_003983fc;
extern float DAT_00398400;
extern float DAT_00398404;
extern float DAT_00398408;
extern float DAT_0039840c;

extern "C" void FUN_00108558(void *);
extern "C" void FUN_00108a2c(void *);

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Inner {
    char pad[0x60];
    float f60;
    char pad2[0x78 - 0x64];
    float f78;
};

struct Obj {
    char pad[0x64];
    Inner *inner;
    char pad2[0x8c - 0x68];
    int count;
};

extern "C" void FUN_0022a77c(Obj *self) {
    if (self->count > 0) {
        self->count--;
        float t = (DAT_003983f4 - (float)self->count) / DAT_003983f4;
        float clamped = Clamp(t, DAT_003983f8, DAT_003983fc);
        self->inner->f60 = DAT_00398400 + clamped * (DAT_00398404 - DAT_00398400);
        self->inner->f78 = DAT_00398408 + clamped * (DAT_0039840c - DAT_00398408);
        FUN_00108558(self->inner);
    }
    FUN_00108a2c(self);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0009c7d4 end=0x0009ca18 symbol=FUN_0009c7d4 lang=c99 */
/* Clone of src/eboot/set_mode_0009a548.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Mode setter: clears DAT_003e1aac, returns when the mode is unchanged, otherwise stores it, clears +0x40
// and runs the per-mode setup. The compare chain 6,5,4,3,0 is the switch with labels 0,3,4,5,6 (tested in
// reverse source order); typed members keep `sw a1,60(s0)` (int casts CSE the +0x3c address into a2).
struct Obj {
    char pad0[0x3c];
    int mode;
    int f40;
    char pad1[0x409 - 0x44];
    char f409;
    char pad2[0x410 - 0x40a];
    char f410;
    char f411;
    char pad3[2];
    int f414;
    char pad4[0x444 - 0x418];
    int f444;
    int f448;
    int f44c;
    int f450;
    int f454;
    int f458;
    char pad5[0x460 - 0x45c];
    char f460;
    char f461;
    char f462;
    char f463;
    char pad6[0x470 - 0x464];
    int f470;
    int f474;
    int f478;
    int f47c;
    char pad7[0x550 - 0x480];
    float f550;
    float f554;
    float f558;
    float f55c;
    float f560;
    float f564;
    float f568;
    float f56c;
    float f570;
    float f574;
    float f578;
    float f57c;
    char pad8[0x7f0 - 0x580];
    int f7f0;
};

extern int DAT_003e1aac;
extern float DAT_002cc260;
extern float DAT_002cc264;
extern float DAT_002cc268;
extern float DAT_002cc26c;
extern float DAT_002cc270;
extern float DAT_002cc274;
extern float DAT_002cc278;
extern float DAT_002cc27c;
extern float DAT_002cc280;
extern float DAT_002cc284;
extern float DAT_002cc288;
extern float DAT_002cc28c;
extern char DAT_0037a9c0[];
extern void FUN_00097e3c(const char *, ...);
extern void FUN_000a2d44(struct Obj *);
extern void FUN_000b5230(struct Obj *);

static inline void ResetState(struct Obj *self)
{
    self->f444 = 0;
    self->f448 = 0;
    self->f44c = 0;
    self->f450 = 0;
    self->f454 = 0;
    self->f458 = 0;
    self->f460 = 0;
    self->f461 = 0;
    self->f462 = 0;
    self->f463 = 0;
    self->f470 = 0;
    self->f474 = 0;
    self->f478 = 0;
    self->f47c = 0;
    self->f550 = DAT_002cc260;
    self->f554 = DAT_002cc264;
    self->f558 = DAT_002cc268;
    self->f55c = DAT_002cc26c;
    self->f560 = DAT_002cc270;
    self->f564 = DAT_002cc274;
    self->f568 = DAT_002cc278;
    self->f56c = DAT_002cc27c;
    self->f570 = DAT_002cc280;
    self->f574 = DAT_002cc284;
    self->f578 = DAT_002cc288;
    self->f57c = DAT_002cc28c;
}

void FUN_0009c7d4(struct Obj *self, int mode)
{
    DAT_003e1aac = 0;
    if (self->mode == mode)
        return;
    self->mode = mode;
    self->f40 = 0;
    switch (self->mode) {
    case 0:
        break;
    case 3:
        FUN_00097e3c(DAT_0037a9c0);
        self->f7f0 = 0;
        self->f409 = 0;
        self->f410 = 0;
        self->f411 = 0;
        self->f414 = -1;
        ResetState(self);
        break;
    case 4:
        self->f7f0 = 0;
        FUN_000b5230(self);
        ResetState(self);
        break;
    case 5:
        break;
    case 6:
        FUN_000a2d44(self);
        break;
    }
}

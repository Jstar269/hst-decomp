/* HSTMATCH module=EBOOT.BIN start=0x0009a548 end=0x0009a78c symbol=FUN_0009a548 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Mode setter: clears DAT_0033876c, returns when the mode is unchanged, otherwise stores it, clears +0x40
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

extern int DAT_0033876c;
extern float DAT_002bc410;
extern float DAT_002bc414;
extern float DAT_002bc418;
extern float DAT_002bc41c;
extern float DAT_002bc420;
extern float DAT_002bc424;
extern float DAT_002bc428;
extern float DAT_002bc42c;
extern float DAT_002bc430;
extern float DAT_002bc434;
extern float DAT_002bc438;
extern float DAT_002bc43c;
extern char DAT_002d4574[];
extern void FUN_00096994(const char *, ...);
extern void FUN_000a0738(struct Obj *);
extern void FUN_000b2218(struct Obj *);

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
    self->f550 = DAT_002bc410;
    self->f554 = DAT_002bc414;
    self->f558 = DAT_002bc418;
    self->f55c = DAT_002bc41c;
    self->f560 = DAT_002bc420;
    self->f564 = DAT_002bc424;
    self->f568 = DAT_002bc428;
    self->f56c = DAT_002bc42c;
    self->f570 = DAT_002bc430;
    self->f574 = DAT_002bc434;
    self->f578 = DAT_002bc438;
    self->f57c = DAT_002bc43c;
}

void FUN_0009a548(struct Obj *self, int mode)
{
    DAT_0033876c = 0;
    if (self->mode == mode)
        return;
    self->mode = mode;
    self->f40 = 0;
    switch (self->mode) {
    case 0:
        break;
    case 3:
        FUN_00096994(DAT_002d4574);
        self->f7f0 = 0;
        self->f409 = 0;
        self->f410 = 0;
        self->f411 = 0;
        self->f414 = -1;
        ResetState(self);
        break;
    case 4:
        self->f7f0 = 0;
        FUN_000b2218(self);
        ResetState(self);
        break;
    case 5:
        break;
    case 6:
        FUN_000a0738(self);
        break;
    }
}

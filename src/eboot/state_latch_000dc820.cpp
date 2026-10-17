/* HSTMATCH module=EBOOT.BIN start=0x000dc820 end=0x000dc90c symbol=FUN_000dc820 lang=c++ */
/* Clone of src/sharing_main/state_latch_000e0924.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the table scan is a static inline helper returning 0/1 (a preset flag local keeps the flag in a separate register). */

struct Pl {
    char pad[0x144];
    unsigned int f144;
};

struct Game {
    char pad[0x70];
    Pl *players[4];
};

struct Obj {
    char pad0[0x50];
    int f50;
    char pad54[8];
    unsigned char f5c;
    char pad5d;
    unsigned char f5e;
    unsigned char f5f;
    char pad60[0x2c];
    int f8c;
    char pad90[12];
    unsigned int f9c;
};

extern Game *DAT_003386b0;
extern void *DAT_0033b460;
extern signed char DAT_003417b8[];
extern "C" void FUN_0011a504(void *, int, int, float);
extern "C" void FUN_000dc820(Obj *o);

static inline int Has9(void)
{
    const signed char *t = DAT_003417b8;
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (t[i + 9] == 9)
            return 1;
    }
    return 0;
}

void FUN_000dc820(Obj *o)
{
    if (o->f5c == 0) {
        if (o->f8c == 1) {
            o->f5e = 1;
            if (Has9()) {
                o->f5c = 1;
                o->f9c = DAT_003386b0->players[o->f50]->f144 ^ 1;
                FUN_0011a504(DAT_0033b460, 1, 0, 0.0f);
            } else {
                o->f5c = 1;
            }
        } else {
            o->f5f = 1;
            o->f5c = 1;
            o->f9c = DAT_003386b0->players[o->f50]->f144 ^ 1;
        }
    }
}

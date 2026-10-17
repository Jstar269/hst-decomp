/* HSTMATCH module=hstp_trans_main.prx start=0x000e0924 end=0x000e0a10 symbol=FUN_000e0924 lang=c++ */
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

extern Game *DAT_003e19f0;
extern void *DAT_003e47a0;
extern signed char DAT_003eaaf0[];
extern "C" void FUN_001256d8(void *, int, int, float);
extern "C" void FUN_000e0924(Obj *o);

static inline int Has9(void)
{
    const signed char *t = DAT_003eaaf0;
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (t[i + 9] == 9)
            return 1;
    }
    return 0;
}

void FUN_000e0924(Obj *o)
{
    if (o->f5c == 0) {
        if (o->f8c == 1) {
            o->f5e = 1;
            if (Has9()) {
                o->f5c = 1;
                o->f9c = DAT_003e19f0->players[o->f50]->f144 ^ 1;
                FUN_001256d8(DAT_003e47a0, 1, 0, 0.0f);
            } else {
                o->f5c = 1;
            }
        } else {
            o->f5f = 1;
            o->f5c = 1;
            o->f9c = DAT_003e19f0->players[o->f50]->f144 ^ 1;
        }
    }
}

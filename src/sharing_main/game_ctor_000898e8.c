/* HSTMATCH module=hstp_trans_main.prx start=0x000898e8 end=0x00089ab4 symbol=FUN_000898e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Game.cpp (from the assert strings): Game constructor, debug build of EBOOT 0x00088258 with the g_pGame / Player::s_pScene / Ball::s_pScene asserts compiled in. */
typedef struct Game {
    void *vptr;                 /* 0x00 */
    char base04[0x38];          /* 0x04 base object (FUN_0001ec44) */
    int f3c;                    /* 0x3c */
    int f40;
    int f44;
    int f48;
    unsigned char f4c;
    int f50;
    int f54;
    unsigned char f58;
    unsigned char f59;
    unsigned char f5a;
    unsigned char f5b;
    int f5c;
    int f60;
    int f64;
    unsigned char f68;
    int f6c;
    int f70[4];                 /* 0x70 */
    int f80;
    int f84;
    int f88;
    int f8c;
    int f90;
    int f94;
    int f98;
    int f9c;
    int fa0;
    int fa4;
} Game;

typedef struct Net {
    char pad0[0xab4f];
    unsigned char fab4f;
    unsigned char fab50;
} Net;

extern char DAT_003b04a4;            /* Game vtable */
extern void *DAT_003ba2c4;
extern Game *DAT_003e19f0;           /* g_pGame */
extern void *DAT_003e1a54;           /* Player::s_pScene */
extern void *DAT_003e1a0c;           /* Ball::s_pScene */
extern unsigned char DAT_003e19f8;
extern const char DAT_0037826c[];    /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00378298[];    /* "g_pGame == 0" */
extern const char DAT_003782a8[];    /* "Game.cpp" */
extern const char DAT_003782b4[];    /* "Player::s_pScene == 0" */
extern const char DAT_003782cc[];    /* "Ball::s_pScene == 0" */
extern char DAT_003b9120;
extern void FUN_0001ec44(Game *self);
extern void FUN_0001ef34(void *list, Game *self);
extern void FUN_000426c0(void *p, int a, int b);
extern void FUN_0006f5ec(float f);
extern void FUN_00089ab4(const char *fmt, ...);
extern Net *FUN_00239ea4(void);

#define GAME_ASSERT(c, text, line) \
    if (!(c)) { FUN_00089ab4(DAT_0037826c, text, DAT_003782a8, line); for (;;) {} }

Game *FUN_000898e8(Game *self)
{
    unsigned int i;

    FUN_0001ec44(self);
    self->vptr = &DAT_003b04a4;
    self->f3c = 11;
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f59 = 0;
    self->f5a = 0;
    self->f5b = 0;
    self->f5c = 0;
    self->f60 = 1;
    self->f64 = 1;
    self->f68 = 0;
    self->f6c = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f8c = 0;
    self->f90 = 0;
    self->f94 = 0;
    self->f98 = 0;
    self->f9c = 0;
    self->fa0 = 0;
    self->fa4 = 0;
    GAME_ASSERT(DAT_003e19f0 == 0, DAT_00378298, 122);
    DAT_003e19f0 = self;
    FUN_000426c0(DAT_003ba2c4, 0x100, 0x80);
    FUN_0006f5ec(2060.0f);
    FUN_0001ef34(&DAT_003b9120, self);
    GAME_ASSERT(DAT_003e1a54 == 0, DAT_003782b4, 135);
    GAME_ASSERT(DAT_003e1a0c == 0, DAT_003782cc, 136);
    i = 0;
    do {
        self->f70[i] = 0;
    } while (++i < 4);
    if (DAT_003e19f8 != 0) {
        FUN_00239ea4()->fab4f = 0;
        FUN_00239ea4()->fab50 = 0;
    }
    return self;
}

/* HSTMATCH module=EBOOT.BIN start=0x000fb734 end=0x000fb7b8 symbol=FUN_000fb734 lang=c99 */
/* Near-miss for check_game_state (33 words).
   Checks DAT_003386b0 mode (cases 2 and 9 return 1), then self->f3c->f94->fc == 11,
   then !self->f40 || self->f40->f4c == 5.
   Differs only in switch block placement: MWCC inlines case 2 return block rather than
   placing it at the function epilogue (0xfb7a0).
*/

struct SubSub {
    char pad[0xc];
    int fc;     /* +0xc */
};

struct Sub3c {
    char pad[0x94];
    struct SubSub *f94; /* +0x94 */
};

struct Sub40 {
    char pad[0x4c];
    int f4c;    /* +0x4c */
};

struct GameObj {
    char pad[0x3c];
    int f3c;    /* +0x3c */
};

struct Obj_000fb734 {
    char pad[0x3c];
    struct Sub3c *f3c;  /* +0x3c */
    struct Sub40 *f40;  /* +0x40 */
};

extern struct GameObj *DAT_003386b0;

int FUN_000fb734(struct Obj_000fb734 *self)
{
    if (DAT_003386b0 != 0) {
        switch (DAT_003386b0->f3c) {
        case 2:
        case 9:
            return 1;
        }
    }
    if (self->f3c->f94->fc != 11) {
        return 0;
    }
    if (self->f40 == 0) {
        return 1;
    }
    if (self->f40->f4c == 5) {
        return 1;
    }
    return 0;
}
// near miss from lane u2r1-3 (unreviewed)

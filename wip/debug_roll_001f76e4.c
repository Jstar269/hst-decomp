/* HSTMATCH module=EBOOT.BIN start=0x001f76e4 end=0x001f780c symbol=FUN_001f76e4 lang=c99 */
typedef struct Slot {
    int f0;
    int f4;
    int val;
    int f12;
    int f16;
} Slot;

extern unsigned int DAT_00310fc8;
extern char DAT_002eeb80[];
extern char DAT_002eeb90[];
extern char DAT_002eeba8[];
extern int FUN_001f7584(int, int, int);

static int Dbg(const char *fmt, ...)
{
}

int FUN_001f76e4(int param_1, Slot *slots, int param_3, int param_4)
{
    int result = 0;
    int total = 0;
    int i;
    for (i = 0; i < 128; i++) {
        total += slots[i].val;
    }
    Dbg(DAT_002eeb80, total);
    int prob = FUN_001f7584(total, param_3, param_4);
    Dbg(DAT_002eeb90, prob / 100, prob % 100);
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    int rv = (int)((DAT_00310fc8 >> 16) & 0x7fff) % 10000;
    Dbg(DAT_002eeba8, rv);
    if (rv < prob) {
        result = 1;
    }
    return result;
}
// Near miss (body exact, sn5): all 74 words equal retail except the three `jal` targets of the debug print and the stub itself, because
// retail's print stub 0x1ef3f8 is a STATIC variadic function defined earlier in the same translation unit (0x1ef3f8..0x1f780c, 57 functions):
// MWCC then knows it clobbers no register, so `prob` stays in v0 (the final `slt at,a1,v0` compares against it), a2/a3 and t0 survive the first
// print, and `result` is the only s-register (s0). With the stub defined `static int Dbg(const char *fmt, ...) {}` before the function the
// whole 74-word body compiles identically (checked with try/lane-work/cmpcc.py: relocation fields masked, 0 words differ), but hstmatch
// reports MISPLACED (two .text sections, the stub first) and the jal targets point at the local copy. Same blocker as wip/sync_player_profile_001a24ac.cpp.
// Idioms: `int result = 0; ... if (rv < prob) result = 1; return result;` after the third print, `(int)((seed >> 16) & 0x7fff) % 10000` (gives ext),
// signed `int i` counter for the 8x-unrolled 128-element sum with 160-byte pointer bumps.
// near miss from lane sn5 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0001c604 end=0x0001c810 symbol=FUN_0001c604 lang=c++ */
struct Buf {
    int *begin;
    int m4;
    int *end;
    char padc[0x14 - 0xc];
    int extra;
    char pad18[0x20 - 0x18];
    int kind;
};

extern "C" {
extern int DAT_002cfae4;
extern volatile int DAT_0030ebd0;
extern char DAT_002cfc04[];
void FUN_0001b918(char *, int);
void FUN_002b78f0(void);
void FUN_002b7958(int);
int FUN_0001cd38(void);
int FUN_0001ce28(void);
int FUN_0001cf14(int, int *, int (*)(void));
void FUN_00011090(int, int *, int);
void FUN_000009e4(int);
}

inline void Convert(int dst, int *src)
{
    int t = FUN_0001cf14(0, src, FUN_0001cd38);
    FUN_0001cf14(dst, (int *)t, FUN_0001ce28);
    if (DAT_002cfae4 == 4 || t != 0x70000000)
        FUN_000009e4(t);
}

extern "C" void FUN_0001c604(Buf *b, int dst)
{
    if (b->end == 0)
        return;
    int n = (b->end - b->begin) * 4;
    int mode = DAT_002cfae4;
    if (mode == 3 || mode == 2) {
        while (DAT_0030ebd0 < n + 8) {
            FUN_002b78f0();
            FUN_002b7958(100);
        }
    } else {
        FUN_0001b918(DAT_002cfc04, mode);
        for (;;) {
        }
    }
    mode = DAT_002cfae4;
    int more = b->extra + 8;
    if (mode == 3 || mode == 2) {
        n += more;
        while (DAT_0030ebd0 < n) {
            FUN_002b78f0();
            FUN_002b7958(100);
        }
    } else {
        FUN_0001b918(DAT_002cfc04, mode);
        for (;;) {
        }
    }
    switch (b->kind) {
    default:
        Convert(dst, b->end);
        break;
    case 1:
        FUN_0001cf14(dst, b->end, FUN_0001cd38);
        break;
    case 2:
        FUN_0001cf14(dst, b->end, FUN_0001ce28);
        break;
    case 3: {
        int sz = b->extra;
        FUN_00011090(dst, b->end, sz);
        break;
    }
    }
}
// NEAR 48 (shifted; ~6 real words): default-case first FUN_0001cf14 call leaves a nop delay slot (retail fills it with the addiu a2),
// and in case 3 retail loads b->extra (a2) in the beql delay before b->end (a1). Switch with default first, volatile DAT_0030ebd0 fixed the rest.
// Tried if-chain (worse), const params, inline Convert(), local sz. ~11 compiles.
// near miss from lane ol2 (unreviewed)

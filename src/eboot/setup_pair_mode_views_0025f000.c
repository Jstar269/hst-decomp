/* HSTMATCH module=EBOOT.BIN start=0x0025f000 end=0x0025f0c4 symbol=FUN_0025f000 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a7/v21/FUN_0025f000.c (tag: a7) */
extern unsigned char DAT_003417be;

typedef struct PairScreen {
    char pad0[0x64];
    unsigned char enabled;   /* 0x64 */
    unsigned char altFlag;   /* 0x65 */
    char pad66[0x7c - 0x66];
    void *viewA;             /* 0x7c */
    void *viewB;             /* 0x80 */
    char pad84[4];
    void *viewC;             /* 0x88 */
    void *viewD;             /* 0x8c */
} PairScreen;

extern void FUN_000ffb3c(void *, int);

void FUN_0025f000(PairScreen *screen, int visible)
{
    if (screen->enabled != 0 && (screen->altFlag == 0 || DAT_003417be != 0)) {
        FUN_000ffb3c(screen->viewA, 1);
        FUN_000ffb3c(screen->viewB, 1);
        FUN_000ffb3c(screen->viewC, 1);
        FUN_000ffb3c(screen->viewD, 1);
    } else {
        if (screen->altFlag != 0) {
            FUN_000ffb3c(screen->viewA, 0);
            FUN_000ffb3c(screen->viewB, 0);
        }
        FUN_000ffb3c(screen->viewC, visible);
        FUN_000ffb3c(screen->viewD, visible);
    }
}

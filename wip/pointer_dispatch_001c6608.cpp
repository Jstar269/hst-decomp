/* HSTMATCH module=EBOOT.BIN start=0x001c6608 end=0x001c67e8 symbol=FUN_001c6608 lang=c++ */
// NEAR 6/120 (sn7 2026-10-24): same length as retail, control flow and every other word exact.
// Remaining 6 words are one register choice: retail reads p->f8 into $a1 (both the 'mode==12 &&
// f8 < fc' test at +0x34/+0x3c and the 'f8 >= fc' test in the case-12 arm) and loads the debug flag
// DAT_0034a81c into $a0; ours uses $a0 for f8 and $v1 for the flag.
// Levers found: the guard is the DOUBLE test
//   if (p->f61 != 0) { if (p->f61 != 0) { ...texture/overlay code... } }  mode = p->f4;
// (outer test = retail's beqzl with the mode load in the slot, inner = the second beqz); the
// if/else form with mode assigned in both arms (earlier wip) gave 122 words. And 'y = 0.0f;' must
// be written BEFORE the FUN_00051490 call so the mtc1 $f20 fills its delay slot.
// Ruled out for the a0/a1 choice: local for f8 or for the flag, inline helper (pointer or value
// params) for the compare, struct-typed p with member functions, swapped compare operands (7-9
// words), declaration order of p/mode/b (all 4 permutations identical).

struct Disp_1c6608 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" {
extern int DAT_0034a81c;
extern char DAT_00311170[];
extern void FUN_001c6354(void);
extern int FUN_00050534(char *name);
extern void FUN_00051398(int id, float f);
extern void FUN_00051490(int id, int a, int b, int c, int d, int e, int f);
extern void FUN_00051894(void *tex, float u0, float v0, float x0, float y0,
                         float u1, float v1, float x1, float y1, float z,
                         unsigned color);
extern void FUN_0005185c(int id);
extern void FUN_000503d0(char *msg, float v);
extern void FUN_002917ac(void);
}

extern "C" void FUN_001c6608(char *self)
{
    char *p = *(char **)(self + 0x15c);
    int mode;
    int b;

    b = 0;
    b = *(int *)(p + 4) == 0xc;
    if (b)
        b = *(int *)(p + 8) < *(int *)(p + 0xfc);
    if (b) {
        FUN_001c6354();
        return;
    }

    if (*(unsigned char *)(p + 0x61) != 0) {
        if (*(unsigned char *)(p + 0x61) != 0) {
            if (*(unsigned char *)(p + 0x62) != 0) {
                FUN_000503d0(DAT_00311170, 3999.89990234375f);
                *(unsigned char *)(p + 0x62) = 0;
            } else {
                int tex = FUN_00050534(DAT_00311170);
                if (tex != 0) {
                    unsigned char col[4];
                    int i;
                    int packed;
                    float y;

                    FUN_00051398(tex, 0.0f);
                    col[0] = 128;
                    col[1] = 128;
                    col[2] = 128;
                    col[3] = 128;
                    y = 0.0f;
                    FUN_00051490(tex, 0, 0, 0x1e0, 0x110, 0, 0);
                    packed = *(int *)col;
                    for (i = 0; i < 4; i++) {
                        FUN_00051894((void *)tex, y, 0.0f, y, 0.0f,
                                     y + 120.0f, 272.0f, y + 120.0f, 272.0f,
                                     0.0f, packed);
                        y = y + 120.0f;
                    }
                    FUN_0005185c(tex);
                }
            }
        }
    }
    mode = *(int *)(p + 4);

    switch (mode) {
    case 2:
        if (*(unsigned char *)(p + 0x63) != 0)
            (*(Disp_1c6608 **)(p + 0x20))->v3();
        break;
    case 0xc:
        if (DAT_0034a81c != 0) {
            if (*(int *)(p + 8) >= *(int *)(p + 0xfc))
                FUN_002917ac();
        }
        break;
    }
}
// improved by lane sn7 (unreviewed): 102 -> 6 differing words

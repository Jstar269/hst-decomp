/* HSTMATCH module=EBOOT.BIN start=0x00199754 end=0x001997dc symbol=FUN_00199754 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: Ghidra's if/else-if chain on the mode is a `switch (m)` (case 0..3 in source order; retail tests 3,2,1,0 in reverse order); exact match verified; names and types await human review. */
struct S_00199754 {
    char pad0[0x18];
    int mode;
    int level;
    int frames;
};
extern "C" void FUN_00199754(S_00199754 *s, int m)
{
    s->mode = m;
    switch (m) {
    case 0:
        s->frames = 0xf;
        break;
    case 1:
        if (s->level < 3) {
            s->frames = 0x5a;
        } else if (s->level == 5) {
            s->frames = 0x78;
        } else {
            s->frames = 0x3c;
        }
        break;
    case 2:
        s->frames = 0xf;
        break;
    case 3:
        s->frames = 1;
        break;
    }
}

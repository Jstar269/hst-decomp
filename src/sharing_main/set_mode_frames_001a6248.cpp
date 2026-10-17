/* HSTMATCH module=hstp_trans_main.prx start=0x001a6248 end=0x001a62d0 symbol=FUN_001a6248 lang=c++ */
/* Clone of src/eboot/set_mode_frames_00199754.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: Ghidra's if/else-if chain on the mode is a `switch (m)` (case 0..3 in source order; retail tests 3,2,1,0 in reverse order); exact match verified; names and types await human review. */
struct S_001a6248 {
    char pad0[0x18];
    int mode;
    int level;
    int frames;
};
extern "C" void FUN_001a6248(S_001a6248 *s, int m)
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

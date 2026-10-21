/* HSTMATCH module=hstp_trans_main.prx start=0x002b04e4 end=0x002b07a4 symbol=FUN_002b04e4 lang=c++ */
/* Clone of src/eboot/anim_ready_check_002a10d8.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the object's `last` index is volatile (the scan bound is re-read every pass), FUN_000588b4 takes the incoming (self, idx) registers unchanged (Ghidra shows no arguments), the Level/Ready helpers are inline with `!F(..)` giving sltu/xori/andi, and the middle arm loads the limit before the level; names and types await human review. */
struct Obj8 {
    char pad[8];
    float f8;
};
struct Entry {
    Obj8 **ptr;
    char pad[0x10 - 4];
    float f10;
    char pad1[0x34 - 0x14];
};
struct Self {
    char pad0[0xf4];
    Entry ent[1];
    char pad1[0x158 - 0xf4 - 0x34];
    int first;
    volatile int last;
    char pad2[0x1b0 - 0x160];
    int state;
};
extern "C" int FUN_000588b4(Self *, int);

static inline float Level(Entry *e)
{
    return e->ptr != 0 ? (*e->ptr)->f8 : 0.0f;
}

static inline bool Ready(Self *s, int idx)
{
    if (idx < 0) {
        int i = s->first;
        if (i <= s->last) {
            do {
                float t = Level(&s->ent[i]);
                if (s->ent[i].f10 < t) {
                    return false;
                }
                i++;
            } while (i <= s->last);
        }
        return true;
    }
    float t = Level(&s->ent[idx]);
    return s->ent[idx].f10 >= t;
}

extern "C" bool FUN_002b04e4(Self *s, int idx)
{
    if (idx == 0) {
        return Ready(s, idx) && !FUN_000588b4(s, idx);
    } else if (s->state == 0 || s->state == 3) {
        float f = s->ent[idx].f10;
        float t = Level(&s->ent[idx]);
        float d = idx == 0 ? 3.0f : 10.0f;
        return f >= (t - d) - 1.5f;
    } else {
        return Ready(s, idx) && !FUN_000588b4(s, idx);
    }
}

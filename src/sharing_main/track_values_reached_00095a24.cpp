/* HSTMATCH module=hstp_trans_main.prx start=0x00095a24 end=0x00095b04 symbol=FUN_00095a24 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: the range bound is read through the const getter Last() (re-loaded every pass, as in update_range_items_00059c1c.cpp); exact match verified; names and types await human review. */
/* True when the object's motion (+0x58) is missing, or when track idx (idx >= 0) / every track first..last
   (idx < 0) has f14 >= the float at +8 of its key (a track without a key compares against 0.0f). The tracks
   are the two 52-byte records FUN_000579bc clears at +0xf0. The result-variable block with its own
   `return r;` is what keeps retail's layout: plain early returns give dead slot copies (46 differ), a single
   trailing `return r;` leaves a `b` to the epilogue (8 differ). Names provisional. */
struct Key {
    char pad0[8];
    float f8;
};

struct KeyRef {
    Key *key;
};

struct Track {
    int id;
    KeyRef *ref;
    char pad8[8];
    float f10;
    float f14;
    float f18;
    float f1c;
    int f20;
    char pad24[0x34 - 0x24];
};

struct Motion {
    char pad0[0xf0];
    Track tracks[2];
    int first;
    int last;
    int Last() const { return last; }
};

struct Obj {
    char pad0[0x58];
    Motion *motion;
};

static inline float KeyValue(const Track &t)
{
    return t.ref ? t.ref->key->f8 : 0.0f;
}

extern "C" bool FUN_00095a24(Obj *self, int idx)
{
    Motion *m = self->motion;
    if (m != 0) {
        bool r;
        if (idx < 0) {
            for (int i = m->first; i <= m->Last(); i++) {
                if (m->tracks[i].f14 < KeyValue(m->tracks[i])) {
                    return false;
                }
            }
            r = true;
        } else {
            r = m->tracks[idx].f14 >= KeyValue(m->tracks[idx]);
        }
        return r;
    }
    return true;
}

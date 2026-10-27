/* HSTMATCH module=EBOOT.BIN start=0x00093b00 end=0x00093be0 symbol=FUN_00093b00 lang=c++ */
/* Hand-written reconstruction (port of src/sharing_main/track_values_reached_00095a24.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* True when the object's motion (+0x58) is missing, or when track idx (idx >= 0) / every track first..last
   (idx < 0) has f14 >= the float at +8 of its key (a track without a key compares against 0.0f). The tracks
   are the two 52-byte records FUN_00056d68 clears at +0xf0. The result-variable block with its own
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

extern "C" bool FUN_00093b00(Obj *self, int idx)
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

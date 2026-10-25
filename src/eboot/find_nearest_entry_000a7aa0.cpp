/* HSTMATCH module=EBOOT.BIN start=0x000a7aa0 end=0x000a7cec symbol=FUN_000a7aa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);


struct Entry {
    int id;
    unsigned char active;
    int f8;
    Vec4 pos;
    Entry() {}
};

struct EntryList {
    Entry *data;
    unsigned int size;
    unsigned int cap;
    int Size() const { return size; }
    Entry &operator[](unsigned int i)
    {
        if (i >= size)
            i = size - 1;
        return data[i];
    }
};

struct Track {
    EntryList pending;
    EntryList done;
};

struct Holder {
    char pad[0x268];
    int first;
    Track track;
};

struct Obj {
    char pad[0x5a8];
    float side;
};

inline const int &max(const int &a, const int &b) { return a < b ? b : a; }

extern "C" int FUN_000a8080(Obj *obj, Vec4 *pos, int id);

extern "C" int FUN_000a7aa0(Obj *obj, Entry *out, Holder *h, Vec4 pos, int idBase, float hi, float lo)
{
    float best = 3.4028235e+38f;
    int i = h->first;
    int found = 0;
    Track &l = h->track;
    if ((int)l.done.size > 0) {
        int k = 0;
        if (l.done.size == 0)
            k = l.done.size - 1;
        i = max(i, l.done.data[k].id);
    }
    for (; i < l.pending.Size(); i++) {
        Entry e = l.pending[i];
        if (e.active != 0 && e.pos.z * obj->side < -2.0f && hi > e.pos.y && e.pos.y > lo) {
            Vec4 d;
            FUN_00022434(&d, &pos, &e.pos);
            float dist = d.x * d.x + d.z * d.z;
            if (best > dist && FUN_000a8080(obj, &e.pos, e.id + idBase) >= 0) {
                best = dist;
                found = 1;
                *out = e;
            }
        }
    }
    return found;
}

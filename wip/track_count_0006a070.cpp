/* HSTMATCH module=EBOOT.BIN start=0x0006a070 end=0x0006a208 symbol=FUN_0006a070 lang=c++ */
struct Elem {
    short h0;
    short key;
    short h4;
    short step;
    short len;
    char pad[40 - 10];
};

struct Info {
    char pad[8];
    float frames;
};

struct Pair {
    int key;
    int count;
    Pair() {}
    Pair(int k, int c) : key(k), count(c) {}
};

struct MapIt {
    void *node;
};

struct Map;
extern "C" {
MapIt *FUN_0006b0f4(MapIt *, Map *, const int *);
Pair *FUN_0006b064(Map *, const int *);
void FUN_0006b8c8(MapIt *, Map *, const Pair *);
}
struct Map {
    int m0;
    char header[4];
    MapIt find(const int &k) { MapIt r; FUN_0006b0f4(&r, this, &k); return r; }
    MapIt end() { MapIt r; r.node = header; return r; }
    Pair &operator[](const int &k) { return *FUN_0006b064(this, &k); }
    MapIt insert(const Pair &p) { MapIt r; FUN_0006b8c8(&r, this, &p); return r; }
};

struct ElemIt {
    Elem *p;
};

inline bool Same(Elem *a, Elem *b) { return a == b; }
inline bool Differ(Elem *a, Elem *b) { return !Same(a, b); }

struct Track {
    int m0;
    Info *info;
    Elem *data;
    int size;
    int m10;
    Map map;
    Elem *begin() const { return data; }
    Elem *end() const { return data + size; }
};

struct Node {
    char pad[16];
    Track track;
};

struct ListIt {
    Node *node;
};

struct Mgr {
    char pad[12];
    Node *first;
};

extern "C" {
extern Mgr *DAT_00331c28;
void FUN_000643e8(ListIt *);
void FUN_0006b584(ListIt *);
void FUN_0006b888(Map *);
MapIt *FUN_0006b0f4(MapIt *, Map *, const int *);
Pair *FUN_0006b064(Map *, const int *);
void FUN_0006b8c8(MapIt *, Map *, const Pair *);
}

inline int Count(int len, int step) { return len / step + 1; }

extern "C" void FUN_0006a070(int n)
{
    ListIt it;
    it.node = DAT_00331c28->first;
    if (n >= 0) {
        while (n > 0) {
            FUN_000643e8(&it);
            n--;
        }
    } else {
        while (n < 0) {
            FUN_0006b584(&it);
            n++;
        }
    }
    Track *t = &it.node->track;
    Map *m = &t->map;
    FUN_0006b888(m);
    Elem *e = t->begin();
    int frames = (int)t->info->frames;
    for (; Differ(e, t->end()); e++) {
        int cnt = Count(e->len, e->step) + Count(e->len, frames);
        if (m->find(e->key).node != m->end().node) {
            (*m)[e->key].count += cnt;
        } else {
            m->insert(Pair(e->key, cnt));
        }
    }
}
// NEAR 72: MWCC folds (len/step+1)+(len/frames+1) into +2 and orders the frames divide first; retail keeps two +1s,
// divides by step first, frame is 80 (ours 64) with locals it@44 pair@48 r@56 k@64 key@68 f@72, and regs e=s1 frames=s2 t=s3.
// Tried split locals, inline Count(), map member wrappers. ~10 compiles.
// near miss from lane ol2 (unreviewed)

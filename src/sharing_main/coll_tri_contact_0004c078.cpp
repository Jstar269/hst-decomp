/* HSTMATCH module=hstp_trans_main.prx start=0x0004c078 end=0x0004c820 symbol=FUN_0004c078 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* collision.cpp (per the Sharing twin's assert strings): per-triangle contact callback. Look up the
   current entry, refresh the node world matrix when the node changes (debug build asserts the node index),
   gather the triangle (winding flipped by the sign of pos.w), transform it to world space, test it against
   a copy of the current hit; on a hit store the normal, build the triangle key and skip triangles already
   in the key list; otherwise resolve the attribute id (0x4b25c) and, unless it is in the ignore list,
   commit the hit. Shape notes: Vec4 and TriKey copy constructors are declared in the classes but defined
   inline after the function, so MWCC calls their out-of-line copies (emitted right after this function, as
   in retail); the triangle buffer is 9 entries (frame size); the list searches are rotated do-while loops
   (re-reading the bound each pass) with strength reduction off. Names provisional. */

#pragma opt_strength_reduction off

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &v);
    bool operator==(const Vec4 &v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
} __attribute__((aligned(16)));

struct Mat4 { Vec4 r[4]; };

struct TriKey {
    Vec4 v[3];
    int type;
    int id;
    TriKey() {}
    TriKey(int t, int i, const Vec4 &a, const Vec4 &b, const Vec4 &c)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
        type = t;
        id = i;
    }
    TriKey(const TriKey &k);
    bool operator==(const TriKey &k) const
    {
        return v[0] == k.v[0] && v[1] == k.v[1] && v[2] == k.v[2] && id == k.id && type == k.type;
    }
};

struct Hit {
    Vec4 pos;
    Vec4 normal;
    Vec4 c;
    float m30;
    float m34;
    int m38;
    int m3c;
    int m40;
    TriKey key;
};

struct TriKeyList {
    TriKey *data;
    unsigned size_;
    unsigned size() const { return size_; }
    bool Contains(const TriKey &k) const
    {
        unsigned i = 0;
        if (i < size()) {
            do {
                if (k == data[i])
                    return true;
            } while (++i < size());
        }
        return false;
    }
};

inline bool IdListContains(const int *p, int r)
{
    if (*p != 0) {
        do {
            if (*p++ == r)
                return true;
        } while (*p != 0);
    }
    return false;
}

struct Entry { char pad0[0x1c]; int m1c; char pad20[4]; };

struct State {
    int node;           /* 0x00 */
    Mat4 *nodeMtx;      /* 0x04 */
    char pad8[8];
    Mat4 mtx;           /* 0x10 */
    Vec4 m50;           /* 0x50 */
    Vec4 m60;           /* 0x60 */
    int m70;            /* 0x70 */
    int m74;            /* 0x74 */
    Mat4 *m78;          /* 0x78 */
    int m7c;            /* 0x7c */
    Hit *hit;           /* 0x80 */
    char pad84[4];
    unsigned char enable; /* 0x88 */
    char pad89[3];
    int m8c;            /* 0x8c */
    Entry *entries;     /* 0x90 */
    int *ids;           /* 0x94 */
    TriKeyList *keys;   /* 0x98 */
};

struct Info { char pad0[0x20]; int index; };

struct Coll {
    char pad0[4];
    Mat4 *nodes;            /* 0x04 */
    unsigned short *nodeMap; /* 0x08 */
    char padc[0x18 - 0xc];
    State *st;              /* 0x18 */
    Info *info;             /* 0x1c */
};

extern "C" {
Mat4 *FUN_00022598(Mat4 *, const Mat4 *, const Mat4 *);
Vec4 *FUN_00022570(Vec4 *, const Mat4 *, const Vec4 *);
int FUN_0004db54(Vec4 *, Hit *, int);
int FUN_0004b438(Coll *, const unsigned short *, const Vec4 *, Vec4 *, Entry *);
}

#define I3C_INVALID_NODE 0xffff

/* Debug build: assertions print through the (empty) variadic debug printf and hang. */
extern const char DAT_002cc1d4[];   /* "assertion \"%s\" failed: file \"%s\", line %d
" */
extern const char DAT_002cc1b4[];   /* "nodeIndexR != I3C_INVALID_NODE" */
extern const char DAT_002cc1a4[];   /* "collision.cpp" */
extern "C" void FUN_0004ae24(...);
#define HST_ASSERT(cond, text, line)     do { if (!(cond)) { FUN_0004ae24(DAT_002cc1d4, text, DAT_002cc1a4, line); for (;;) {} } } while (0)

extern "C" int FUN_0004c078(Coll *self, int key, const unsigned short *tri, const Vec4 *verts, const Vec4 *pos, Vec4 *out)
{
    int index = self->info->index;
    if (index < 0)
        return 0;
    State *st = self->st;
    Entry *e = &st->entries[index];
    if (e->m1c == 0)
        return 0;
    int node = key >> 16;
    if (st->node != node) {
        st->node = node;
        unsigned short nodeIndexR = self->nodeMap[node];
        HST_ASSERT(nodeIndexR != I3C_INVALID_NODE, DAT_002cc1b4, 514);
        st->nodeMtx = self->nodes + nodeIndexR;
        FUN_00022598(&st->mtx, st->m78, st->nodeMtx);
    }
    Vec4 v[9];          /* polygon buffer; only the triangle's three vertices are used */
    if (pos->w >= 0.0f) {
        v[0] = verts[tri[2]];
        v[1] = verts[tri[1]];
        v[2] = verts[tri[0]];
    } else {
        v[0] = verts[tri[0]];
        v[1] = verts[tri[1]];
        v[2] = verts[tri[2]];
    }
    int i;
    Vec4 *p;
    for (i = 0, p = v; i < 3; i++, p++) {
        p->w = 1.0f;
        FUN_00022570(p, &st->mtx, p);
    }
    Hit hit = *st->hit;
    if (FUN_0004db54(v, &hit, st->m7c) != 0) {
        if (!st->enable) {
            st->m70 = 0;
            return 0;
        }
        bool found = false;
        out->x = hit.normal.x;
        out->y = hit.normal.y;
        out->z = hit.normal.z;
        TriKey k(st->m8c, st->node, verts[tri[2]], verts[tri[1]], verts[tri[0]]);
        TriKeyList *keys = st->keys;
        if (keys != 0 && keys->size() != 0)
            found = keys->Contains(k);
        if (!found) {
            int r = FUN_0004b438(self, tri, verts, out, e);
            if (r == 0)
                r = st->hit->m3c;
            if (r != 0) {
                int *ids = st->ids;
                bool known = false;
                if (ids != 0)
                    known = IdListContains(ids, r);
                if (!known) {
                    *st->hit = hit;
                    st->hit->m38 = r;
                    st->hit->key = k;
                    st->m50 = *out;
                    st->m60 = *pos;
                    st->m70 = key;
                    st->m74 = index;
                }
            }
        }
    }
    return 1;
}

inline TriKey::TriKey(const TriKey &k)
{
    v[0] = k.v[0];
    v[1] = k.v[1];
    v[2] = k.v[2];
    type = k.type;
    id = k.id;
}

inline Vec4::Vec4(const Vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

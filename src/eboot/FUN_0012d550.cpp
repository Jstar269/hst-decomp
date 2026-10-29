/* HSTMATCH module=EBOOT.BIN start=0x0012d550 end=0x0012d75c symbol=FUN_0012d550 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

template<typename T>
struct Vector {
    T *data;
    int count;

    struct Iter {
        T *p;
        Iter(T *p_) : p(p_) {}
        T &operator*() const { return *p; }
        Iter &operator++() { ++p; return *this; }
        friend bool operator!=(const Iter &a, const Iter &b) {
            return !(a.p == b.p);
        }
    };

    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + count); }
};

/* Values of GetType() that carry a probe object. */
enum { ENTITY_TYPE_LIST1 = 4, ENTITY_TYPE_LIST2 = 5 };
struct Entity {
    virtual void _0() = 0;
    virtual void _1() = 0;
    virtual void _2() = 0;
    virtual void _3() = 0;
    virtual void _4() = 0;
    virtual void _5() = 0;
    virtual void _6() = 0;
    virtual void _7() = 0;
    virtual void _8() = 0;
    virtual void _9() = 0;
    virtual void _10() = 0;
    virtual int GetType() = 0; // offset 52 (0x34)

    char pad[0x54 - 4];
    unsigned char enabled;     // 84 (0x54)
    char pad55[0x74 - 0x55];
    void *probe1;             // 116 (0x74)
    void *probe2;             // 120 (0x78)
};

struct SceneObj {  // global scene (two entity lists)
    char pad[0x70];
    Vector<Entity *> list1;        // 0x70
    char pad78[4];
    Vector<Entity *> list2;        // 0x7c
};

struct RayHit {
    char pad[0x30];
    unsigned int dist;         // 48 (0x30)
    int unk34;                 // 52 (0x34)
    char pad38[4];
    int unk3c;                 // 60 (0x3c)
    int unk40;                 // 64 (0x40)
};

struct Context {
    char pad[12];
    void *mainProbe;            // 12 (0x0c)
};

extern "C" {
extern char DAT_002c1514;
extern SceneObj *DAT_0034a114;
extern bool FUN_00055b54(void *, RayHit *, int, void *, int, int, int);
}

/* Probe the main object and the enabled entities of both lists; true when any probe reports a hit. */
extern "C" bool FUN_0012d550(Context *ctx, RayHit *hit, int mask)
{
    hit->dist = 0x7f7fffff;  /* largest float: no hit yet */
    hit->unk34 = 0;
    hit->unk3c = 0;
    hit->unk40 = 0;

    bool result = false;
    if (FUN_00055b54(ctx->mainProbe, hit, mask, &DAT_002c1514, 0, 0, 1)) {
        result = true;
    }

    Entity *obj;
    Vector<Entity *> &list1 = DAT_0034a114->list1;
    for (Vector<Entity *>::Iter it = list1.begin(); it != list1.end(); ++it) {
        obj = *it;
        if (obj->GetType() == ENTITY_TYPE_LIST1) {
            if (obj->enabled && obj->probe1) {
                if (FUN_00055b54(obj->probe1, hit, mask, 0, 0, 0, 1)) {
                    result = true;
                }
            }
        }
    }

    Vector<Entity *> &list2 = DAT_0034a114->list2;
    for (Vector<Entity *>::Iter it = list2.begin(); it != list2.end(); ++it) {
        obj = *it;
        if (obj != 0) {
            if (obj->GetType() == ENTITY_TYPE_LIST2 && obj->enabled && obj->probe2) {
                if (FUN_00055b54(obj->probe2, hit, mask, 0, 0, 0, 1)) {
                    result = true;
                }
            }
        }
    }

    return result;
}

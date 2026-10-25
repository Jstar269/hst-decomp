/* HSTMATCH module=EBOOT.BIN start=0x00134210 end=0x00134414 symbol=FUN_00134210 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

typedef unsigned int uint;

struct Tag {};

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj1 {
    char pad[0x24c];
    float f24c;
    float f250;
};

class Obj_0023ed34 {
public:
    char pad0[0x3c];
    char b3c;
    char b3d;
    char pad1[0x301 - 0x3e];
    char b301;
    char pad2[0x330 - 0x302];
    void SetFlags() { b3c = 1; b3d = 1; b301 = 1; }
};

struct PVec1_00134210;
extern "C" void FUN_0013cb30(PVec1_00134210 *v, Obj1 *const *x, Tag a);

struct PVec1_00134210 {
    Obj1 **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj1 *const &x)
    {
        if (size < capacity) {
            unsigned idx = ++size - 1;
            data[idx] = x;
        } else {
            FUN_0013cb30(this, &x, Tag());
        }
    }
};

struct PVec2_00134210;
extern "C" void FUN_0013ca84(PVec2_00134210 *v, Obj_0023ed34 *const *x, Tag a);

struct PVec2_00134210 {
    Obj_0023ed34 **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj_0023ed34 *const &x)
    {
        if (size < capacity) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_0013ca84(this, &x, Tag());
        }
    }
};

struct Rec_00134414 {
    int id;
    int a;
    int b;
    int c;
    float d;
    float e;
    int f;
    int g;
    int flagged;
};

struct Owner_00134210 {
    char pad0[0x1350];
    float f1350;
    float f1354;
    char pad1[0x1398 - 0x1358];
    PVec2_00134210 objects2;
    PVec1_00134210 objects1;
    char pad2[0x13cc - 0x13b0];
    Rec_00134414 *records;
    unsigned count;
};

extern "C" {
void *operator new(unsigned int size);
Obj1 *FUN_0024b5a0(void *mem, int arg);
void FUN_0024ba68(Obj1 *obj, Vec4 *v1, Vec4 *v2);
void FUN_0001f21c(void *owner, void *obj);
Obj_0023ed34 *FUN_0023ed34(void *mem, int id);
void FUN_0023fe08(Obj_0023ed34 *obj, int a1, int a2, int a3, float f1, float f2, int a6, int a7);
}

extern "C" void FUN_00134210(Owner_00134210 *self) {
    Obj1 *local_4;
    Obj_0023ed34 *local_8;
    Vec4 v[3];

    Obj1 *mem1 = (Obj1 *)operator new(0x280);
    if (mem1)
        mem1 = FUN_0024b5a0(mem1, 8);
    local_4 = mem1;

    v[1].x = 12.0f;
    v[1].y = -3.0f;
    v[0].y = -3.0f;
    v[1].z = -9.12f;
    v[0].z = -9.12f;
    v[1].w = 1.0f;
    v[0].w = 1.0f;
    v[0].x = -12.0f;

    FUN_0024ba68(local_4, &v[1], &v[0]);

    float f1 = self->f1354;
    Obj1 *o = local_4;
    o->f24c = self->f1350;
    o->f250 = f1;

    self->objects1.push_back(local_4);

    FUN_0001f21c(self, local_4);

    for (unsigned i = 0; i < self->count; i++) {
        Obj_0023ed34 *mem = (Obj_0023ed34 *)operator new(0x330);
        if (mem)
            mem = FUN_0023ed34(mem, self->records[i].id);
        local_8 = mem;
        Rec_00134414 *r = &self->records[i];
        FUN_0023fe08(local_8, r->a, r->b, r->c, r->d, r->e, r->f, r->g);
        if (self->records[i].flagged)
            local_8->SetFlags();
        self->objects2.push_back(local_8);
        FUN_0001f21c(self, local_8);
    }
}

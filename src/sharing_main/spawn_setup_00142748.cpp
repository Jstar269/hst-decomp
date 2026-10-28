/* HSTMATCH module=hstp_trans_main.prx start=0x00142748 end=0x0014294c symbol=FUN_00142748 lang=c++ */
/* Clone of src/eboot/spawn_setup_001370fc.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Tag {};

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj1 {
    char pad[0x24c];
    float f24c;
    float f250;
};

class Obj_0024eecc {
public:
    char pad0[0x3c];
    char b3c;
    char b3d;
    char pad1[0x301 - 0x3e];
    char b301;
    char pad2[0x330 - 0x302];
    void SetFlags() { b3c = 1; b3d = 1; b301 = 1; }
};

struct PVec1_00142748;
extern "C" void FUN_0014817c(PVec1_00142748 *v, Obj1 *const *x, Tag a);

struct PVec1_00142748 {
    Obj1 **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj1 *const &x)
    {
        if (size < capacity) {
            unsigned idx = ++size - 1;
            data[idx] = x;
        } else {
            FUN_0014817c(this, &x, Tag());
        }
    }
};

struct PVec2_00142748;
extern "C" void FUN_001480d0(PVec2_00142748 *v, Obj_0024eecc *const *x, Tag a);

struct PVec2_00142748 {
    Obj_0024eecc **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj_0024eecc *const &x)
    {
        if (size < capacity) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_001480d0(this, &x, Tag());
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

struct Owner_00142748 {
    char pad0[0x1350];
    float f1350;
    float f1354;
    char pad1[0x1398 - 0x1358];
    PVec2_00142748 objects2;
    PVec1_00142748 objects1;
    char pad2[0x13cc - 0x13b0];
    Rec_00134414 *records;
    unsigned count;
};

extern "C" {
void *operator new(unsigned int size);
Obj1 *FUN_0025b7a8(void *mem, int arg);
void FUN_0025bc70(Obj1 *obj, Vec4 *v1, Vec4 *v2);
void FUN_0001ef34(void *owner, void *obj);
Obj_0024eecc *FUN_0024eecc(void *mem, int id);
void FUN_0024ffa0(Obj_0024eecc *obj, int a1, int a2, int a3, float f1, float f2, int a6, int a7);
}

extern "C" void FUN_00142748(Owner_00142748 *self) {
    Obj1 *local_4;
    Obj_0024eecc *local_8;
    Vec4 v[3];

    Obj1 *mem1 = (Obj1 *)operator new(0x280);
    if (mem1)
        mem1 = FUN_0025b7a8(mem1, 5);
    local_4 = mem1;

    v[1].x = 12.0f;
    v[1].y = -3.0f;
    v[0].y = -3.0f;
    v[1].z = -9.12f;
    v[0].z = -9.12f;
    v[1].w = 1.0f;
    v[0].w = 1.0f;
    v[0].x = -12.0f;

    FUN_0025bc70(local_4, &v[1], &v[0]);

    float f1 = self->f1354;
    Obj1 *o = local_4;
    o->f24c = self->f1350;
    o->f250 = f1;

    self->objects1.push_back(local_4);

    FUN_0001ef34(self, local_4);

    for (unsigned i = 0; i < self->count; i++) {
        Obj_0024eecc *mem = (Obj_0024eecc *)operator new(0x330);
        if (mem)
            mem = FUN_0024eecc(mem, self->records[i].id);
        local_8 = mem;
        Rec_00134414 *r = &self->records[i];
        FUN_0024ffa0(local_8, r->a, r->b, r->c, r->d, r->e, r->f, r->g);
        if (self->records[i].flagged)
            local_8->SetFlags();
        self->objects2.push_back(local_8);
        FUN_0001ef34(self, local_8);
    }
}

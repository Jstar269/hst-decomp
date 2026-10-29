/* HSTMATCH module=EBOOT.BIN start=0x00134210 end=0x00134414 symbol=FUN_00134210 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#define FIRST_OBJ_SIZE 0x280 /* bytes of the first object */
#define SPAWN_OBJ_SIZE 0x330  /* bytes per spawned record object */

struct Tag {};

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

/* First object (0x280 bytes): only the two floats copied from the owner are named. */
struct Obj280 {
    char pad[0x24c];
    float unk24c;
    float unk250;
};

/* Spawned object (0x330 bytes); only the three bytes set by SetFlags are named. */
class SpawnObj {
public:
    char pad0[0x3c];
    char unk3c;
    char unk3d;
    char pad1[0x301 - 0x3e];
    char unk301;
    char pad2[0x330 - 0x302];
    void SetFlags() { unk3c = 1; unk3d = 1; unk301 = 1; }
};

struct Obj280Vec;
extern "C" void FUN_0013cb30(Obj280Vec *v, Obj280 *const *x, Tag a);

struct Obj280Vec {
    Obj280 **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj280 *const &x)
    {
        if (size < capacity) {
            unsigned idx = ++size - 1;
            data[idx] = x;
        } else {
            FUN_0013cb30(this, &x, Tag());
        }
    }
};

struct SpawnObjVec;
extern "C" void FUN_0013ca84(SpawnObjVec *v, SpawnObj *const *x, Tag a);

struct SpawnObjVec {
    SpawnObj **data;
    unsigned size;
    unsigned capacity;
    void push_back(SpawnObj *const &x)
    {
        if (size < capacity) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_0013ca84(this, &x, Tag());
        }
    }
};

/* Spawn record (0x24 bytes): object id, seven configuration values passed to the setup call, and a flag word. */
struct SpawnRec {
    int id;
    int unk04;
    int unk08;
    int unk0c;
    float unk10;
    float unk14;
    int unk18;
    int unk1c;
    int flagged;
};

struct Owner {
    char pad0[0x1350];
    float unk1350;
    float unk1354;
    char pad1[0x1398 - 0x1358];
    SpawnObjVec spawns;
    Obj280Vec bigObjs;
    char pad2[0x13cc - 0x13b0];
    SpawnRec *records;
    unsigned count;
};

extern "C" {
void *operator new(unsigned int size);
Obj280 *FUN_0024b5a0(void *storage, int arg);
void FUN_0024ba68(Obj280 *obj, Vec4 *v1, Vec4 *v2);
void FUN_0001f21c(void *owner, void *obj);
SpawnObj *FUN_0023ed34(void *storage, int id);
void FUN_0023fe08(SpawnObj *obj, int a1, int a2, int a3, float f1, float f2, int a6, int a7);
}

/* Creates the first object (set up from two fixed corner vectors and carrying the owner's two floats), then one object per spawn record,
   registering each with the owner. */
extern "C" void FUN_00134210(Owner *self) {
    Obj280 *first_obj;
    SpawnObj *spawned;
    Vec4 v[3];

    Obj280 *first_mem = (Obj280 *)operator new(FIRST_OBJ_SIZE);
    if (first_mem)
        first_mem = FUN_0024b5a0(first_mem, 8);
    first_obj = first_mem;

    v[1].x = 12.0f;
    v[1].y = -3.0f;
    v[0].y = -3.0f;
    v[1].z = -9.12f;
    v[0].z = -9.12f;
    v[1].w = 1.0f;
    v[0].w = 1.0f;
    v[0].x = -12.0f;

    FUN_0024ba68(first_obj, &v[1], &v[0]);

    float second = self->unk1354;
    Obj280 *o = first_obj;
    o->unk24c = self->unk1350;
    o->unk250 = second;

    self->bigObjs.push_back(first_obj);

    FUN_0001f21c(self, first_obj);

    for (unsigned i = 0; i < self->count; i++) {
        SpawnObj *storage = (SpawnObj *)operator new(SPAWN_OBJ_SIZE);
        if (storage)
            storage = FUN_0023ed34(storage, self->records[i].id);
        spawned = storage;
        SpawnRec *r = &self->records[i];
        FUN_0023fe08(spawned, r->unk04, r->unk08, r->unk0c, r->unk10, r->unk14, r->unk18, r->unk1c);
        if (self->records[i].flagged)
            spawned->SetFlags();
        self->spawns.push_back(spawned);
        FUN_0001f21c(self, spawned);
    }
}

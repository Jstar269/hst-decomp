/* HSTMATCH module=EBOOT.BIN start=0x00134414 end=0x00134548 symbol=FUN_00134414 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
/* Spawn loop: for each 0x24-byte spawn record, construct a 0x330-byte object from the record's id,
   configure it (two float parameters), optionally set three flags, append it to an object vector and
   register it with the owner. The constructor result is assigned back to the allocation pointer and then
   copied into the address-taken local, so both paths share one store (retail `beqzl v0; sw v0,28(sp)`).
   Names provisional. */
#define SPAWN_OBJ_SIZE 0x330 /* bytes per spawned object */

extern "C" {
void FUN_0023fe08(void *obj, int a, int b, int c, float d, float e, int f, int g);
void FUN_0001f21c(void *owner, void *obj);
}
struct Tag {};
/* Spawn record (0x24 bytes): object id, seven configuration values passed to the setup call, and a flag word. */
struct SpawnRec { int id; int unk04; int unk08; int unk0c; float unk10; float unk14; int unk18; int unk1c; int flagged; };
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
extern "C" SpawnObj *FUN_0023ed34(void *storage, int id);
void *operator new(unsigned int size);
struct ObjVec;
extern "C" void FUN_0013ca84(ObjVec *v, SpawnObj *const *x, Tag a);
struct ObjVec {
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
struct Owner {
    char pad0[0x1398];
    ObjVec objects;                  /* 0x1398 spawned objects */
    char pad1[0x13cc - 0x13a4];
    SpawnRec *records;               /* 0x13cc spawn records */
    unsigned count;                  /* 0x13d0 number of records */
};
extern "C" void FUN_00134414(Owner *owner)
{
    for (unsigned i = 0; i < owner->count; i++) {
        SpawnObj *storage = (SpawnObj *)operator new(SPAWN_OBJ_SIZE);
        if (storage)
            storage = FUN_0023ed34(storage, owner->records[i].id);
        SpawnObj *obj = storage;
        SpawnRec *r = &owner->records[i];
        FUN_0023fe08(obj, r->unk04, r->unk08, r->unk0c, r->unk10, r->unk14, r->unk18, r->unk1c);
        if (owner->records[i].flagged)
            obj->SetFlags();
        owner->objects.push_back(obj);
        FUN_0001f21c(owner, obj);
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x00134414 end=0x00134548 symbol=FUN_00134414 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
/* Spawn loop: for each 0x24-byte spawn record, construct a 0x330-byte object from the record's id,
   configure it (two float parameters), optionally set three flags, append it to an object vector and
   register it with the owner. The constructor result is assigned back to the allocation pointer and then
   copied into the address-taken local, so both paths share one store (retail `beqzl v0; sw v0,28(sp)`).
   Names provisional. */
extern "C" {
void FUN_0023fe08(void *obj, int a, int b, int c, float d, float e, int f, int g);
void FUN_0001f21c(void *owner, void *obj);
}
struct Alloc_00134414 {};
struct Rec_00134414 { int id; int a; int b; int c; float d; float e; int f; int g; int flagged; };
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
extern "C" Obj_0023ed34 *FUN_0023ed34(void *mem, int id);
void *operator new(unsigned int size);
struct PVec_00134414;
extern "C" void FUN_0013ca84(PVec_00134414 *v, Obj_0023ed34 *const *x, Alloc_00134414 a);
struct PVec_00134414 {
    Obj_0023ed34 **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj_0023ed34 *const &x)
    {
        if (size < capacity) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_0013ca84(this, &x, Alloc_00134414());
        }
    }
};
struct Owner_00134414 {
    char pad0[0x1398];
    PVec_00134414 objects;
    char pad1[0x13cc - 0x13a4];
    Rec_00134414 *records;
    unsigned count;
};
extern "C" void FUN_00134414(Owner_00134414 *m)
{
    for (unsigned i = 0; i < m->count; i++) {
        Obj_0023ed34 *mem = (Obj_0023ed34 *)operator new(0x330);
        if (mem)
            mem = FUN_0023ed34(mem, m->records[i].id);
        Obj_0023ed34 *o = mem;
        Rec_00134414 *r = &m->records[i];
        FUN_0023fe08(o, r->a, r->b, r->c, r->d, r->e, r->f, r->g);
        if (m->records[i].flagged)
            o->SetFlags();
        m->objects.push_back(o);
        FUN_0001f21c(m, o);
    }
}

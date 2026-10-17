/* HSTMATCH module=hstp_trans_main.prx start=0x0013fa60 end=0x0013fb94 symbol=FUN_0013fa60 lang=c++ */
/* Clone of src/eboot/spawn_00134414.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
/* Spawn loop: for each 0x24-byte spawn record, construct a 0x330-byte object from the record's id,
   configure it (two float parameters), optionally set three flags, append it to an object vector and
   register it with the owner. The constructor result is assigned back to the allocation pointer and then
   copied into the address-taken local, so both paths share one store (retail `beqzl v0; sw v0,28(sp)`).
   Names provisional. */
extern "C" {
void FUN_0024ffa0(void *obj, int a, int b, int c, float d, float e, int f, int g);
void FUN_0001ef34(void *owner, void *obj);
}
struct Alloc_0013fa60 {};
struct Rec_0013fa60 { int id; int a; int b; int c; float d; float e; int f; int g; int flagged; };
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
extern "C" Obj_0024eecc *FUN_0024eecc(void *mem, int id);
void *operator new(unsigned int size);
struct PVec_0013fa60;
extern "C" void FUN_001480d0(PVec_0013fa60 *v, Obj_0024eecc *const *x, Alloc_0013fa60 a);
struct PVec_0013fa60 {
    Obj_0024eecc **data;
    unsigned size;
    unsigned capacity;
    void push_back(Obj_0024eecc *const &x)
    {
        if (size < capacity) {
            ++size;
            data[size - 1] = x;
        } else {
            FUN_001480d0(this, &x, Alloc_0013fa60());
        }
    }
};
struct Owner_0013fa60 {
    char pad0[0x1398];
    PVec_0013fa60 objects;
    char pad1[0x13cc - 0x13a4];
    Rec_0013fa60 *records;
    unsigned count;
};
extern "C" void FUN_0013fa60(Owner_0013fa60 *m)
{
    for (unsigned i = 0; i < m->count; i++) {
        Obj_0024eecc *mem = (Obj_0024eecc *)operator new(0x330);
        if (mem)
            mem = FUN_0024eecc(mem, m->records[i].id);
        Obj_0024eecc *o = mem;
        Rec_0013fa60 *r = &m->records[i];
        FUN_0024ffa0(o, r->a, r->b, r->c, r->d, r->e, r->f, r->g);
        if (m->records[i].flagged)
            o->SetFlags();
        m->objects.push_back(o);
        FUN_0001ef34(m, o);
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x0028b5f4 end=0x0028b654 symbol=FUN_0028b5f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct VecA; struct VecB; struct VecC;
extern "C" void FUN_0028c860(VecC *v, int n, Tag t);
extern "C" void FUN_0028c7a4(VecB *v, int n, Tag t);
extern "C" void FUN_0028c6e8(VecA *v, int n, Tag t);
struct VecA { void *data; int size; int pad;
    void clear() { int n = size; FUN_0028c6e8(this, n, Tag()); } };
struct VecB { void *data; int size; int pad;
    void clear() { int n = size; FUN_0028c7a4(this, n, Tag()); } };
struct VecC { void *data; int size; int pad;
    void clear() { int n = size; FUN_0028c860(this, n, Tag()); } };
struct Obj {
    VecA a;
    VecB b;
    VecC c;
    int tail;
};
extern "C" void FUN_0028b5f4(Obj *o)
{
    o->tail = 0;
    o->c.clear();
    o->b.clear();
    o->a.clear();
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0029cde8 end=0x0029ce48 symbol=FUN_0029cde8 lang=c++ */
/* Clone of src/eboot/clear_three_vectors_0028b5f4.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct VecA; struct VecB; struct VecC;
extern "C" void FUN_0029e028(VecC *v, int n, Tag t);
extern "C" void FUN_0029df6c(VecB *v, int n, Tag t);
extern "C" void FUN_0029deb0(VecA *v, int n, Tag t);
struct VecA { void *data; int size; int pad;
    void clear() { int n = size; FUN_0029deb0(this, n, Tag()); } };
struct VecB { void *data; int size; int pad;
    void clear() { int n = size; FUN_0029df6c(this, n, Tag()); } };
struct VecC { void *data; int size; int pad;
    void clear() { int n = size; FUN_0029e028(this, n, Tag()); } };
struct Obj {
    VecA a;
    VecB b;
    VecC c;
    int tail;
};
extern "C" void FUN_0029cde8(Obj *o)
{
    o->tail = 0;
    o->c.clear();
    o->b.clear();
    o->a.clear();
}

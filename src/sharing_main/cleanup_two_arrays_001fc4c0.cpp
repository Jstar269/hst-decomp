/* HSTMATCH module=hstp_trans_main.prx start=0x001fc4c0 end=0x001fc5c8 symbol=FUN_001fc4c0 lang=c++ */
/* Clone of src/eboot/cleanup_two_arrays_001ee0f8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (started from the near-miss wip of lane ds1); exact match verified; names and types await human review. */
/* Two groups of 10 {a, b, c(virtual-dtor object)} records cleared from the back; the second group is reached as `q[10]` from the same cursor shape as the first (matching idiom: the +10 element access keeps the base register and gives retail's +0x78.. displacements; each loop declares its own index and pointer). */

struct VB { int pad; };
struct VC : VB { virtual ~VC(); };

struct Rec {
    void *a;
    void *b;
    VC *c;
};

struct X {
    Rec arr[20];
};

extern "C" void FUN_0005e634(void *p, int flag);
extern "C" void FUN_000569f4(void *p, int flag);

extern "C" void FUN_001fc4c0(X *self)
{
    for (int i = 9; i >= 0; i--) {
        Rec *r = &self->arr[i];
        if (r->c) {
            delete r->c;
            r->c = 0;
        }
        if (r->b) {
            FUN_0005e634(r->b, 1);
            r->b = 0;
        }
        if (r->a) {
            FUN_000569f4(r->a, 1);
            r->a = 0;
        }
    }
    for (int j = 9; j >= 0; j--) {
        Rec *q = &self->arr[j];
        if (q[10].c) {
            delete q[10].c;
            q[10].c = 0;
        }
        if (q[10].b) {
            FUN_0005e634(q[10].b, 1);
            q[10].b = 0;
        }
        if (q[10].a) {
            FUN_000569f4(q[10].a, 1);
            q[10].a = 0;
        }
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x001ee0f8 end=0x001ee200 symbol=FUN_001ee0f8 lang=c++ */
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

extern "C" void FUN_0005d818(void *p, int flag);
extern "C" void FUN_00055e48(void *p, int flag);

extern "C" void FUN_001ee0f8(X *self)
{
    for (int i = 9; i >= 0; i--) {
        Rec *r = &self->arr[i];
        if (r->c) {
            delete r->c;
            r->c = 0;
        }
        if (r->b) {
            FUN_0005d818(r->b, 1);
            r->b = 0;
        }
        if (r->a) {
            FUN_00055e48(r->a, 1);
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
            FUN_0005d818(q[10].b, 1);
            q[10].b = 0;
        }
        if (q[10].a) {
            FUN_00055e48(q[10].a, 1);
            q[10].a = 0;
        }
    }
}

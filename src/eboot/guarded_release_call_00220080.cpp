/* HSTMATCH module=EBOOT.BIN start=0x00220080 end=0x002200d4 symbol=FUN_00220080 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_0005f1e8(void *, int);
extern "C" void FUN_001031e8(void *);

struct Obj {
    char pad0[0x54];
    unsigned char f54;
    unsigned char f55;
    char pad1[0x36];
    void *p8c;
};

extern "C" void FUN_00220080(Obj *o)
{
    if (o->p8c != 0) {
        if (o->f55 != 0) {
            FUN_0005f1e8(o->p8c, 0);
        }
    }
    if (o->f54 == 0) {
        FUN_001031e8(o);
    }
}

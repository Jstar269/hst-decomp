/* HSTMATCH module=EBOOT.BIN start=0x0015e660 end=0x0015e704 symbol=FUN_0015e660 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class Poly { public: virtual ~Poly(); };
extern "C" {
extern char DAT_0030907c;
extern void FUN_00060e7c(void *self, int flag);
extern void FUN_00000a00(void *p);
}
struct Obj {
    int vptr;
    char pad[0xa4];
    Poly *fa8;
    int fac[2];
};
extern "C" Obj *FUN_0015e660(Obj *self, short flags)
{
    if (self) {
        self->vptr = (int)&DAT_0030907c;
        unsigned k = 0;
        do { self->fac[k] = 0; } while (++k < 2);
        if (self->fa8) {
            delete self->fa8;
            self->fa8 = 0;
        }
        FUN_00060e7c(self, 0);
        if (flags > 0) FUN_00000a00(self);
    }
    return self;
}

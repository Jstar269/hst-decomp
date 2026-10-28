/* HSTMATCH module=hstp_trans_main.prx start=0x0016abec end=0x0016ac90 symbol=FUN_0016abec lang=c++ */
/* Clone of src/eboot/release_obj_0015e660.cpp (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class Poly { public: virtual ~Poly(); };
extern "C" {
extern char DAT_003b2348;
extern void FUN_00061d00(void *self, int flag);
extern void FUN_00000a00(void *p);
}
struct Obj {
    int vptr;
    char pad[0xa4];
    Poly *fa8;
    int fac[2];
};
extern "C" Obj *FUN_0016abec(Obj *self, short flags)
{
    if (self) {
        self->vptr = (int)&DAT_003b2348;
        unsigned k = 0;
        do { self->fac[k] = 0; } while (++k < 2);
        if (self->fa8) {
            delete self->fa8;
            self->fa8 = 0;
        }
        FUN_00061d00(self, 0);
        if (flags > 0) FUN_00000a00(self);
    }
    return self;
}

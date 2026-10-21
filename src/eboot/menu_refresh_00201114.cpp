/* HSTMATCH module=EBOOT.BIN start=0x00201114 end=0x00201228 symbol=FUN_00201114 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void FUN_0019335c(int *a, int *b, void *arg);
void FUN_00200f48(void *self, void *entry, int mode, int idx);
extern char *DAT_0034a13c;
}
struct Widget_00201114 {
    virtual void Vfn0();
    virtual void Vfn1(int on);
};
extern "C" void FUN_00201114(char *self)
{
    int a = 0;
    int b = 0;
    FUN_0019335c(&a, &b, *(void **)self);
    (*(Widget_00201114 **)(self + 0x10))->Vfn1(1);
    (*(Widget_00201114 **)(self + 0x14))->Vfn1(1);
    if (*(unsigned char *)(DAT_0034a13c + 0xc4) == 0) {
        if (a == 0)
            return;
        (*(Widget_00201114 **)(self + 0x10))->Vfn1(0);
        FUN_00200f48(self, (void *)a, 3, 0);
    } else {
        if (a != 0) {
            (*(Widget_00201114 **)(self + 0x10))->Vfn1(0);
            FUN_00200f48(self, (void *)a, 3, 0);
        }
        if (b != 0) {
            (*(Widget_00201114 **)(self + 0x14))->Vfn1(0);
            FUN_00200f48(self, (void *)b, 8, 1);
        }
    }
}

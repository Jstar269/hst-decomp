/* HSTMATCH module=hstp_trans_main.prx start=0x0020f8e4 end=0x0020f9f8 symbol=FUN_0020f8e4 lang=c++ */
/* Clone of src/eboot/menu_refresh_00201114.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void FUN_0019fb6c(int *a, int *b, void *arg);
void FUN_0020f718(void *self, void *entry, int mode, int idx);
extern char *DAT_003f3474;
}
struct Widget_0020f8e4 {
    virtual void Vfn0();
    virtual void Vfn1(int on);
};
extern "C" void FUN_0020f8e4(char *self)
{
    int a = 0;
    int b = 0;
    FUN_0019fb6c(&a, &b, *(void **)self);
    (*(Widget_0020f8e4 **)(self + 0x10))->Vfn1(1);
    (*(Widget_0020f8e4 **)(self + 0x14))->Vfn1(1);
    if (*(unsigned char *)(DAT_003f3474 + 0xc4) == 0) {
        if (a == 0)
            return;
        (*(Widget_0020f8e4 **)(self + 0x10))->Vfn1(0);
        FUN_0020f718(self, (void *)a, 3, 0);
    } else {
        if (a != 0) {
            (*(Widget_0020f8e4 **)(self + 0x10))->Vfn1(0);
            FUN_0020f718(self, (void *)a, 3, 0);
        }
        if (b != 0) {
            (*(Widget_0020f8e4 **)(self + 0x14))->Vfn1(0);
            FUN_0020f718(self, (void *)b, 8, 1);
        }
    }
}

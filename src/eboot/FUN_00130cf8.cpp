/* HSTMATCH module=EBOOT.BIN start=0x00130cf8 end=0x00130d60 symbol=FUN_00130cf8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x48];
    void *p;
    unsigned char flag;
};

extern float DAT_002db1a4;
extern "C" void FUN_00063ebc(void *, float, float);

extern "C" void FUN_00130cf8(Obj *self)
{
    if (self->p != 0) {
        if (self->flag != 0) {
            self->flag = 0;
            FUN_00063ebc(self->p, 65279.0f, 0.0f);
        } else {
            FUN_00063ebc(self->p, 65279.0f, DAT_002db1a4);
        }
    }
}

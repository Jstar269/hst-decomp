/* HSTMATCH module=hstp_trans_main.prx start=0x0013c2b0 end=0x0013c318 symbol=FUN_0013c2b0 lang=c++ */
/* Clone of src/eboot/FUN_00130cf8.cpp (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[0x48];
    void *p;
    unsigned char flag;
};

extern float DAT_003823b0;
extern "C" void FUN_00064d80(void *, float, float);

extern "C" void FUN_0013c2b0(Obj *self)
{
    if (self->p != 0) {
        if (self->flag != 0) {
            self->flag = 0;
            FUN_00064d80(self->p, 65279.0f, 0.0f);
        } else {
            FUN_00064d80(self->p, 65279.0f, DAT_003823b0);
        }
    }
}

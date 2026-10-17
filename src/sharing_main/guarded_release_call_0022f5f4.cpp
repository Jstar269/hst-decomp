/* HSTMATCH module=hstp_trans_main.prx start=0x0022f5f4 end=0x0022f648 symbol=FUN_0022f5f4 lang=c++ */
/* Clone of src/eboot/guarded_release_call_00220080.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_0005ffd8(void *, int);
extern "C" void FUN_00108aec(void *);

struct Obj {
    char pad0[0x54];
    unsigned char f54;
    unsigned char f55;
    char pad1[0x36];
    void *p8c;
};

extern "C" void FUN_0022f5f4(Obj *o)
{
    if (o->p8c != 0) {
        if (o->f55 != 0) {
            FUN_0005ffd8(o->p8c, 0);
        }
    }
    if (o->f54 == 0) {
        FUN_00108aec(o);
    }
}

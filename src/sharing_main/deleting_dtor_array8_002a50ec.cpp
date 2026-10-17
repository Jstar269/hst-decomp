/* HSTMATCH module=hstp_trans_main.prx start=0x002a50ec end=0x002a5188 symbol=FUN_002a50ec lang=c++ */
/* Clone of src/eboot/deleting_dtor_array8_00293ae0.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of an object holding Elem[8] (12-byte elements, sizes at +4): body shrinks each element by its own size through the out-of-line 0x2a4010 (empty tag by value), then the member-array destroy 0x788 with the element deleting-dtor stub 0x2a5080. Names provisional. */
struct Tag {};
struct Elem {
    int a;
    int size;
    int c;
};
struct Obj {
    Elem e[8];
};
extern "C" void FUN_002a561c(Elem *, int, Tag);
extern "C" void FUN_002a5080();
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);

extern "C" Obj *FUN_002a50ec(Obj *self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < 8; i++) {
            FUN_002a561c(&self->e[i], self->e[i].size, Tag());
        }
        FUN_00000788(self, (void *)FUN_002a5080, 12, 8);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}

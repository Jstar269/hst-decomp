/* HSTMATCH module=hstp_trans_main.prx start=0x001980f4 end=0x00198190 symbol=FUN_001980f4 lang=c++ */
/* Hand-written reconstruction from the disassembly (statement order as in the EBOOT twin src/eboot/obj_ctor_0018b944.cpp, here with a typed layout); exact match verified; names and types await human review. */
/* Constructor: base init FUN_0001ec44, vtable DAT_003b2428, registers itself in DAT_003ea86c, clears its
   state, keeps the two arguments at +0x48/+0x4c, runs FUN_00198c8c and installs three callbacks. */
typedef void (*Callback)();

struct Obj {
    void *vptr;
    char pad04[0x3c - 0x4];
    int f3c;
    char pad40[0x44 - 0x40];
    unsigned char b44;
    unsigned char b45;
    char pad46[0x48 - 0x46];
    int f48;
    int f4c;
    int f50;
    int f54;
    char pad58[0x7c - 0x58];
    Callback cb7c;
    Callback cb80;
    Callback cb84;
};

extern "C" void FUN_0001ec44(Obj *self);
extern "C" void FUN_00198c8c(Obj *self);
extern "C" void FUN_00198000();
extern "C" void FUN_00197fc0();
extern "C" void FUN_00197fdc();
extern char DAT_003b2428[];
extern Obj *DAT_003ea86c;

extern "C" Obj *FUN_001980f4(Obj *self, int a, int b)
{
    FUN_0001ec44(self);
    self->vptr = DAT_003b2428;
    DAT_003ea86c = self;
    self->f50 = 0;
    self->f54 = 0;
    self->b44 = 0;
    self->b45 = 0;
    self->f3c = 0;
    self->f48 = a;
    self->f4c = b;
    FUN_00198c8c(self);
    self->cb7c = FUN_00198000;
    self->cb80 = FUN_00197fc0;
    self->cb84 = FUN_00197fdc;
    return self;
}

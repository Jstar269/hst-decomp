/* HSTMATCH module=hstp_trans_main.prx start=0x0020fef4 end=0x0020ffe0 symbol=FUN_0020fef4 lang=c++ */
/* Clone of src/eboot/set_sub_floats_00201724.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: virtual slot-1 calls (`lw t9,12(t9)`) as a polymorphic member call s1(1) on all three objects (the first call's a1 = 1 is shared with the constant stored to +0x710, Ghidra drops that argument), float stores of -240.0f/240.0f into a typed Sub60 field, DAT_003f3474 as a byte-addressed table pointer; exact match verified; names and types await human review. */
struct Virt { virtual void s0(); virtual void s1(int); };
struct Sub60 { char pad[0x60]; float f60; };
struct Obj {
    char pad0[0xc];
    Virt *a;
    Sub60 *o10;
    Sub60 *o14;
    Sub60 *o18;
    Sub60 *o1c;
    Sub60 *o20;
    Virt *b24;
    char pad28[0x708 - 0x28];
    Virt *b708;
    int pad70c;
    int f710;
    int f714;
};
struct Tab { char pad[0xcd0]; };
extern Tab *DAT_003f3474;
extern "C" {
void FUN_00108558(Sub60 *);
void FUN_0020f39c(Obj *, char *, char *);
void FUN_0020ffe0(Obj *);
}

extern "C" void FUN_0020fef4(Obj *o)
{
    o->f710 = 1;
    o->f714 = 0;
    o->a->s1(1);
    o->b24->s1(1);
    o->b708->s1(1);
    o->o20->f60 = -240.0f;
    FUN_00108558(o->o20);
    o->o10->f60 = 240.0f;
    FUN_00108558(o->o10);
    o->o14->f60 = 240.0f;
    FUN_00108558(o->o14);
    o->o18->f60 = 240.0f;
    FUN_00108558(o->o18);
    o->o1c->f60 = 240.0f;
    FUN_00108558(o->o1c);
    FUN_0020f39c(o, (char *)DAT_003f3474 + 0xcd0, (char *)DAT_003f3474 + 0xf90);
    FUN_0020ffe0(o);
}

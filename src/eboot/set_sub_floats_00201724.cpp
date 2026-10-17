/* HSTMATCH module=EBOOT.BIN start=0x00201724 end=0x00201810 symbol=FUN_00201724 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: virtual slot-1 calls (`lw t9,12(t9)`) as a polymorphic member call s1(1) on all three objects (the first call's a1 = 1 is shared with the constant stored to +0x710, Ghidra drops that argument), float stores of -240.0f/240.0f into a typed Sub60 field, DAT_0034a13c as a byte-addressed table pointer; exact match verified; names and types await human review. */
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
extern Tab *DAT_0034a13c;
extern "C" {
void FUN_00102c54(Sub60 *);
void FUN_00200bcc(Obj *, char *, char *);
void FUN_00201810(Obj *);
}

extern "C" void FUN_00201724(Obj *o)
{
    o->f710 = 1;
    o->f714 = 0;
    o->a->s1(1);
    o->b24->s1(1);
    o->b708->s1(1);
    o->o20->f60 = -240.0f;
    FUN_00102c54(o->o20);
    o->o10->f60 = 240.0f;
    FUN_00102c54(o->o10);
    o->o14->f60 = 240.0f;
    FUN_00102c54(o->o14);
    o->o18->f60 = 240.0f;
    FUN_00102c54(o->o18);
    o->o1c->f60 = 240.0f;
    FUN_00102c54(o->o1c);
    FUN_00200bcc(o, (char *)DAT_0034a13c + 0xcd0, (char *)DAT_0034a13c + 0xf90);
    FUN_00201810(o);
}

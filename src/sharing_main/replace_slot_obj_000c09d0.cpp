/* HSTMATCH module=hstp_trans_main.prx start=0x000c09d0 end=0x000c0ab8 symbol=FUN_000c09d0 lang=c++ */
/* Clone of src/eboot/replace_slot_obj_000bd480.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: typed 7-byte entry struct (unsigned char on = lbu) and slot array member addressed as g->slots[idx] at every use (the local-pointer form flips the addu operands), allocation stored with the merged store (beqzl) and o->c written through the new object; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b06b0;
extern char DAT_0037bdcc[];
extern char DAT_0037bdf8[];
extern int FUN_00000a90(...);
extern void *FUN_00000bcc(...);
extern void FUN_000bd6f0(...);
}
struct VC_0 { virtual ~VC_0(); };
struct Ent { char pad[6]; unsigned char on; };
struct Rec { int vptr; int a; int b; int c; char d; };
struct Self {
    char pad0[0x58];
    Ent ent[8];
    char pad1[0x1dc - 0x58 - 56];
    VC_0 *slots[8];
};

extern "C" int FUN_000c09d0(Self *g, int idx, int a, int b)
{
    if (g->ent[idx].on == 0) {
        FUN_000bd6f0(DAT_0037bdcc);
        return 0;
    }
    if (g->slots[idx] != 0) {
        delete g->slots[idx];
        g->slots[idx] = 0;
    }
    Rec *o = (Rec *)FUN_00000bcc(0x14);
    if (o != 0) {
        o->vptr = (int)&DAT_003b06b0;
        o->b = 0;
        o->a = 0;
        o->c = 0;
        o->d = 0;
    }
    g->slots[idx] = (VC_0 *)o;
    o->c = b;
    ((Rec *)g->slots[idx])->a = a;
    int r = FUN_00000a90(b);
    ((Rec *)g->slots[idx])->b = r;
    FUN_000bd6f0(DAT_0037bdf8);
    return 1;
}

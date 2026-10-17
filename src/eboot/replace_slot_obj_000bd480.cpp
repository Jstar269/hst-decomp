/* HSTMATCH module=EBOOT.BIN start=0x000bd480 end=0x000bd568 symbol=FUN_000bd480 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: typed 7-byte entry struct (unsigned char on = lbu) and slot array member addressed as g->slots[idx] at every use (the local-pointer form flips the addu operands), allocation stored with the merged store (beqzl) and o->c written through the new object; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003073e4;
extern char DAT_002d5498[];
extern char DAT_002d54c4[];
extern int FUN_00000a90(...);
extern void *FUN_00000bcc(...);
extern void FUN_000ba3ac(...);
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

extern "C" int FUN_000bd480(Self *g, int idx, int a, int b)
{
    if (g->ent[idx].on == 0) {
        FUN_000ba3ac(DAT_002d5498);
        return 0;
    }
    if (g->slots[idx] != 0) {
        delete g->slots[idx];
        g->slots[idx] = 0;
    }
    Rec *o = (Rec *)FUN_00000bcc(0x14);
    if (o != 0) {
        o->vptr = (int)&DAT_003073e4;
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
    FUN_000ba3ac(DAT_002d54c4);
    return 1;
}

/* HSTMATCH module=EBOOT.BIN start=0x001f4ee0 end=0x001f4f80 symbol=FUN_001f4ee0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ent {
    char pad[0x58];
    int f58;
};
struct Glob {
    char pad[0xa8];
    void *p;
};
extern Glob *DAT_003386b0;
extern "C" int FUN_001b5764(void *p, int i, int c);
struct Obj {
    char pad[0x3a0];
    Ent *ents[4];
};
extern "C" void FUN_001f4ee0(Obj *o, Ent *sel)
{
    void *m = DAT_003386b0->p;
    for (int i = 0; i < 4; i++) {
        if (sel == 0 || sel == o->ents[i]) {
            Ent *e = o->ents[i];
            int v = e ? e->f58 : 0;
            if (v != 0 && m != 0) {
                FUN_001b5764(m, i, 0x82);
            }
        }
    }
}

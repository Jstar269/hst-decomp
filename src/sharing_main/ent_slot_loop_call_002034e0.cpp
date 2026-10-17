/* HSTMATCH module=hstp_trans_main.prx start=0x002034e0 end=0x00203580 symbol=FUN_002034e0 lang=c++ */
/* Clone of src/eboot/ent_slot_loop_call_001f4ee0.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ent {
    char pad[0x58];
    int f58;
};
struct Glob {
    char pad[0xa8];
    void *p;
};
extern Glob *DAT_003e19f0;
extern "C" int FUN_001c3418(void *p, int i, int c);
struct Obj {
    char pad[0x3a0];
    Ent *ents[4];
};
extern "C" void FUN_002034e0(Obj *o, Ent *sel)
{
    void *m = DAT_003e19f0->p;
    for (int i = 0; i < 4; i++) {
        if (sel == 0 || sel == o->ents[i]) {
            Ent *e = o->ents[i];
            int v = e ? e->f58 : 0;
            if (v != 0 && m != 0) {
                FUN_001c3418(m, i, 0x82);
            }
        }
    }
}

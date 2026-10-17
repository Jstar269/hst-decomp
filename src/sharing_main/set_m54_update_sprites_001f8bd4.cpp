/* HSTMATCH module=hstp_trans_main.prx start=0x001f8bd4 end=0x001f8ca4 symbol=FUN_001f8bd4 lang=c++ */
/* Clone of src/eboot/set_m54_update_sprites_001ea930.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed Holder/Panel/Sprite structs, unsigned loop over the 8 sprite pointers, `changed` bool materialised before the store (matching idiom: bool computed before the store, it gives retail's xor/sltu/beqz with the store in the slot); exact match verified; names and types await human review. */
struct Sprite {
    char pad[0x60];
    float f60;
    float f64;
};

struct Rules {
    char pad[0x45];
    unsigned char doubles;
};

struct Panel {
    char pad[0x54];
    int m54;
    int m58;
    Sprite *w[8];
};

struct Holder {
    Panel *p;
};

extern Rules *DAT_003e1e84;
extern "C" void FUN_00108558(Sprite *);
extern "C" void FUN_00108dac(Panel *);

extern "C" void FUN_001f8bd4(Holder *h, int v) {
    bool changed = h->p->m54 != v;
    h->p->m54 = v;
    if (changed) {
        Panel *p = h->p;
        for (unsigned i = 0; i < 8; i++) {
            p->w[i]->f60 = (float)p->m54;
            p->w[i]->f64 = (float)p->m58;
            if (i == 2 && (DAT_003e1e84->doubles != 0) ^ 1)
                p->w[i]->f64 = p->w[i]->f64 - 14.0f;
            FUN_00108558(p->w[i]);
        }
        FUN_00108dac(p);
    }
}

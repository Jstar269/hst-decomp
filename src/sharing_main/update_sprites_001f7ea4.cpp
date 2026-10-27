/* HSTMATCH module=hstp_trans_main.prx start=0x001f7ea4 end=0x001f7f5c symbol=FUN_001f7ea4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets the panel's 8 sprites to (m54, m58), 14 less in sprite 2's f64 when DAT_003e1e84->doubles is clear, then
   refreshes the panel: the loop of set_m54_update_sprites_001f8bd4.cpp (same file) without the setter. Names provisional. */
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

extern Rules *DAT_003e1e84;
extern "C" void FUN_00108558(Sprite *);
extern "C" void FUN_00108dac(Panel *);

extern "C" void FUN_001f7ea4(Panel *p) {
    for (unsigned i = 0; i < 8; i++) {
        p->w[i]->f60 = (float)p->m54;
        p->w[i]->f64 = (float)p->m58;
        if (i == 2 && (DAT_003e1e84->doubles != 0) ^ 1)
            p->w[i]->f64 = p->w[i]->f64 - 14.0f;
        FUN_00108558(p->w[i]);
    }
    FUN_00108dac(p);
}

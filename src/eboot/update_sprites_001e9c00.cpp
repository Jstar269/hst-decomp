/* HSTMATCH module=EBOOT.BIN start=0x001e9c00 end=0x001e9cb8 symbol=FUN_001e9c00 lang=c++ */
/* Clone of src/sharing_main/update_sprites_001f7ea4.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets the panel's 8 sprites to (m54, m58), 14 less in sprite 2's f64 when DAT_00338b44->doubles is clear, then
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

extern Rules *DAT_00338b44;
extern "C" void FUN_00102c54(Sprite *);
extern "C" void FUN_00103480(Panel *);

extern "C" void FUN_001e9c00(Panel *p) {
    for (unsigned i = 0; i < 8; i++) {
        p->w[i]->f60 = (float)p->m54;
        p->w[i]->f64 = (float)p->m58;
        if (i == 2 && (DAT_00338b44->doubles != 0) ^ 1)
            p->w[i]->f64 = p->w[i]->f64 - 14.0f;
        FUN_00102c54(p->w[i]);
    }
    FUN_00103480(p);
}

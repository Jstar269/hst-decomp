/* HSTMATCH module=hstp_trans_main.prx start=0x001f3544 end=0x001f3688 symbol=FUN_001f3544 lang=c99 */
/* Clone of src/eboot/set_three_quads_001e532c.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Bytes4 {
    unsigned char b0, pad1, b1, pad3, b2, pad5, b3, pad7;
} Bytes4;

typedef struct Panel {
    char pad0[0x20];
    int f20;
    char pad24[0x70 - 0x24];
    Bytes4 col;
    char pad78[0x8c - 0x78];
} Panel;

typedef struct Self {
    char pad0[0x438];
    unsigned char dirty;
    char pad439[0x4c8 - 0x439];
    Panel panels[3];
} Self;

extern char DAT_003940a4[];
extern int FUN_00066a84(int, char *, int);
extern int FUN_001fc5ec(void);
extern void FUN_002268dc(Panel *, unsigned int, int, int);

static inline void Refresh(Panel *p)
{
    int f = p->f20;
    unsigned int c = (p->col.b3 << 24) | (p->col.b2 << 16) | (p->col.b1 << 8) | p->col.b0;
    FUN_002268dc(p, c, f, FUN_00066a84(FUN_001fc5ec(), DAT_003940a4, 1));
}

void FUN_001f3544(Self *self)
{
    if (self->dirty != 0) {
        Refresh(&self->panels[0]);
        Refresh(&self->panels[1]);
        Refresh(&self->panels[2]);
        self->dirty = 0;
    }
}

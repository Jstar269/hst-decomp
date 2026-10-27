/* HSTMATCH module=EBOOT.BIN start=0x001e532c end=0x001e5470 symbol=FUN_001e532c lang=c99 */
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

extern char DAT_002ec18c[];
extern int FUN_00065740(int, char *, int);
extern int FUN_001ee224(void);
extern void FUN_00217834(Panel *, unsigned int, int, int);

static inline void Refresh(Panel *p)
{
    int f = p->f20;
    unsigned int c = (p->col.b3 << 24) | (p->col.b2 << 16) | (p->col.b1 << 8) | p->col.b0;
    FUN_00217834(p, c, f, FUN_00065740(FUN_001ee224(), DAT_002ec18c, 1));
}

void FUN_001e532c(Self *self)
{
    if (self->dirty != 0) {
        Refresh(&self->panels[0]);
        Refresh(&self->panels[1]);
        Refresh(&self->panels[2]);
        self->dirty = 0;
    }
}

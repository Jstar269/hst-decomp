/* HSTMATCH module=EBOOT.BIN start=0x00127004 end=0x0012704c symbol=FUN_00127004 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub8c {
    char pad[8];
    int f8;
};

struct Sub58 {
    char pad[0x8c];
    Sub8c *p8c;
};

struct Self {
    char pad[0x58];
    Sub58 *p58;
    char pad2[0x350 - 0x5c];
    int f350;
};

extern "C" {
extern char DAT_002da80c[];
extern int FUN_0002fe80(int, char *);
}

extern "C" void FUN_00127004(Self *self)
{
    int h = self->p58->p8c->f8;
    self->f350 = h != 0 ? FUN_0002fe80(h, DAT_002da80c) : -1;
}

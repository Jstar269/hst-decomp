/* HSTMATCH module=hstp_trans_main.prx start=0x00132274 end=0x001322bc symbol=FUN_00132274 lang=c++ data=0x0038188c */
/* Clone of src/eboot/lookup_or_default_00127004.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0038188c-0x00381898) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern int FUN_0002fea8(int, char *);
}

extern "C" void FUN_00132274(Self *self)
{
    int h = self->p58->p8c->f8;
    self->f350 = h != 0 ? FUN_0002fea8(h, "Bip01Pelvis") : -1;
}

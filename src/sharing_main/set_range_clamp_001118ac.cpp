/* HSTMATCH module=hstp_trans_main.prx start=0x001118ac end=0x00111908 symbol=FUN_001118ac lang=c++ */
/* Clone of src/eboot/set_range_clamp_0010b6d4.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self_001118ac {
    char pad0[0xd0];
    int fd0;
    char padd4[8];
    int fdc;
    int fe0;
    int fe4;
    char padE8[0x124 - 0xe8];
    unsigned f124;
};
extern "C" int DAT_0037ffe8;
inline int Max_001118ac(const int &a, const int &b) { return a < b ? b : a; }
inline unsigned Min_001118ac(const unsigned &a, const unsigned &b) { return a < b ? a : b; }
extern "C" void FUN_001118ac(Self_001118ac *p, int x, unsigned y)
{
    if (p->f124 == 0) {
        p->fe4 = 0;
        p->fe0 = 0;
    } else {
        p->fe0 = Max_001118ac(x, DAT_0037ffe8);
        p->fe4 = Min_001118ac(p->f124 - 1, y);
    }
    p->fdc = 0;
    p->fd0 = 3;
}

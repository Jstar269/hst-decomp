/* HSTMATCH module=EBOOT.BIN start=0x0010b6d4 end=0x0010b730 symbol=FUN_0010b6d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self_0010b6d4 {
    char pad0[0xd0];
    int fd0;
    char padd4[8];
    int fdc;
    int fe0;
    int fe4;
    char padE8[0x124 - 0xe8];
    unsigned f124;
};
extern "C" int DAT_002d9214;
inline int Max_0010b6d4(const int &a, const int &b) { return a < b ? b : a; }
inline unsigned Min_0010b6d4(const unsigned &a, const unsigned &b) { return a < b ? a : b; }
extern "C" void FUN_0010b6d4(Self_0010b6d4 *p, int x, unsigned y)
{
    if (p->f124 == 0) {
        p->fe4 = 0;
        p->fe0 = 0;
    } else {
        p->fe0 = Max_0010b6d4(x, DAT_002d9214);
        p->fe4 = Min_0010b6d4(p->f124 - 1, y);
    }
    p->fdc = 0;
    p->fd0 = 3;
}

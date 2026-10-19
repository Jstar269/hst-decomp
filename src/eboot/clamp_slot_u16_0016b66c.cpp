/* HSTMATCH module=EBOOT.BIN start=0x0016b66c end=0x0016b6c8 symbol=FUN_0016b66c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Blk { unsigned char pad[0x410]; short v; };
extern Blk DAT_00341ccc;
extern int DAT_002e04c0;
extern int DAT_002e04c4;

static inline int Clamp(unsigned short v, const int &lo, const int &hi)
{
    if (v < lo) return lo;
    return hi < v ? hi : v;
}

extern "C" void FUN_0016b66c(unsigned short v)
{
    Blk &b = DAT_00341ccc;
    b.v = (short)Clamp(v, DAT_002e04c0, DAT_002e04c4);
}

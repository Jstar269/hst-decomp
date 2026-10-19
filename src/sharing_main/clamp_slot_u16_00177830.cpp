/* HSTMATCH module=hstp_trans_main.prx start=0x00177830 end=0x0017788c symbol=FUN_00177830 lang=c++ */
/* Clone of src/eboot/clamp_slot_u16_0016b66c.cpp (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Blk { unsigned char pad[0x410]; short v; };
extern Blk DAT_003eb004;
extern int DAT_00387a7c;
extern int DAT_00387a80;

static inline int Clamp(unsigned short v, const int &lo, const int &hi)
{
    if (v < lo) return lo;
    return hi < v ? hi : v;
}

extern "C" void FUN_00177830(unsigned short v)
{
    Blk &b = DAT_003eb004;
    b.v = (short)Clamp(v, DAT_00387a7c, DAT_00387a80);
}

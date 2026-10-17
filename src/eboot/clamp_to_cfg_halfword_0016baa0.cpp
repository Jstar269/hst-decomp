/* HSTMATCH module=EBOOT.BIN start=0x0016baa0 end=0x0016bb00 symbol=FUN_0016baa0 lang=c++ */
/* Clone of src/sharing_main/clamp_to_cfg_halfword_00177c64.cpp (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cfg { char pad[0x40]; short f40; };
extern "C" {
extern int DAT_002e04b8;
extern int DAT_002e04bc;
extern Cfg DAT_00341ccc;
extern unsigned char DAT_00341d0e;
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_0016baa0(short v, unsigned char b)
{
  Cfg *c = &DAT_00341ccc;
  c->f40 = Clamp(v, DAT_002e04b8, DAT_002e04bc);
  DAT_00341d0e = b;
}

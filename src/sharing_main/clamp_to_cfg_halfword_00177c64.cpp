/* HSTMATCH module=hstp_trans_main.prx start=0x00177c64 end=0x00177cc4 symbol=FUN_00177c64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: the halfword goes through a pointer local (`Cfg *c = &DAT_003eb004`), the byte at +0x42 is a separate global store (retail: sh via a2, sb via a fresh lui v1). Clamp by const reference as in clamp_to_cfg_byte_00177cc4.cpp.
struct Cfg { char pad[0x40]; short f40; };
extern "C" {
extern int DAT_00387a74;
extern int DAT_00387a78;
extern Cfg DAT_003eb004;
extern unsigned char DAT_003eb046;
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00177c64(short v, unsigned char b)
{
  Cfg *c = &DAT_003eb004;
  c->f40 = Clamp(v, DAT_00387a74, DAT_00387a78);
  DAT_003eb046 = b;
}

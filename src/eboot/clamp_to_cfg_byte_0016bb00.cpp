/* HSTMATCH module=EBOOT.BIN start=0x0016bb00 end=0x0016bb5c symbol=FUN_0016bb00 lang=c++ */
/* Clone of src/sharing_main/clamp_to_cfg_byte_00177cc4.cpp (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Cfg { char pad[0x43]; unsigned char f43; };
extern "C" {
extern int DAT_002e04b0;
extern int DAT_002e04b4;
extern Cfg DAT_00341ccc;
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_0016bb00(unsigned char p)
{
  Cfg *c = &DAT_00341ccc;
  c->f43 = Clamp(p, DAT_002e04b0, DAT_002e04b4);
}

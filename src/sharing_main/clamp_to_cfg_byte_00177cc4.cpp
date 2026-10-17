/* HSTMATCH module=hstp_trans_main.prx start=0x00177cc4 end=0x00177d20 symbol=FUN_00177cc4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: the destination is reached through a pointer local (`Cfg *c = &DAT_003eb004; c->f43 = Clamp(...)`); writing the global directly shares one lui/sb instead of retail's early `lui a1`/`addiu a1` base and two `sb a2,67(a1)` copies. The clamp takes lo/hi by const reference (retail reloads the globals).
struct Cfg { char pad[0x43]; unsigned char f43; };
extern "C" {
extern int DAT_00387a6c;
extern int DAT_00387a70;
extern Cfg DAT_003eb004;
}
inline int Clamp(int v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}
extern "C" void FUN_00177cc4(unsigned char p)
{
  Cfg *c = &DAT_003eb004;
  c->f43 = Clamp(p, DAT_00387a6c, DAT_00387a70);
}

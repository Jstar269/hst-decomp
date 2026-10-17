/* HSTMATCH module=hstp_trans_main.prx start=0x001dbdc4 end=0x001dbed4 symbol=FUN_001dbdc4 lang=c++ */
/* Clone of src/eboot/clamped_halfword_store_001cd6e8.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC_001dbdc4 {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
  virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
  virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
  virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
  virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
  virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
  virtual void s24(); virtual void s25(); virtual void s26();
};
struct Sub_001dbdc4 { char pad[0xf4]; unsigned f_f4; };
struct Obj_001dbdc4 { char pad[0x15c]; Sub_001dbdc4 *f15c; };
struct Game_001dbdc4 { char pad[0x10b4]; short f10b4; };

extern "C" {
extern unsigned DAT_00392a9c;
extern unsigned DAT_00392aa0;
extern Game_001dbdc4 *DAT_003ea8e8;
extern VC_001dbdc4 *DAT_003f3450;
extern char DAT_003eaad8;
void FUN_001c28a4(char *, float);
void FUN_001c04c4(char *);
void FUN_002985fc(char *, int, int, int, int, int, int, int);
void FUN_00132a58(VC_001dbdc4 *);
void FUN_001354c4(VC_001dbdc4 *, int, int, int);
void FUN_001c26e0(char *);
}

inline unsigned Clamp_001dbdc4(unsigned v, const unsigned &lo, const unsigned &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001dbdc4(Obj_001dbdc4 *o)
{
  FUN_001c28a4(&DAT_003eaad8, 0.1f);
  FUN_001c04c4(&DAT_003eaad8);
  DAT_003ea8e8->f10b4 = Clamp_001dbdc4(o->f15c->f_f4, DAT_00392a9c, DAT_00392aa0);
  FUN_002985fc((char *)DAT_003f3450 + 0xe0, 0, 0, 0, 0, 0, 0, 0);
  FUN_00132a58(DAT_003f3450);
  FUN_001354c4(DAT_003f3450, 0, -1, 1);
  DAT_003f3450->s26();
  FUN_001c26e0(&DAT_003eaad8);
}

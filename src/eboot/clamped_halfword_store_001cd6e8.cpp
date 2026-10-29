/* HSTMATCH module=EBOOT.BIN start=0x001cd6e8 end=0x001cd7f8 symbol=FUN_001cd6e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/flow_state.h"

/* Host object (global DAT_0034a118): a table of virtual slots; only the last one is called here. */
struct Host {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
  virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
  virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
  virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
  virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
  virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
  virtual void s24(); virtual void s25(); virtual void s26();
};
/* Game settings object; only one halfword is written. */
struct Settings { char pad[0x10b4]; short unk10b4; };

extern "C" {
extern unsigned DAT_002eac88; /* lower bound of the stored value */
extern unsigned DAT_002eac8c; /* upper bound of the stored value */
extern Settings *DAT_003415a8;
extern Host *DAT_0034a118;
extern char DAT_0034179c;
void FUN_001b4848(char *, float);
void FUN_001b2430(char *);
void FUN_00286f00(char *, int, int, int, int, int, int, int);
void FUN_001277e8(Host *);
void FUN_0012a254(Host *, int, int, int);
void FUN_001b46bc(char *);
}

inline unsigned Clamp(unsigned v, const unsigned &lo, const unsigned &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

/* Store the state's clamped value into the settings and reset the host. */
extern "C" void FUN_001cd6e8(FlowOwner *self)
{
  FUN_001b4848(&DAT_0034179c, 0.1f);
  FUN_001b2430(&DAT_0034179c);
  DAT_003415a8->unk10b4 = Clamp(self->state->unkf4, DAT_002eac88, DAT_002eac8c);
  FUN_00286f00((char *)DAT_0034a118 + 0xe0, 0, 0, 0, 0, 0, 0, 0);
  FUN_001277e8(DAT_0034a118);
  FUN_0012a254(DAT_0034a118, 0, -1, 1);
  DAT_0034a118->s26();
  FUN_001b46bc(&DAT_0034179c);
}

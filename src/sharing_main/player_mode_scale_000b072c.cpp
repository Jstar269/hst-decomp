/* HSTMATCH module=hstp_trans_main.prx start=0x000b072c end=0x000b07f0 symbol=FUN_000b072c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Player.cpp (debug build, real ASSERT): scales x - f580*f5a0 by a mode-dependent percentage global. The
   switch lists its labels 0,1 / 2 / 3,4 / default so MWCC tests 4,3,2,1,0 with the bodies in source order. */
struct Player {
  char pad0[0x580];
  float f580;
  char pad584[0x5a0 - 0x584];
  float f5a0;
};

extern "C" {
extern float DAT_003ea518;
extern float DAT_003ea51c;
extern const char DAT_0037a6cc[];   /* assertion message format */
extern const char DAT_0037a704[];   /* "Player.cpp" */
extern const char DAT_0037a8b8[];   /* "false" */
void FUN_00097e3c(...);
}

#define HST_ASSERT(cond, text, line) \
  do { if (!(cond)) { FUN_00097e3c(DAT_0037a6cc, text, DAT_0037a704, line); for (;;) {} } } while (0)

extern "C" float FUN_000b072c(float x, Player *p, int mode)
{
  float base = p->f580 * p->f5a0;
  float d = x - base;
  switch (mode) {
  case 0:
  case 1:
    break;
  case 2:
    d *= DAT_003ea518 * 0.01f;
    break;
  case 3:
  case 4:
    d *= DAT_003ea51c * 0.01f;
    break;
  default:
    HST_ASSERT(false, DAT_0037a8b8, 10203);
  }
  return base + d;
}

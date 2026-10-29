/* HSTMATCH module=EBOOT.BIN start=0x0012c1c4 end=0x0012c2dc symbol=FUN_0012c1c4 lang=c++ */
struct Cfg {
  char pad00[0x8b];
  signed char b0 : 2;
  signed char b2 : 2;
  signed char b4 : 2;
  signed char b6 : 2;
};

extern Cfg *DAT_002cfc8c;
extern int DAT_0033b574;
extern int DAT_0033b4a4;
extern "C" int FUN_0012d76c(void);
extern "C" void FUN_00126d1c(char *msg);
extern char DAT_002da9f4[];

extern "C" int FUN_0012c1c4(int state)
{
  int r;

  switch (state) {
  case 0:
    r = 0;
    break;
  case 1:
    r = DAT_002cfc8c->b4 != 1;
    break;
  case 2:
    r = 0;
    break;
  case 3:
    if (DAT_0033b574 != 0 && FUN_0012d76c() != 0) {
      r = 0;
      break;
    }
    if (DAT_002cfc8c->b4 != 0) {
      r = 0;
      break;
    }
    r = DAT_0033b4a4 != 0;
    break;
  case 4:
    r = !DAT_002cfc8c->b2;
    break;
  default:
    FUN_00126d1c(DAT_002da9f4);
    r = 0;
    break;
  }
  return r;
}
// NEAR (sy2): 60/70 words, 61 differ. Decoded: DAT_002cfc8c is a POINTER to a config struct whose byte +0x8b holds signed 2-bit
// bitfields (b2 = bits 3:2 -> `sll 0x1c; sra 0x1e`, b4 = bits 5:4 -> `sll 0x1a; sra 0x1e`; the real struct bitfields compile to retail's
// lb/sll/sra); cases written ASCENDING (0..4) give retail's descending 4,3,2,1,0 compare chain. The default string is DAT_002da9f4 (the old
// wip said ...f3: low half -22028 sign-extends to 0x2da9f4). What is missing: retail keeps the bodies of cases 0 and 2 as two DEAD
// `move v0,zero; b end; nop` blocks (the chain jumps over them with `move v0,zero` in a beql/beqzl slot) and uses plain `beq a0,v0,L; nop`
// for cases 3 and 1 and the first compare; ours threads everything into likely branches and drops the dead blocks (59-62 words vs 70).
// Tried: return form, `r = ...; break` form, fall-out-of-switch default, plain descending if chain (62 words).
// near miss from lane sy2 (unreviewed)

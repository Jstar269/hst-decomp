/* HSTMATCH module=EBOOT.BIN start=0x0016b90c end=0x0016b998 symbol=FUN_0016b90c lang=c++ */
/* Hand-written reconstruction from the disassembly (from the ds4 near miss, now with an inline Clamp(const&) and a hoisted base local); exact match verified; names and types await human review. */
struct Rec {
  unsigned char pad00[1];
  unsigned char level;        /* 0x01 */
  unsigned char pad02[54];
};

extern int DAT_002e04a0;
extern int DAT_002e04a4;
extern char DAT_00341ccc[];

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0016b90c(unsigned short idx, unsigned short val)
{
  char *base = DAT_00341ccc;
  unsigned short level = Clamp(val, DAT_002e04a0, DAT_002e04a4);
  Rec *e;
  if (idx >= 0 && idx < 15) {
    e = (Rec *)(base + idx * 56 + 200);
  } else {
    e = 0;
  }
  e->level = level;
}

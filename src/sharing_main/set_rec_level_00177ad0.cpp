/* HSTMATCH module=hstp_trans_main.prx start=0x00177ad0 end=0x00177b5c symbol=FUN_00177ad0 lang=c++ */
/* Clone of src/eboot/set_rec_level_0016b90c.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (from the ds4 near miss, now with an inline Clamp(const&) and a hoisted base local); exact match verified; names and types await human review. */
struct Rec {
  unsigned char pad00[1];
  unsigned char level;        /* 0x01 */
  unsigned char pad02[54];
};

extern int DAT_00387a5c;
extern int DAT_00387a60;
extern char DAT_003eb004[];

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_00177ad0(unsigned short idx, unsigned short val)
{
  char *base = DAT_003eb004;
  unsigned short level = Clamp(val, DAT_00387a5c, DAT_00387a60);
  Rec *e;
  if (idx >= 0 && idx < 15) {
    e = (Rec *)(base + idx * 56 + 200);
  } else {
    e = 0;
  }
  e->level = level;
}

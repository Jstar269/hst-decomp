/* HSTMATCH module=EBOOT.BIN start=0x0016b7d0 end=0x0016b85c symbol=FUN_0016b7d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: Clamp(const int&,..) returning by value (doubled limit loads) and the table pointer taken into a local before the clamp (hoists its lui/addiu); names and types await human review. */
struct Item {
  unsigned short a;
  unsigned short v;
  char pad[52];
};
struct Tbl { char pad[200]; Item items[15];
  Item *Get(int i) { if (i >= 0 && i < 15) return &items[i]; return 0; } };
extern Tbl DAT_00341ccc;
extern int DAT_002e04a8;
extern int DAT_002e04ac;

inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}


extern "C" void FUN_0016b7d0(unsigned short idx, unsigned short val)
{
  Tbl *t = &DAT_00341ccc;
  unsigned short r = Clamp(val, DAT_002e04a8, DAT_002e04ac);
  t->Get(idx)->v = r;
}

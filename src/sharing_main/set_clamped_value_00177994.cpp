/* HSTMATCH module=hstp_trans_main.prx start=0x00177994 end=0x00177a20 symbol=FUN_00177994 lang=c++ */
/* Clone of src/eboot/set_clamped_value_0016b7d0.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: Clamp(const int&,..) returning by value (doubled limit loads) and the table pointer taken into a local before the clamp (hoists its lui/addiu); names and types await human review. */
struct Item {
  unsigned short a;
  unsigned short v;
  char pad[52];
};
struct Tbl { char pad[200]; Item items[15];
  Item *Get(int i) { if (i >= 0 && i < 15) return &items[i]; return 0; } };
extern Tbl DAT_003eb004;
extern int DAT_00387a64;
extern int DAT_00387a68;

inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}


extern "C" void FUN_00177994(unsigned short idx, unsigned short val)
{
  Tbl *t = &DAT_003eb004;
  unsigned short r = Clamp(val, DAT_00387a64, DAT_00387a68);
  t->Get(idx)->v = r;
}

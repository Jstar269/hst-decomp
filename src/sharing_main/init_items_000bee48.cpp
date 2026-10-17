/* HSTMATCH module=hstp_trans_main.prx start=0x000bee48 end=0x000bf018 symbol=FUN_000bee48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clears 16 seven-byte records (a six-char name copied from a global, then a terminating zero) and a parallel
   int array. The name type has a user constructor, so its assignment is the memberwise count-down byte-pair
   copy loop; the 16-iteration loop is unrolled eight times by the compiler. Names provisional. */
struct Name6 {
  char c[6];
  Name6() {}
};
struct Item {
  Name6 name;
  char term;
};
struct Obj {
  char pad[0x58];
  Item items[16];
  int vals[16];
};
extern Name6 DAT_003e1dfc;

extern "C" void FUN_000bee48(Obj *o)
{
  for (int i = 0; i < 16; i++) {
    o->items[i].name = DAT_003e1dfc;
    o->items[i].term = 0;
    o->vals[i] = 0;
  }
}

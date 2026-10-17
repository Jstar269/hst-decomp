/* HSTMATCH module=hstp_trans_main.prx start=0x000dbb60 end=0x000dbba8 symbol=FUN_000dbb60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review (matching idiom: do-while loops with an unsigned counter, which keep the constant-trip loops rolled). */
/* Copies six halfwords from +0 to +0xbc, sets the word at +0xb8 to -1 and clears the five words at +0xa4..+0xb4. */
struct Obj {
  short cur[6];
  char pad0[0xa4 - 12];
  int counts[5];
  int sel;
  short saved[6];
};

extern "C" void FUN_000dbb60(Obj *o)
{
  unsigned i = 0;
  do {
    o->saved[i] = o->cur[i];
  } while (++i < 6);
  o->sel = -1;
  unsigned j = 0;
  do {
    o->counts[j] = 0;
  } while (++j < 5);
}

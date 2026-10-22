/* HSTMATCH module=hstp_trans_main.prx start=0x0029b4fc end=0x0029b620 symbol=FUN_0029b4fc lang=c++ */
/* Clone of src/eboot/fill_counter_lists_00289d60.cpp (hstclone.py tag km2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Fills the counter at +4 up to 1000 (FUN_0029e0a0), clamps it to 1000 when it is larger, and then
   collects two lists into the array at +0: FUN_0029b720 is called with the index 1..899 (ascending,
   with the third argument taken from the fourth parameter) and then with the index 999..901
   (descending, with the third argument 99 and the second argument taken from the second parameter).
   The value of FUN_0001342c is stored in the global at 0x3f3b24.
   Matching idioms: the counter is UNSIGNED, the index arithmetic is strength reduced off
   (#pragma opt_strength_reduction off), the fourth argument of FUN_0029e0a0 is an empty tag struct
   passed by value (the caller materialises it as `move v0,zero; seb a3,v0`), and the index is set to 1
   AFTER the if/else chain (inside both arms the compiler turns the inner test into a branch likely
   with the join copied into its delay slot). */
struct Tag {};
#pragma opt_strength_reduction off

struct Obj {
  int *items;
  unsigned int count;
};

extern "C" void FUN_0029b620(Obj *self);
extern "C" void FUN_0029e0a0(Obj *self, int count, int *out, Tag tag);
extern "C" int FUN_0029b720(Obj *self, int *p2, int p3, int p4);
extern "C" int FUN_0001342c();
extern int DAT_003f3b24;

extern "C" void FUN_0029b4fc(Obj *self, int *p2, int *p3, int p4)
{
  unsigned int v1;
  int idx;
  int v;

  FUN_0029b620(self);
  int local_4 = 0;
  v1 = self->count;
  if (v1 < 1000) {
    FUN_0029e0a0(self, 1000 - v1, &local_4, Tag());
  } else if (v1 > 1000) {
    self->count -= v1 - 1000;
  }
  idx = 1;
  do {
    v = FUN_0029b720(self, p3, p4, idx);
    if (v == 0) {
      idx = 999;
      break;
    }
    self->items[idx] = v;
    idx++;
  } while (idx < 900);
  idx = 999;
  do {
    v = FUN_0029b720(self, p2, 99, idx);
    if (v == 0) {
      break;
    }
    self->items[idx] = v;
    idx--;
  } while (idx >= 901);
  DAT_003f3b24 = FUN_0001342c();
}

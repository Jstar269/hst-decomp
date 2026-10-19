/* HSTMATCH module=EBOOT.BIN start=0x00106718 end=0x001067c0 symbol=FUN_00106718 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: structured SubItem and Obj types, early return on non-zero param_2, #pragma opt_strength_reduction off; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

extern "C" void FUN_00101c18(void *, int);

struct VC_0 {
  virtual void d0();
  virtual void m(int);
};

struct SubItem {
  char pad_00[14];
  unsigned short flags;
  char pad_10[16];
  VC_0 *target;
};

struct Obj {
  char pad_00[16];
  SubItem **items;
  int count;
};

extern "C" void FUN_00106718(Obj *param_1, int param_2)
{
  if (param_2 != 0) {
    FUN_00101c18(param_1, 1);
    return;
  }

  for (int i = 0; i < param_1->count; ++i) {
    SubItem *item = param_1->items[i];
    if (i != 0) {
      item->flags |= 1;
    } else {
      item->flags &= 0xfffe;
    }
    if (item->target != 0) {
      item->target->m(i != 0);
    }
  }
}

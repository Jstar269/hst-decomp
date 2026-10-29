/* HSTMATCH module=EBOOT.BIN start=0x0021abe0 end=0x0021acb4 symbol=FUN_0021abe0 lang=c++ rodata=0x002c9908 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the slot-3 call is a C++ virtual method (dispatch at vtable +0x0c, so the class declares two virtuals) and the switch lists all 19 states, which is what makes MWCC emit retail's jump table; readability pass; exact match verified; names and types await human review. */
#include "hst/selection_menu.h"

/* Record reached from the global at DAT_003415ac; the word its pointer at 0x58 leads to is passed to FUN_0010b8cc. */
struct Hud {
  char pad00[0x58];
  int *unk58;   /* 0x58 */
};

extern "C" Hud *DAT_003415ac;
extern "C" void FUN_0010b8cc(int a, int b, int c);
extern "C" void FUN_00114168(void *a, int b, void *c, int d, int e);
extern "C" void *FUN_001fea10(int a, int b, int c);

/* Virtual interface of the selection menu. */
struct MenuVirtuals {
  virtual void Release();
  virtual void Activate();
};

/* Stores the new state; state 0 activates the menu, and the states that pick a text id (0 or 1) trigger FUN_00114168. */
extern "C" void FUN_0021abe0(SelectionState *self, int state)
{
  int text_id = -1;

  self->state = state;
  switch (state) {
  case 0:
    ((MenuVirtuals *)self->menu)->Activate();
    break;
  case 1: case 2: case 3: case 4: case 5:
    break;
  case 7: case 13: text_id = 0; break;
  case 8: case 9: case 10: case 11: case 12:
    break;
  case 14: case 15: case 16: case 17:
    break;
  case 18: text_id = 1; break;
  case 6: text_id = 1; break;
  }
  if (text_id < 0)
    return;
  FUN_00114168(DAT_003415ac, 1, FUN_001fea10(17, 8, text_id), 0, 0);
  if (text_id == 1)
    FUN_0010b8cc(*DAT_003415ac->unk58, 0, 0);
}

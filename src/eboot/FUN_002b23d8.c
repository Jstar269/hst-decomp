/* HSTMATCH module=EBOOT.BIN start=0x002b23d8 end=0x002b2628 symbol=FUN_002b23d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_00302e9c[];
extern char DAT_00302fd0[];
extern char DAT_00302fe4[];
extern char DAT_00302ff0[];
extern char DAT_00303000[];
extern char DAT_00303010[];
extern char DAT_0030301c[];
extern char DAT_00303028[];
extern char DAT_0030303c[];
extern void FUN_000143b0();
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern int FUN_001039d8();

/* Looks up nine named child widgets of the pane `pane_id` (name built from a format and `index`) and shows each. */
void FUN_002b23d8(int self,u32 pane_id,u32 index)
{
  u32 widget;
  u8 name [64];
  
  FUN_000143b0(name,DAT_00302fd0);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00302fe4,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00302ff0,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00303000,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00303010,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_0030301c,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00303028,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_0030303c,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
  FUN_000143b0(name,DAT_00302e9c,index);
  widget = FUN_001039d8(self + 0x3c,pane_id,0);
  widget = FUN_001026b8(widget,name);
  FUN_000ffb3c(widget,1);
}

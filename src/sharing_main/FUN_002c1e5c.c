/* HSTMATCH module=hstp_trans_main.prx start=0x002c1e5c end=0x002c20ac symbol=FUN_002c1e5c lang=c99 */
/* Clone of src/eboot/FUN_002b23d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003ac0a4[];
extern char DAT_003ac21c[];
extern char DAT_003ac230[];
extern char DAT_003ac23c[];
extern char DAT_003ac24c[];
extern char DAT_003ac25c[];
extern char DAT_003ac268[];
extern char DAT_003ac274[];
extern char DAT_003ac288[];
extern void FUN_000143b0();
extern void FUN_00105470();
extern int FUN_00108124();
extern int FUN_00109304();

/* Looks up nine named child widgets of the pane `pane_id` (name built from a format and `index`) and shows each. */
void FUN_002c1e5c(int self,u32 pane_id,u32 index)
{
  u32 widget;
  u8 name [64];
  
  FUN_000143b0(name,DAT_003ac21c);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac230,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac23c,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac24c,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac25c,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac268,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac274,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac288,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
  FUN_000143b0(name,DAT_003ac0a4,index);
  widget = FUN_00109304(self + 0x3c,pane_id,0);
  widget = FUN_00108124(widget,name);
  FUN_00105470(widget,1);
}

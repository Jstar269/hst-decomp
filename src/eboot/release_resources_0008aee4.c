/* HSTMATCH module=EBOOT.BIN start=0x0008aee4 end=0x0008af7c symbol=FUN_0008aee4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the two tail calls take the tested member as their argument (Ghidra dropped it); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/play_flow.h"

extern u32 DAT_003313c4;
extern u32 DAT_003386cc;
extern u32 DAT_00338714;
extern u8 * DAT_003402a0;
extern int FUN_0005ba78();
extern void FUN_000c7894(int);
extern void FUN_00140acc();
extern void FUN_001f4c04(PlayFlowSub *);

/* Release the global resources, then the two members this object holds. */
void FUN_0008aee4(PlayFlowObj *self)
{
  int handle;
  PlayFlowSub *sub;

  if (DAT_00338714 != 0) {
    FUN_0005ba78(DAT_00338714,DAT_003313c4);
  }
  if (DAT_003386cc != 0) {
    FUN_0005ba78(DAT_003386cc,DAT_003313c4);
  }
  if (DAT_003402a0 != 0) {
    FUN_00140acc(DAT_003402a0 + 0x40);
  }
  handle = self->unk90;
  if (handle != 0) {
    FUN_000c7894(handle);
  }
  sub = self->sub;
  if (sub != 0) {
    FUN_001f4c04(sub);
  }
}

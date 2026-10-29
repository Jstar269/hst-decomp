/* HSTMATCH module=EBOOT.BIN start=0x0012b568 end=0x0012b678 symbol=FUN_0012b568 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored signed arithmetic and typed helper/global values; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern int DAT_0033b4b0;
extern int DAT_0033b4b4;
extern int FUN_0012b72c(Avatar *,int,int);

#define SELECT_NONE 0xffffffff /* no entry matches */

/* Maps the avatar's current animation to a selector code, or SELECT_NONE. */
u32 FUN_0012b568(Avatar *self)
{
  int row;
  u32 rel;
  int animId;
  int col;
  u32 result;
  
  row = FUN_0012b72c(self,self->unk35c,0);
  animId = self->unk334;
  col = self->unk354;
  result = SELECT_NONE;
  if (animId >= 0 && animId <= DAT_0033b4b4) {
    rel = animId - DAT_0033b4b0;
    row = (int)rel / 2;
    col = (int)rel % 2;
  }
  if ((row == 0) && (col == 0)) {
    result = 7;
  }
  else if ((row == 0) && (col == 1)) {
    result = 4;
  }
  else if ((row == 3) && (col == 1)) {
    result = 10;
  }
  else if ((row == 4) && (col == 0)) {
    result = 4;
  }
  else if ((row == 5) && (col == 1)) {
    result = 0xd;
  }
  return result;
}

/* HSTMATCH module=EBOOT.BIN start=0x000ea868 end=0x000ea8ec symbol=FUN_000ea868 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: merged each allocation store and restored the final constructor argument; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pair_owner.h"

#define CHILD_SIZE 0x70 /* bytes allocated for each child */

extern int FUN_00000bcc();
extern u32 * FUN_0005aa44(u32 *, int, int, int, int, int);

/* Allocate and construct the two children (identical arguments) and store them in the owner. */
void FUN_000ea868(PairOwner *self)
{
  u32 *obj;
  
  obj = (u32 *)FUN_00000bcc(CHILD_SIZE);
  if (obj != (u32 *)0x0)
    obj = FUN_0005aa44(obj,1,4,1,1,0);
  self->first = obj;
  obj = (u32 *)FUN_00000bcc(CHILD_SIZE);
  if (obj != (u32 *)0x0)
    obj = FUN_0005aa44(obj,1,4,1,1,0);
  self->second = obj;
}

/* HSTMATCH module=EBOOT.BIN start=0x001cd0e4 end=0x001cd13c symbol=FUN_001cd0e4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reused the allocation result for the conditional copy and return; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

#define COPY_OBJECT_SIZE 0x100 /* size of the allocated copy */

extern int FUN_00000bcc();
extern u32 * FUN_0028a230();

/* Allocate a copy of the object at table[index]; returns 0 when the slot is empty. */
u32 FUN_001cd0e4(FlowOwner *self,int index)
{
  int source = self->table[index];
  int result;

  if (source == 0) return 0;
  result = FUN_00000bcc(COPY_OBJECT_SIZE);
  if (result != 0) result = (int)FUN_0028a230((int *)result,source);
  return (u32)result;
}

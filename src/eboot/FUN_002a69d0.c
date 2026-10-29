/* HSTMATCH module=EBOOT.BIN start=0x002a69d0 end=0x002a6a40 symbol=FUN_002a69d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj {
  char pad00[0x178];
  u32 owner;        /* 0x178 */
} Obj;

extern int DAT_00300af4[];
extern u32 DAT_0034b354;
extern void FUN_0010b8cc();
extern void FUN_00110a78();
extern u8 * FUN_001fea10();

/* Select entry `index`: pass it to the owner and, when the global handle is set, look up and assign the matching value. */
void FUN_002a69d0(Obj *self,int index)
{
  u32 value;
  
  FUN_0010b8cc(self->owner,index,0);
  if (DAT_0034b354 != 0) {
    value = (unsigned int)(FUN_001fea10(0x12,0x31,DAT_00300af4[index]));
    FUN_00110a78(DAT_0034b354,value,0);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x0013110c end=0x0013115c symbol=FUN_0013110c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001f1fc();
extern void FUN_001240fc();
extern u32 FUN_00125218();

/* Object whose member at 0x80 is configured, with the result stored at 0x88 and the constant 3 at 0x8c. */
typedef struct HolderObj {
  char pad00[0x80];
  u32 unk80;        /* 0x80 */
  char pad84[4];
  u32 unk88;        /* 0x88 */
  u32 unk8c;        /* 0x8c */
} HolderObj;

void FUN_0013110c(HolderObj *self)
{
  u32 value;
  
  FUN_0001f1fc(self->unk80,1);
  FUN_001240fc(self->unk80,0,0);
  value = FUN_00125218(self->unk80);
  self->unk88 = value;
  self->unk8c = 3;
}

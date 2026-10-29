/* HSTMATCH module=EBOOT.BIN start=0x00285f28 end=0x00285f3c symbol=FUN_00285f28 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ClearedObj {
  u32 unk00;            /* 0x00 */
  u8 unk04;             /* 0x04 */
  char pad05[0xc5 - 0x5];
  u8 unkc5;             /* 0xc5 */
} ClearedObj;

ClearedObj * FUN_00285f28(ClearedObj *self)
{
  self->unk00 = 0;
  self->unk04 = 0;
  self->unkc5 = 0;
  return self;
}

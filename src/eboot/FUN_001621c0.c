/* HSTMATCH module=EBOOT.BIN start=0x001621c0 end=0x001621e0 symbol=FUN_001621c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct OffsetObj {
  char pad0[0x16c];
  float base;       /* 0x16c */
  char pad170[0x3c4 - 0x170];
  float extra;      /* 0x3c4 added to base for modes 1 and 2 */
} OffsetObj;

float FUN_001621c0(OffsetObj *obj,int mode)
{
  float result;
  
  result = obj->base;
  if (mode - 1U < 2) {
    result = result + obj->extra;
  }
  return result;
}

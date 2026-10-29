/* HSTMATCH module=EBOOT.BIN start=0x000d7420 end=0x000d7458 symbol=FUN_000d7420 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

/* Short-string-optimised string value: bit 0 of cap set = heap storage at 0x8. */
typedef struct StringValue {
  u32 cap;   /* 0x0 */
  u32 size;  /* 0x4 */
  void *data;/* 0x8 */
} StringValue;

/* Releases the value's heap storage when it has any (the allocator argument is unused). */
void FUN_000d7420(u32 allocator,StringValue *value)
{
  if (((value != (StringValue *)0x0) && (value != (StringValue *)0x0)) && ((value->cap & 1) != 0)) {
    FUN_00000a00(value->data);
  }
}

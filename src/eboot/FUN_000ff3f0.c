/* HSTMATCH module=EBOOT.BIN start=0x000ff3f0 end=0x000ff414 symbol=FUN_000ff3f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define KEY_MIN_SIZE 0x14       /* smallest block that holds the keyed word */
#define KEY_NONE 0xffffffff     /* returned when the block is too small */
#define KEY_XOR_WORDC 0x8729382e

typedef struct KeyBlock {
  char pad0[0xc];
  u32 wordc; /* 0xc */
} KeyBlock;

/* Returns the scrambled key word of a block, or KEY_NONE if the block is shorter than KEY_MIN_SIZE. */
u32 FUN_000ff3f0(KeyBlock *block,u32 size)
{
  u32 key;
  
  key = KEY_NONE;
  if (size >= KEY_MIN_SIZE) {
    key = block->wordc ^ KEY_XOR_WORDC;
  }
  return key;
}

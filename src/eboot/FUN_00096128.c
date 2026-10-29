/* HSTMATCH module=EBOOT.BIN start=0x00096128 end=0x00096178 symbol=FUN_00096128 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00096128.c) corrected by hand: materialized the state test as an int and initialized the return local from it before the conditional call; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Record whose halfword at 0xe carries two low flag bits. */
typedef struct FlagRec {
  char pad0[0xe];
  u16 flags; /* 0x0e */
} FlagRec;

typedef struct RecHolder {
  char pad0[0x10];
  FlagRec **rec; /* 0x10 */
} RecHolder;

typedef struct RootObj {
  char pad0[0x54];
  RecHolder *holder; /* 0x54 */
} RootObj;

extern u32 DAT_00338c20;
extern RootObj * DAT_003415ac;
extern u32 FUN_000fb7b8();

/* True when the record has a flag in its low two bits and FUN_000fb7b8 reports zero for the global. */
int FUN_00096128(void)
{
  int has_state = (((*DAT_003415ac->holder->rec)->flags & 3) != 0);
  int result = has_state;
  if (has_state != 0) {
    int check = FUN_000fb7b8(DAT_00338c20);
    result = (check != 0) ^ 1;
  }
  return result;
}

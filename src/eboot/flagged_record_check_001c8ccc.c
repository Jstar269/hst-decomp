/* HSTMATCH module=EBOOT.BIN start=0x001c8ccc end=0x001c8dc8 symbol=FUN_001c8ccc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: one result variable that the loop sets to 0 and leaves with `break`, no else branch (earlier early `return 0` and `else { r = 0; }` forms moved the joins); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Global object whose word at 0x1324 is a table handed to the value lookup. */
typedef struct ValueHost {
  char pad0000[0x1324];
  u32 values;               /* 0x1324 */
} ValueHost;

/* Record returned by the indexed lookup: a flag byte and two shorts. */
typedef struct FlagRecord {
  char pad00[0x2f];
  char flag;                /* 0x2f */
  char pad30[6];
  short x;                  /* 0x36 */
  short y;                  /* 0x38 */
} FlagRecord;

extern ValueHost * DAT_0033b574;
extern int * FUN_0014c344();
extern FlagRecord * FUN_001930c4();
extern int FUN_0019319c();
extern int FUN_0022ada4();

/* Returns 1 when the first lookup value is at least 2, the second is 0, and every flagged record passes the
   FUN_0022ada4 check on its two shorts; otherwise 0. */
u32 FUN_001c8ccc(void)
{
  bool ok;
  int *value;
  int count;
  int check;
  u32 result;
  int i;
  FlagRecord *rec;
  
  result = 0;
  ok = false;
  if ((DAT_0033b574 != 0) &&
     (value = FUN_0014c344(DAT_0033b574->values,0xbe), *value >= 2)) {
    ok = true;
  }
  if (ok) {
    ok = false;
    if ((DAT_0033b574 != 0) &&
       (value = FUN_0014c344(DAT_0033b574->values,0xbf), *value != 0)) {
      ok = true;
    }
    if (!ok) {
      result = 1;
      i = 0;
      count = FUN_0019319c();
      if (0 < count) {
        do {
          rec = FUN_001930c4(i);
          if (((rec != 0) && (rec->flag != '\0')) &&
             (check = FUN_0022ada4((int)rec->x,(int)rec->y),
             check == 0)) {
            result = 0;
            break;
          }
          i = i + 1;
          count = FUN_0019319c();
        } while (i < count);
      }
    }
  }
  return result;
}

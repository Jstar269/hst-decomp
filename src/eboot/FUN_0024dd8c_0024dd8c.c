/* HSTMATCH module=EBOOT.BIN start=0x0024dd8c end=0x0024de20 symbol=FUN_0024dd8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a signed nonnegative loop edge; readability pass; exact match verified; names and types await human review. */
#include "hst/aityaku_table.h"

/* Progress (0..1) of a value through the level it has reached; 1.0 once the top level is reached. */
float FUN_0024dd8c(float value,AityakuTable *table)
{
  bool found;
  int level;
  float base;
  float progress;
  
  progress = 0.0f;
  found = false;
  level = AITYAKU_LEVELS - 1;
  do {
    if (table->threshold[level] < value) {
      if (level == AITYAKU_LEVELS - 1) {
        progress = 1.0f;
        found = true;
      }
      else {
        base = table->threshold[level];
        found = true;
        progress = (value - base) / (table->threshold[level + 1] - base);
      }
      break;
    }
    level = level + -1;
  } while (level >= 0);
  if (!found) {
    progress = value / table->threshold[0];
  }
  return progress;
}

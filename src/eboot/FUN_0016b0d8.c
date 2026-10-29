/* HSTMATCH module=EBOOT.BIN start=0x0016b0d8 end=0x0016b110 symbol=FUN_0016b0d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#define LOOKUP_COUNT 3   /* entries in the table */

extern int DAT_002c1e34[LOOKUP_COUNT];

/* Returns the index of value in the table, or 0 when it is absent. */
int FUN_0016b0d8(int value)
{
  int index;
  int *entry;
  
  index = 0;
  entry = DAT_002c1e34;
  do {
    if (value == *entry) {
      return index;
    }
    index = index + 1;
    entry = entry + 1;
  } while (index < LOOKUP_COUNT);
  return 0;
}

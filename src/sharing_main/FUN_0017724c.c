/* HSTMATCH module=hstp_trans_main.prx start=0x0017724c end=0x00177284 symbol=FUN_0017724c lang=c99 */
/* Clone of src/eboot/FUN_0016b088.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#define LOOKUP_COUNT 3   /* entries in the table */

extern int DAT_002d2320[LOOKUP_COUNT];

/* Returns the index of value in the table, or 0 when it is absent. */
int FUN_0017724c(int value)
{
  int index;
  int *entry;
  
  index = 0;
  entry = DAT_002d2320;
  do {
    if (value == *entry) {
      return index;
    }
    index = index + 1;
    entry = entry + 1;
  } while (index < LOOKUP_COUNT);
  return 0;
}

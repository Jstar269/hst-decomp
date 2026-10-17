/* HSTMATCH module=EBOOT.BIN start=0x000db93c end=0x000db9f4 symbol=FUN_000db93c lang=c99 */
/* Clone of src/sharing_main/FUN_000df95c_000df95c.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: volatile state-field read preserves post-call load order; names and types await human review. */
extern unsigned char DAT_003417b8;
extern int FUN_000def0c(int);
int FUN_000db93c(int self)
{
  int retry = 0;
  int ok;
  do {
    if (*(int *)(self + 0x8c) != 0) {
      ok = 0;
      goto checked;
    }
    ++retry;
  } while (retry < 2);
  ok = 1;
checked:
  if (ok == 0) return 0;
  int i = 0;
  unsigned char *entry = &DAT_003417b8;
  int *cursor = (int *)self;
  do {
    int status = FUN_000def0c(self);
    unsigned expected;
    if (status != 0) expected = 0;
    else expected = entry[0xe3];
    if (*(volatile unsigned *)(cursor + 0xd0 / 4) != expected) return 0;
    ++i;
    entry += 0x120;
    ++cursor;
  } while (i < 2);
  return 1;
}

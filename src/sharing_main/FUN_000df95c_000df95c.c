/* HSTMATCH module=hstp_trans_main.prx start=0x000df95c end=0x000dfa14 symbol=FUN_000df95c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: volatile state-field read preserves post-call load order; names and types await human review. */
extern unsigned char DAT_003eaaf0;
extern int FUN_000e30f8(int);
int FUN_000df95c(int self)
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
  unsigned char *entry = &DAT_003eaaf0;
  int *cursor = (int *)self;
  do {
    int status = FUN_000e30f8(self);
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

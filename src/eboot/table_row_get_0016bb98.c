/* HSTMATCH module=EBOOT.BIN start=0x0016bb98 end=0x0016bc30 symbol=FUN_0016bb98 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int *DAT_00341508;
extern char DAT_002e04c8[];
int FUN_00014d64(int, char *);
int FUN_00165004(void *, int);

int FUN_0016bb98(int unused, int param)
{
  int idx;
  int kind;

  if (FUN_00014d64(param, DAT_002e04c8) != 0) {
    kind = 1;
    idx = FUN_00165004((char *)DAT_00341508 + 0x18, param);
  } else {
    kind = 0;
    idx = FUN_00165004(DAT_00341508, param);
  }
  return *(char *)(*(int *)((char *)DAT_00341508 + kind * 0x18) + idx * 0x22c + 0x14);
}
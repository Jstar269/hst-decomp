/* HSTMATCH module=EBOOT.BIN start=0x001510d0 end=0x00151110 symbol=FUN_001510d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a114;
extern int FUN_001cd1a4(int);

typedef struct Tick {
  int f0;
  int f4;
} Tick;

int FUN_001510d0(Tick *t)
{
  int v = t->f4;

  if (0 < v) {
    t->f4 = v - 1;
    return 0;
  }
  return !(0U < (unsigned int)FUN_001cd1a4(DAT_0034a114));
}

/* HSTMATCH module=EBOOT.BIN start=0x001c9d7c end=0x001c9dec symbol=FUN_001c9d7c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern char *DAT_0034a118;
extern char DAT_0034a678;
extern void FUN_00234158();

/* Copies one word per slot out of six global entries into the object. */
void FUN_001c9d7c(int param_1)
{
  unsigned int i;
  int off;
  int p;
  int v;

  FUN_00234158(&DAT_0034a678, 0x24);
  i = 0;
  off = 0;
  do {
    p = *(int *)(DAT_0034a118 + off + 0x50);
    v = p ? *(int *)(p + 0x1b4) : -1;
    *(int *)(param_1 + 0x134) = v;
    i++;
    off += 4;
    param_1 += 4;
  } while (i < 6);
}

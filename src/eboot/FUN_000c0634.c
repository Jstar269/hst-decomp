/* HSTMATCH module=EBOOT.BIN start=0x000c0634 end=0x000c067c symbol=FUN_000c0634 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
  char pad0[0xc];
  int f0c;
  int f10;
} Buf;

extern void FUN_000ff5b0(Buf *p, int param_2, int param_3, int param_4);

int FUN_000c0634(int param_1, int param_2, int param_3)
{
  Buf *p = *(Buf **)(param_1 + 0x14);
  int r = 0;

  if ((unsigned)(param_3 + (p->f10 - p->f0c)) < 0x10001) {
    FUN_000ff5b0(p, param_2, param_3, p->f10);
    r = 1;
  }
  return r;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000c3cd4 end=0x000c3d1c symbol=FUN_000c3cd4 lang=c99 */
/* Clone of src/eboot/FUN_000c0634.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef struct {
  char pad0[0xc];
  int f0c;
  int f10;
} Buf;

extern void FUN_00104e48(Buf *p, int param_2, int param_3, int param_4);

int FUN_000c3cd4(int param_1, int param_2, int param_3)
{
  Buf *p = *(Buf **)(param_1 + 0x14);
  int r = 0;

  if ((unsigned)(param_3 + (p->f10 - p->f0c)) < 0x10001) {
    FUN_00104e48(p, param_2, param_3, p->f10);
    r = 1;
  }
  return r;
}

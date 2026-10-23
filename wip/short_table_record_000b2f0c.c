/* HSTMATCH module=EBOOT.BIN start=0x000b2f0c end=0x000b2fc0 symbol=FUN_000b2f0c lang=c99 */
extern unsigned char *DAT_00338b08;

extern int DAT_0034a7e8;
extern char DAT_0034180e[];
extern int FUN_000d8c24(unsigned char *, int, int);

int FUN_000b2f0c(int param_1)
{
  short *p;
  int iVar2;
  int rec;
  int sel;

  p = *(short **)(param_1 + 0x154);
  iVar2 = *p;
  rec = FUN_000d8c24(DAT_00338b08, 0, iVar2);
  sel = ((int)(*(signed char *)(rec + 0x62) << 0x1c)) >> 0x1c;
  int *tbl = (int *)(DAT_0034a7e8 + (sel != 0) * 0xc);
  if (sel != 0) {
    iVar2 = *(short *)(DAT_0034180e + *(int *)(param_1 + 0x148) * 0x120);
  }
  return *tbl + iVar2 * 0x68;
}
// NEAR MISS (lane fm3): 43/45 words; the only difference is branch layout. Retail emits
// "bnez a2,then / b join / sll v1,s0,1" (2 extra words, the sll is dead) where mwcc folds the
// test into "beqz a2,join" and lets the then-block fall through; every instruction of the
// then-block, the hoisted (sel!=0)*0xc pointer and the merged tail are already identical.
// Ruled out: duplicating the return in both arms (kills the pointer hoist, 32 words differ);
// an else-arm multiply of 0x10 (retail multiplies both arms by 0x68); tbl as int* vs char*.
// near miss from lane fm3 (unreviewed)

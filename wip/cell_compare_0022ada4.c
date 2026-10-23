/* HSTMATCH module=EBOOT.BIN start=0x0022ada4 end=0x0022ae88 symbol=FUN_0022ada4 lang=c99 */
extern char *DAT_003415a8;
extern int FUN_0022a9a8(int, int);

unsigned char FUN_0022ada4(int param_1, int param_2)
{
  int v;
  unsigned char b;
  unsigned char ok;

  v = FUN_0022a9a8(param_1, param_2);
  if (v == 1) {
    b = *(unsigned char *)((int)(DAT_003415a8 + param_1 * 0x14) + (param_2 + 10) + 0x3d00);
  }
  else {
    b = *(unsigned char *)((int)(DAT_003415a8 + param_1 * 0x14) + param_2 + 0x3d00);
  }
  ok = b >= 4;
  if (!ok) {
    return 0;
  }
  v = FUN_0022a9a8(param_1, param_2);
  if (v == 1) {
    b = *(unsigned char *)((int)(DAT_003415a8 + param_1 * 0x14) + (param_2 + 10) + 0x3d00);
  }
  else {
    b = *(unsigned char *)((int)(DAT_003415a8 + param_1 * 0x14) + param_2 + 0x3d00);
  }
  return b < 7;
}
// NEAR MISS: 37/57 words differ; EVERY remaining difference is the same one compiler behaviour:
// retail keeps the cell-table offset 0x3d00 in the lbu DISPLACEMENT and puts only the +10 on
// param_2 (`addiu v0,s1,10 ; addu v1,s0,v1 ; addu v0,v0,v1 ; lbu v0,0x3d00(v0)`), while mwccpsp 219
// always merges the two constants into one addiu on param_2 (`addiu v1,s1,0x3d0a ... lbu 0(v0)`).
// Ruled out: typed member at +0x3d00, 2-D rows[param_1][param_2+10] (0x14 stride), explicit char*
// sums in all association orders, `char *rows = DAT+0x3d00; int base=(int)(rows+p1*0x14)`,
// a named `int off = param_1*0x14;` vs the expression written inline (inline is what retail does:
// the p1*0x14 shift chain is duplicated in both arms and lands in the likely slot), and a named
// `int j = param_2 + 10;`. Same blocker as wip/row_cell_lookup_0022abdc.c (0x22abdc).
// near miss from lane fm3 (unreviewed)

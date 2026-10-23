/* HSTMATCH module=EBOOT.BIN start=0x0022abdc end=0x0022ac78 symbol=FUN_0022abdc lang=c99 */
typedef struct {
  char pad_0000[0x3d00];
  unsigned char map[1];
} Table_0022abdc;

extern int DAT_003415a8;
extern int FUN_0022a9a8(int, int);

unsigned char FUN_0022abdc(int param_1, int param_2, int *param_3)
{
  int v;
  unsigned char r;

  v = FUN_0022a9a8(param_1, param_2);
  if (param_3 != 0) {
    *param_3 = v;
  }
  if (v == 1) {
    r = ((Table_0022abdc *)DAT_003415a8)->map[param_1 * 0x14 + param_2 + 15];
  }
  else {
    r = ((Table_0022abdc *)DAT_003415a8)->map[param_1 * 0x14 + param_2 + 5];
  }
  return r;
}
// NEAR MISS: 10/39 words differ, all inside the two cell loads. Retail:
//   lw a0,DAT_003415a8 ; addiu v1,param_2,15 ; sll/addu/sll (param_1*0x14) ; addu v0,v0,a0
//   ; addu v0,v1,v0 ; lbu v0,0x3d00(v0)
// Ours: lw v1,DAT ; addiu a0,param_2,0x3d0f ; addu v1,a0,v1 ; addu v0,v1,v0 ; lbu 0(v0)
// i.e. mwccpsp always merges the +15 into the 0x3d00 table offset (0x3d0f) and never leaves
// 0x3d00 as the load displacement. Ruled out: typed member at +0x3d00 (`->map[i]`),
// row struct (`->rows[param_1].b[param_2+15]`, stride 0x14), explicit char* pointer arithmetic
// with the constant first/middle/last, `char *rows = DAT+0x3d00; int base=(int)(rows+p1*0x14)`
// (the shape that matched the sibling 0x0022a9a8, but there the branch has no +15 so retail has an
// addiu too), named `int col = param_2+15;` (constant propagated), inline helpers Cell(p,i) /
// MapByte(t,row,col) with the member offset inside the helper (still merged and hoists the global),
// and all four written orders of the index sum. The one unexplained retail detail is the pointer
// arriving in a0 (arg register) instead of a t register.
// near miss from lane fm3 (unreviewed)

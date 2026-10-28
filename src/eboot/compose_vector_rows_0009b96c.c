/* HSTMATCH module=EBOOT.BIN start=0x0009b96c end=0x0009ba58 symbol=FUN_0009b96c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v10) corrected by hand: typed the four output temporaries and matrix row copies as Float4; exact match verified; names and types await human review. */

typedef struct { float x, y, z, w; } Float4;
typedef struct { Float4 row[4]; } Matrix4;
extern void FUN_00022450(Float4 *out,Float4 *a,Float4 *b);
extern void FUN_00093434(int param_1,Matrix4 *param_2);

void FUN_0009b96c(char *param_1)
{
  Matrix4 result;
  Float4 temp0;
  Float4 temp1;
  Float4 temp2;
  Float4 temp3;
  FUN_00022450(&temp0,(Float4 *)(param_1 + 0x550),(Float4 *)(param_1 + 0x5a0));
  result.row[0] = temp0;
  FUN_00022450(&temp1,(Float4 *)(param_1 + 0x560),(Float4 *)(param_1 + 0x5a0));
  result.row[1] = temp1;
  FUN_00022450(&temp2,(Float4 *)(param_1 + 0x570),(Float4 *)(param_1 + 0x5a0));
  result.row[2] = temp2;
  FUN_00022450(&temp3,(Float4 *)(param_1 + 0x580),(Float4 *)(param_1 + 0x5a0));
  result.row[3] = temp3;
  FUN_00093434(*(int *)(param_1 + 0x5bc),&result);
}

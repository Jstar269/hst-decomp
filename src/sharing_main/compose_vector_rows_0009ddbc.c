/* HSTMATCH module=hstp_trans_main.prx start=0x0009ddbc end=0x0009dea8 symbol=FUN_0009ddbc lang=c99 */
/* Clone of src/eboot/compose_vector_rows_0009b96c.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v10) corrected by hand: typed the four output temporaries and matrix row copies as Float4; exact match verified; names and types await human review. */

typedef struct { float x, y, z, w; } Float4;
typedef struct { Float4 row[4]; } Matrix4;
extern void FUN_00022478(Float4 *out,Float4 *a,Float4 *b);
extern void FUN_00095358(int param_1,Matrix4 *param_2);

void FUN_0009ddbc(char *param_1)
{
  Matrix4 result;
  Float4 temp0;
  Float4 temp1;
  Float4 temp2;
  Float4 temp3;
  FUN_00022478(&temp0,(Float4 *)(param_1 + 0x550),(Float4 *)(param_1 + 0x5a0));
  result.row[0] = temp0;
  FUN_00022478(&temp1,(Float4 *)(param_1 + 0x560),(Float4 *)(param_1 + 0x5a0));
  result.row[1] = temp1;
  FUN_00022478(&temp2,(Float4 *)(param_1 + 0x570),(Float4 *)(param_1 + 0x5a0));
  result.row[2] = temp2;
  FUN_00022478(&temp3,(Float4 *)(param_1 + 0x580),(Float4 *)(param_1 + 0x5a0));
  result.row[3] = temp3;
  FUN_00095358(*(int *)(param_1 + 0x5bc),&result);
}

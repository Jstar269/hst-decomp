/* HSTMATCH module=EBOOT.BIN start=0x0009b96c end=0x0009ba58 symbol=FUN_0009b96c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v10) corrected by hand: typed the four output temporaries and matrix row copies as Float4; readability pass; exact match verified; names and types await human review. */
#include "hst/rig_obj.h"

typedef struct { Float4 row[4]; } Matrix4;
extern void FUN_00022450(Float4 *out,Float4 *a,Float4 *b);
extern void FUN_00093434(void *model,Matrix4 *matrix);

/* Multiplies each of the four rows by the scale vector and hands the resulting matrix to the model. */
void FUN_0009b96c(RigObj *obj)
{
  Matrix4 result;
  Float4 temp0;
  Float4 temp1;
  Float4 temp2;
  Float4 temp3;
  FUN_00022450(&temp0,&obj->rows[0],&obj->scale);
  result.row[0] = temp0;
  FUN_00022450(&temp1,&obj->rows[1],&obj->scale);
  result.row[1] = temp1;
  FUN_00022450(&temp2,&obj->rows[2],&obj->scale);
  result.row[2] = temp2;
  FUN_00022450(&temp3,&obj->rows[3],&obj->scale);
  result.row[3] = temp3;
  FUN_00093434(obj->model,&result);
}

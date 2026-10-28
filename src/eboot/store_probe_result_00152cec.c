/* HSTMATCH module=EBOOT.BIN start=0x00152cec end=0x00152d70 symbol=FUN_00152cec lang=c99 data=0x002dc6f0 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print argument (&DAT_002dc6f0, f8), typed Ctx/Obj/Arg views, the callee's bool result kept in an int, and matching idiom: the argument pointer param_2[3] is read through a volatile Arg before *param_2 (that fixes the load order so param_2 and the id share one saved register; plain locals, const, comma sequences and statement permutations all gave a third saved register); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc6f0-0x002dc6ff) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct { char pad[0x1b4]; int f1b4; } Inner;
typedef struct { char pad[0x50]; Inner *f50; } Ctx;
typedef struct { char pad[8]; int f8; } Obj;
typedef struct { int f0; int f4; int f8; int *fc; } Arg;
#include "hst/types.h"
extern unsigned char DAT_003402f0;
extern Ctx *DAT_0034a118;
extern unsigned int *FUN_0014c384(int a, int b);
extern void FUN_0014d044(Arg *p);
extern void FUN_0014fd94(const char *fmt, int a);
extern bool FUN_00288be8(int *a, int b);

int FUN_00152cec(Obj *param_1, Arg *param_2)
{
  int result;
  int id;
  int *fc;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94("IsMyBoss [%d]\n", param_1->f8);
  }
  fc = ((volatile Arg *)param_2)->fc;
  id = param_2->f0;
  result = FUN_00288be8(fc, DAT_0034a118->f50->f1b4);
  *FUN_0014c384(id, param_1->f8) = result;
  return 0;
}

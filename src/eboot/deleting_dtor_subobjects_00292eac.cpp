/* HSTMATCH module=EBOOT.BIN start=0x00292eac end=0x00292fa0 symbol=FUN_00292eac lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: declared loop counter before walking pointer to fix s2/s3 register allocation; exact match verified; names and types await human review. */

#include "hst/types.h"

extern "C" {
extern char DAT_00309dcc;
extern char DAT_00309ddc;
extern void FUN_00000a00(void *);
extern int FUN_0005ba00(int, int);
}

struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" u32 * FUN_00292eac(u32 *param_1, short param_2)
{
  int i;
  u32 *puVar3;
  int *piVar1;
  int obj4;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309dcc);
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_00309ddc);
      piVar1 = (int *)param_1[3];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        param_1[3] = 0;
      }
      obj4 = param_1[4];
      if (obj4 != 0) {
        FUN_0005ba00(obj4, 1);
        param_1[4] = 0;
      }
      i = 0;
      puVar3 = param_1;
      do {
        piVar1 = (int *)puVar3[6];
        if (piVar1 != (int *)0x0) {
          delete ((VC_1 *)(piVar1));
          puVar3[6] = 0;
        }
        i = i + 1;
        puVar3 = puVar3 + 1;
      } while (i < 7);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

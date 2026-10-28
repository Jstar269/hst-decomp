/* HSTMATCH module=EBOOT.BIN start=0x0021ab48 end=0x0021ab8c symbol=FUN_0021ab48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the call to FUN_001b1c44 takes the module global by address and the state value 11 as the second argument Ghidra dropped (li a1,11 before the compare); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Obj_0021ab48 {
  int f0;
  int f4;
} Obj_0021ab48;

extern u8 DAT_0034179c;
extern void FUN_001b1c44(u8 *, int);
extern void FUN_0021abe0(Obj_0021ab48 *, int);

void FUN_0021ab48(Obj_0021ab48 *param_1)
{
  if (param_1->f4 == 0xb) {
    FUN_001b1c44(&DAT_0034179c, 0xb);
    FUN_0021abe0(param_1, 0);
  }
}

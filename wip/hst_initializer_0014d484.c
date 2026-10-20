/* HSTMATCH module=EBOOT.BIN start=0x0014d484 end=0x0014d53c symbol=FUN_0014d484 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_00308360;
extern undefined DAT_0030840c;
extern undefined4 FUN_0014f028();
extern undefined4 FUN_0014f03c();
extern undefined2 FUN_0014f050();

#pragma opt_strength_reduction off

undefined4 * FUN_0014d484(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar2;
  uint iVar3;
  int uVar1;
  
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_00308360);
  uVar1 = FUN_0014f050(param_2);
  param_1[2] = uVar1 & 0xffff;
  uVar2 = FUN_0014f03c(param_2);
  param_1[3] = uVar2;
  iVar3 = 0;
  uVar1 = 0;
  do {
    if (uVar1 < (uint)param_1[3]) {
      uVar2 = FUN_0014f028(param_2);
      *(undefined4 *)((int)param_1 + iVar3 + 0x10) = uVar2;
    }
    else {
      *(undefined4 *)((int)param_1 + iVar3 + 0x10) = 0;
    }
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 8);
  return param_1;
}
// Near miss: 6 retail words differ; the loop counter and byte offset use s0/s1 in the opposite order.
// opt_strength_reduction off aligned the address recurrence; declaration order and signedness variants did not swap the two registers.
// near miss from lane cx1 (unreviewed)

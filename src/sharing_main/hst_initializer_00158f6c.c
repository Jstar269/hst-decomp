/* HSTMATCH module=hstp_trans_main.prx start=0x00158f6c end=0x00159024 symbol=FUN_00158f6c lang=c99 */
/* Clone of src/eboot/hst_initializer_0014d484.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop counter is an unsigned local declared before the byte-offset local (counter s1, offset s0, sltiu); exact match verified; names and types await human review. */
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

extern undefined DAT_003b162c;
extern undefined DAT_003b16d8;
extern undefined4 FUN_0015b028();
extern undefined4 FUN_0015b03c();
extern undefined2 FUN_0015b050();

#pragma opt_strength_reduction off

undefined4 * FUN_00158f6c(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar2;
  int r;
  uint i;
  int off;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b162c);
  r = FUN_0015b050(param_2);
  param_1[2] = r & 0xffff;
  uVar2 = FUN_0015b03c(param_2);
  param_1[3] = uVar2;
  i = 0;
  off = 0;
  do {
    if (i < (uint)param_1[3]) {
      uVar2 = FUN_0015b028(param_2);
      *(undefined4 *)((int)param_1 + off + 0x10) = uVar2;
    }
    else {
      *(undefined4 *)((int)param_1 + off + 0x10) = 0;
    }
    i = i + 1;
    off = off + 4;
  } while (i < 8);
  return param_1;
}

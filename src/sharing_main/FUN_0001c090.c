/* HSTMATCH module=hstp_trans_main.prx start=0x0001c090 end=0x0001c134 symbol=FUN_0001c090 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: positive-path guard, retained intermediate pointer store, and byte-offset expression; exact match verified; names and types await human review. */
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

extern int FUN_0001bd34();

undefined4 FUN_0001c090(int *param_1)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0001bd34();
  if (iVar1 >= 0) {
    if (iVar1 < param_1[1]) {
      iVar1 = *param_1 + iVar1 * 8;
      param_1[2] = iVar1 + 8;
      param_1[2] = param_1[2] + 4;
      param_1[5] = *(int *)(iVar1 + 8);
      uVar2 = *(uint *)param_1[2];
      param_1[8] = uVar2;
      param_1[2] = (int)((char *)*param_1 + ((uVar2 & 0xfffffff) << 2));
      param_1[8] = (uint)param_1[8] >> 0x1c;
      return 1;
    }
  }
  param_1[2] = 0;
  param_1[5] = 0;
  return 0;
}

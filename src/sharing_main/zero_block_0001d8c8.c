/* HSTMATCH module=hstp_trans_main.prx start=0x0001d8c8 end=0x0001d930 symbol=FUN_0001d8c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: moved pointer declaration/init before the loop counter; exact match verified; names and types await human review. */
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

extern void FUN_0001d970();

undefined4 * FUN_0001d8c8(undefined4 *param_1)
{
  undefined4 *puVar2;
  int iVar1;
  
  puVar2 = param_1;
  iVar1 = 0;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    iVar1 = iVar1 + 8;
    puVar2[7] = 0;
    puVar2 = puVar2 + 8;
  } while (iVar1 < 0x30);
  param_1[1] = 0x10;
  FUN_0001d970(param_1);
  return param_1;
}

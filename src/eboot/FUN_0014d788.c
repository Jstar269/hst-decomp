/* HSTMATCH module=EBOOT.BIN start=0x0014d788 end=0x0014d7fc symbol=FUN_0014d788 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the 4-bit field extracted as (x >> 12) & 0xf; exact match verified; names and types await human review. */
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

extern undefined DAT_0030832c;
extern undefined DAT_0030840c;
extern undefined4 FUN_0014f028();
extern undefined2 FUN_0014f050();

undefined4 * FUN_0014d788(undefined4 *param_1,undefined4 param_2)
{
  uint uVar1;
  undefined4 uVar2;
  
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_0030832c);
  uVar1 = FUN_0014f050(param_2);
  param_1[2] = (uVar1 >> 0xc) & 0xf;
  param_1[3] = uVar1 & 0xfff;
  uVar2 = FUN_0014f028(param_2);
  param_1[4] = uVar2;
  return param_1;
}

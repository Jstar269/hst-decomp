/* HSTMATCH module=hstp_trans_main.prx start=0x001592b0 end=0x00159324 symbol=FUN_001592b0 lang=c99 */
/* Clone of src/eboot/FUN_0014d788.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b15f8;
extern undefined DAT_003b16d8;
extern undefined4 FUN_0015b028();
extern undefined2 FUN_0015b050();

undefined4 * FUN_001592b0(undefined4 *param_1,undefined4 param_2)
{
  uint uVar1;
  undefined4 uVar2;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b15f8);
  uVar1 = FUN_0015b050(param_2);
  param_1[2] = (uVar1 >> 0xc) & 0xf;
  param_1[3] = uVar1 & 0xfff;
  uVar2 = FUN_0015b028(param_2);
  param_1[4] = uVar2;
  return param_1;
}

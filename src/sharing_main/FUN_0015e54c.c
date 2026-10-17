/* HSTMATCH module=hstp_trans_main.prx start=0x0015e54c end=0x0015e5d4 symbol=FUN_0015e54c lang=c99 */
/* Clone of src/eboot/FUN_001523fc.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b16d8;
extern undefined DAT_003b1eec;
extern void FUN_000009e4();
extern void FUN_00000a00();

undefined4 * FUN_0015e54c(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1eec);
    iVar1 = param_1[4];
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      param_1[4] = 0;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b16d8);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

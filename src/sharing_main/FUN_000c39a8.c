/* HSTMATCH module=hstp_trans_main.prx start=0x000c39a8 end=0x000c3a2c symbol=FUN_000c39a8 lang=c99 */
/* Clone of src/eboot/FUN_000c0308.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b06c8;
extern void FUN_00000a00();
extern void FUN_002c7680();
extern void FUN_002c76a0();

undefined4 * FUN_000c39a8(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b06c8);
    if ((undefined1 *)param_1[4] != (undefined1 *)0x0) {
      *(undefined1 *)param_1[4] = 1;
    }
    iVar1 = param_1[1];
    if (0 < iVar1) {
      FUN_002c7680(iVar1,0);
      FUN_002c76a0(param_1[1]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00225e74 end=0x00225e94 symbol=FUN_00225e74 lang=c99 */
/* Clone of src/eboot/FUN_00216e70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00225e74(undefined1 *param_1,undefined4 *param_2,undefined1 param_3)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2[2];
  uVar1 = param_2[1];
  *param_1 = (char)*param_2;
  param_1[1] = (char)uVar1;
  param_1[2] = (char)uVar2;
  param_1[3] = param_3;
  return;
}

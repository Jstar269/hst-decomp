/* HSTMATCH module=hstp_trans_main.prx start=0x001c0414 end=0x001c0454 symbol=FUN_001c0414 lang=c99 */
/* Clone of src/eboot/FUN_001b2380.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001be964();
extern void FUN_001bf834();

void FUN_001c0414(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  FUN_001be964(uVar1,0x58,0,0,0);
  FUN_001bf834(uVar1);
  return;
}

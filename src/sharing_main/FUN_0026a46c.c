/* HSTMATCH module=hstp_trans_main.prx start=0x0026a46c end=0x0026a4ac symbol=FUN_0026a46c lang=c99 */
/* Clone of src/eboot/FUN_00259fbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003eaafc;
extern void FUN_001c2a10();
extern void FUN_00265b24();
extern int FUN_00297288();

void FUN_0026a46c(int param_1)
{
  undefined4 uVar1;
  
  FUN_001c2a10(DAT_003eaafc);
  uVar1 = FUN_00297288(*(undefined4 *)(param_1 + 0x640));
  FUN_00265b24(param_1 + 0x60,uVar1);
  return;
}

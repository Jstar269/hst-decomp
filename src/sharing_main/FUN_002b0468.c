/* HSTMATCH module=hstp_trans_main.prx start=0x002b0468 end=0x002b04ac symbol=FUN_002b0468 lang=c99 */
/* Clone of src/eboot/FUN_002a105c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern uint FUN_0001342c();

void FUN_002b0468(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0001342c();
  *(int *)(param_1 + 0x1f0) = (iVar1 % 0xc) * 0x1e + 0x78;
  return;
}

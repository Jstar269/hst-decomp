/* HSTMATCH module=hstp_trans_main.prx start=0x002a4c68 end=0x002a4c98 symbol=FUN_002a4c68 lang=c99 */
/* Clone of src/eboot/FUN_0029365c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00059e58();
extern void FUN_0005fec8();

void FUN_002a4c68(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x78);
  FUN_00059e58(uVar1);
  FUN_0005fec8(uVar1);
  return;
}

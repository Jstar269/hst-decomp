/* HSTMATCH module=hstp_trans_main.prx start=0x0018afb0 end=0x0018b018 symbol=FUN_0018afb0 lang=c99 */
/* Clone of src/eboot/FUN_0017e8bc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern int DAT_003da704;
extern int FUN_0005c700();
extern void FUN_0005c8e0();
extern void FUN_0018adb4();

void FUN_0018afb0(int param_1)
{
  int iVar1;
  
  FUN_0018adb4();
  iVar1 = DAT_003da704;
  *(undefined4 *)(DAT_003da704 + 0x1d0) = *(undefined4 *)(param_1 + 0x5a0);
  *(undefined4 *)(iVar1 + 0x1d4) = *(undefined4 *)(param_1 + 0x5a4);
  *(undefined4 *)(iVar1 + 0x1d8) = *(undefined4 *)(param_1 + 0x5a8);
  *(undefined4 *)(iVar1 + 0x1dc) = *(undefined4 *)(param_1 + 0x5ac);
  FUN_0005c8e0(DAT_003da704);
  FUN_0005c700(param_1 + 0x10,DAT_003da704);
  return;
}

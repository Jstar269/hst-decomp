/* HSTMATCH module=hstp_trans_main.prx start=0x00123a9c end=0x00123adc symbol=FUN_00123a9c lang=c99 */
/* Clone of src/eboot/FUN_001188c8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern int FUN_0005c688();

void FUN_00123a9c(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xec);
  if ((iVar1 != 0) && (iVar1 != 0)) {
    FUN_0005c688(iVar1,1);
    *(undefined4 *)(param_1 + 0xec) = 0;
  }
  return;
}

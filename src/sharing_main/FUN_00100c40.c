/* HSTMATCH module=hstp_trans_main.prx start=0x00100c40 end=0x00100c64 symbol=FUN_00100c40 lang=c99 */
/* Clone of src/eboot/FUN_000fb504.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


bool FUN_00100c40(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 100);
  bVar1 = true;
  if (iVar2 != 0) {
    bVar1 = *(int *)(iVar2 + 0xb8) == 5;
  }
  return bVar1;
}

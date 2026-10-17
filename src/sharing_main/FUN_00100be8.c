/* HSTMATCH module=hstp_trans_main.prx start=0x00100be8 end=0x00100c0c symbol=FUN_00100be8 lang=c99 */
/* Clone of src/eboot/FUN_000fb4ac.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00100be8(int param_1,undefined1 param_2)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x8c), iVar1 != 0)) {
    *(undefined1 *)(iVar1 + 0x870) = param_2;
  }
  return;
}

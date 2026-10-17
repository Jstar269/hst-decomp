/* HSTMATCH module=hstp_trans_main.prx start=0x000df92c end=0x000df95c symbol=FUN_000df92c lang=c99 */
/* Clone of src/eboot/FUN_000db90c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_000df92c(int param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x8c) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return 1;
}

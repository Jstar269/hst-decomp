/* HSTMATCH module=hstp_trans_main.prx start=0x001259ac end=0x001259f4 symbol=FUN_001259ac lang=c99 */
/* Clone of src/eboot/FUN_0011a7d8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1e84;

undefined4 FUN_001259ac(int param_1)
{
  int iVar1;
  
  if (*(int *)(DAT_003e1e84 + 0x8c) == 0) {
    iVar1 = 0;
    do {
      if (*(int *)(param_1 + 0x314) == 5) {
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 4;
    } while (iVar1 < 2);
  }
  return 0;
}

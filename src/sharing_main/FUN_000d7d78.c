/* HSTMATCH module=hstp_trans_main.prx start=0x000d7d78 end=0x000d7e04 symbol=FUN_000d7d78 lang=c99 */
/* Clone of src/eboot/FUN_000d40b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern void FUN_0005ffd8();

void FUN_000d7d78(int param_1)
{
  int iVar3;
  int iVar2;
  int iVar1;
  
  iVar3 = 0;
  iVar2 = 0;
  iVar1 = param_1;
  do {
    if ((*(int *)(DAT_003e19f0 + iVar2 + 0x70) != 0) &&
       (*(uchar *)(param_1 + iVar3 + 0x7a0) != '\0')) {
      FUN_0005ffd8(iVar1 + 0xe0,0);
    }
    iVar3 += 1;
    iVar2 += 4;
    iVar1 = iVar1 + 0x1b0;
  } while (iVar3 < 4);
  return;
}

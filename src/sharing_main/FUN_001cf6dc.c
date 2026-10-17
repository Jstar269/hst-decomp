/* HSTMATCH module=hstp_trans_main.prx start=0x001cf6dc end=0x001cf72c symbol=FUN_001cf6dc lang=c99 */
/* Clone of src/eboot/FUN_001c14c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001ccd50();
extern void FUN_001cf558();

void FUN_001cf6dc(undefined4 *param_1)
{
  int iVar1;
  
  FUN_001ccd50(*param_1);
  *(undefined2 *)(param_1 + 0x104) = 0;
  FUN_001cf558(param_1);
  iVar1 = 0;
  do {
    *(undefined1 *)((int)param_1 + 0x412) = 0;
    iVar1 = iVar1 + 1;
    *(undefined1 *)((int)param_1 + 0x413) = 0;
    param_1 = (undefined4 *)((int)param_1 + 2);
  } while (iVar1 < 2);
  return;
}

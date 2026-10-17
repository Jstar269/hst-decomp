/* HSTMATCH module=hstp_trans_main.prx start=0x002b1770 end=0x002b17cc symbol=FUN_002b1770 lang=c99 */
/* Clone of src/eboot/FUN_002a23d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003eaad8;
extern int FUN_001bfc3c();
extern void FUN_002b136c();

void FUN_002b1770(int param_1)
{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x1b0) == 5) && (piVar1 = *(int **)(param_1 + 0x1d0), *piVar1 == 1)) {
    FUN_001bfc3c((int *)&DAT_003eaad8,0xf);
    FUN_002b136c(piVar1,2);
  }
  return;
}

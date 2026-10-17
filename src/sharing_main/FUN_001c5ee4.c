/* HSTMATCH module=hstp_trans_main.prx start=0x001c5ee4 end=0x001c5f20 symbol=FUN_001c5ee4 lang=c99 */
/* Clone of src/eboot/FUN_001b8224.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

void FUN_001c5ee4(char *param_1)
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x8c)) &&
     (iVar1 = *(int *)(param_1 + 0x8c) + -1, *(int *)(param_1 + 0x8c) = iVar1, iVar1 < 1)) {
    FUN_001bfc3c((int *)&DAT_003eaad8,0x45);
  }
  return;
}

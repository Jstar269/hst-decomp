/* HSTMATCH module=hstp_trans_main.prx start=0x002983b4 end=0x00298404 symbol=FUN_002983b4 lang=c99 */
/* Clone of src/eboot/FUN_00286cb8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00158308();

void FUN_002983b4(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00158308(*(int *)(param_1 + 0xc),1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    FUN_00158308(iVar1,1);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

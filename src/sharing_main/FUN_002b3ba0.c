/* HSTMATCH module=hstp_trans_main.prx start=0x002b3ba0 end=0x002b3c08 symbol=FUN_002b3ba0 lang=c99 */
/* Clone of src/eboot/FUN_002a4488.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined * DAT_003ea8e8;
extern void FUN_002b1820();

void FUN_002b3ba0(int param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_003ea8e8 + 0x86d10);
  if (((uVar1 & 1) == 0) &&
     (*(uint *)(DAT_003ea8e8 + 0x86d10) = uVar1 | 1, *(int *)(param_1 + 0x1b0) != 5)) {
    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1b8);
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    FUN_002b1820(param_1,1);
  }
  return;
}

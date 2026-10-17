/* HSTMATCH module=hstp_trans_main.prx start=0x00274340 end=0x002743d4 symbol=FUN_00274340 lang=c99 */
/* Clone of src/eboot/FUN_002634c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003ea8ec;
extern undefined DAT_003f39a8;
extern void FUN_00108f54();
extern void FUN_00244258();
extern void FUN_002929dc();

void FUN_00274340(int param_1)
{
  FUN_00108f54(DAT_003ea8ec,1);
  *(undefined4 *)(*(int *)(param_1 + 0x640) + 0x61c) =
       *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xdc);
  FUN_002929dc(*(undefined4 *)(param_1 + 0x640));
  if ((*(int *)(*(int *)(param_1 + 0x640) + 0x80) == 1) &&
     (*(int *)(*(int *)(param_1 + 0x640) + 0x61c) == 2)) {
    FUN_00244258(&DAT_003f39a8,0x40);
  }
  else {
    FUN_00244258(&DAT_003f39a8,0x3f);
  }
  return;
}

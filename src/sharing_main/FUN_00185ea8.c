/* HSTMATCH module=hstp_trans_main.prx start=0x00185ea8 end=0x00185ef0 symbol=FUN_00185ea8 lang=c99 */
/* Clone of src/eboot/FUN_001797b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00189578();
extern void FUN_0018d5d0();

void FUN_00185ea8(int param_1)
{
  undefined4 uVar1;
  
  if (0 < *(int *)(param_1 + 0x6c)) {
    uVar1 = (**(code **)(param_1 + 0x558))();
    FUN_0018d5d0(*(undefined4 *)(param_1 + 0x174),uVar1);
    FUN_00189578(*(undefined4 *)(param_1 + 0x178));
  }
  return;
}

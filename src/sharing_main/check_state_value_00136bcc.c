/* HSTMATCH module=hstp_trans_main.prx start=0x00136bcc end=0x00136c38 symbol=FUN_00136bcc lang=c99 */
/* Clone of src/eboot/check_state_value_0012b760.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered the conditions and grouped the signed offset expression; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e47f0;
extern undefined4 DAT_003e47f4;

bool FUN_00136bcc(int param_1)
{
  bool bVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x58) == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0xf0);
    bVar1 = false;
    if (*(int *)(param_1 + 0x334) >= 0) {
      if (iVar2 == *(int *)(param_1 + 0x334)) {
        bVar1 = iVar2 <= (int)DAT_003e47f4;
      }
    }
    else if (iVar2 == (int)DAT_003e47f0 +
        (*(int *)(param_1 + 0x354) + (int)*(byte *)(param_1 + 0x364) * 2)) {
      bVar1 = true;
    }
  }
  return bVar1;
}

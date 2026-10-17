/* HSTMATCH module=hstp_trans_main.prx start=0x001cc9c8 end=0x001cca9c symbol=FUN_001cc9c8 lang=c99 */
/* Clone of src/eboot/helper_001bec74.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct signed-byte guard and the retail nested likely-branch ordering; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1e48;
extern int FUN_000dca74();
extern undefined4 FUN_001c972c();
extern void FUN_001cd708();

void FUN_001cc9c8(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_000dca74(DAT_003e1e48,1,iVar2);
    *(undefined1 *)(param_1 + iVar2 + 0x84c) = 0;
    if (iVar1 != 0 && *(char *)(iVar1 + 0x60) >= 0) {
      if (param_2 != 0) {
        FUN_001cd708(param_1,iVar2,5);
      }
      else if (*(char *)(iVar1 + 0x60) == 1) {
        FUN_001cd708(param_1,iVar2,5);
      }
      else {
        if (FUN_001c972c(param_1,1,iVar2) != 0) {
          FUN_001cd708(param_1,iVar2,5);
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x280);
  return;
}

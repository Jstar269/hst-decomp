/* HSTMATCH module=EBOOT.BIN start=0x001bec74 end=0x001bed48 symbol=FUN_001bec74 lang=c99 */
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

extern undefined4 DAT_00338b08;
extern int FUN_000d8c24();
extern undefined4 FUN_001bb944();
extern void FUN_001bf948();

void FUN_001bec74(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_000d8c24(DAT_00338b08,1,iVar2);
    *(undefined1 *)(param_1 + iVar2 + 0x84c) = 0;
    if (iVar1 != 0 && *(char *)(iVar1 + 0x60) >= 0) {
      if (param_2 != 0) {
        FUN_001bf948(param_1,iVar2,5);
      }
      else if (*(char *)(iVar1 + 0x60) == 1) {
        FUN_001bf948(param_1,iVar2,5);
      }
      else {
        if (FUN_001bb944(param_1,1,iVar2) != 0) {
          FUN_001bf948(param_1,iVar2,5);
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x280);
  return;
}

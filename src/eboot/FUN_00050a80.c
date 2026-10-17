/* HSTMATCH module=EBOOT.BIN start=0x00050a80 end=0x00050b2c symbol=FUN_00050a80 lang=c99 */
/* Clone of src/sharing_main/FUN_00051394.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_00022570();
extern int FUN_0003ea00();
extern int FUN_0003ea08();
extern int FUN_0003ea10();

void FUN_00050a80(char *param_1)
{
  undefined1 (*pauVar1) [64];
  undefined1 (*pauVar2) [64];
  undefined1 (*pauVar3) [64];
  
  if (*(int *)(param_1 + 0x1a014) != 0) {
    pauVar1 = (undefined1 (*) [64])FUN_0003ea00(*(int *)(param_1 + 0x1a014));
    pauVar2 = (undefined1 (*) [64])FUN_0003ea08(*(int *)(param_1 + 0x1a014));
    pauVar3 = (undefined1 (*) [64])FUN_0003ea10(*(int *)(param_1 + 0x1a014));
    FUN_00022570((undefined4 *)(param_1 + 0x1a020),pauVar3,pauVar2);
    FUN_00022570((undefined4 *)(param_1 + 0x1a060),(undefined1 (*) [64])(param_1 + 0x1a020),pauVar1)
    ;
  }
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x001557c8 end=0x00155834 symbol=FUN_001557c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the true work in the if body and return false after it. */
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

extern void *DAT_0034a114;
extern int *FUN_0014c384(undefined4, undefined4);
extern int FUN_001cd190(void *);
extern undefined4 FUN_001cd29c(void *);

bool FUN_001557c8(int param_1,undefined4 *param_2)
{
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (FUN_001cd190(DAT_0034a114) == 0) {
    uVar4 = *param_2;
    uVar2 = FUN_001cd29c(DAT_0034a114);
    puVar3 = (undefined4 *)FUN_0014c384(uVar4,*(undefined4 *)(*(int *)(param_1 + 4) + 8));
    *puVar3 = uVar2;
    return true;
  }
  return false;
}

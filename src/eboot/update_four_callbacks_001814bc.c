/* HSTMATCH module=EBOOT.BIN start=0x001814bc end=0x001815bc symbol=FUN_001814bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a/v3) corrected by hand: inverted outer and nested condition ordering; exact match verified; names and types await human review. */
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

extern void FUN_000ffb3c();
extern undefined4 FUN_0016bc70();

void FUN_001814bc(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(param_1 + 0x80);
  puVar4 = (undefined4 *)(param_1 + 0x94);
  puVar3 = (undefined4 *)(param_1 + 0xa8);
  puVar2 = (undefined4 *)(param_1 + 0xbc);
  iVar1 = FUN_0016bc70();
  if (*(uchar *)(iVar1 + 0x94) != '\0') {
    iVar1 = FUN_0016bc70();
    if (*(uchar *)(iVar1 + 0x45) != '\0') {
      FUN_000ffb3c(*puVar5,0);
      FUN_000ffb3c(*puVar4,0);
      FUN_000ffb3c(*puVar3,1);
      FUN_000ffb3c(*puVar2,1);
    }
    else {
      FUN_000ffb3c(*puVar5,1);
      FUN_000ffb3c(*puVar4,1);
      FUN_000ffb3c(*puVar3,0);
      FUN_000ffb3c(*puVar2,0);
    }
  }
  else {
    FUN_000ffb3c(*puVar5,1);
    FUN_000ffb3c(*puVar4,1);
    FUN_000ffb3c(*puVar3,1);
    FUN_000ffb3c(*puVar2,1);
  }
  return;
}

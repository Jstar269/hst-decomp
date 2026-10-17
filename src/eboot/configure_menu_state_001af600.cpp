/* HSTMATCH module=EBOOT.BIN start=0x001af600 end=0x001af6f4 symbol=FUN_001af600 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" void FUN_000ffb3c(...);
extern "C" void FUN_0010b6d4(...);
extern "C" undefined4 FUN_0019d474();
extern "C" void FUN_001acc30(...);
extern "C" void FUN_001acf64(...);
extern "C" void FUN_001ad350(...);
extern "C" void FUN_001ad604(...);
extern "C" void FUN_001ad89c(...);

static inline int &EntryValue(int *p)
{
  return *(int *)((char *)p + 0x24);
}

extern "C" void FUN_001af600(int param_1)
{
  int iVar7;
  uint uVar6;
  int iVar5;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar7 = *(int *)(param_1 + 0xc);
  FUN_0010b6d4(*(undefined4 *)(iVar7 + 0x914),0x1e,0x1f);
  iVar1 = FUN_0019d474();
  uVar4 = *(uint *)(iVar1 + 0x2dc);
  iVar1 = FUN_0019d474() + 0x360;
  uVar6 = 0;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar5 = 0;
    do {
      puVar2 = (undefined4 *)(iVar7 + (iVar5 + 0x7bc));
      int &item = EntryValue((int *)puVar2);
      if (uVar4 == uVar6) {
        FUN_000ffb3c(item,0);
        uVar3 = *(uint *)(iVar1 + 4);
      }
      else {
        FUN_000ffb3c(item,1);
        uVar3 = *(uint *)(iVar1 + 4);
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar6 < uVar3);
  }
  FUN_001acc30(iVar7,0);
  FUN_001acf64(iVar7,0);
  FUN_001ad350(iVar7,0);
  FUN_001ad604(iVar7,0);
  FUN_001ad89c(iVar7,1);
  return;
}

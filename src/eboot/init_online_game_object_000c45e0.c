/* HSTMATCH module=EBOOT.BIN start=0x000c45e0 end=0x000c4708 symbol=FUN_000c45e0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: assign the vtable before deriving the element base and set the inner iterator at the loop header. */
#include "hst/types.h"

extern char DAT_00307430[];
extern char DAT_002d5ac8[];
extern u32 DAT_00338af0;
extern u32 * FUN_0001f06c();
extern u32 * FUN_00095d64();
extern u8 * FUN_00095d94();
extern u32 * FUN_00095da8();
extern u32 * FUN_00095dd8();
extern u32 * FUN_00095e10();
extern u32 * FUN_00095e40();
extern u32 * FUN_00095e70();
extern u32 * FUN_00095ea0();
extern u32 * FUN_00095ed0();
extern u32 * FUN_00095f00();
extern u32 * FUN_00095f30();
extern u32 * FUN_00095f60();
extern u32 * FUN_00095f90();
extern void FUN_000c4708(const char *, int);
extern void FUN_000c4bd4();

typedef struct ObjectLayout {
  u32 vtable;
  char padding[0x3c];
  u32 first;
} ObjectLayout;

u32 * FUN_000c45e0(u32 *param_1)
{
  u32 *puVar1;
  u32 *puVar2;
  ObjectLayout *object = (ObjectLayout *)param_1;
  
  FUN_0001f06c(param_1);
  puVar1 = (u32 *)((*(u32 *)param_1 = (u32)DAT_00307430), (char *)param_1 + 0x40);
  do {
    puVar2 = puVar1 + 3;
    do {
      FUN_00095f90(puVar2);
      puVar2 = puVar2 + 1;
    } while (puVar2 < puVar1 + 5);
    FUN_00095f60(puVar1 + 5);
    FUN_00095f30(puVar1 + 8);
    puVar2 = puVar1 + 0x14;
    do {
      FUN_00095f00(puVar2);
      puVar2 = puVar2 + 3;
    } while (puVar2 < puVar1 + 0x1a);
    FUN_00095ed0(puVar1 + 0x1a);
    FUN_00095ea0(puVar1 + 0x1d);
    FUN_00095e70(puVar1 + 0x20);
    FUN_00095e40(puVar1 + 0x2c);
    FUN_00095e10(puVar1 + 0x38);
    FUN_00095dd8(puVar1 + 0x3c);
    FUN_00095da8(puVar1 + 0x4c);
    FUN_00095d94((u8 *)(puVar1 + 0x4e));
    FUN_00095d64(puVar1 + 0x50);
    *(u8 *)puVar1 = 0;
    *(u8 *)((int)puVar1 + 1) = 0;
    *(u16 *)((int)puVar1 + 2) = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1 = puVar1 + 0x74;
  } while (puVar1 < param_1 + 0x1e0);
  FUN_000c4708(DAT_002d5ac8,0x1d0);
  DAT_00338af0 = (unsigned int)(param_1);
  FUN_000c4bd4((int)param_1);
  return param_1;
}

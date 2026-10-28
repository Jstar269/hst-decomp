/* HSTMATCH module=EBOOT.BIN start=0x0012f41c end=0x0012f698 symbol=FUN_0012f41c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Record {
  u32 w00;
  u32 w04;
  u32 w08;
  u32 w0c;
  u32 w10;
  u32 w14;
  u32 w18;
  u32 w1c;
  u32 w20;
  u32 w24;
  u32 w28;
  u32 w2c;
  u32 w30;
  u32 w34;
  u32 w38;
  u32 w3c;
  u32 w40;
  u16 h44;
  u16 h46;
  u16 h48;
  u8 b4a;
  u8 b4b;
  u8 b4c;
  u8 b4d;
  u8 b4e;
  u8 b4f;
  u8 b50;
  u8 b51;
  u8 b52;
  u8 b53;
  u8 b54;
  u8 b55;
  u8 b56;
  u8 b57;
} Record;

extern u8 DAT_003081f0;
extern Record DAT_0033b584[];
extern u32 * DAT_00340284;
extern void * FUN_00000bcc(unsigned int);
extern void FUN_0001f06c();
extern void FUN_0001f1fc(void *, int);
extern void FUN_0001f21c(void *, void *);
extern u32 * FUN_000b7e7c(void *);
extern u32 * FUN_00122888(void *);
extern u32 FUN_0012f698(void *);
extern u32 * FUN_001b9760(void *);

u32 * FUN_0012f41c(u32 *param_1)
{
  u32 uVar1;
  u32 *resource;
  int iVar3;
  Record *puVar2;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_003081f0);
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  DAT_00340284 = param_1;
  iVar3 = 0;
  puVar2 = DAT_0033b584;
  do {
    puVar2->w00 = 0;
    puVar2->w04 = 0;
    puVar2->w08 = 0;
    puVar2->w0c = 0;
    puVar2->b4a = 0;
    puVar2->w10 = 0;
    puVar2->w14 = 0;
    puVar2->w18 = 0;
    puVar2->b4b = 0;
    puVar2->b4c = 0;
    puVar2->b4e = 0;
    puVar2->b4f = 0;
    puVar2->w1c = 0;
    puVar2->b50 = 0;
    puVar2->h44 = 0;
    puVar2->h46 = 0;
    puVar2->b51 = 0;
    puVar2->w38 = 0;
    puVar2->h48 = 0;
    puVar2->b52 = 0;
    puVar2->w3c = 0;
    puVar2->b53 = 0;
    puVar2->w34 = 0;
    puVar2->b54 = 0;
    puVar2->b55 = 0;
    puVar2->b56 = 0;
    puVar2->b57 = 0;
    puVar2->w20 = 0;
    puVar2->w24 = 0;
    puVar2->w28 = 0;
    puVar2->w2c = 0;
    puVar2->w30 = 0;
    iVar3 = iVar3 + 1;
    puVar2->w40 = 1;
    puVar2++;
  } while (iVar3 < 0xe0);
  {
    int iVar3 = 0;
    float *puVar5 = (float *)param_1;
    int iVar4;
    do {
      iVar4 = iVar3;
      *(float *)((char *)puVar5 + 0x50) = 1.0f;
      *(float *)((char *)puVar5 + 0x54) = 1.0f;
      *(float *)((char *)puVar5 + 0x58) = 1.0f;
      *(float *)((char *)puVar5 + 0x5c) = 1.0f;
      iVar3 = iVar4 + 5;
      *(float *)((char *)puVar5 + 0x60) = 1.0f;
      puVar5 = puVar5 + 5;
    } while (iVar3 < 6);
    {
      int off = iVar3 * 4;
      *(float *)(off + (int)param_1 + 0x50) = 1.0f;
    }
  }
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(float *)((char *)param_1 + 0xcc) = 1.0f;
  param_1[0x24] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  *(float *)((char *)param_1 + 0xac) = 1.0f;
  param_1[0x34] = 0;
  param_1[0x11] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  *(float *)((char *)param_1 + 0xec) = 1.0f;
  *(u8 *)(param_1 + 0x3c) = 1;
  *(u8 *)(param_1 + 0x4d) = 0;
  *(u8 *)((int)param_1 + 0xf1) = 0;
  *(u8 *)((int)param_1 + 0xf2) = 0;
  *(u8 *)((int)param_1 + 0xf3) = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  *(float *)((char *)param_1 + 0x11c) = 1.0f;
  param_1[0x48] = 0xffffffff;
  param_1[0x49] = 0xffffffff;
  param_1[0xf] = 0;
  param_1[0x10] = 0xffffffff;
  param_1[0x12] = 0;
  *(u8 *)(param_1 + 0x13) = 1;
  param_1[0x4a] = 0;
  param_1[0x4b] = 1;
  param_1[0x4c] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  FUN_0012f698(param_1);
  resource = (u32 *)FUN_00000bcc(0x100);
  if (resource != 0) {
    resource = FUN_000b7e7c(resource);
  }
  param_1[0x1f] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x1f],1);
  resource = (u32 *)FUN_00000bcc(0xa0);
  if (resource != 0) {
    resource = FUN_00122888(resource);
  }
  param_1[0x20] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x20],0);
  resource = (u32 *)FUN_00000bcc(0x48);
  if (resource != 0) {
    resource = FUN_001b9760(resource);
  }
  param_1[0x21] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x21],0);
  return param_1;
}

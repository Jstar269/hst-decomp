/* HSTMATCH module=EBOOT.BIN start=0x0012f41c end=0x0012f698 symbol=FUN_0012f41c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

typedef struct Record {
  undefined4 w00;
  undefined4 w04;
  undefined4 w08;
  undefined4 w0c;
  undefined4 w10;
  undefined4 w14;
  undefined4 w18;
  undefined4 w1c;
  undefined4 w20;
  undefined4 w24;
  undefined4 w28;
  undefined4 w2c;
  undefined4 w30;
  undefined4 w34;
  undefined4 w38;
  undefined4 w3c;
  undefined4 w40;
  undefined2 h44;
  undefined2 h46;
  undefined2 h48;
  undefined1 b4a;
  undefined1 b4b;
  undefined1 b4c;
  undefined1 b4d;
  undefined1 b4e;
  undefined1 b4f;
  undefined1 b50;
  undefined1 b51;
  undefined1 b52;
  undefined1 b53;
  undefined1 b54;
  undefined1 b55;
  undefined1 b56;
  undefined1 b57;
} Record;

extern undefined DAT_003081f0;
extern Record DAT_0033b584[];
extern undefined4 * DAT_00340284;
extern void * FUN_00000bcc(unsigned int);
extern void FUN_0001f06c();
extern void FUN_0001f1fc(void *, int);
extern void FUN_0001f21c(void *, void *);
extern undefined4 * FUN_000b7e7c(void *);
extern undefined4 * FUN_00122888(void *);
extern undefined4 FUN_0012f698(void *);
extern undefined4 * FUN_001b9760(void *);

undefined4 * FUN_0012f41c(undefined4 *param_1)
{
  undefined4 uVar1;
  undefined4 *resource;
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
  *(undefined1 *)(param_1 + 0x3c) = 1;
  *(undefined1 *)(param_1 + 0x4d) = 0;
  *(undefined1 *)((int)param_1 + 0xf1) = 0;
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  *(undefined1 *)((int)param_1 + 0xf3) = 0;
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
  *(undefined1 *)(param_1 + 0x13) = 1;
  param_1[0x4a] = 0;
  param_1[0x4b] = 1;
  param_1[0x4c] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  FUN_0012f698(param_1);
  resource = (undefined4 *)FUN_00000bcc(0x100);
  if (resource != 0) {
    resource = FUN_000b7e7c(resource);
  }
  param_1[0x1f] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x1f],1);
  resource = (undefined4 *)FUN_00000bcc(0xa0);
  if (resource != 0) {
    resource = FUN_00122888(resource);
  }
  param_1[0x20] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x20],0);
  resource = (undefined4 *)FUN_00000bcc(0x48);
  if (resource != 0) {
    resource = FUN_001b9760(resource);
  }
  param_1[0x21] = (unsigned int)resource;
  FUN_0001f21c(param_1,resource);
  FUN_0001f1fc((void *)param_1[0x21],0);
  return param_1;
}

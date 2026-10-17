/* HSTMATCH module=hstp_trans_main.prx start=0x000579bc end=0x00057aac symbol=FUN_000579bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used a by-value empty tag for the third helper argument and a typed member address; exact match verified; names and types await human review. */
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

struct EmptyTag_000579bc {};
struct Obj_000579bc { char pad[0x174]; uint field174; };

extern "C" void * FUN_000114c0(void *,int,uint);
extern "C" void FUN_0005a2dc(void *,int);
extern "C" void FUN_0005a59c(void *,undefined4,EmptyTag_000579bc);

extern "C" void FUN_000579bc(int param_1)
{
  uint uVar2;
  int iVar1;
  
  *(undefined1 *)(param_1 + 0xec) = 1;
  uVar2 = 0;
  iVar1 = param_1;
  do {
    FUN_000114c0((void *)(iVar1 + 0xf0),0,0x34);
    *(undefined4 *)(iVar1 + 0xf0) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x100) = 0x3f800000;
    uVar2 = uVar2 + 1;
    *(undefined4 *)(iVar1 + 0x110) = 0xffffffff;
    iVar1 = iVar1 + 0x34;
  } while (uVar2 < 2);
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x16c) = 0;
  *(undefined1 *)(param_1 + 0x170) = 1;
  *(undefined1 *)(param_1 + 0x171) = 0;
  FUN_0005a59c(&((Obj_000579bc *)param_1)->field174,*(undefined4 *)(param_1 + 0x178),EmptyTag_000579bc());
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0x3f800000;
  *(undefined4 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined1 *)(param_1 + 0x1a8) = 1;
  if (*(uint *)(param_1 + 0xe8) < 4) {
    FUN_0005a2dc((void *)(param_1 + 0xe0),4);
  }
  return;
}

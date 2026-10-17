/* HSTMATCH module=hstp_trans_main.prx start=0x0006f80c end=0x0006f988 symbol=FUN_0006f80c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v15) corrected by hand: typed the float global and destinations and factored the indexed offset into Lookup; exact match verified; names and types await human review. */
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

extern float DAT_003daf70;
extern void FUN_0005b3a0();
extern void FUN_0005b3fc();

static inline int *Lookup(int base)
{
  int offset = *(int *)(base + 0x54) * 4;
  return (int *)(offset + base + 100);
}

void FUN_0006f80c(float param_1,float param_2,int param_3)
{
  float uVar1;
  int iVar2;
  
  if (*(int *)(param_3 + 4) != 0) {
    FUN_0005b3a0(*(int *)(param_3 + 4));
    uVar1 = DAT_003daf70;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x10) = -param_1;
    *(float *)(*Lookup(iVar2) + 0x14) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x18) = param_2;
    uVar1 = DAT_003daf70;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x2c) = param_1;
    *(float *)(*Lookup(iVar2) + 0x30) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x34) = param_2;
    uVar1 = DAT_003daf70;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 0x48) = -param_1;
    *(float *)(*Lookup(iVar2) + 0x4c) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x50) = -param_2;
    uVar1 = DAT_003daf70;
    iVar2 = *(int *)(param_3 + 4);
    *(float *)(*Lookup(iVar2) + 100) = param_1;
    *(float *)(*Lookup(iVar2) + 0x68) = uVar1;
    *(float *)(*Lookup(iVar2) + 0x6c) = -param_2;
    FUN_0005b3fc(*(undefined4 *)(param_3 + 4),4);
  }
  return;
}

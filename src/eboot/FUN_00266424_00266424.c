/* HSTMATCH module=EBOOT.BIN start=0x00266424 end=0x002664c0 symbol=FUN_00266424 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the final copied state field as float; exact match verified; names and types await human review. */
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

extern void FUN_00055044();
extern void FUN_00059174();
extern void FUN_0005f0d8();
extern float FUN_00128e40(float param_1,float param_2);
extern void FUN_00266818();
extern void FUN_0026694c();
extern void FUN_00266b1c();

void FUN_00266424(int param_1)
{
  int iVar1;
  float fVar2;
  
  FUN_0026694c(param_1);
  fVar2 = FUN_00128e40(*(float *)(param_1 + 0x164),*(float *)(param_1 + 0x168));
  *(float *)(param_1 + 0x164) = fVar2;
  FUN_00266b1c(param_1);
  iVar1 = *(int *)(param_1 + 0x70);
  FUN_00059174(iVar1);
  FUN_0005f0d8(iVar1);
  if (*(int *)(param_1 + 0x74) != 0) {
    FUN_00055044(*(int *)(param_1 + 0x74),(undefined4 *)(*(int *)(param_1 + 0x70) + 0x30));
    iVar1 = *(int *)(param_1 + 0x74);
    FUN_00059174(iVar1);
    FUN_0005f0d8(iVar1);
  }
  FUN_00266818(param_1);
  *(float *)(*(int *)(param_1 + 0x70) + 0x80) =
       *(float *)(*(int *)(param_1 + 0x70) + 0x104);
  return;
}

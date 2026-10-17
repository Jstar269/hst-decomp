/* HSTMATCH module=EBOOT.BIN start=0x00281128 end=0x00281238 symbol=FUN_00281128 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern undefined * DAT_003415a8;
extern uint * FUN_000149a8();
extern void FUN_0008d148();
extern uint * FUN_0008d388();
extern int FUN_000d7e30();
extern undefined8 FUN_001bc630(float param_1);
extern undefined2 * FUN_00259a1c();
extern void FUN_00281238();

void FUN_00281128(int param_1)
{
  float fVar1;
  undefined8 uVar2;
  uint auStack_c8 [50];
  uint auStack_190 [50];
  uint auStack_258 [50];
  
  FUN_00281238((undefined4 *)(param_1 + 0x4e8));
  FUN_0008d148((undefined1 *)(param_1 + 0x890));
  FUN_0008d388(auStack_c8,0,0,0,0,0,0);
  FUN_00259a1c((undefined2 *)(param_1 + 0x528),(undefined2 *)auStack_c8);
  FUN_000d7e30((int)auStack_c8,-1);
  FUN_0008d388(auStack_190,0,0,0,0,0,0);
  FUN_00259a1c((undefined2 *)(param_1 + 0x648),(undefined2 *)auStack_190);
  FUN_000d7e30((int)auStack_190,-1);
  FUN_0008d388(auStack_258,0,0,0,0,0,0);
  FUN_00259a1c((undefined2 *)(param_1 + 0x768),(undefined2 *)auStack_258);
  FUN_000d7e30((int)auStack_258,-1);
  FUN_000149a8((uint *)(param_1 + 0x5f4),(uint *)(DAT_003415a8 + 0x20));
  fVar1 = *(float *)(DAT_003415a8 + 0x1414);
  uVar2 = FUN_001bc630(fVar1);
  *(char *)(param_1 + 0x628) = (char)uVar2;
  *(float *)(param_1 + 0x624) = fVar1;
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x000ee44c end=0x000ee510 symbol=FUN_000ee44c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag exp-gen3, variant v8) corrected by hand: the hoisted index temporary inlined and the array base written first; exact match verified; names and types await human review. */
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

extern undefined DAT_002d6cbc;
extern undefined DAT_002d6cc0;
extern undefined DAT_00338b58;
extern undefined DAT_00338b5c;
extern undefined DAT_00338b60;
extern undefined DAT_00338b64;

void FUN_000ee44c(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 + param_4;
  *(int *)((int)&DAT_00338b58 + param_1 * 0x10) = iVar1 / 2;
  iVar2 = param_3 + param_5;
  *(int *)((int)&DAT_00338b5c + param_1 * 0x10) = iVar2 / 2;
  *(int *)((int)&DAT_00338b60 + param_1 * 0x10) = iVar1 / 2;
  *(int *)((int)&DAT_00338b64 + param_1 * 0x10) = iVar2 / 2;
  *(float *)(&DAT_002d6cbc + param_1 * 8) = (float)(param_4 - param_2) / 60.0f;
  *(float *)(&DAT_002d6cc0 + param_1 * 8) = (float)(param_5 - param_3) / 28.0f;
  return;
}

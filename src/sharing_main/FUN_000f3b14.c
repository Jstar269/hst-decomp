/* HSTMATCH module=hstp_trans_main.prx start=0x000f3b14 end=0x000f3bd8 symbol=FUN_000f3b14 lang=c99 */
/* Clone of src/eboot/FUN_000ee44c.c (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0037da94;
extern undefined DAT_0037da98;
extern undefined DAT_003e1e98;
extern undefined DAT_003e1e9c;
extern undefined DAT_003e1ea0;
extern undefined DAT_003e1ea4;

void FUN_000f3b14(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 + param_4;
  *(int *)((int)&DAT_003e1e98 + param_1 * 0x10) = iVar1 / 2;
  iVar2 = param_3 + param_5;
  *(int *)((int)&DAT_003e1e9c + param_1 * 0x10) = iVar2 / 2;
  *(int *)((int)&DAT_003e1ea0 + param_1 * 0x10) = iVar1 / 2;
  *(int *)((int)&DAT_003e1ea4 + param_1 * 0x10) = iVar2 / 2;
  *(float *)(&DAT_0037da94 + param_1 * 8) = (float)(param_4 - param_2) / 60.0f;
  *(float *)(&DAT_0037da98 + param_1 * 8) = (float)(param_5 - param_3) / 28.0f;
  return;
}

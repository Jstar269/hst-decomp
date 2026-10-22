/* HSTMATCH module=EBOOT.BIN start=0x001c1ff8 end=0x001c2118 symbol=FUN_001c1ff8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_001c1ff8) corrected by hand: swapped the declaration order of the loop counter and pointer; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern uint * FUN_000114c0();

void FUN_001c1ff8(undefined1 *param_1)
{
  int iVar2;
  undefined1 *puVar1;
  
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 2;
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x10] = 0;
  param_1[0x14] = 0;
  iVar2 = 0;
  puVar1 = param_1;
  do {
    puVar1[0xe0] = 0;
    puVar1[0xe3] = 0;
    puVar1[0xe1] = 0;
    puVar1[0x105] = 0;
    puVar1[0x106] = 0;
    puVar1[0x107] = 0;
    puVar1[0x108] = 0;
    *(undefined4 *)(puVar1 + 0x10c) = 0xffffffff;
    *(undefined4 *)(puVar1 + 0x110) = 0xffffffff;
    *(undefined4 *)(puVar1 + 0x114) = 0x40a00000;
    puVar1[0x118] = 10;
    puVar1[0x119] = 0;
    *(undefined4 *)(puVar1 + 0x11c) = 0;
    puVar1[0xe4] = 0xe3;
    puVar1[0xe5] = 0x81;
    puVar1[0xe6] = 0xbf;
    puVar1[0xe7] = 0xe3;
    puVar1[0xe8] = 0x82;
    puVar1[0xe9] = 0x93;
    puVar1[0xea] = 0xe3;
    puVar1[0xeb] = 0x83;
    puVar1[0xec] = 0x86;
    puVar1[0xed] = 0xe3;
    puVar1[0xee] = 0x83;
    puVar1[0xef] = 0x8b;
    iVar2 = iVar2 + 1;
    puVar1[0xf0] = 0x50;
    puVar1 = puVar1 + 0x120;
  } while (iVar2 < 4);
  param_1[0x498] = 0;
  param_1[0x499] = 0;
  FUN_000114c0(param_1 + 0x49c,0,0x6c);
  *(undefined2 *)(param_1 + 0x504) = 0xffff;
  *(undefined2 *)(param_1 + 0x506) = 0xffff;
  *(undefined2 *)(param_1 + 0x4c0) = 0xffff;
  return;
}

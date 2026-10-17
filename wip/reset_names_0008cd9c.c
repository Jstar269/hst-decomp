/* HSTMATCH module=EBOOT.BIN start=0x0008cd9c end=0x0008cea4 symbol=FUN_0008cd9c lang=c99 */
// Near miss (7 words): the three trailing halfword stores. Retail: `li v1,-1; sh 4cc; lui a0; sh 4ce; addiu a0; li a1,1252; jal 0x8cae8; sh v1,0x488(s0)`
// (-1 in v1, last store in the delay slot, arg setup interleaved early). Ours: -1 in v0, stores 4cc/4ce/488 packed before `lui a0`, `li a1` in the delay slot.
// Fixed: loop locals declared `uint uVar2; int iVar1;` (counter t7, pointer t6 like retail; Ghidra's order swapped them).
// Ruled out: all 6 store orders, `short m = -1` local, short* base for the sub-struct, C++ with `extern "C" f(...)` stubs, store inside the call's argument list (comma),
//   args as locals, call result returned. Using the memset result as the store base (`q = memset(..); sh 0x68(q)`) gives retail's `li v1,-1` (v0 kept busy) but
//   v0-relative stores (6 words), so retail's v0 occupancy / late delay-slot store is unexplained.
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern char DAT_002beac0[];
extern uint * FUN_000114c0();
extern void FUN_0008cae8();
extern void FUN_002b7898();

void FUN_0008cd9c(int param_1)
{
  uint uVar2;
  int iVar1;
  
  FUN_000114c0(param_1,0,0x4e4);
  uVar2 = 0;
  iVar1 = param_1;
  do {
    *(undefined1 *)(iVar1 + 0x15c) = 0;
    *(undefined4 *)(iVar1 + 0x180) = 0x40a00000;
    *(undefined1 *)(iVar1 + 0x184) = 10;
    *(undefined1 *)(iVar1 + 0x185) = 0;
    *(undefined1 *)(iVar1 + 0x15d) = 0xe3;
    *(undefined1 *)(iVar1 + 0x15e) = 0x81;
    *(undefined1 *)(iVar1 + 0x15f) = 0xbf;
    *(undefined1 *)(iVar1 + 0x160) = 0xe3;
    *(undefined1 *)(iVar1 + 0x161) = 0x82;
    *(undefined1 *)(iVar1 + 0x162) = 0x93;
    *(undefined1 *)(iVar1 + 0x163) = 0xe3;
    *(undefined1 *)(iVar1 + 0x164) = 0x83;
    *(undefined1 *)(iVar1 + 0x165) = 0x86;
    *(undefined1 *)(iVar1 + 0x166) = 0xe3;
    *(undefined1 *)(iVar1 + 0x167) = 0x83;
    *(undefined1 *)(iVar1 + 0x168) = 0x8b;
    *(undefined1 *)(iVar1 + 0x169) = 0x50;
    uVar2 = uVar2 + 1;
    *(undefined1 *)(iVar1 + 0x15d) = 0;
    iVar1 = iVar1 + 0xf4;
  } while (uVar2 < 4);
  FUN_002b7898(param_1 + 0x10);
  FUN_000114c0(param_1 + 0x58,0,0x1c);
  *(undefined4 *)(param_1 + 0x60) = 1;
  FUN_000114c0(param_1 + 0x464,0,0x6c);
  *(undefined2 *)(param_1 + 0x4cc) = 0xffff;
  *(undefined2 *)(param_1 + 0x4ce) = 0xffff;
  *(undefined2 *)(param_1 + 0x488) = 0xffff;
  FUN_0008cae8(DAT_002beac0,0x4e4);
  return;
}

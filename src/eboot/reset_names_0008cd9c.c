/* HSTMATCH module=EBOOT.BIN start=0x0008cd9c end=0x0008cea4 symbol=FUN_0008cd9c lang=c99 helpers=FUN_0008cae8@0x0008cae8-0x0008cb14 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/reset_names_0008cd9c.c, completed with its same-file static helper FUN_0008cae8 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
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
extern uint * FUN_000114c0(void *, int, uint);
static void FUN_0008cae8(...)
{
}
extern void FUN_002b7898(void *);

void FUN_0008cd9c(char *param_1)
{
  uint uVar2;
  char *iVar1;
  
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

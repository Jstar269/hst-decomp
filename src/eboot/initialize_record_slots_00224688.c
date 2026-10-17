/* HSTMATCH module=EBOOT.BIN start=0x00224688 end=0x00224738 symbol=FUN_00224688 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the loop counter before the cursor; exact match verified; names and types await human review. */
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

extern void FUN_00224738();
extern void FUN_00224830();

void FUN_00224688(int param_1)
{
  int iVar2;
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 2;
  FUN_00224738(param_1,*(undefined4 *)(param_1 + 0x90));
  *(undefined1 *)(param_1 + 0x118) = 0;
  iVar2 = 0;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x98) = 0;
    *(undefined4 *)(iVar1 + 0xd8) = 0;
    *(undefined4 *)(iVar1 + 0x9c) = 0;
    *(undefined4 *)(iVar1 + 0xdc) = 0;
    *(undefined4 *)(iVar1 + 0xa0) = 0;
    *(undefined4 *)(iVar1 + 0xe0) = 0;
    *(undefined4 *)(iVar1 + 0xa4) = 0;
    *(undefined4 *)(iVar1 + 0xe4) = 0;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    *(undefined4 *)(iVar1 + 0xe8) = 0;
    *(undefined4 *)(iVar1 + 0xac) = 0;
    *(undefined4 *)(iVar1 + 0xec) = 0;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0xf0) = 0;
    *(undefined4 *)(iVar1 + 0xb4) = 0;
    iVar2 = iVar2 + 8;
    *(undefined4 *)(iVar1 + 0xf4) = 0;
    iVar1 = iVar1 + 0x20;
  } while (iVar2 < 0x10);
  *(undefined4 *)(param_1 + 0x98) = 0x42480000;
  *(undefined4 *)(param_1 + 0xd8) = 0x42480000;
  *(undefined4 *)(param_1 + 0x9c) = 0x43700000;
  *(undefined4 *)(param_1 + 0xdc) = 0x42480000;
  FUN_00224830(param_1);
  return;
}

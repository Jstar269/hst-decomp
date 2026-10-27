/* HSTMATCH module=EBOOT.BIN start=0x002b2e3c end=0x002b2ec8 symbol=FUN_002b2e3c lang=c99 data=0x0030308c */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: typed the global and helper argument as float; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0030308c-0x003030ac) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern float DAT_00302e20;
extern void FUN_00103540(float, int);
extern void FUN_001037c8();
extern void FUN_00104118();

void FUN_002b2e3c(int param_1)
{
  int iVar1;
  
  FUN_00104118(param_1 + 0x3c,"data/menu/npc_list/npc_list.lay",0);
  FUN_001037c8(param_1 + 0x3c,0xfffffffe);
  FUN_00103540(DAT_00302e20,param_1 + 0x3c);
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x110) = 0;
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x118) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
    iVar1 = iVar1 + 5;
    *(undefined4 *)(param_1 + 0x148) = 0;
    param_1 = param_1 + 0x14;
  } while (iVar1 < 10);
  return;
}

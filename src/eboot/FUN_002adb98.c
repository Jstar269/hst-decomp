/* HSTMATCH module=EBOOT.BIN start=0x002adb98 end=0x002adc74 symbol=FUN_002adb98 lang=c99 data=0x00302c98 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256b); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00302c98-0x00302ceb) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern void FUN_002adc74();
extern void FUN_002adda0();
extern int FUN_002b7d18();
extern int FUN_002b7ee8();

undefined4 * FUN_002adb98(undefined4 *param_1)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,0x80);
  *param_1 = 0;
  iVar1 = FUN_002b7ee8(param_1 + 1);
  if (iVar1 == 0) {
    FUN_002adda0(param_1 + 1);
  }
  else {
    FUN_002adc74("ERROR: sceOpenPSIDGetOpenPSID(): 0x%08x\n",iVar1);
  }
  iVar1 = FUN_002b7d18(param_1 + 6);
  if (iVar1 != 0) {
    FUN_002adc74("ERROR: sceRtcGetCurrentTick(): 0x%08x\n",iVar1);
  }
  *(undefined1 *)(param_1 + 8) = 0xe3;
  *(undefined1 *)((int)param_1 + 0x21) = 0x81;
  *(undefined1 *)((int)param_1 + 0x22) = 0xbf;
  *(undefined1 *)((int)param_1 + 0x23) = 0xe3;
  *(undefined1 *)(param_1 + 9) = 0x82;
  *(undefined1 *)((int)param_1 + 0x25) = 0x93;
  *(undefined1 *)((int)param_1 + 0x26) = 0xe3;
  *(undefined1 *)((int)param_1 + 0x27) = 0x83;
  *(undefined1 *)(param_1 + 10) = 0x86;
  *(undefined1 *)((int)param_1 + 0x29) = 0xe3;
  *(undefined1 *)((int)param_1 + 0x2a) = 0x83;
  *(undefined1 *)((int)param_1 + 0x2b) = 0x8b;
  *(undefined1 *)(param_1 + 0xb) = 0x50;
  return param_1;
}

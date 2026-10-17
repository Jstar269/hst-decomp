/* HSTMATCH module=EBOOT.BIN start=0x002a69d0 end=0x002a6a40 symbol=FUN_002a69d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined DAT_00300af4;
extern undefined4 DAT_0034b354;
extern void FUN_0010b8cc();
extern void FUN_00110a78();
extern undefined * FUN_001fea10();

void FUN_002a69d0(int param_1,int param_2)
{
  undefined4 uVar1;
  
  FUN_0010b8cc(*(undefined4 *)(param_1 + 0x178),param_2,0);
  if (DAT_0034b354 != 0) {
    uVar1 = (unsigned int)(FUN_001fea10(0x12,0x31,*(undefined4 *)(&DAT_00300af4 + param_2 * 4)));
    FUN_00110a78(DAT_0034b354,uVar1,0);
  }
  return;
}

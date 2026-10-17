/* HSTMATCH module=EBOOT.BIN start=0x001541b0 end=0x00154208 symbol=FUN_001541b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003402f0 is an unsigned char flag (lbu); exact match verified; names and types await human review. */
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

extern unsigned char DAT_003402f0;
extern undefined4 DAT_0034a114;
extern char DAT_002dc870[];
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001c7df0();

undefined4 FUN_001541b0(int param_1,undefined4 param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc870,*(undefined4 *)(param_1 + 8));
  }
  FUN_001c7df0(DAT_0034a114,*(undefined4 *)(param_1 + 8));
  return 0;
}

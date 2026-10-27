/* HSTMATCH module=EBOOT.BIN start=0x0015194c end=0x001519b4 symbol=FUN_0015194c lang=c99 data=0x002dc554 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc554-0x002dc568) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined DAT_003402f0;
extern undefined4 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cc7d0();

undefined4 FUN_0015194c(int param_1,undefined4 param_2)
{
  FUN_001cc7d0(DAT_0034a114,*(undefined4 *)(param_1 + 8));
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("Request Event [%s]\n",*(undefined4 *)(param_1 + 8));
  }
  return 0;
}

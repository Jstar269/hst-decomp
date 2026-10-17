/* HSTMATCH module=EBOOT.BIN start=0x001dd21c end=0x001dd260 symbol=FUN_001dd21c lang=c99 */
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

extern void FUN_00103480();
extern void FUN_001ea8dc();
extern void FUN_001ea930();
extern void FUN_001eaa00();

void FUN_001dd21c(int param_1)
{
  FUN_00103480();
  FUN_001ea930(*(undefined4 *)(param_1 + 0x8c),0);
  FUN_001eaa00(*(undefined4 *)(param_1 + 0x8c),0);
  FUN_001ea8dc(*(undefined4 *)(param_1 + 0x8c));
  return;
}

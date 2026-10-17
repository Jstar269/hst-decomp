/* HSTMATCH module=EBOOT.BIN start=0x001ec2f8 end=0x001ec35c symbol=FUN_001ec2f8 lang=c99 */
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

extern undefined4 DAT_0034a138;
extern void FUN_001ec3b8();
extern void FUN_001ec564();

undefined4 * FUN_001ec2f8(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  DAT_0034a138 = (unsigned int)(param_1);
  FUN_001ec3b8();
  FUN_001ec564(param_1,0xb,0);
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[5] = 0;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  return param_1;
}

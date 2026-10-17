/* HSTMATCH module=hstp_trans_main.prx start=0x000577ec end=0x00057840 symbol=FUN_000577ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003b02c4;
extern void FUN_000579bc();
extern undefined4 * FUN_0005f898();

undefined4 * FUN_000577ec(undefined4 *param_1)
{
  FUN_0005f898();
  *param_1 = (unsigned int)(&DAT_003b02c4);
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_000579bc(param_1);
  return param_1;
}

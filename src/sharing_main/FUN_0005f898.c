/* HSTMATCH module=hstp_trans_main.prx start=0x0005f898 end=0x0005f8ec symbol=FUN_0005f898 lang=c99 */
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

extern undefined DAT_003b0318;
extern undefined4 * FUN_000559f4();
extern void FUN_0005f988();

undefined4 * FUN_0005f898(undefined4 *param_1)
{
  FUN_000559f4();
  *param_1 = (unsigned int)(&DAT_003b0318);
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  FUN_0005f988(param_1);
  return param_1;
}

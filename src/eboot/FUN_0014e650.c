/* HSTMATCH module=EBOOT.BIN start=0x0014e650 end=0x0014e698 symbol=FUN_0014e650 lang=c99 */
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

extern undefined DAT_0030829c;
extern undefined DAT_0030840c;
extern undefined2 FUN_0014f050();

undefined4 * FUN_0014e650(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_0030829c);
  FUN_0014f050(param_2);
  return param_1;
}

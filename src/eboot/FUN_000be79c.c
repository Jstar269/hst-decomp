/* HSTMATCH module=EBOOT.BIN start=0x000be79c end=0x000be7b4 symbol=FUN_000be79c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern undefined DAT_003073cc;

undefined4 * FUN_000be79c(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003073cc);
  param_1[6] = 0;
  return param_1;
}

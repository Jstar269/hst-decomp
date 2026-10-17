/* HSTMATCH module=EBOOT.BIN start=0x000dac88 end=0x000dacc0 symbol=FUN_000dac88 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 * FUN_000dacc0();

undefined2 * FUN_000dac88(undefined2 *param_1,undefined2 *param_2)
{
  *param_1 = *param_2;
  FUN_000dacc0(param_1 + 2,param_2 + 2);
  return param_1;
}

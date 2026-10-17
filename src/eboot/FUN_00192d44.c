/* HSTMATCH module=EBOOT.BIN start=0x00192d44 end=0x00192d8c symbol=FUN_00192d44 lang=c99 */
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

extern undefined4 * FUN_00192b7c();
extern undefined4 * FUN_00192fb8();

undefined4 * FUN_00192d44(undefined4 *param_1)
{
  FUN_00192fb8(param_1 + 1);
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_00192b7c(param_1 + 8);
  FUN_00192b7c(param_1 + 0x2c);
  *param_1 = 0;
  return param_1;
}

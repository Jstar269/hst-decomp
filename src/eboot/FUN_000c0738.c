/* HSTMATCH module=EBOOT.BIN start=0x000c0738 end=0x000c07b8 symbol=FUN_000c0738 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the flag global typed as a byte; exact match verified; names and types await human review. */
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

extern undefined DAT_00307408;
extern undefined DAT_00338acc;
extern undefined4 DAT_00338ad0;
extern undefined4 * FUN_0001f06c();

undefined4 * FUN_000c0738(undefined4 *param_1)
{
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00307408);
  param_1[0x1dc] = 0;
  param_1[0x1dd] = 0;
  param_1[0x1de] = 0;
  param_1[0x1df] = 0;
  param_1[0x1e0] = 0;
  param_1[0x1e1] = 0;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  param_1[0x1a5] = 0;
  DAT_00338acc = 0;
  DAT_00338ad0 = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  param_1[0x1cb] = 0;
  param_1[0x1db] = 0;
  param_1[0x1e2] = 0;
  param_1[0x1e3] = 0;
  return param_1;
}

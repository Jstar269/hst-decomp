/* HSTMATCH module=EBOOT.BIN start=0x000f78ac end=0x000f7950 symbol=FUN_000f78ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the if/else flag store is a single store of a bool local (r = DAT == 0x2a; if (r) r = f() != 0), callee returns int; exact match verified; names and types await human review. */
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

extern undefined DAT_0030777c;
extern undefined4 DAT_0034a678;
extern undefined4 * FUN_00102e38();
extern int FUN_0022c860();

undefined4 * FUN_000f78ac(undefined4 *param_1)
{
  int r;
  
  FUN_00102e38();
  *param_1 = (unsigned int)(&DAT_0030777c);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  r = DAT_0034a678 == 0x2a;
  if (r) {
    r = FUN_0022c860() != 0;
  }
  *(unsigned char *)((int)param_1 + 0x156) = r;
  return param_1;
}

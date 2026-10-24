/* HSTMATCH module=EBOOT.BIN start=0x0008d148 end=0x0008d1ec symbol=FUN_0008d148 lang=c99 helpers=FUN_0008cae8@0x0008cae8-0x0008cb14 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0008d148.c) corrected by hand: FUN_0008cae8 is the empty variadic log stub, defined static in front and placed by helpers= (this is what moves the shared -1 into v1); the three halfword stores write -1; exact match verified; names and types await human review. */
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

extern char DAT_002beaa8[];
extern void FUN_000114c0(void *, int, int);
static void FUN_0008cae8(...) { }

void FUN_0008d148(undefined1 *param_1)
{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 1;
  param_1[0x22] = 2;
  param_1[0x23] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x30] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  FUN_000114c0(param_1 + 0x38,0,0x6c);
  *(short *)(param_1 + 0xa0) = -1;
  *(short *)(param_1 + 0xa2) = -1;
  *(short *)(param_1 + 0x5c) = -1;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  FUN_0008cae8(DAT_002beaa8);
  return;
}

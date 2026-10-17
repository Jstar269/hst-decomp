/* HSTMATCH module=EBOOT.BIN start=0x0008d2ec end=0x0008d388 symbol=FUN_0008d2ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;


void FUN_0008d2ec(int param_1)
{
  *(undefined1 *)(param_1 + 200) = 0;
  *(undefined1 *)(param_1 + 0xcb) = 0;
  *(undefined1 *)(param_1 + 0xc9) = 0;
  *(undefined1 *)(param_1 + 0xed) = 0;
  *(undefined1 *)(param_1 + 0xee) = 0;
  *(undefined1 *)(param_1 + 0xef) = 0;
  *(undefined1 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xfc) = 0x40a00000;
  *(undefined1 *)(param_1 + 0x100) = 10;
  *(undefined1 *)(param_1 + 0x101) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined1 *)(param_1 + 0xcc) = 0xe3;
  *(undefined1 *)(param_1 + 0xcd) = 0x81;
  *(undefined1 *)(param_1 + 0xce) = 0xbf;
  *(undefined1 *)(param_1 + 0xcf) = 0xe3;
  *(undefined1 *)(param_1 + 0xd0) = 0x82;
  *(undefined1 *)(param_1 + 0xd1) = 0x93;
  *(undefined1 *)(param_1 + 0xd2) = 0xe3;
  *(undefined1 *)(param_1 + 0xd3) = 0x83;
  *(undefined1 *)(param_1 + 0xd4) = 0x86;
  *(undefined1 *)(param_1 + 0xd5) = 0xe3;
  *(undefined1 *)(param_1 + 0xd6) = 0x83;
  *(undefined1 *)(param_1 + 0xd7) = 0x8b;
  *(undefined1 *)(param_1 + 0xd8) = 0x50;
  return;
}

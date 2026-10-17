/* HSTMATCH module=hstp_trans_main.prx start=0x0011398c end=0x00113a50 symbol=FUN_0011398c lang=c99 */
/* Clone of src/eboot/FUN_0010d3e4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern uint * FUN_000114c0();

void FUN_0011398c(int param_1)
{
  *(undefined4 *)(param_1 + 0x148) = 0x47c35040;
  FUN_000114c0(param_1 + 0xd0,0,0x28);
  *(undefined4 *)(param_1 + 0xdc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xe0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined2 *)(param_1 + 0xfc) = 0;
  *(undefined2 *)(param_1 + 0xfe) = 0;
  *(undefined2 *)(param_1 + 0x100) = 0;
  *(undefined2 *)(param_1 + 0x102) = 0;
  *(undefined2 *)(param_1 + 0x104) = 0xffff;
  *(undefined4 *)(param_1 + 0x108) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x10c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x110) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x114) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x118) = 0x80808080;
  *(undefined4 *)(param_1 + 0x120) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x124) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x128) = 0x3f800000;
  *(undefined4 *)(param_1 + 300) = 0x3f800000;
  *(undefined2 *)(param_1 + 0x130) = 0;
  *(undefined2 *)(param_1 + 0x132) = 0;
  *(undefined2 *)(param_1 + 0x134) = 0x1e0;
  *(undefined2 *)(param_1 + 0x136) = 0x110;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined1 *)(param_1 + 0x144) = 0;
  *(undefined1 *)(param_1 + 0x145) = 0;
  *(undefined1 *)(param_1 + 0x14c) = 0;
  *(undefined1 *)(param_1 + 0x14d) = 0;
  return;
}

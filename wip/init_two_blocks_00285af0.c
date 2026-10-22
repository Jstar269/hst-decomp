/* HSTMATCH module=EBOOT.BIN start=0x00285af0 end=0x00285c14 symbol=FUN_00285af0 lang=c99 */
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

extern char DAT_002beaa8[];
extern uint * FUN_000114c0();
extern void FUN_002803d8();

undefined1 * FUN_00285af0(undefined1 *param_1)
{
  FUN_000114c0(param_1 + 0x20,0,0x14);
  param_1[0x20] = 0;
  param_1[0x21] = 1;
  param_1[0x22] = 2;
  param_1[0x23] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x30] = 0;
  FUN_000114c0(param_1 + 0x34,0);
  param_1[0x34] = 0;
  FUN_000114c0(param_1 + 0x35,0,3);
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  FUN_000114c0(param_1 + 0x38,0,0x6c);
  *(undefined2 *)(param_1 + 0xa0) = 0xffff;
  *(undefined2 *)(param_1 + 0xa2) = 0xffff;
  *(undefined2 *)(param_1 + 0x5c) = 0xffff;
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
  *(undefined2 *)(param_1 + 0xa0) = 0xffff;
  *(undefined2 *)(param_1 + 0xa2) = 0xffff;
  *(undefined2 *)(param_1 + 0x5c) = 0xffff;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  FUN_002803d8(DAT_002beaa8);
  return param_1;
}
// near miss from lane od3 (unreviewed)

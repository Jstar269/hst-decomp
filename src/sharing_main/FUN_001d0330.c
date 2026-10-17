/* HSTMATCH module=hstp_trans_main.prx start=0x001d0330 end=0x001d0468 symbol=FUN_001d0330 lang=c99 */
/* Clone of src/eboot/FUN_001c2118.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern void FUN_0008ed94();
extern undefined2 * FUN_0008ede8();
extern void FUN_000dbb60();

int FUN_001d0330(int param_1)
{
  FUN_0008ede8();
  FUN_000114c0(param_1,0,200);
  FUN_0008ed94(param_1,0,0);
  FUN_0008ed94(param_1,1,0);
  FUN_0008ed94(param_1,2,0);
  FUN_0008ed94(param_1,3,0);
  FUN_0008ed94(param_1,4,0);
  FUN_0008ed94(param_1,5,0);
  FUN_000dbb60(param_1);
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
  return param_1;
}

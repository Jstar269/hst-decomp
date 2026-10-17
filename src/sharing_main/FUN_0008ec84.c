/* HSTMATCH module=hstp_trans_main.prx start=0x0008ec84 end=0x0008ed94 symbol=FUN_0008ec84 lang=c99 */
/* Clone of src/eboot/FUN_0008d530.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

int FUN_0008ec84(int param_1)
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
  *(undefined4 *)(param_1 + 0xec) = 0x40a00000;
  *(undefined1 *)(param_1 + 0xf0) = 10;
  *(undefined1 *)(param_1 + 0xf1) = 0;
  *(undefined1 *)(param_1 + 0xc9) = 0xe3;
  *(undefined1 *)(param_1 + 0xca) = 0x81;
  *(undefined1 *)(param_1 + 0xcb) = 0xbf;
  *(undefined1 *)(param_1 + 0xcc) = 0xe3;
  *(undefined1 *)(param_1 + 0xcd) = 0x82;
  *(undefined1 *)(param_1 + 0xce) = 0x93;
  *(undefined1 *)(param_1 + 0xcf) = 0xe3;
  *(undefined1 *)(param_1 + 0xd0) = 0x83;
  *(undefined1 *)(param_1 + 0xd1) = 0x86;
  *(undefined1 *)(param_1 + 0xd2) = 0xe3;
  *(undefined1 *)(param_1 + 0xd3) = 0x83;
  *(undefined1 *)(param_1 + 0xd4) = 0x8b;
  *(undefined1 *)(param_1 + 0xd5) = 0x50;
  return param_1;
}

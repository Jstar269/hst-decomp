/* HSTMATCH module=hstp_trans_main.prx start=0x000c4bd4 end=0x000c4c80 symbol=FUN_000c4bd4 lang=c99 */
/* Clone of src/eboot/FUN_000c1534.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern uint * FUN_000149a8();

void FUN_000c4bd4(int param_1)
{
  FUN_000149a8(param_1 + 0x114,*(undefined4 *)(param_1 + 0x80));
  FUN_000149a8(param_1 + 0x194,*(undefined4 *)(param_1 + 0x84));
  FUN_000149a8(param_1 + 0x214,*(undefined4 *)(param_1 + 0x88));
  *(char *)(param_1 + 0x614) = (char)*(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x618) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_1 + 0x61c) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x620) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x638) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x63c) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x640) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x628) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x62c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x630) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x650) = *(undefined4 *)(param_1 + 100);
  return;
}

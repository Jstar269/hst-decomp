/* HSTMATCH module=hstp_trans_main.prx start=0x000fb4c0 end=0x000fb514 symbol=FUN_000fb4c0 lang=c99 */
/* Clone of src/eboot/FUN_000f5dcc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_000fb4c0(int param_1)
{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(param_1 + 0xa0) = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0x10;
    *(undefined4 *)(param_1 + 0xa8) = 0;
    *(undefined4 *)(param_1 + 0xac) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0x3f800000;
    uVar1 = uVar1 + 1;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    param_1 = param_1 + 0x40;
  } while (uVar1 < 0x10);
  return;
}

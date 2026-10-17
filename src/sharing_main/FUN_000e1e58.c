/* HSTMATCH module=hstp_trans_main.prx start=0x000e1e58 end=0x000e1e94 symbol=FUN_000e1e58 lang=c99 */
/* Clone of src/eboot/FUN_000ddc6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003e19f0;

void FUN_000e1e58(int param_1)
{
  *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x54) =
       *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x54) + *(int *)(param_1 + 0xc4);
  *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x58) =
       *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x58) + *(int *)(param_1 + 200);
  return;
}

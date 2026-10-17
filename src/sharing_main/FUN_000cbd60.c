/* HSTMATCH module=hstp_trans_main.prx start=0x000cbd60 end=0x000cbd8c symbol=FUN_000cbd60 lang=c99 */
/* Clone of src/eboot/FUN_000c81c0.c (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000d2328();

undefined4 FUN_000cbd60(int param_1)
{
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_000d2328(*(int *)(param_1 + 0x44));
  }
  return 1;
}

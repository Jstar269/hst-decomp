/* HSTMATCH module=hstp_trans_main.prx start=0x0013a948 end=0x0013a96c symbol=FUN_0013a948 lang=c99 */
/* Clone of src/eboot/FUN_0012f3f0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern void FUN_0013a7a0();

void FUN_0013a948(int param_1)
{
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x7c);
  FUN_0013a7a0();
  return;
}

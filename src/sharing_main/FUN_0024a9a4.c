/* HSTMATCH module=hstp_trans_main.prx start=0x0024a9a4 end=0x0024a9c8 symbol=FUN_0024a9a4 lang=c99 */
/* Clone of src/eboot/FUN_0023a80c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f39ec;

bool FUN_0024a9a4(int param_1)
{
  return (*(int *)(param_1 + 0x1850) / *(int *)(DAT_003f39ec + 0x18b8) & 1U) != 0;
}

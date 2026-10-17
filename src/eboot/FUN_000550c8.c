/* HSTMATCH module=EBOOT.BIN start=0x000550c8 end=0x000550ec symbol=FUN_000550c8 lang=c99 */
/* Clone of src/eboot/FUN_0012c7b4.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_000550c8(int param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 0x60) = *param_2;
  *(undefined4 *)(param_1 + 100) = param_2[1];
  *(undefined4 *)(param_1 + 0x68) = param_2[2];
  *(undefined4 *)(param_1 + 0x6c) = param_2[3];
  return;
}

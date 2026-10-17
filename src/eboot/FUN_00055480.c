/* HSTMATCH module=EBOOT.BIN start=0x00055480 end=0x0005548c symbol=FUN_00055480 lang=c99 */
/* Clone of src/sharing_main/FUN_00055fd0.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_00055480(int param_1)
{
  return *(undefined4 *)(*(int *)(param_1 + 0x8c) + 0xc);
}

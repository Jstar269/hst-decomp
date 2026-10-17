/* HSTMATCH module=hstp_trans_main.prx start=0x0022c934 end=0x0022c96c symbol=FUN_0022c934 lang=c99 */
/* Clone of src/eboot/FUN_0021b79c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();

void FUN_0022c934(int param_1)
{
  FUN_00108f54(param_1,1);
  *(undefined1 *)(param_1 + 0x54) = 1;
  *(undefined4 *)(param_1 + 100) = 0xffffffff;
  return;
}

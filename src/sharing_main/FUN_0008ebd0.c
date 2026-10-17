/* HSTMATCH module=hstp_trans_main.prx start=0x0008ebd0 end=0x0008ec34 symbol=FUN_0008ebd0 lang=c99 */
/* Clone of src/eboot/FUN_0008d47c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000007f4();
extern uint * FUN_000114c0();
extern void FUN_0008ec34();
extern void FUN_0008ec84();

int FUN_0008ebd0(int param_1)
{
  FUN_000007f4(param_1 + 0x94,FUN_0008ec84,FUN_0008ec34,0xf4,4);
  FUN_000114c0(param_1 + 0x464,0,0x6c);
  *(undefined2 *)(param_1 + 0x4cc) = 0xffff;
  *(undefined2 *)(param_1 + 0x4ce) = 0xffff;
  *(undefined2 *)(param_1 + 0x488) = 0xffff;
  return param_1;
}

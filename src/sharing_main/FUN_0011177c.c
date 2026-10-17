/* HSTMATCH module=hstp_trans_main.prx start=0x0011177c end=0x001117ec symbol=FUN_0011177c lang=c99 */
/* Clone of src/eboot/FUN_0010b5a4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00110f78();
extern void FUN_00111474();

void FUN_0011177c(int param_1)
{
  FUN_00111474(param_1,0);
  *(undefined2 *)(param_1 + 0xec) =
       *(undefined2 *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0xdc) * 0xc);
  *(undefined2 *)(param_1 + 0xee) =
       *(undefined2 *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0xdc) * 0xc + 2);
  FUN_00110f78(param_1);
  return;
}

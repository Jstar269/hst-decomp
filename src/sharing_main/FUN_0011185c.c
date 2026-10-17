/* HSTMATCH module=hstp_trans_main.prx start=0x0011185c end=0x001118ac symbol=FUN_0011185c lang=c99 */
/* Clone of src/eboot/FUN_0010b684.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00110f78();
extern void FUN_00111474();

void FUN_0011185c(int param_1,undefined4 param_2,undefined1 param_3)
{
  FUN_00111474(param_1,0);
  *(undefined1 *)(param_1 + 0x114) = param_3;
  *(undefined4 *)(param_1 + 0x118) = param_2;
  FUN_00110f78(param_1);
  return;
}

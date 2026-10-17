/* HSTMATCH module=hstp_trans_main.prx start=0x000f786c end=0x000f78b8 symbol=FUN_000f786c lang=c99 */
/* Clone of src/eboot/FUN_000f21a4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000f78b8();
extern void FUN_00116fd4();

void FUN_000f786c(int param_1)
{
  if (*(uchar *)(param_1 + 0x84) != '\0') {
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x80) = 1;
    FUN_00116fd4(*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x78));
    FUN_000f78b8(param_1);
  }
  return;
}

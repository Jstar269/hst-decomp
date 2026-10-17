/* HSTMATCH module=EBOOT.BIN start=0x00062990 end=0x000629c4 symbol=FUN_00062990 lang=c99 */
/* Clone of src/sharing_main/FUN_00063854.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00062a44();
extern void FUN_0007658c();

void FUN_00062990(int param_1)
{
  FUN_0007658c(*(undefined4 *)(param_1 + 4));
  FUN_00062a44(param_1,*(undefined4 *)(param_1 + 0xc));
  return;
}

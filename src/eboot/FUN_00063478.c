/* HSTMATCH module=EBOOT.BIN start=0x00063478 end=0x000634a0 symbol=FUN_00063478 lang=c99 */
/* Clone of src/sharing_main/FUN_0006433c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00311170;
extern undefined4 FUN_00050534();
extern void FUN_00051398();

void FUN_00063478(int param_1)
{
  FUN_00051398(*(undefined4 *)(param_1 + 4));
  FUN_00050534((int)&DAT_00311170);
  return;
}

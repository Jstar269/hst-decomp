/* HSTMATCH module=EBOOT.BIN start=0x00042ff4 end=0x00043004 symbol=FUN_00042ff4 lang=c99 */
/* Clone of src/sharing_main/FUN_000430d8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00051398();

void FUN_00042ff4(char *param_1)
{
  FUN_00051398(*(undefined4 *)(param_1 + 0x19074));
  return;
}

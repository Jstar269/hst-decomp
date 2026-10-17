/* HSTMATCH module=EBOOT.BIN start=0x001b871c end=0x001b8754 symbol=FUN_001b871c lang=c99 */
/* Clone of src/sharing_main/FUN_001c6408.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern undefined4 FUN_001b1f84();

void FUN_001b871c(int param_1)
{
  FUN_001b1f84((int)&DAT_0034179c,param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  return;
}

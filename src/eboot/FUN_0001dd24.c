/* HSTMATCH module=EBOOT.BIN start=0x0001dd24 end=0x0001dd58 symbol=FUN_0001dd24 lang=c99 */
/* Clone of src/sharing_main/FUN_0001d970.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0001dd58();
extern void FUN_0001dfa0();

void FUN_0001dd24(undefined4 param_1)
{
  FUN_0001dd58();
  FUN_0001dfa0(param_1,1,0);
  return;
}

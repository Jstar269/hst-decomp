/* HSTMATCH module=EBOOT.BIN start=0x001a57d0 end=0x001a5808 symbol=FUN_001a57d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern void FUN_001aedc8();
extern void FUN_001bae28();

void FUN_001a57d0(int param_1)
{
  if (0 < *(int *)(param_1 + 0x3c)) {
    FUN_001aedc8(param_1 + 0x68);
    FUN_001bae28(*(undefined4 *)(param_1 + 0x88));
  }
  return;
}

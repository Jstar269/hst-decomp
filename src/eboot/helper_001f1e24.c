/* HSTMATCH module=EBOOT.BIN start=0x001f1e24 end=0x001f1e8c symbol=FUN_001f1e24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: materialized the zero-float guard result with a default-true flag; exact match verified; names and types await human review. */
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

extern undefined * DAT_00331b84;
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001f9518();

void FUN_001f1e24(undefined4 param_1)
{
  int should_call = 1;
  if (*(float *)(DAT_00331b84 + 0xc) != 0.0f) {
    should_call = 0;
  }
  if (should_call != 0) {
    FUN_001f9518(param_1);
  }
  FUN_001f4bfc(param_1);
  FUN_001f47a4(param_1);
  return;
}

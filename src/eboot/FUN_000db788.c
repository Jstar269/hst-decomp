/* HSTMATCH module=EBOOT.BIN start=0x000db788 end=0x000db7f4 symbol=FUN_000db788 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a3); exact match verified; names and types await human review. */
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

extern undefined DAT_00338b48;
extern undefined DAT_003417bb;
extern undefined DAT_0034189b;
extern undefined DAT_003419bb;
extern void FUN_000db7f4();
extern void FUN_000db868();

void FUN_000db788(int param_1)
{
  if (DAT_00338b48 != '\0') {
    DAT_003417bb = 0;
    DAT_0034189b = 2;
    DAT_003419bb = 1;
    *(undefined4 *)(param_1 + 0xb4) = 1;
    *(undefined4 *)(param_1 + 0xc0) = 9;
  }
  FUN_000db7f4(param_1);
  FUN_000db868(param_1);
  *(undefined1 *)(param_1 + 0xb0) = 0;
  return;
}

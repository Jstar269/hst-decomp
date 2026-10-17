/* HSTMATCH module=EBOOT.BIN start=0x00199afc end=0x00199b40 symbol=FUN_00199afc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined DAT_0034a678;
extern void FUN_00199398();
extern void FUN_002345f8();

void FUN_00199afc(int param_1)
{
  FUN_00199398(*(undefined4 *)(param_1 + 0x3c));
  if (*(uchar *)(*(int *)(param_1 + 0x3c) + 0x24) != '\0') {
    FUN_002345f8(&DAT_0034a678);
  }
  return;
}

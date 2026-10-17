/* HSTMATCH module=EBOOT.BIN start=0x0016fbf4 end=0x0016fc48 symbol=FUN_0016fbf4 lang=c99 */
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

extern void FUN_0016b6c8();
extern void FUN_00170c24();
extern void FUN_00170d9c();

void FUN_0016fbf4(int param_1)
{
  (**(code **)(param_1 + 0x53c))(*(undefined4 *)(param_1 + 0xb8));
  FUN_0016b6c8(*(undefined4 *)(param_1 + 0xbc));
  FUN_00170c24(param_1,0);
  if (*(uchar *)(param_1 + 0x3e) != '\0') {
    FUN_00170d9c(param_1);
  }
  return;
}

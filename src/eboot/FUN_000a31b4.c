/* HSTMATCH module=EBOOT.BIN start=0x000a31b4 end=0x000a31fc symbol=FUN_000a31b4 lang=c99 */
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

extern int FUN_000b3c68();
extern float FUN_00163e60();

float FUN_000a31b4(int param_1)
{
  undefined4 uVar1;
  float fVar2;
  
  uVar1 = FUN_000b3c68();
  fVar2 = (float)FUN_00163e60(uVar1,*(undefined4 *)(param_1 + 0x154));
  return (fVar2 - 1.0f) / 9.0f;
}

/* HSTMATCH module=EBOOT.BIN start=0x0021db30 end=0x0021dbbc symbol=FUN_0021db30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the float zero argument and placed the receiver first in the helper prototype; exact match verified; names and types await human review. */
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

extern void FUN_0021dbbc();
extern void FUN_0021dd14();
extern void FUN_0021df6c();
extern void FUN_0021e090(float param_1,int param_2);
extern void FUN_0021e14c();
extern void FUN_0021e20c(float param_1,int param_2);
extern void FUN_0021e25c(int param_1,float param_2,float param_3);
extern void FUN_0021e4cc();

void FUN_0021db30(int param_1)
{
  *(undefined4 *)(param_1 + 0x1e8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  FUN_0021df6c(param_1,0);
  FUN_0021e090(0.0f,param_1);
  FUN_0021e20c(1.0f,param_1);
  FUN_0021e4cc(param_1,0,0);
  FUN_0021e25c(param_1,0.0f,0.0f);
  FUN_0021e14c(param_1,0);
  FUN_0021dbbc(param_1);
  FUN_0021dd14(param_1);
  return;
}

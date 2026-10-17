/* HSTMATCH module=EBOOT.BIN start=0x0012d464 end=0x0012d550 symbol=FUN_0012d464 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern char DAT_002dac60[];
extern char DAT_002dac94[];
extern char DAT_002dacc4[];
extern char DAT_002dacf4[];
extern char DAT_002dad24[];
extern void FUN_000143b0();
extern void FUN_00141718();
extern void FUN_0014189c();
extern void FUN_00141c3c();
extern void FUN_00141e70();
extern void FUN_0014613c();

void FUN_0012d464(undefined4 param_1,int param_2,int param_3)
{
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,DAT_002dac60,param_2 + 1,param_3 + 1);
  FUN_00141718(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_002dac94,param_2 + 1,param_3 + 1);
  FUN_0014613c(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_002dacc4,param_2 + 1,param_3 + 1);
  FUN_0014189c(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_002dacf4,param_2 + 1,param_3 + 1);
  FUN_00141c3c(param_1,auStack_100);
  FUN_000143b0(auStack_100,DAT_002dad24,param_2 + 1,param_3 + 1);
  FUN_00141e70(param_1,auStack_100);
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x00130074 end=0x00130174 symbol=FUN_00130074 lang=c99 data=0x002db068 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: ordered result tests; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002db068-0x002db092) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern char DAT_002daf84[];
extern char DAT_002daf90[];
extern char DAT_002db01c[];
extern char * FUN_00014d64();

undefined4 FUN_00130074(undefined4 param_1,int param_2)
{
  int result = 0;
  if (param_2 == 0) result = 0;
  else if (FUN_00014d64(param_2,"SERVICE") != 0) result = 1;
  else if (FUN_00014d64(param_2,"REPLAYSTART") != 0) result = 2;
  else if (FUN_00014d64(param_2,DAT_002daf84) != 0) result = 3;
  else if (FUN_00014d64(param_2,"BOUND_FIRST") != 0) result = 4;
  else if (FUN_00014d64(param_2,DAT_002daf90) != 0) result = 5;
  else if (FUN_00014d64(param_2,"FINISHCAM") != 0) result = 6;
  else if (FUN_00014d64(param_2,DAT_002db01c) != 0) result = 7;
  return result;
}

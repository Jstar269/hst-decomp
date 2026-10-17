/* HSTMATCH module=EBOOT.BIN start=0x001b8c54 end=0x001b8cf8 symbol=FUN_001b8c54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q2); exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern void FUN_00000a00();
extern int FUN_001b23c0();
extern void FUN_001b8d2c();
extern void FUN_001b94f8();

int FUN_001b8c54(int param_1,short param_2)
{
  undefined1 auStack_4 [4];
  undefined4 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_001b8d2c();
    if ((((param_1 != 0) && (FUN_001b23c0((int)&DAT_0034179c,0), param_1 != 0)) && (param_1 != 0)) &&
       (param_1 != 0)) {
      local_c = param_1 + 4;
      local_8 = *(undefined4 *)(param_1 + 8);
      FUN_001b94f8(auStack_4,param_1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

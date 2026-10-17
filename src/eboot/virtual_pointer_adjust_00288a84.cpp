/* HSTMATCH module=EBOOT.BIN start=0x00288a84 end=0x00288af0 symbol=FUN_00288a84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();


#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
struct Interface {
  virtual int m0(); virtual int m1(); virtual int m2(); virtual int m3();
  virtual int m4(); virtual int m5(); virtual int m6(); virtual int m7();
  virtual int m8(); virtual int m9(); virtual int m10(); virtual int m11();
};
extern "C" int *FUN_00288a84(int *param_1)
{
  int result;
  bool match;
  result = ((Interface *)param_1)->m11();
  match = result == 2;
  if (!match) {
    result = ((Interface *)param_1)->m11();
    match = result == 3;
  }
  if (match) {
    if (param_1 != (int *)0) param_1 = (int *)((char *)param_1 - 0xe0);
  } else {
    return (int *)0;
  }
  return param_1;
}
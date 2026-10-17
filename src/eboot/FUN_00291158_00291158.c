/* HSTMATCH module=EBOOT.BIN start=0x00291158 end=0x002911b8 symbol=FUN_00291158 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed the float field and used a zero-result switch case; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern int FUN_002911b8(void *,int);
extern int FUN_00291280(void *,int,int);

int FUN_00291158(void *param_1,int *param_2)
{
  int result = FUN_002911b8(param_1,param_2[0]);
  switch (result) {
  case 0:
    return 0;
  default: {
    int value = (int)(((float *)param_2)[1] * 32768.0f);
    return FUN_00291280(param_1,value,value);
  }
  }
}

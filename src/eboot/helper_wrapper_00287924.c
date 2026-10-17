/* HSTMATCH module=EBOOT.BIN start=0x00287924 end=0x0028797c symbol=FUN_00287924 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: recovered the packed helper-call record and symbolic error-data address; exact match verified; names and types await human review. */
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

extern void FUN_001b29a8();
extern undefined4 DAT_0034179c;
extern undefined4 FUN_00289544(int *, int, int *, int *);

struct ErrorCallState {
  int address;
  int result;
  int type;
  int count;
  int parameter;
  int unused[3];
};

void FUN_00287924(int param_1,undefined4 param_2,int param_3)
{
  struct ErrorCallState local;
  
  if (param_3 < 1) {
    FUN_001b29a8(&DAT_0034179c);
  }
  else {
    local.type = 0x33;
    local.parameter = param_2;
    local.count = param_3;
    local.address = param_1 + 0x68;
    FUN_00289544(&local.result,param_1 + 100,&local.address,&local.type);
  }
  return;
}

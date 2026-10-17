/* HSTMATCH module=EBOOT.BIN start=0x00231b08 end=0x00231ba0 symbol=FUN_00231b08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3/v0) corrected by hand: typed the record tables as floats and used the short-circuit index guard; exact match verified; names and types await human review. */
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

extern int DAT_002f3664;
extern undefined4 FUN_0022c194();

struct Object_231b08 {
  char pad000[0x1e0];
  int index;
  char pad1e4[8];
  float value1;
  float value2;
  char pad1f4[0x0c];
  int valid[40];
  float values1[10];
  float values2[10];
};

void FUN_00231b08(int param_1)
{
  struct Object_231b08 *self = (struct Object_231b08 *)param_1;
  undefined4 uVar1;
  
  if (DAT_002f3664 < 0) {
    uVar1 = FUN_0022c194();
    self->index = uVar1;
  }
  else {
    self->index = DAT_002f3664;
    DAT_002f3664 = -1;
  }
  if (self->index < 0 || self->valid[self->index] == 0) {
    self->index = 0;
  }
  self->value1 = self->values1[self->index];
  self->value2 = self->values2[self->index];
  return;
}

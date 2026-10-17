/* HSTMATCH module=EBOOT.BIN start=0x002634c4 end=0x00263558 symbol=FUN_002634c4 lang=c99 */
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

extern undefined4 DAT_003415ac;
extern undefined DAT_0034a678;
extern void FUN_00103628();
extern void FUN_00234158();
extern void FUN_002815c4();

void FUN_002634c4(int param_1)
{
  FUN_00103628(DAT_003415ac,1);
  *(undefined4 *)(*(int *)(param_1 + 0x640) + 0x61c) =
       *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xdc);
  FUN_002815c4(*(undefined4 *)(param_1 + 0x640));
  if ((*(int *)(*(int *)(param_1 + 0x640) + 0x80) == 1) &&
     (*(int *)(*(int *)(param_1 + 0x640) + 0x61c) == 2)) {
    FUN_00234158(&DAT_0034a678,0x40);
  }
  else {
    FUN_00234158(&DAT_0034a678,0x3f);
  }
  return;
}

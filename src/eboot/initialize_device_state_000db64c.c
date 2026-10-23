/* HSTMATCH module=EBOOT.BIN start=0x000db64c end=0x000db724 symbol=FUN_000db64c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: model byte +0x45 as a field and route the zero flag to the common initializer call. */
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

extern undefined DAT_003075f8;
extern undefined DAT_003386b8;
extern undefined * DAT_00338ac4;
extern undefined4 DAT_00338b44;
extern unsigned char DAT_00338b48;
extern undefined DAT_003417b8;
extern undefined DAT_003417b9;
extern unsigned char DAT_003417ba;
extern undefined4 * FUN_0001f06c();
extern void FUN_000db788();

typedef struct FlagView {
  char padding[0x45];
  unsigned char flag;
} FlagView;

undefined4 * FUN_000db64c(undefined4 *param_1)
{
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003075f8);
  param_1[0xf] = 5;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 1;
  param_1[0x2d] = 3;
  param_1[0x30] = 2;
  param_1[0x33] = 4;
  DAT_00338b48 = 0;
  ((unsigned char *)param_1)[0x45] = DAT_003417b8 == '\0';
  param_1[0x2d] = (uint)DAT_003417b9;
  param_1[0x30] = (uint)DAT_003417ba;
  if ((DAT_003386b8 != '\0') && (2 < *(int *)(DAT_00338ac4 + 0x194))) {
    ((FlagView *)param_1)->flag = 0;
  }
  FUN_000db788((int)param_1);
  DAT_00338b44 = (unsigned int)(param_1);
  return param_1;
}

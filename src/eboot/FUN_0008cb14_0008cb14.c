/* HSTMATCH module=EBOOT.BIN start=0x0008cb14 end=0x0008cb68 symbol=FUN_0008cb14 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: update guard and old-state reload; exact match verified; names and types await human review. */
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

extern undefined DAT_002d26b0;
extern undefined4 DAT_003386c4;
extern void FUN_00110a78();

struct OldStateView { char pad[0x9c0]; int state; };

void FUN_0008cb14(int param_1,int param_2,int param_3)
{
  int old = *(int *)(param_1 + 0x9c0);
  if (old == param_2 && param_3 == 0) {
    return;
  }
  old = ((struct OldStateView *)param_1)->state;
  *(int *)(param_1 + 0x9c4) = old;
  *(int *)(param_1 + 0x9c0) = param_2;
  *(undefined1 *)(param_1 + 0x9c8) = 1;
  FUN_00110a78(DAT_003386c4,&DAT_002d26b0,0);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0008e25c end=0x0008e2b0 symbol=FUN_0008e25c lang=c99 */
/* Clone of src/eboot/FUN_0008cb14_0008cb14.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003787a8;
extern undefined4 DAT_003e1a04;
extern void FUN_0011988c();

struct OldStateView { char pad[0x9c0]; int state; };

void FUN_0008e25c(int param_1,int param_2,int param_3)
{
  int old = *(int *)(param_1 + 0x9c0);
  if (old == param_2 && param_3 == 0) {
    return;
  }
  old = ((struct OldStateView *)param_1)->state;
  *(int *)(param_1 + 0x9c4) = old;
  *(int *)(param_1 + 0x9c0) = param_2;
  *(undefined1 *)(param_1 + 0x9c8) = 1;
  FUN_0011988c(DAT_003e1a04,&DAT_003787a8,0);
}

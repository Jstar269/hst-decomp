/* HSTMATCH module=hstp_trans_main.prx start=0x001d4320 end=0x001d4390 symbol=FUN_001d4320 lang=c99 */
/* Clone of src/eboot/conditional_state_reset_001c5f54.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: passed the named module address and two state values to the helper; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00392328;
extern void FUN_001c04c4();
extern void FUN_001d56bc(int *,int,int);
extern int DAT_003eaad8;

void FUN_001d4320(int param_1)
{
  if (DAT_00392328 < *(int *)(param_1 + 200)) {
    FUN_001c04c4(&DAT_003eaad8);
    int first = *(int *)(param_1 + 0xd4);
    if (first >= 0) {
      int second = *(int *)(param_1 + 0xd8);
      if (second >= 0) {
        FUN_001d56bc((int *)param_1,first,second);
      }
    }
    *(undefined4 *)(param_1 + 0xc4) = 2;
    *(undefined4 *)(param_1 + 200) = 0;
  }
  return;
}

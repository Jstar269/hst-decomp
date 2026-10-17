/* HSTMATCH module=EBOOT.BIN start=0x001c5f54 end=0x001c5fc4 symbol=FUN_001c5f54 lang=c99 */
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

extern undefined4 DAT_002ea610;
extern void FUN_001b2430();
extern void FUN_001c725c(int *,int,int);
extern int DAT_0034179c;

void FUN_001c5f54(int param_1)
{
  if (DAT_002ea610 < *(int *)(param_1 + 200)) {
    FUN_001b2430(&DAT_0034179c);
    int first = *(int *)(param_1 + 0xd4);
    if (first >= 0) {
      int second = *(int *)(param_1 + 0xd8);
      if (second >= 0) {
        FUN_001c725c((int *)param_1,first,second);
      }
    }
    *(undefined4 *)(param_1 + 0xc4) = 2;
    *(undefined4 *)(param_1 + 200) = 0;
  }
  return;
}

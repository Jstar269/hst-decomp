/* HSTMATCH module=EBOOT.BIN start=0x001b7218 end=0x001b7298 symbol=FUN_001b7218 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: symbol-address and pointer/float helper prototypes; exact match verified; names and types await human review. */
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

extern void FUN_001b2430(int *param_1);
extern void FUN_001b3ea4(int *param_1, float param_2);
extern void FUN_001b4240(int *param_1, float param_2);
extern void FUN_001b464c(int *param_1, float param_2);
extern void FUN_001b871c();
extern int DAT_0034179c;

void FUN_001b7218(int param_1)
{
  FUN_001b871c();
  *(undefined1 *)(param_1 + 0x78) = 1;
  FUN_001b3ea4(&DAT_0034179c,0.1f);
  FUN_001b4240(&DAT_0034179c,0.1f);
  FUN_001b464c(&DAT_0034179c,0.1f);
  FUN_001b2430(&DAT_0034179c);
  return;
}

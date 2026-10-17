/* HSTMATCH module=EBOOT.BIN start=0x001b87e8 end=0x001b8890 symbol=FUN_001b87e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: express the two guarded paths and shared flag store explicitly; exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern void FUN_001b4240(int *,float);
extern int FUN_001b4528(int *,int);

void FUN_001b87e8(int param_1,int param_2,int param_3)
{
  int flag;

  if (param_2 == 0) goto zero_case;
  if (*(uchar *)(param_1 + 0x78) == 0) goto zero_case;
  FUN_001b4528((int *)&DAT_0034179c,param_2);
  goto store_flag;

zero_case:
  if (param_2 != 0) goto store_flag;
  if (*(uchar *)(param_1 + 0x78) != 0) goto store_flag;
  FUN_001b4528((int *)&DAT_0034179c,param_2);
  if (param_3 == 0) goto store_flag;
  FUN_001b4240((int *)&DAT_0034179c,0.5f);

store_flag:
  flag = param_2 != 0;
  flag ^= 1;
  *(uchar *)(param_1 + 0x78) = (uchar)flag;
  return;
}

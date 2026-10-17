/* HSTMATCH module=EBOOT.BIN start=0x001afcd4 end=0x001afd70 symbol=FUN_001afcd4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the do-while rewritten as a for loop with an inclusive bound (i <= 0x179); exact match verified; names and types await human review. */
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

extern undefined DAT_002e58e4;
extern undefined DAT_002e58ec;
extern undefined DAT_002e58f4;
extern undefined DAT_002e5908;
extern void FUN_001b04d0();
extern void FUN_001b08a0();

void FUN_001afcd4(int param_1)
{
  int iVar1;
  
  for (iVar1 = 0x16a; iVar1 <= 0x179; iVar1++) {
    FUN_001b04d0(param_1,iVar1);
  }
  *(undefined4 *)(param_1 + 0x788) = 0;
  FUN_001b08a0(param_1,&DAT_002e5908,4);
  FUN_001b08a0(param_1,&DAT_002e58f4,5);
  FUN_001b08a0(param_1,&DAT_002e58ec,2);
  FUN_001b08a0(param_1,&DAT_002e58e4,2);
  return;
}

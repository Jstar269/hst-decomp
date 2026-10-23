/* HSTMATCH module=EBOOT.BIN start=0x001b38dc end=0x001b39e4 symbol=FUN_001b38dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001b38dc.c) corrected by hand: replaced the absolute data address literal with DAT_0030ebf4; exact match verified; names and types await human review. */
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
extern undefined4 DAT_0034178c;
extern char DAT_0030ebf4[];
extern char DAT_002e9544[];
extern char DAT_002e9560[];
extern char DAT_002e957c[];
extern uint FUN_0001342c();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern void FUN_001b06d4();
extern void FUN_001b0ef8();

void FUN_001b38dc(undefined4 *param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  DAT_0034178c = FUN_0001342c();
  FUN_0001ca58(DAT_0030ebf4,DAT_002e9544);
  FUN_001b06d4(uVar1,&DAT_002e58e4,2,0);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_0001ca58(DAT_0030ebf4,DAT_002e9560);
  FUN_001b06d4(uVar1,&DAT_002e58ec,2,0);
  FUN_0001cb88(DAT_0030ebf4);
  FUN_0001ca58(DAT_0030ebf4,DAT_002e957c);
  FUN_001b06d4(uVar1,&DAT_002e58f4,5,0);
  FUN_001b0ef8(uVar1,*(undefined4 *)(&DAT_002e5908 + param_2 * 4),0,0,0);
  FUN_0001cb88(DAT_0030ebf4);
  return;
}

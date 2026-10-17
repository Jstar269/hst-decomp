/* HSTMATCH module=EBOOT.BIN start=0x001b3068 end=0x001b3130 symbol=FUN_001b3068 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the module address 0x30ebf4 is the symbol &DAT_0030ebf4 (lui/addiu, not lui/ori); exact match verified; names and types await human review. */
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

extern undefined DAT_002e5970;
extern undefined DAT_002e5978;
extern undefined DAT_002e5984;
extern undefined DAT_0030ebf4;
extern char DAT_002e9488[];
extern char DAT_002e94b4[];
extern char DAT_002e94e0[];
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern void FUN_001b06d4();

void FUN_001b3068(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  FUN_0001ca58(&DAT_0030ebf4,DAT_002e9488);
  FUN_001b06d4(uVar1,&DAT_002e5970,2,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,DAT_002e94b4);
  FUN_001b06d4(uVar1,&DAT_002e5978,3,0);
  FUN_0001cb88(&DAT_0030ebf4);
  FUN_0001ca58(&DAT_0030ebf4,DAT_002e94e0);
  FUN_001b06d4(uVar1,&DAT_002e5984,2,0);
  FUN_0001cb88(&DAT_0030ebf4);
  return;
}

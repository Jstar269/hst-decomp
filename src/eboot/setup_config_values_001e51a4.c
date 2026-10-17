/* HSTMATCH module=EBOOT.BIN start=0x001e51a4 end=0x001e521c symbol=FUN_001e51a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: typed float query results and the mixed int/float updater arguments; exact match verified; names and types await human review. */
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

extern char DAT_002ec168[];
extern char DAT_002ec174[];
extern float FUN_000657e4(int, char *, int);
extern int FUN_001ee224();
extern void FUN_0021780c(void *, int, float, float);

void FUN_001e51a4(int param_1)
{
  float fVar1;
  float fVar2;
  
  fVar1 = FUN_000657e4(FUN_001ee224(),DAT_002ec168,1);
  fVar2 = FUN_000657e4(FUN_001ee224(),DAT_002ec174,1);
  FUN_0021780c((char *)param_1 + 0x43c,(int)fVar2,fVar1,1.0f);
  return;
}

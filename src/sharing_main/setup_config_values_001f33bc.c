/* HSTMATCH module=hstp_trans_main.prx start=0x001f33bc end=0x001f3434 symbol=FUN_001f33bc lang=c99 */
/* Clone of src/eboot/setup_config_values_001e51a4.c (hstclone.py tag u5cr4s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_00394080[];
extern char DAT_0039408c[];
extern float FUN_00066bb0(int, char *, int);
extern int FUN_001fc5ec();
extern void FUN_002268b4(void *, int, float, float);

void FUN_001f33bc(int param_1)
{
  float fVar1;
  float fVar2;
  
  fVar1 = FUN_00066bb0(FUN_001fc5ec(),DAT_00394080,1);
  fVar2 = FUN_00066bb0(FUN_001fc5ec(),DAT_0039408c,1);
  FUN_002268b4((char *)param_1 + 0x43c,(int)fVar2,fVar1,1.0f);
  return;
}

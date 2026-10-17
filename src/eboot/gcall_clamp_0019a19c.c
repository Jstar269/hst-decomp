/* HSTMATCH module=EBOOT.BIN start=0x0019a19c end=0x0019a210 symbol=FUN_0019a19c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: byte field at +0xea read as unsigned char (lbu) instead of char; exact match verified; names and types await human review. */
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
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_00103128();
extern void FUN_00199f78();
extern int FUN_001b1c44();

void FUN_0019a19c(int param_1)
{
  float fVar1;
  
  if (*(uchar *)(*(int *)(param_1 + 0x54) + 0xea) != 0) {
    FUN_001b1c44((int *)&DAT_0034179c,1);
  }
  fVar1 = FUN_000ede98(*(float *)(param_1 + 0x5c),1.0f,0.5f,0.005f);
  *(float *)(param_1 + 0x5c) = fVar1;
  FUN_00199f78(param_1);
  FUN_00103128(param_1);
  return;
}

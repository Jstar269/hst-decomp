/* HSTMATCH module=EBOOT.BIN start=0x00089a44 end=0x00089abc symbol=FUN_00089a44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: fixed the callback prototype, float constants, and integer return type; exact match verified; names and types await human review. */
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

extern void *DAT_00331b88;
extern void *DAT_00338c20;
extern void FUN_00063d08(float param_1,float param_2,void *param_3,int param_4);
extern void FUN_0008ad40();
extern undefined4 FUN_0008add8();
extern int FUN_000fb504(void *param_1);

void FUN_00089a44(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_000fb504(DAT_00338c20);
  if (iVar1 != 0) {
    FUN_0008ad40(param_1);
    iVar1 = FUN_0008add8(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x40) = 4;
    FUN_00063d08(65264.0f,-1.0f,DAT_00331b88,0xf);
    }
  }
  return;
}

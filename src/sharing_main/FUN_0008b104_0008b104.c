/* HSTMATCH module=hstp_trans_main.prx start=0x0008b104 end=0x0008b17c symbol=FUN_0008b104 lang=c99 */
/* Clone of src/eboot/FUN_00089a44_00089a44.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern void *DAT_003daec8;
extern void *DAT_003e1f60;
extern void FUN_00064bcc(float param_1,float param_2,void *param_3,int param_4);
extern void FUN_0008c400();
extern undefined4 FUN_0008c498();
extern int FUN_00100c40(void *param_1);

void FUN_0008b104(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_00100c40(DAT_003e1f60);
  if (iVar1 != 0) {
    FUN_0008c400(param_1);
    iVar1 = FUN_0008c498(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x40) = 4;
    FUN_00064bcc(65264.0f,-1.0f,DAT_003daec8,0xf);
    }
  }
  return;
}

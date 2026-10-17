/* HSTMATCH module=hstp_trans_main.prx start=0x001368dc end=0x001369d4 symbol=FUN_001368dc lang=c99 */
/* Clone of src/eboot/FUN_0012b470_0012b470.c (hstclone.py tag u3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern float DAT_00381abc;
extern int DAT_003e47f0[];
extern void FUN_001361c0(int,int,int,int,int,int,float);
extern int FUN_001369d4(int);
extern int FUN_00136b98(int,undefined4,int);

void FUN_001368dc(int param_1,int param_2,undefined4 param_3)
{
  int selector = FUN_001369d4(param_1);
  if (selector < 0) {
    int index = FUN_00136b98(param_1,*(undefined4 *)(param_1 + 0x35c),0);
    int offset = index * 2;
    int base = *(int *)(param_1 + 0x354);
    int address = base + offset;
    int current = *(int *)(param_1 + 0x334);
    if (current >= 0) {
      FUN_001361c0(param_1,current,1,0,1,1,-1.0f);
    } else {
      FUN_001361c0(param_1,DAT_003e47f0[0] + address,1,0,1,1,-1.0f);
    }
  } else {
    selector = selector + param_2;
    FUN_001361c0(param_1,DAT_003e47f0[selector],1,0,param_3,1,DAT_00381abc);
  }
}

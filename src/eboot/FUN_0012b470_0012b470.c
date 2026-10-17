/* HSTMATCH module=EBOOT.BIN start=0x0012b470 end=0x0012b568 symbol=FUN_0012b470 lang=c99 */
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

extern float DAT_002da9cc;
extern int DAT_0033b4b0[];
extern void FUN_0012ad54(int,int,int,int,int,int,float);
extern int FUN_0012b568(int);
extern int FUN_0012b72c(int,undefined4,int);

void FUN_0012b470(int param_1,int param_2,undefined4 param_3)
{
  int selector = FUN_0012b568(param_1);
  if (selector < 0) {
    int index = FUN_0012b72c(param_1,*(undefined4 *)(param_1 + 0x35c),0);
    int offset = index * 2;
    int base = *(int *)(param_1 + 0x354);
    int address = base + offset;
    int current = *(int *)(param_1 + 0x334);
    if (current >= 0) {
      FUN_0012ad54(param_1,current,1,0,1,1,-1.0f);
    } else {
      FUN_0012ad54(param_1,DAT_0033b4b0[0] + address,1,0,1,1,-1.0f);
    }
  } else {
    selector = selector + param_2;
    FUN_0012ad54(param_1,DAT_0033b4b0[selector],1,0,param_3,1,DAT_002da9cc);
  }
}

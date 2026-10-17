/* HSTMATCH module=EBOOT.BIN start=0x0010061c end=0x001006b0 symbol=FUN_0010061c lang=c99 */
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

extern void FUN_00014788(void *param_1, int *param_2);
extern void FUN_000149a8(void *param_1, uint *param_2);
extern uint FUN_0004cad0(char *param_1, int *param_2, int param_3, int param_4);
extern void FUN_000511c4(int param_1, uint *param_2, undefined4 param_3);
extern void FUN_00051398(float param_1, int param_2);
extern int DAT_002d8a50;

void FUN_0010061c(int param_1,uint *param_2,undefined4 param_3)
{
  uint uVar1;
  uint auStack_100 [64];
  int local_104;
  
  FUN_000511c4(param_1,param_2,param_3);
  FUN_00051398(100000.0f,param_1);
  FUN_000149a8(auStack_100,param_2);
  FUN_00014788(auStack_100,&DAT_002d8a50);
  uVar1 = FUN_0004cad0((char *)auStack_100,&local_104,0x10,1);
  {
    uint value;
    if (uVar1 == 0) {
      value = 0;
    }
    else {
      value = uVar1;
    }
    if (local_104 > 0) {
      *(uint *)(param_1 + 0x50) = value;
    }
    else {
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
  }
  return;
}
// Best near miss: 6 differing words remain in the post-call result/count branch and store scheduling.
// near miss from lane u1r1-0 (unreviewed)

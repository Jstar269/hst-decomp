/* HSTMATCH module=EBOOT.BIN start=0x00127240 end=0x00127308 symbol=FUN_00127240 lang=c99 */
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

extern float FUN_0000c6dc(float param_1,float param_2);
extern undefined4 * FUN_00022434();
extern void FUN_00022518(void *param_1,void *param_2);
extern float fabsf(float);

undefined4 FUN_00127240(int param_1)
{
  float a[4];
  float b[4];
  undefined4 uVar1;
  float fVar2;
  float fVar3;

  if ((!(fabsf(*(float *)(param_1 + 0x1e4) - *(float *)(param_1 + 0x1e8)) < 0.001f)) ||
     (*(unsigned char *)(param_1 + 0x1e0) != '\0')) {
    FUN_00022518(a,(void *)(param_1 + 0x100));
    a[3] = 0;
    fVar2 = FUN_0000c6dc(a[0],a[2]);
    FUN_00022434(b,(void *)(param_1 + 0x1d0),(void *)(param_1 + 0x1b0));
    fVar3 = FUN_0000c6dc(b[0],b[2]);
    if (!(fabsf(fVar3 - fVar2) < 0.001f)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
// near miss from lane od3 (unreviewed)

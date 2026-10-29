/* HSTMATCH module=EBOOT.BIN start=0x001c2714 end=0x001c2874 symbol=FUN_001c2714 lang=c99 */
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

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined DAT_002ea308;
extern void FUN_0018a950();
extern undefined1 * FUN_0018c9f4();
extern void FUN_001cd88c();
extern undefined4 FUN_0022977c();

void FUN_001c2714(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5, undefined4 *param_6)
{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  
  iVar1 = (int)(FUN_0018c9f4(8));
  *(undefined1 *)(param_1 + 99) = 0;
  *(undefined1 *)(param_1 + 100) = 0;
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002c0e20;
  }
  else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
    puVar2 = &DAT_002c0e1c;
  }
  else if ((param_2 < 0) || ((*(int **)(iVar1 + 0xc))[1] <= param_2)) {
    puVar2 = &DAT_002c0e18;
  }
  else {
    puVar2 = *(undefined **)(**(int **)(iVar1 + 0xc) + param_2 * 4);
  }
  *(undefined **)(param_1 + 0x68) = puVar2;
  *(undefined4 *)(param_1 + 0x6c) = param_5;
  *(undefined4 *)(param_1 + 0x70) = 0;
  FUN_0018a950(*(undefined4 *)(param_1 + 0x20),&DAT_002ea308);
  FUN_001cd88c(param_1,2,1);
  *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  FUN_0022977c(param_1 + 0x34,0,param_2);
  *(undefined4 *)(param_1 + 0x74) = param_3;
  *(undefined4 *)(param_1 + 0x78) = param_4;
  {
    undefined4 tmp[4];
    undefined4 *s;

    if (param_6 != (undefined4 *)0x0) {
      s = param_6;
    } else {
      tmp[0] = 0;
      tmp[1] = 0;
      tmp[2] = 0;
      tmp[3] = 0;
      s = tmp;
    }
    *(float *)(param_1 + 0x80) = ((float *)s)[0];
    *(float *)(param_1 + 0x84) = ((float *)s)[1];
    *(float *)(param_1 + 0x88) = ((float *)s)[2];
    *(float *)(param_1 + 0x8c) = ((float *)s)[3];
  }
  return;
}
// improved by lane dsn3 (unreviewed): 27 -> 2 differing words

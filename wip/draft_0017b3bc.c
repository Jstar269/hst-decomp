/* HSTMATCH module=EBOOT.BIN start=0x0017b3bc end=0x0017b554 symbol=FUN_0017b3bc lang=c99 */
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

extern undefined DAT_003090c8;
extern int FUN_00000bcc();
extern undefined4 * FUN_00091830();
extern void FUN_0017df4c();
extern void FUN_0017df90();
extern undefined4 * FUN_001fe178();

undefined4 * FUN_0017b3bc(undefined4 *param_1,uint param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *local_4;
  
  *param_1 = (unsigned int)(&DAT_003090c8);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  FUN_001fe178(param_1 + 0x17);
  FUN_001fe178(param_1 + 0x68);
  param_1[0xb9] = 0x7fffffff;
  *(undefined1 *)(param_1 + 0xba) = 0;
  *(undefined1 *)((int)param_1 + 0x2e9) = 0;
  *(undefined1 *)((int)param_1 + 0x2ea) = 0;
  *(undefined1 *)((int)param_1 + 0x2eb) = 0;
  param_1[0xbb] = 0x7fffffff;
  param_1[0xbc] = 0x7fffffff;
  param_1[0xbd] = 0x7fffffff;
  param_1[0xbe] = 0x7fffffff;
  param_1[0xbf] = 0x7fffffff;
  param_1[0xc0] = 0x7fffffff;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 1;
  param_1[0x11] = 0;
  param_1[0x13] = 0x3f800000;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 1;
  if ((uint)param_1[4] < param_2) {
    FUN_0017df90(param_1 + 2,param_2);
  }
  iVar3 = 0;
  if (0 < (int)param_2) {
    do {
      puVar1 = (undefined4 *)FUN_00000bcc(0xf0);
      if (puVar1 != (undefined4 *)0x0) {
        FUN_00091830(puVar1 + 4);
        *puVar1 = 0;
        puVar1[1] = 0;
      }
      local_4 = puVar1;
      if ((uint)param_1[3] < (uint)param_1[4]) {
        iVar2 = param_1[3] + 1;
        param_1[3] = iVar2;
        *(undefined4 **)(param_1[2] + iVar2 * 4 + -4) = puVar1;
      }
      else {
        FUN_0017df4c(param_1 + 2,&local_4,0);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_2);
  }
  return param_1;
}
// near miss from lane fm9 (unreviewed)

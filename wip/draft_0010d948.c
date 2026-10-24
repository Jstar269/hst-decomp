/* HSTMATCH module=EBOOT.BIN start=0x0010d948 end=0x0010db54 symbol=FUN_0010d948 lang=c99 */
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

extern void FUN_00101630();

void FUN_0010d948(int param_1,undefined4 *param_2,uint param_3)
{
  bool bVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  short local_9e;
  short local_a0;
  short local_a2;
  short local_a4;
  undefined4 local_b4 [4];
  
  puVar4 = param_2 + param_3 * 9;
  puVar5 = local_b4;
  for (; param_2 < puVar4; param_2 = param_2 + 9) {
    *puVar5 = *param_2;
    puVar5[1] = param_2[1];
    puVar5[2] = param_2[2];
    puVar5[3] = param_2[3];
    *(undefined2 *)(puVar5 + 4) = *(undefined2 *)(param_2 + 4);
    *(undefined2 *)((int)puVar5 + 0x12) = *(undefined2 *)((int)param_2 + 0x12);
    *(undefined2 *)(puVar5 + 5) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)((int)param_2 + 0x16);
    *(undefined2 *)(puVar5 + 6) = *(undefined2 *)(param_2 + 6);
    puVar5[7] = param_2[7];
    puVar5[8] = param_2[8];
    puVar5 = puVar5 + 9;
  }
  sVar2 = local_a0 - local_a4;
  sVar3 = local_9e - local_a2;
  *(float *)(param_1 + 0x60) = (float)(int)local_a4;
  iVar6 = 0;
  *(float *)(param_1 + 100) = (float)(int)local_a2;
  if ((int)param_3 < 1) goto LAB_0010db30;
  if ((int)param_3 < 9) {
LAB_0010daec:
    bVar1 = iVar6 < (int)param_3;
  }
  else {
    bVar1 = false;
    if ((-1 < (int)param_3) && ((int)param_3 < 0x7fffffff)) {
      bVar1 = true;
    }
    if (bVar1) {
      puVar5 = local_b4;
      do {
        *(undefined2 *)(puVar5 + 4) = 0;
        *(undefined2 *)((int)puVar5 + 0x12) = 0;
        *(short *)(puVar5 + 5) = sVar2;
        *(short *)((int)puVar5 + 0x16) = sVar3;
        *(undefined2 *)(puVar5 + 0xd) = 0;
        *(undefined2 *)((int)puVar5 + 0x36) = 0;
        *(short *)(puVar5 + 0xe) = sVar2;
        *(short *)((int)puVar5 + 0x3a) = sVar3;
        *(undefined2 *)(puVar5 + 0x16) = 0;
        *(undefined2 *)((int)puVar5 + 0x5a) = 0;
        *(short *)(puVar5 + 0x17) = sVar2;
        *(short *)((int)puVar5 + 0x5e) = sVar3;
        *(undefined2 *)(puVar5 + 0x1f) = 0;
        *(undefined2 *)((int)puVar5 + 0x7e) = 0;
        *(short *)(puVar5 + 0x20) = sVar2;
        *(short *)((int)puVar5 + 0x82) = sVar3;
        *(undefined2 *)(puVar5 + 0x28) = 0;
        *(undefined2 *)((int)puVar5 + 0xa2) = 0;
        *(short *)(puVar5 + 0x29) = sVar2;
        *(short *)((int)puVar5 + 0xa6) = sVar3;
        *(undefined2 *)(puVar5 + 0x31) = 0;
        *(undefined2 *)((int)puVar5 + 0xc6) = 0;
        *(short *)(puVar5 + 0x32) = sVar2;
        *(short *)((int)puVar5 + 0xca) = sVar3;
        *(undefined2 *)(puVar5 + 0x3a) = 0;
        *(undefined2 *)((int)puVar5 + 0xea) = 0;
        *(short *)(puVar5 + 0x3b) = sVar2;
        *(short *)((int)puVar5 + 0xee) = sVar3;
        *(undefined2 *)(puVar5 + 0x43) = 0;
        *(undefined2 *)((int)puVar5 + 0x10e) = 0;
        *(short *)(puVar5 + 0x44) = sVar2;
        iVar6 = iVar6 + 8;
        *(short *)((int)puVar5 + 0x112) = sVar3;
        puVar5 = puVar5 + 0x48;
      } while (iVar6 < (int)(param_3 - 8));
      goto LAB_0010daec;
    }
    bVar1 = 0 < (int)param_3;
  }
  if (bVar1) {
    puVar5 = local_b4 + iVar6 * 9;
    do {
      *(undefined2 *)(puVar5 + 4) = 0;
      *(undefined2 *)((int)puVar5 + 0x12) = 0;
      *(short *)(puVar5 + 5) = sVar2;
      iVar6 = iVar6 + 1;
      *(short *)((int)puVar5 + 0x16) = sVar3;
      puVar5 = puVar5 + 9;
    } while (iVar6 < (int)param_3);
  }
LAB_0010db30:
  FUN_00101630(param_1,local_b4,param_3);
  *(uint *)(param_1 + 0xd4) = param_3;
  return;
}
// near miss from lane fm9 (unreviewed)

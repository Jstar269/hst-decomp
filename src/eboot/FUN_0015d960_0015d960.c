/* HSTMATCH module=EBOOT.BIN start=0x0015d960 end=0x0015dbbc symbol=FUN_0015d960 lang=c99 */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_002dcc1c;
extern undefined * DAT_00331b84;
extern undefined * DAT_003403f8;
extern undefined4 DAT_003415d4;
extern undefined DAT_0034a678;
extern undefined * DAT_0034a820;
extern undefined DAT_0034179c;
extern void FUN_00047864();
extern void FUN_0006391c(float, void *, int);
extern void FUN_0015a118();
extern void FUN_001905b8();
extern int FUN_00190724();
extern void FUN_001b3ea4(float, void *);
extern void FUN_00234158();
extern void FUN_002930c8(float, void *, int);

typedef struct Object {
  char pad0[0x3c];
  int state;
  int timer;
  char pad1[4];
  unsigned char flag;
  char pad2[9];
  unsigned char unk52;
} Object;

void FUN_0015d960(Object *param_1)
{
  int iVar1;
  
  FUN_0015a118(DAT_003403f8);
  if (*(int *)(DAT_003403f8 + 0x14) == 8) {
    iVar1 = param_1->state;
    switch (iVar1) {
    case 0:
    case 1:
    case 2:
      FUN_00047864();
      break;
    case 3:
      FUN_00234158(&DAT_0034a678,0x20);
      break;
    case 4:
      param_1->flag = 0;
      if (param_1->flag != 0) {
        FUN_002930c8(65534.0f,DAT_0034a820,0);
      }
      else {
        FUN_0006391c(65534.0f,DAT_00331b84,0xf);
      }
      FUN_001b3ea4(0.5f,&DAT_0034179c);
      *(undefined4 *)(DAT_003403f8 + 0x14) = 4;
      break;
    }
  }
  iVar1 = param_1->timer;
  if (iVar1 > 0) {
    param_1->timer = iVar1 + -1;
    if (iVar1 + -1 <= 0) {
      switch (param_1->state) {
      case 4:
        *(undefined4 *)(DAT_003403f8 + 0x14) = 8;
        FUN_00234158(&DAT_0034a678,DAT_002dcc1c);
        iVar1 = (int)(DAT_00331b84);
        *(undefined4 *)(DAT_00331b84 + 0xc) = 0;
        *(undefined1 *)(iVar1 + 0x52) = 0;
        break;
      }
    }
  }
  else if ((*(int *)(DAT_003403f8 + 0x14) == 3) && (iVar1 = FUN_00190724(DAT_003415d4), iVar1 != 0)) {
    param_1->timer = 5;
  }
  if (*(int *)(DAT_003403f8 + 0x14) == 5) {
    FUN_001905b8(DAT_003415d4,3);
    *(undefined4 *)(DAT_003403f8 + 0x14) = 3;
  }
  if (*(int *)(DAT_003403f8 + 0x14) == 4) {
    if (param_1->flag != 0) {
      if (*(float *)(DAT_0034a820 + 8) == 0.0f) {
        *(undefined4 *)(DAT_003403f8 + 0x14) = 5;
      }
    } else if (*(float *)(DAT_00331b84 + 0xc) == 0.0f) {
      *(undefined4 *)(DAT_003403f8 + 0x14) = 5;
    }
  }
  return;
}

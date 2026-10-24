/* HSTMATCH module=EBOOT.BIN start=0x001e1614 end=0x001e185c symbol=FUN_001e1614 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_0000175c;
extern undefined4 DAT_0034a130;
extern void FUN_000009e4(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };
struct VC_6 { virtual ~VC_6(); };
struct VC_7 { virtual ~VC_7(); };
struct VC_8 { virtual ~VC_8(); };
struct VC_9 { virtual ~VC_9(); };
struct VC_10 { virtual ~VC_10(); };
struct VC_11 { virtual ~VC_11(); };

extern "C" void FUN_001e1614(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (DAT_0034a130 != 0) {
    FUN_000009e4();
    DAT_0034a130 = 0;
  }
  piVar1 = *(int **)(param_1 + 0x9b4);
  if (piVar1 != (int *)0x0) {
    delete ((VC_1 *)(piVar1));
    *(undefined4 *)(param_1 + 0x9b4) = 0;
  }
  piVar1 = *(int **)(param_1 + 500);
  if (piVar1 != (int *)0x0) {
    delete ((VC_2 *)(piVar1));
    *(undefined4 *)(param_1 + 500) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x810);
  if (piVar1 != (int *)0x0) {
    delete ((VC_3 *)(piVar1));
    *(undefined4 *)(param_1 + 0x810) = 0;
  }
  piVar1 = *(int **)(&DAT_0000175c + param_1);
  if (piVar1 != (int *)0x0) {
    delete ((VC_4 *)(piVar1));
    *(undefined4 *)(&DAT_0000175c + param_1) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x1d68);
  if (piVar1 != (int *)0x0) {
    delete ((VC_5 *)(piVar1));
    *(undefined4 *)(param_1 + 0x1d68) = 0;
  }
  iVar3 = 0;
  iVar2 = param_1;
  do {
    piVar1 = *(int **)(iVar2 + 0x1adc);
    if (piVar1 != (int *)0x0) {
      delete ((VC_6 *)(piVar1));
      *(undefined4 *)(iVar2 + 0x1adc) = 0;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0x15);
  piVar1 = *(int **)(param_1 + 0x1958);
  if (piVar1 != (int *)0x0) {
    delete ((VC_7 *)(piVar1));
    *(undefined4 *)(param_1 + 0x1958) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x195c);
  if (piVar1 != (int *)0x0) {
    delete ((VC_8 *)(piVar1));
    *(undefined4 *)(param_1 + 0x195c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x1d64);
  if (piVar1 != (int *)0x0) {
    delete ((VC_9 *)(piVar1));
    *(undefined4 *)(param_1 + 0x1d64) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x1954);
  if (piVar1 != (int *)0x0) {
    delete ((VC_10 *)(piVar1));
    *(undefined4 *)(param_1 + 0x1954) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x25b8);
  if (piVar1 != (int *)0x0) {
    delete ((VC_11 *)(piVar1));
    *(undefined4 *)(param_1 + 0x25b8) = 0;
  }
  return;
}
// near miss from lane fm9 (unreviewed)

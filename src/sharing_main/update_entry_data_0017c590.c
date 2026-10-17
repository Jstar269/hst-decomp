/* HSTMATCH module=hstp_trans_main.prx start=0x0017c590 end=0x0017c6e8 symbol=FUN_0017c590 lang=c99 */
/* Hand-written reconstruction: inverted if/else, 6-int stack array with 0x7fffffff bounds, struct assignment for the 4-short payload, &DAT_003eaad8 symbol reference; exact match verified; names and types await human review. */
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

extern void FUN_0017bfe0(int);
extern void FUN_001888f8(undefined4);
extern void FUN_00189c84(undefined4, int *, int, int);
extern void FUN_001c189c(void *);
extern void *DAT_003eaad8;

void FUN_0017c590(int param_1, int param_2)
{
  undefined4 uVar4;
  undefined4 uVar5;
  int arr[6];

  if (param_2 != 0) {
    short *puVar6;
    *(undefined1 *)(param_1 + 0x59c) = 0;
    uVar4 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x550))(uVar5);
    puVar6 = (short *)(**(code **)(param_1 + 0x3ec))(uVar4, uVar5);
    struct S4 { short s[4]; };
    *(struct S4 *)puVar6 = *(struct S4 *)(param_1 + 0x59e);
    *(uchar *)((char *)puVar6 + 8) = *(uchar *)(param_1 + 0x5a6);
    *(uchar *)((char *)puVar6 + 9) = *(uchar *)(param_1 + 0x5a7);
    *(uchar *)((char *)puVar6 + 10) = *(uchar *)(param_1 + 0x5a8);
  }
  else {
    ushort *puVar7;
    int i;
    *(undefined1 *)(param_1 + 0x59c) = 0;
    uVar4 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x558))();
    uVar5 = (**(code **)(param_1 + 0x550))(uVar5);
    puVar7 = (ushort *)(**(code **)(param_1 + 0x3ec))(uVar4, uVar5);
    for (i = 0; i < 6; i++) {
      arr[i] = 0x7fffffff;
    }
    arr[1] = puVar7[0];
    arr[2] = puVar7[1];
    arr[3] = puVar7[2];
    arr[4] = puVar7[3];
    FUN_00189c84(*(undefined4 *)(param_1 + 0x178), arr, 0, 0);
  }
  FUN_0017bfe0(param_1);
  FUN_001c189c(&DAT_003eaad8);
  FUN_001888f8(*(undefined4 *)(param_1 + 0x178));
}

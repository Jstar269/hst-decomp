/* HSTMATCH module=EBOOT.BIN start=0x0009a548 end=0x0009a78c symbol=FUN_0009a548 lang=c99 */
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

extern undefined4 DAT_002bc410;
extern undefined4 DAT_002bc414;
extern undefined4 DAT_002bc418;
extern undefined4 DAT_002bc41c;
extern undefined4 DAT_002bc420;
extern undefined4 DAT_002bc424;
extern undefined4 DAT_002bc428;
extern undefined4 DAT_002bc42c;
extern undefined4 DAT_002bc430;
extern undefined4 DAT_002bc434;
extern undefined4 DAT_002bc438;
extern undefined4 DAT_002bc43c;
extern undefined4 DAT_0033876c;
extern char DAT_002d4574[];
extern void FUN_00096994();
extern void FUN_000a0738();
extern void FUN_000b2218();

void FUN_0009a548(int param_1,int param_2)
{
  int iVar1;
  
  DAT_0033876c = 0;
  if (*(int *)(param_1 + 0x3c) != param_2) {
    *(int *)(param_1 + 0x3c) = param_2;
    *(undefined4 *)(param_1 + 0x40) = 0;
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 == 6) {
      FUN_000a0738();
    }
    else if (iVar1 != 5) {
      if (iVar1 == 4) {
        *(undefined4 *)(param_1 + 0x7f0) = 0;
        FUN_000b2218();
        *(undefined4 *)(param_1 + 0x444) = 0;
        *(undefined4 *)(param_1 + 0x448) = 0;
        *(undefined4 *)(param_1 + 0x44c) = 0;
        *(undefined4 *)(param_1 + 0x450) = 0;
        *(undefined4 *)(param_1 + 0x454) = 0;
        *(undefined4 *)(param_1 + 0x458) = 0;
        *(undefined1 *)(param_1 + 0x460) = 0;
        *(undefined1 *)(param_1 + 0x461) = 0;
        *(undefined1 *)(param_1 + 0x462) = 0;
        *(undefined1 *)(param_1 + 0x463) = 0;
        *(undefined4 *)(param_1 + 0x470) = 0;
        *(undefined4 *)(param_1 + 0x474) = 0;
        *(undefined4 *)(param_1 + 0x478) = 0;
        *(undefined4 *)(param_1 + 0x47c) = 0;
        *(undefined4 *)(param_1 + 0x550) = DAT_002bc410;
        *(undefined4 *)(param_1 + 0x554) = DAT_002bc414;
        *(undefined4 *)(param_1 + 0x558) = DAT_002bc418;
        *(undefined4 *)(param_1 + 0x55c) = DAT_002bc41c;
        *(undefined4 *)(param_1 + 0x560) = DAT_002bc420;
        *(undefined4 *)(param_1 + 0x564) = DAT_002bc424;
        *(undefined4 *)(param_1 + 0x568) = DAT_002bc428;
        *(undefined4 *)(param_1 + 0x56c) = DAT_002bc42c;
        *(undefined4 *)(param_1 + 0x570) = DAT_002bc430;
        *(undefined4 *)(param_1 + 0x574) = DAT_002bc434;
        *(undefined4 *)(param_1 + 0x578) = DAT_002bc438;
        *(undefined4 *)(param_1 + 0x57c) = DAT_002bc43c;
      }
      else if (iVar1 == 3) {
        FUN_00096994(DAT_002d4574);
        *(undefined4 *)(param_1 + 0x7f0) = 0;
        *(undefined1 *)(param_1 + 0x409) = 0;
        *(undefined1 *)(param_1 + 0x410) = 0;
        *(undefined1 *)(param_1 + 0x411) = 0;
        *(undefined4 *)(param_1 + 0x414) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x444) = 0;
        *(undefined4 *)(param_1 + 0x448) = 0;
        *(undefined4 *)(param_1 + 0x44c) = 0;
        *(undefined4 *)(param_1 + 0x450) = 0;
        *(undefined4 *)(param_1 + 0x454) = 0;
        *(undefined4 *)(param_1 + 0x458) = 0;
        *(undefined1 *)(param_1 + 0x460) = 0;
        *(undefined1 *)(param_1 + 0x461) = 0;
        *(undefined1 *)(param_1 + 0x462) = 0;
        *(undefined1 *)(param_1 + 0x463) = 0;
        *(undefined4 *)(param_1 + 0x470) = 0;
        *(undefined4 *)(param_1 + 0x474) = 0;
        *(undefined4 *)(param_1 + 0x478) = 0;
        *(undefined4 *)(param_1 + 0x47c) = 0;
        *(undefined4 *)(param_1 + 0x550) = DAT_002bc410;
        *(undefined4 *)(param_1 + 0x554) = DAT_002bc414;
        *(undefined4 *)(param_1 + 0x558) = DAT_002bc418;
        *(undefined4 *)(param_1 + 0x55c) = DAT_002bc41c;
        *(undefined4 *)(param_1 + 0x560) = DAT_002bc420;
        *(undefined4 *)(param_1 + 0x564) = DAT_002bc424;
        *(undefined4 *)(param_1 + 0x568) = DAT_002bc428;
        *(undefined4 *)(param_1 + 0x56c) = DAT_002bc42c;
        *(undefined4 *)(param_1 + 0x570) = DAT_002bc430;
        *(undefined4 *)(param_1 + 0x574) = DAT_002bc434;
        *(undefined4 *)(param_1 + 0x578) = DAT_002bc438;
        *(undefined4 *)(param_1 + 0x57c) = DAT_002bc43c;
      }
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)

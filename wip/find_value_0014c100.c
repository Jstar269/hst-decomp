/* HSTMATCH module=EBOOT.BIN start=0x0014c100 end=0x0014c214 symbol=FUN_0014c100 lang=c99 */
// NEAR MISS (61/69 words, 68 differ, first at +0x4): mechanically generated candidate, measured as
// received (attempt 1 of this address). Retail's shape is decoded: a 12-byte search object at
// sp+16 built with lwc1/swc1 copies (value from a2, end pointer, cursor), a loop that pre-increments the
// cursor into the object, tests `cursor == end`, calls FUN_00014934(*cursor, value), and on a hit
// re-derives the end pointer before calling FUN_0014c794; on a miss it calls FUN_0014c794(s, 0,0,0).
// The lwc1/swc1 copies are the known by-value iterator-copy idiom (0x1ce96c); the mismatch is a whole-
// function colouring gap (retail spends 80 bytes of frame, ours 61 words of code).
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

extern int FUN_00014934();
extern undefined4 * FUN_0014c794();
extern int FUN_0014c820();
extern undefined4 * FUN_0014c914();
extern undefined4 * FUN_0014f528();

undefined4 FUN_0014c100(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_28 [40];
  undefined4 *local_38;
  
  local_38 = (undefined4 *)*param_2;
  puVar1 = local_38 + param_2[1] * 2;
  do {
    if (local_38 == puVar1) {
      iVar3 = param_2[1];
LAB_0014c18c:
      if (local_38 == (undefined4 *)(*param_2 + iVar3 * 8)) {
        uVar2 = (unsigned int)(FUN_0014c794(param_1,0,0,0));
      }
      else {
        FUN_0014c794(auStack_28,param_2,local_38[1],param_4);
        *(undefined4 *)(param_1 + 8) = 0;
        FUN_0014f528(param_1 + 0x18);
        FUN_0014c914(param_1,auStack_28);
        FUN_0014c820(auStack_28,0xffffffff);
        uVar2 = 0;
      }
      return uVar2;
    }
    iVar3 = FUN_00014934(*local_38,param_3);
    if (iVar3 == 0) {
      iVar3 = param_2[1];
      goto LAB_0014c18c;
    }
    local_38 = local_38 + 2;
  } while( true );
}
// near miss from lane ds1 (unreviewed)

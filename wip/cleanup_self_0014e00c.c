/* HSTMATCH module=EBOOT.BIN start=0x0014e00c end=0x0014e11c symbol=FUN_0014e00c lang=c99 */
// NEAR MISS (69/68 words, 67 differ, first at +0x0): mechanically generated candidate, measured as
// received (attempt 1 of this address). Retail is a destructor-shaped function: vptr store, a walk over
// an intrusive list deleting each element through vtable slot 2, two two-iterator erase calls
// (FUN_0014f540), a second vptr store. Only the candidate was measured this session; no source-level
// change was attempted, so the 4-byte stack slot layout and the t/s colouring are unexamined.
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

extern undefined DAT_003082d4;
extern undefined DAT_0030840c;
extern void FUN_00000a00();
extern void FUN_0014f540();

undefined4 * FUN_0014e00c(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 auStack_10 [16];
  undefined4 local_14;
  undefined4 *local_18;
  undefined1 auStack_1c [4];
  undefined4 local_20;
  undefined4 *local_24;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003082d4);
    puVar2 = (undefined4 *)param_1[4];
    if (puVar2 != param_1 + 3) {
      piVar1 = (int *)puVar2[2];
      while( true ) {
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1,1);
        }
        puVar2 = (undefined4 *)puVar2[1];
        if (puVar2 == param_1 + 3) break;
        piVar1 = (int *)puVar2[2];
      }
    }
    local_18 = param_1 + 3;
    local_14 = param_1[4];
    FUN_0014f540(auStack_10,param_1 + 2,&local_14,&local_18);
    puVar2 = param_1 + 2;
    if (((puVar2 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) &&
       (puVar2 != (undefined4 *)0x0)) {
      local_24 = param_1 + 3;
      local_20 = param_1[4];
      FUN_0014f540(auStack_1c,puVar2,&local_20,&local_24);
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_0030840c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane ds1 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0016bee8 end=0x0016bf78 symbol=FUN_0016bee8 lang=c99 */
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

extern undefined4 DAT_0034a678;
extern undefined4 DAT_0034a67c;

undefined4 FUN_0016bee8(void)
{
  undefined4 uVar1;
  
  if (DAT_0034a678 == 3) {
    uVar1 = 1;
  }
  else if (DAT_0034a678 == 0x55) {
    if (DAT_0034a67c == 0x54) {
      uVar1 = 1;
    }
    else if (DAT_0034a67c != 0x1d) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else if (DAT_0034a678 == 0x24) {
    uVar1 = 0;
  }
  else if (DAT_0034a67c == 0x30) {
    uVar1 = 0;
  }
  else if (DAT_0034a67c == 0x29) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

// NEAR MISS: 35/36 words, 19 words differ (best of 9 compiles).
// Retail's 0x55 branch is `beql c,0x54,EPI; li v0,1` / `li v0,0x1d; bnel c,0x1d,EPI; move v0,zero`
// / `li v0,1; b EPI` (likely branches straight to the epilogue); ours emits the return-1 body
// inline (`bnel ... NEXTTEST`) and a local `li v0,1; b EPI` block, so every later branch is off.
// Ruled out: early returns (`if (c == 0x54) return 1; if (c != 0x1d) return 0; return 1;` = 31-34
// words), the inner case as a switch with both label orders, mixed if/else-if + inner returns,
// uVar1 result variable with a single trailing return.
// near miss from lane fm2 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00218814 end=0x00218a24 symbol=FUN_00218814 lang=c99 */

// near miss: 132/132 words, 2 differ - both are ONLY the branch encoding at 0x2189f0 and 0x218a0c:
// retail has the likely forms (bgezl a2 / beqzl v1) whose delay slots already hold exactly the same
// instruction we put there (sw v1,0(a0) / sw v1,0(a1)), while MWCC emits plain bgez / beqz. Ruled
// out: an explicit if/else for the >>6 (adds 2 words, 32 differ), the mirrored >= 0 first arm
// (134 words), the ternary (off by 1 word elsewhere). Everything else - the 0xcc..0x102 equality
// ladder, the >= 600/500/400/300 chain, the masked remainder - is word-for-word.
// Recipes that DID work here:
// - the descending range chain must be written >= 600, >= 500, >= 400, >= 300 (not nested < tests):
//   that is what gives retail's `slti v1,a2,600; bnezl v1,<smaller block>` (a `at` register and a
//   beqzl mean the nesting is written the other way round).
// - `*param_2 = uVar1; if (uVar1 == 0) return; uVar1 -= 0x40; *param_2 = uVar1;` - the store BEFORE
//   the zero test reproduces retail's `beqzl v1,end; sw v1,0(a1)` delay-slot store; the Ghidra form
//   (`if (uVar1 == 0) { *param_2 = 0; return; }`) costs an extra `sw zero` plus a `b`.
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


void FUN_00218814(int *param_1,uint *param_2,uint param_3)
{
  uint uVar1;
  
  if (param_3 == 0xcc) {
    *param_1 = 0;
    *param_2 = 0x11;
  }
  else if (param_3 == 0xcd) {
    *param_1 = 0;
    *param_2 = 0x1c;
  }
  else if (param_3 == 0xce) {
    *param_1 = 0;
    *param_2 = 0x1e;
  }
  else if (param_3 == 0xcf) {
    *param_1 = 0;
    *param_2 = 0x22;
  }
  else if (param_3 == 0xd0) {
    *param_1 = 0;
    *param_2 = 0x2d;
  }
  else if (param_3 == 0xfa) {
    *param_1 = 0;
    *param_2 = 0x2e;
  }
  else if (param_3 == 0xfb) {
    *param_1 = 0;
    *param_2 = 0x39;
  }
  else if (param_3 == 0xfc) {
    *param_1 = 0;
    *param_2 = 0x3d;
  }
  else if (param_3 == 0xfd) {
    *param_1 = 1;
    *param_2 = 4;
  }
  else if (param_3 == 0xfe) {
    *param_1 = 1;
    *param_2 = 6;
  }
  else if (param_3 == 0xff) {
    *param_1 = 1;
    *param_2 = 9;
  }
  else if (param_3 == 0x100) {
    *param_1 = 1;
    *param_2 = 0xb;
  }
  else if (param_3 == 0x101) {
    *param_1 = 1;
    *param_2 = 0x12;
  }
  else if (param_3 == 0x102) {
    *param_1 = 1;
    *param_2 = 0x13;
  }
  else if ((int)param_3 >= 600) {
    *param_1 = 7;
    *param_2 = param_3 - 600;
  }
  else if ((int)param_3 >= 500) {
    *param_1 = 6;
    *param_2 = param_3 - 500;
  }
  else if ((int)param_3 >= 400) {
    *param_1 = 5;
    *param_2 = param_3 - 400;
  }
  else if ((int)param_3 >= 300) {
    *param_1 = 4;
    *param_2 = param_3 - 300;
  }
  else {
    *param_1 = (int)param_3 >> 6;
    if ((int)param_3 < 0) {
      *param_1 = (int)(param_3 + 0x3f) >> 6;
    }
    uVar1 = param_3 & 0x3f;
    if ((int)param_3 < 0) {
      *param_2 = uVar1;
      if (uVar1 == 0) {
        return;
      }
      uVar1 = uVar1 - 0x40;
    }
    *param_2 = uVar1;
  }
  return;
}
// near miss from lane fm9 (unreviewed)

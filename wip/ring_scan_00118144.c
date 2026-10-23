/* HSTMATCH module=EBOOT.BIN start=0x00118144 end=0x001181c0 symbol=FUN_00118144 lang=c99 */
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


undefined4 FUN_00118144(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x60);
  uVar1 = 0xffffffff;
  if (iVar2 < 0) goto LAB_00118198;
  if (iVar2 != *(volatile int *)(param_1 + 100)) {
    int modulus = 9;
    do {
      if (*(unsigned char *)(param_1 + iVar2 * 0x70 + 0xe1) != 0) {
        iVar2 = (iVar2 + 1) % modulus;
      } else goto LAB_0011819c;
    } while (iVar2 != *(volatile int *)(param_1 + 100));
  }
LAB_00118198:
  iVar2 = -1;
LAB_0011819c:
  if (-1 < iVar2) {
    int offset = iVar2 * 0x70;
    uVar1 = *(undefined4 *)((offset, offset + param_1 + 0xb8));
  }
  return uVar1;
}

// NEAR 13 words. Retail uses bnezl with the increment in its delay slot, then b/nop before div; this source emits beqzl with the final slti in its delay slot. The initial bltz/beql targets are one word early, and the final guard is slti/bnez instead of bltz.
// Tried alternate if/goto, break, for, switch and ternary forms; separated/postfix increment and modulo; volatile boundary reload; C++ and signed int return. No variant beat 13 differing words in 15 attempts after the best improved.
// near miss from lane km3 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x000bae04 end=0x000bae98 symbol=FUN_000bae04 lang=c99 */
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

extern char DAT_002d512c[];
extern char DAT_002d515c[];
extern char DAT_002d5190[];
extern void FUN_000ba3ac();
extern int FUN_002b7db0();
extern int FUN_002b7df8();

undefined4 FUN_000bae04(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x16c) < 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_002b7db0();
    if (iVar2 < 0) {
      FUN_000ba3ac(DAT_002d512c,iVar2);
      uVar1 = 0;
    }
    else {
      iVar2 = FUN_002b7df8(*(undefined4 *)(param_1 + 0x16c));
      if (iVar2 < 0) {
        FUN_000ba3ac(DAT_002d515c,iVar2);
        uVar1 = 0;
      }
      else {
        FUN_000ba3ac(DAT_002d5190);
        *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

// NEAR 4 words. Retail saves s0=a0 before loading the status into a0, then uses slti at; bnezl at; move v0,zero. The best source loads the status into v0, uses bgez v0, and copies a0 in the branch delay slot.
// Tried generated and typed helper prototypes, pointer and struct parameters, early return, outer if, 0 > status, status > -1, bool and switch forms, C++ free/member forms, and local aliases; no version improved in 15 attempts.
// near miss from lane km3 (unreviewed)

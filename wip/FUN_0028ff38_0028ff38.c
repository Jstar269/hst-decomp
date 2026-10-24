/* HSTMATCH module=EBOOT.BIN start=0x0028ff38 end=0x00290288 symbol=FUN_0028ff38 lang=c99 helpers=FUN_0028fb44@0x0028fb44-0x0028fb70 */
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

extern undefined4 DAT_0034a80c;
extern char DAT_002cabbc[];
extern char DAT_002cabe4[];
extern char DAT_002ff27c[];
extern char DAT_002ff2a8[];
extern char DAT_002ff2d0[];
extern char DAT_002ff300[];
extern char DAT_002ff320[];
extern char DAT_002ff34c[];
extern char DAT_002ff3e0[];
extern char DAT_002ff454[];
extern void FUN_000104e0();
extern undefined4 FUN_0006165c();
static void FUN_0028fb44(...) { }
extern bool FUN_002903cc();
extern bool FUN_002908cc();
extern int FUN_002b78d0();
extern int FUN_002b7908();
extern void FUN_002b7958();
extern int FUN_002b7980();
extern int FUN_002b79a8();
extern int FUN_002b7a08();
extern int FUN_002b7cc0();
extern int FUN_002b7d50();
extern int FUN_002b7e90();
extern int FUN_002b7ec0();
extern int FUN_002b7ee0();

undefined4 FUN_0028ff38(int param_1)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    uVar2 = 1;
  }
  else {
    FUN_0028fb44(DAT_002ff454);
    while (((DAT_0034a80c == '\0' && (iVar3 = FUN_002b7ee0(param_1), -1 < iVar3)) && (iVar3 != 1)))
    {
      FUN_002b7958(1000);
    }
    *(undefined1 *)(param_1 + 0x2a) = 1;
    while (iVar3 = FUN_002b7908(*(undefined4 *)(param_1 + 0x48)), iVar3 < 0) {
      iVar3 = FUN_002b7e90(param_1);
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002ff3e0,iVar3);
      }
      FUN_002b7958(100000);
    }
    if (*(int *)(param_1 + 0x48) < 0) {
      iVar3 = *(int *)(param_1 + 0x80);
    }
    else {
      iVar3 = FUN_002b7980(*(int *)(param_1 + 0x48),0);
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar3);
      }
      iVar3 = *(int *)(param_1 + 0x80);
    }
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_1 + 100);
    }
    else {
      iVar3 = FUN_002b7980(iVar3,0);
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar3);
      }
      iVar3 = *(int *)(param_1 + 100);
    }
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar3 = FUN_002b7980(iVar3,0);
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar3);
      }
      iVar3 = *(int *)(param_1 + 0x48);
    }
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_1 + 0x80);
    }
    else {
      iVar3 = FUN_002b79a8();
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar3);
      }
      *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
      iVar3 = *(int *)(param_1 + 0x80);
    }
    if (iVar3 < 0) {
      iVar3 = *(int *)(param_1 + 100);
    }
    else {
      iVar3 = FUN_002b79a8();
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar3);
      }
      *(undefined4 *)(param_1 + 0x80) = 0xffffffff;
      iVar3 = *(int *)(param_1 + 100);
    }
    if (-1 < iVar3) {
      iVar3 = FUN_002b79a8();
      if (iVar3 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar3);
      }
      *(undefined4 *)(param_1 + 100) = 0xffffffff;
    }
    uVar4 = 0;
    iVar3 = param_1;
    do {
      if (*(int *)(iVar3 + 0xd4) != 0) {
        FUN_000104e0();
        *(undefined4 *)(iVar3 + 0xd4) = 0;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < 2);
    if (*(int *)(param_1 + 0xe4) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x88);
    }
    else {
      FUN_000104e0();
      *(undefined4 *)(param_1 + 0xe4) = 0;
      uVar2 = *(undefined4 *)(param_1 + 0x88);
    }
    iVar3 = FUN_002b78d0(uVar2);
    if (iVar3 != 0) {
      FUN_0028fb44(DAT_002ff27c,iVar3);
    }
    FUN_002908cc(param_1);
    iVar3 = FUN_002b7ec0(param_1);
    if (iVar3 != 0) {
      FUN_0028fb44(DAT_002ff2a8,iVar3);
    }
    iVar3 = FUN_002b7a08(0);
    if (iVar3 < 0) {
      FUN_0028fb44(DAT_002ff2d0,iVar3);
    }
    iVar3 = FUN_002b7d50();
    if (iVar3 != 0) {
      FUN_0028fb44(DAT_002ff300,iVar3);
    }
    iVar3 = FUN_002b7cc0(0x303);
    if (iVar3 < 0) {
      FUN_0028fb44(DAT_002ff320,iVar3);
    }
    iVar3 = FUN_0006165c();
    if (iVar3 == 0) {
      cVar1 = *(char *)(param_1 + 0x1ec);
    }
    else {
      FUN_0028fb44(DAT_002ff34c,iVar3);
      cVar1 = *(char *)(param_1 + 0x1ec);
    }
    if (cVar1 == '\0') {
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    else {
      FUN_002903cc();
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    else {
      FUN_000104e0();
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0xe0) = 0;
    }
    *(undefined1 *)(param_1 + 0x29) = 0;
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x2a) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

// NEAR MISS 0x0028ff38: 235/212 words (ours 23 too long), ~206 differing words.
// Tried here: `helpers=FUN_0028fb44@0x0028fb44-0x0028fb70` with the empty
// variadic stub declared `static void FUN_0028fb44(...) { }` in front of the
// target (the stub's own source already exists as src/eboot/FUN_0028fb44.cpp),
// which compiles and places both functions. Still open: (a) the +0x28 flag must
// be `unsigned char` (retail `lbu`, ours `lb`); (b) retail's second block reads
// DAT_0034a80c with `lbu` and branches `bnezl` into a `move a0,s0; jal`
// sequence ours does not have at all, so the while-condition order
// (`DAT_0034a80c == 0 && (iVar3 = FUN_002b7ee0(param_1), -1 < iVar3) && iVar3 != 1`)
// needs to be re-derived from the retail blocks - ours emits 23 extra words.
// Ghidra's chained assignment inside the `while` is not a legal statement order
// for the compiler, so write `for (;;) { iVar3 = FUN(...); if (cond) break; ... }`
// and compare with retail's `bltz`/`beq v0,1` pair.
// near miss from lane fm10 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x001faa10 end=0x001fabb4 symbol=FUN_001faa10 lang=c99 */
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
extern void FUN_0015d1e8(uint param_1);
extern undefined4 FUN_0015d3fc(void);
extern int FUN_0016bb88(void);
extern int FUN_0022c484(void);
extern int FUN_0024e064(void);
extern int FUN_0024e230(int param_1,int param_2,int param_3,int param_4);
extern bool FUN_002acd28(int param_1);
extern undefined4 FUN_002ada80(int param_1);

void FUN_001faa10(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = FUN_0016bb88();
  if (((DAT_0034a678 == 0x2a) && (*(char *)(param_1 + 0x521) == '\0')) &&
     (iVar6 = FUN_0022c484(), 2 < iVar6)) {
    FUN_0015d1e8((uint)(0));
  }
  bVar1 = true;
  iVar6 = 0;
  do {
    iVar3 = FUN_002acd28((int)(iVar6));
    if (iVar3 != 0) {
      if (iVar6 < 0) {
        pbVar4 = (byte *)0x0;
      }
      else if (iVar6 < 0x28) {
        pbVar4 = (byte *)(iVar2 + 0x1058);
      }
      else {
        pbVar4 = (byte *)0x0;
      }
      if (1 < *pbVar4 - 4) {
        bVar1 = false;
      }
    }
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar6 < 0x28);
  if (bVar1) {
    FUN_0015d1e8((uint)(3));
  }
  bVar1 = true;
  iVar2 = 0;
  do {
    iVar6 = 0;
    do {
      uVar5 = FUN_0024e064();
      uVar5 = FUN_0024e230((int)(uVar5),(int)(iVar2 != 0),(int)(iVar6),(int)(3));
      iVar3 = FUN_002ada80((int)(uVar5));
      if (((iVar3 != 3) && (iVar3 != 4)) && (iVar3 != 5)) {
        bVar1 = false;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xf);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  if (bVar1) {
    FUN_0015d1e8((uint)(4));
  }
  iVar2 = FUN_0015d3fc();
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 0x5a2) = 1;
    *(undefined1 *)(param_1 + 0x59f) = 0;
    *(undefined1 *)(param_1 + 0x5a0) = 0;
    *(undefined1 *)(param_1 + 0x5a1) = 0;
  }
  return;
}
// near miss: 105/105 words, 25 differing.
// Structure matches the draft's; the remaining delta is a saved-register permutation plus two
// small idioms. Retail: iVar2 = s3 (the FUN_0016bb88 result), bVar1 = s2 (the check flag),
// iVar6 = s1 (first loop counter), the second flag = s4. Ours: iVar2 = s2, first flag = s3,
// second flag reuses s2's register. Swapping the declarations of bVar1/iVar2, and splitting the
// flag into two separate bool locals (each tried alone), did not move the assignment.
// Also: `2 < FUN_0022c484()` compiles to `slti at,v0,3` where retail has `slti v0,v0,3`; writing
// `FUN_0022c484() >= 3` keeps the slti in v0 but rebuilds the &&-chain and costs 4 more words.
// The field at param_1+0x521 is an unsigned char (retail lbu; the draft's `char` gives lb).
// The pbVar4 if/else chain: retail leaves a `nop` after `beqz at` and duplicates the two
// `move v0,zero` arms (105 words); every spelling we tried makes MWCC merge the two null arms
// (104 words) and shifts the whole block by one.
// near miss from lane fm9 (unreviewed)

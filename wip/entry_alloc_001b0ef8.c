/* HSTMATCH module=EBOOT.BIN start=0x001b0ef8 end=0x001b10b0 symbol=FUN_001b0ef8 lang=c99 */
/* NEAR MISS 110/110 words, 26 differ - every remaining difference is one temp register: MWCC puts the
   CSE'd `param_2 * 4` in a0 where retail has a3, which displaces the 5-entry loop counter (a1 vs a0) and
   the 2-byte copy counter (a3 vs a0); source, dst and the code itself are word-for-word retail. Confirmed:
   the guard is a bool seeded from the comparison (`bVar1 = param_2 < 0x1da; if (bVar1) bVar1 = ...` -
   that is what makes MWCC reuse the `slti` result as the false value instead of a `move v1,zero`); the
   allocation is `if (iVar3 != 0) iVar3 = FUN_000623f8(iVar3);` (beqzl over the call, no dead arm); the
   special block is entered with the positive condition (`param_2 == 0x2a || (param_2 >= 0xc3 &&
   param_2 < 0x1da)`) and the load of the slot is shared after it, so the skip branch is `bnel` with
   `lw a0,0(s0)` in its delay; cVar2 must be `unsigned char` (`andi`), and the loop counter `unsigned`
   (`sltiu`). Tried without effect: pointer/int/void spellings, sizeof(int), 4 * param_2, array indexing,
   a local `off = param_2 * 4`, slot pointer local, declaration reorders. */
typedef unsigned int uint;

extern char DAT_002e96fc[];
extern int DAT_002e5148[];
extern char DAT_002c5a34[];

extern int FUN_00000bcc(int);
extern int FUN_000623f8(int);
extern void FUN_00014788(char *, char *);
extern void FUN_00062468(int, char *, int);
extern int FUN_001b1744(int);
extern void FUN_001b177c(char *);

void FUN_001b0ef8(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int bVar1;
  unsigned char cVar2;
  int iVar3;
  uint uVar10;
  unsigned int uVar5;
  int *piVar4;
  char local_100[256];

  bVar1 = param_2 < 0x1da;
  if (bVar1)
    bVar1 = *(int *)(param_1 + param_2 * 4) != 0;
  if (!bVar1) {
    iVar3 = FUN_00000bcc(0x14);
    if (iVar3 != 0)
      iVar3 = FUN_000623f8(iVar3);
    *(int *)(param_1 + param_2 * 4) = iVar3;

    uVar10 = param_4 & 0xff;
    if (param_4 == 0) {
      uVar5 = 0;
      piVar4 = DAT_002e5148;
      do {
        if (param_2 == *piVar4) {
          uVar10 = 1;
          break;
        }
        uVar5++;
        piVar4++;
      } while (uVar5 < 5);
    }

    {
      int n = 0x80;
      char *src = DAT_002e96fc;
      char *dst = local_100;
      do {
        char c = src[1];
        n--;
        *dst = *src;
        dst[1] = c;
        src += 2;
        dst += 2;
      } while (n > 0);
    }

    if (param_5 != 0)
      FUN_00014788(local_100,(char *)param_5);
    else
      FUN_00014788(local_100,*(char **)(DAT_002c5a34 + param_2 * 4));

    if (param_2 == 0x2a || (param_2 >= 0xc3 && param_2 < 0x1da)) {
      if (param_3 == 1)
        cVar2 = 1;
      else if (param_3 == 2)
        cVar2 = 0;
      else {
        iVar3 = *(int *)(param_1 + 0x79c);
        if (iVar3 < 0)
          iVar3 = *(int *)(param_1 + 0x7a0);
        cVar2 = FUN_001b1744(iVar3);
      }
      if (cVar2)
        FUN_001b177c(local_100);
    }
    iVar3 = *(int *)(param_1 + param_2 * 4);
    FUN_00062468(iVar3,local_100,uVar10);
  }
}
// near miss from lane fm7 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0016fd94 end=0x0016fe64 symbol=FUN_0016fd94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: byte pointers typed unsigned char (lbu), renamed src/dst with src declared first for register choice; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern int FUN_0016bb88();

void FUN_0016fd94(int param_1)
{
  int iVar1;
  uchar *src;
  uchar *dst;
  
  iVar1 = FUN_0016bb88();
  dst = (uchar *)(iVar1 + 0x84c);
  src = (uchar *)(param_1 + 0x63b);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
  iVar1 = FUN_0016bb88();
  dst = (uchar *)(iVar1 + 0xacc);
  src = (uchar *)(param_1 + 0x8bb);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
  iVar1 = FUN_0016bb88();
  src = (uchar *)(param_1 + 0xb3b);
  dst = (uchar *)(iVar1 + 0xd4c);
  iVar1 = 0;
  do {
    if (*src != *dst) {
      *dst = *src;
    }
    iVar1 = iVar1 + 1;
    src = src + 1;
    dst = dst + 1;
  } while (iVar1 < 0x280);
}

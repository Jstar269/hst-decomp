/* HSTMATCH module=EBOOT.BIN start=0x001d4058 end=0x001d407c symbol=FUN_001d4058 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Quad16 {
  char pad0[4];
  short unk4;  /* 0x4 */
  short unk6;  /* 0x6 */
  short unk8;  /* 0x8 */
  short unka;  /* 0xa */
} Quad16;

/* Copy the four halfwords at +4..+0xb from src to dst. */
void FUN_001d4058(Quad16 *dst,Quad16 *src)
{
  dst->unk4 = src->unk4;
  dst->unk6 = src->unk6;
  dst->unk8 = src->unk8;
  dst->unka = src->unka;
  return;
}

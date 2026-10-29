/* HSTMATCH module=EBOOT.BIN start=0x001917b4 end=0x001917f8 symbol=FUN_001917b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Source descriptor: element count, a word, a start index and a base address. */
typedef struct Desc {
  int count;  /* 0x0 */
  int unk4;   /* 0x4 */
  int start;  /* 0x8 start index, in 4-byte elements */
  int base;   /* 0xc base address */
} Desc;

/* Four derived addresses. */
typedef struct Span {
  int unk0; /* 0x0 base + start * 4 */
  int unk4; /* 0x4 base */
  int unk8; /* 0x8 base + start * 4 */
  int unkc; /* 0xc base + count * 4 */
} Span;

void FUN_001917b4(Span *out,Desc *desc)
{
  int base;
  
  out->unk0 = desc->base + desc->start * 4;
  base = desc->base;
  out->unk4 = base;
  out->unk8 = base + desc->start * 4;
  out->unkc = out->unk4 + desc->count * 4;
}

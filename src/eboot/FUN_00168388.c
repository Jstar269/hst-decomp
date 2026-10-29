/* HSTMATCH module=EBOOT.BIN start=0x00168388 end=0x001683b0 symbol=FUN_00168388 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct Params {
  int unk00;        /* 0x00 */
  float unk04;      /* 0x04 */
  int unk08;        /* 0x08 */
  float unk0c;      /* 0x0c */
  float unk10;      /* 0x10 */
} Params;

/* Sets the five parameter words to their defaults (0, 1.0, 0, 0.5, 2.0). */
Params * FUN_00168388(Params *params)
{
  params->unk00 = 0;
  params->unk04 = 1.0f;
  params->unk08 = 0;
  params->unk0c = 0.5f;
  params->unk10 = 2.0f;
  return params;
}

/* HSTMATCH module=EBOOT.BIN start=0x0008d148 end=0x0008d1ec symbol=FUN_0008d148 lang=c99 helpers=FUN_0008cae8@0x0008cae8-0x0008cb14 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0008d148.c) corrected by hand: FUN_0008cae8 is the empty variadic log stub, defined static in front and placed by helpers= (this is what moves the shared -1 into v1); the three halfword stores write -1; readability pass; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern char DAT_002beaa8[];
extern void FUN_000114c0(void *, int, int);
static void FUN_0008cae8(...) { }

/* Info record: counters and flag bytes up front, then an embedded Rec6c at 0x38. */
typedef struct Info {
  u8 unk00;   /* 0x00 */
  char pad01[3];
  u32 unk04;  /* 0x04 */
  u32 unk08;  /* 0x08 */
  u32 unk0c;  /* 0x0c */
  u32 unk10;  /* 0x10 */
  u32 unk14;  /* 0x14 */
  u32 unk18;  /* 0x18 */
  u32 unk1c;  /* 0x1c */
  u8 unk20;   /* 0x20 */
  u8 unk21;   /* 0x21, initial 1 */
  u8 unk22;   /* 0x22, initial 2 */
  u8 unk23;   /* 0x23 */
  char pad24[5];
  u8 unk29;   /* 0x29 */
  u8 unk2a;   /* 0x2a */
  char pad2b[5];
  u8 unk30;   /* 0x30 */
  char pad31[3];
  u8 unk34;   /* 0x34 */
  u8 unk35;   /* 0x35 */
  u8 unk36;   /* 0x36 */
  char pad37;
  Rec6c rec;  /* 0x38 */
  u32 unka4;  /* 0xa4 */
  u32 unka8;  /* 0xa8 */
} Info;

void FUN_0008d148(Info *info)
{
  info->unk00 = 0;
  info->unk04 = 0;
  info->unk08 = 0;
  info->unk0c = 0;
  info->unk18 = 0;
  info->unk1c = 0;
  info->unk10 = 0;
  info->unk14 = 0;
  info->unk20 = 0;
  info->unk21 = 1;
  info->unk22 = 2;
  info->unk23 = 0;
  info->unk29 = 0;
  info->unk2a = 0;
  info->unk30 = 0;
  info->unk34 = 0;
  info->unk35 = 0;
  info->unk36 = 0;
  FUN_000114c0(&info->rec, 0, sizeof(Rec6c));
  info->rec.unk68 = -1;
  info->rec.unk6a = -1;
  info->rec.unk24 = -1;
  info->unka4 = 0;
  info->unka8 = 0;
  FUN_0008cae8(DAT_002beaa8);
}

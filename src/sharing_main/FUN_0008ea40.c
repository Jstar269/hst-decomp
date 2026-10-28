/* HSTMATCH module=hstp_trans_main.prx start=0x0008ea40 end=0x0008eadc symbol=FUN_0008ea40 lang=c99 */
/* Clone of src/eboot/FUN_0008d2ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Tail of a larger Entry-like record (0xc8 and up), sibling layout of Entry in hst/entry_records.h. */
typedef struct EntryTail {
  char pad00[0xc8];
  u8 unkc8;       /* 0xc8 */
  u8 unkc9;       /* 0xc9 */
  char padca;
  u8 unkcb;       /* 0xcb */
  char strcc[13]; /* 0xcc, default UTF-8 string */
  char padd9[0x14];
  u8 unked;       /* 0xed */
  u8 unkee;       /* 0xee */
  u8 unkef;       /* 0xef */
  u8 unkf0;       /* 0xf0 */
  char padf1[3];
  s32 unkf4;      /* 0xf4 */
  s32 unkf8;      /* 0xf8 */
  float unkfc;    /* 0xfc, initial 5.0f */
  u8 unk100;      /* 0x100, initial 10 */
  u8 unk101;      /* 0x101 */
  char pad102[2];
  u32 unk104;     /* 0x104 */
} EntryTail;

void FUN_0008ea40(EntryTail *entry)
{
  entry->unkc8 = 0;
  entry->unkcb = 0;
  entry->unkc9 = 0;
  entry->unked = 0;
  entry->unkee = 0;
  entry->unkef = 0;
  entry->unkf0 = 0;
  entry->unkf4 = -1;
  entry->unkf8 = -1;
  entry->unkfc = 5.0f;
  entry->unk100 = 10;
  entry->unk101 = 0;
  entry->unk104 = 0;
  /* default UTF-8 string, five characters (four 3-byte kana, then 'P') */
  entry->strcc[0] = 0xe3;
  entry->strcc[1] = 0x81;
  entry->strcc[2] = 0xbf;
  entry->strcc[3] = 0xe3;
  entry->strcc[4] = 0x82;
  entry->strcc[5] = 0x93;
  entry->strcc[6] = 0xe3;
  entry->strcc[7] = 0x83;
  entry->strcc[8] = 0x86;
  entry->strcc[9] = 0xe3;
  entry->strcc[10] = 0x83;
  entry->strcc[11] = 0x8b;
  entry->strcc[12] = 0x50;
}

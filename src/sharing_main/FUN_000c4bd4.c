/* HSTMATCH module=hstp_trans_main.prx start=0x000c4bd4 end=0x000c4c80 symbol=FUN_000c4bd4 lang=c99 */
/* Clone of src/eboot/FUN_000c1534.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { TEXT_SIZE = 0x80, PAIR_COUNT = 4 };

/* Output record: one value from each source array, the second stored twice. */
typedef struct PairOut {
  u32 first;      /* 0x0 */
  u32 second;     /* 0x4 */
  u32 second_dup; /* 0x8 */
  char pad0c[4];
} PairOut;        /* size 0x10 */

typedef struct SettingsBlock {
  char pad00[0x48];
  u32 first[PAIR_COUNT];            /* 0x48 */
  u32 second[PAIR_COUNT];           /* 0x58 */
  char pad68[0x80 - 0x68];
  u32 src_text0;                    /* 0x80 */
  u32 src_text1;                    /* 0x84 */
  u32 src_text2;                    /* 0x88 */
  u32 src_byte;                     /* 0x8c */
  char pad90[0x114 - 0x90];
  char text0[TEXT_SIZE];            /* 0x114 */
  char text1[TEXT_SIZE];            /* 0x194 */
  char text2[TEXT_SIZE];            /* 0x214 */
  char pad294[0x614 - 0x294];
  char byte_copy;                   /* 0x614 */
  char pad615[3];
  PairOut out[PAIR_COUNT];          /* 0x618 */
} SettingsBlock;

extern u32 * FUN_000149a8();

/* Copies the three source texts (strcpy), the byte and the value pairs into the output area. */
void FUN_000c4bd4(SettingsBlock *self)
{
  FUN_000149a8(self->text0,self->src_text0);
  FUN_000149a8(self->text1,self->src_text1);
  FUN_000149a8(self->text2,self->src_text2);
  self->byte_copy = (char)self->src_byte;
  self->out[0].first = self->first[0];
  self->out[0].second = self->second[0];
  self->out[0].second_dup = self->second[0];
  self->out[2].first = self->first[2];
  self->out[2].second = self->second[2];
  self->out[2].second_dup = self->second[2];
  self->out[1].first = self->first[1];
  self->out[1].second = self->second[1];
  self->out[1].second_dup = self->second[1];
  self->out[3].first = self->first[3];
  self->out[3].second = self->second[3];
  self->out[3].second_dup = self->second[3];
}

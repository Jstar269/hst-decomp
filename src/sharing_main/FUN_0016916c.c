/* HSTMATCH module=hstp_trans_main.prx start=0x0016916c end=0x00169290 symbol=FUN_0016916c lang=c99 */
/* Clone of src/eboot/FUN_0015cbc4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_kind.h"

/* Split a flat id into a table kind and an index inside it:
   0x00 kind 10, 0x04 kind 0, 0x40 kind 11, 0x50 kind 2, 0x60 kind 1, 0x80 kind 3, 0xa0 kind 4, 0xb0 kind 5,
   0xd0 kind 6, 0xe4 kind 7; anything else gives kind -1, index -1. */
void FUN_0016916c(int id,u32 *kind,int *index)
{
  if (id < 4) {
    *kind = ENTRY_KIND_10;
    *index = id;
  }
  else if (id + -4 < 0x3c) {
    *kind = ENTRY_KIND_0;
    *index = id + -4;
  }
  else if (id + -0x40 < 0x10) {
    *kind = ENTRY_KIND_11;
    *index = id + -0x40;
  }
  else if (id + -0x50 < 0x10) {
    *kind = ENTRY_KIND_2;
    *index = id + -0x50;
  }
  else if (id + -0x60 < 0x20) {
    *kind = ENTRY_KIND_1;
    *index = id + -0x60;
  }
  else if (id + -0x80 < 0x20) {
    *kind = ENTRY_KIND_3;
    *index = id + -0x80;
  }
  else if (id + -0xa0 < 0x10) {
    *kind = ENTRY_KIND_4;
    *index = id + -0xa0;
  }
  else if (id + -0xb0 < 0x20) {
    *kind = ENTRY_KIND_5;
    *index = id + -0xb0;
  }
  else if (id + -0xd0 < 0x10) {
    *kind = ENTRY_KIND_6;
    *index = id + -0xd0;
  }
  else if (id + -0xe4 < 0xc) {
    *kind = ENTRY_KIND_7;
    *index = id + -0xe4;
  }
  else {
    *kind = ENTRY_KIND_NONE;
    *index = -1;
  }
}

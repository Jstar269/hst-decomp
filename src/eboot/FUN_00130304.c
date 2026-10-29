/* HSTMATCH module=EBOOT.BIN start=0x00130304 end=0x00130654 symbol=FUN_00130304 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen mechanical draft) corrected by hand: flipped the strcmp-equality chain to the positive if/else-if form, an accumulator per digit field, and the loop increment order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002db130;
extern u8 DAT_002db134;
extern char DAT_002db01c[];
extern char DAT_002db100[];
extern char DAT_002db10c[];
extern char DAT_002db118[];
extern char DAT_002db124[];
extern char DAT_002db13c[];
extern char DAT_002db144[];
extern char DAT_002db150[];
extern char DAT_002db158[];
extern char DAT_002db164[];
extern char DAT_002db174[];
extern char DAT_002db180[];
extern char *FUN_00014d64();

/* Classifies a command name by substring match and returns its kind id (0 if none). Kinds that carry
   digits in the name also set *out: kind 4 ORs in one bit per 2-digit number in a separator-delimited
   list; the others store a 2- or 3-digit number. */
u32 FUN_00130304(u32 unused, char *name, unsigned int *out)
{
  char *hit;
  char *cur;
  int num;
  u32 kind;

  kind = 0;
  if (name == 0) {
    kind = 0;
  }
  else {
    if (FUN_00014d64(name, DAT_002db100) != 0) {
      kind = 1;
    }
    else if (FUN_00014d64(name, DAT_002db10c) != 0) {
      kind = 2;
    }
    else if (FUN_00014d64(name, DAT_002db118) != 0) {
      kind = 3;
    }
    else if (FUN_00014d64(name, DAT_002db124) != 0) {
      kind = 4;
      cur = FUN_00014d64(name, DAT_002db124) + 10;
      while (1) {
        num = 0;
        num += (*cur - '0') * 10;
        num += cur[1] - '0';
        *out = *out | 1 << num;
        cur++;
        hit = FUN_00014d64(cur, &DAT_002db130);
        if (hit == 0) break;
        cur = hit + 1;
      }
    }
    else if (FUN_00014d64(name, &DAT_002db134) != 0) {
      kind = 5;
      hit = FUN_00014d64(name, &DAT_002db134);
      num = 0;
      num += (hit[4] - '0') * 10;
      num += hit[5] - '0';
      *out = num;
    }
    else if (FUN_00014d64(name, DAT_002db13c) != 0) {
      kind = 6;
      hit = FUN_00014d64(name, DAT_002db13c);
      num = 0;
      num += (hit[6] - '0') * 10;
      num += hit[7] - '0';
      *out = num;
    }
    else if (FUN_00014d64(name, DAT_002db144) != 0) {
      kind = 7;
    }
    else if (FUN_00014d64(name, DAT_002db150) != 0) {
      kind = 8;
    }
    else if (FUN_00014d64(name, DAT_002db158) != 0) {
      kind = 9;
    }
    else if (FUN_00014d64(name, DAT_002db01c) != 0) {
      kind = 10;
      hit = FUN_00014d64(name, DAT_002db01c);
      num = 0;
      num += (hit[10] - '0') * 100;
      num += (hit[0xb] - '0') * 10;
      num += hit[0xc] - '0';
      *out = num;
    }
    else if (FUN_00014d64(name, DAT_002db164) != 0) {
      kind = 0xc;
    }
    else if (FUN_00014d64(name, DAT_002db174) != 0) {
      kind = 0xd;
    }
    else if (FUN_00014d64(name, DAT_002db180) != 0) {
      kind = 0xe;
      hit = FUN_00014d64(name, DAT_002db180);
      num = 0;
      num += (hit[0xb] - '0') * 100;
      num += (hit[0xc] - '0') * 10;
      num += hit[0xd] - '0';
      *out = num;
    }
  }
  return kind;
}

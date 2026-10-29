/* HSTMATCH module=EBOOT.BIN start=0x001814bc end=0x001815bc symbol=FUN_001814bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a/v3) corrected by hand: inverted outer and nested condition ordering; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Global option block read through an accessor. */
typedef struct Options {
  char pad45[0x45];
  u8 alt_layout;      /* 0x45 */
  char pad46[0x94 - 0x46];
  u8 layout_enabled;  /* 0x94 */
} Options;

/* Screen with four consecutive item handles, 0x14 apart. */
typedef struct ItemScreen {
  char pad[0x80];
  u32 item_a;         /* 0x80 */
  char pad84[0x94 - 0x84];
  u32 item_b;         /* 0x94 */
  char pad98[0xa8 - 0x98];
  u32 item_c;         /* 0xa8 */
  char padac[0xbc - 0xac];
  u32 item_d;         /* 0xbc */
} ItemScreen;

extern void FUN_000ffb3c();
extern Options *FUN_0016bc70();

void FUN_001814bc(ItemScreen *self)
{
  u32 *item_d;
  u32 *item_c;
  u32 *item_b;
  u32 *item_a;
  Options *options;

  item_a = &self->item_a;
  item_b = &self->item_b;
  item_c = &self->item_c;
  item_d = &self->item_d;
  options = FUN_0016bc70();
  if (options->layout_enabled != '\0') {
    options = FUN_0016bc70();
    if (options->alt_layout != '\0') {
      FUN_000ffb3c(*item_a,0);
      FUN_000ffb3c(*item_b,0);
      FUN_000ffb3c(*item_c,1);
      FUN_000ffb3c(*item_d,1);
    }
    else {
      FUN_000ffb3c(*item_a,1);
      FUN_000ffb3c(*item_b,1);
      FUN_000ffb3c(*item_c,0);
      FUN_000ffb3c(*item_d,0);
    }
  }
  else {
    FUN_000ffb3c(*item_a,1);
    FUN_000ffb3c(*item_b,1);
    FUN_000ffb3c(*item_c,1);
    FUN_000ffb3c(*item_d,1);
  }
}

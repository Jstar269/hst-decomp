/* HSTMATCH module=EBOOT.BIN start=0x001c2ea8 end=0x001c2f90 symbol=FUN_001c2ea8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the two DAT pointers as structs, FUN_002afcd0 as int and &DAT_0034179c as the address; kept the byte read as a uchar local and the second pointer in a local (matching idioms for register colours); readability pass; exact match verified; names and types await human review. */
#include "hst/menu_state.h"

typedef struct Pick { char pad[0x169]; unsigned char active; unsigned char col; unsigned char row; } Pick;
typedef struct Cfg { char pad[0xcc]; unsigned col; unsigned row; } Cfg;

extern Cfg *DAT_0034a114;
extern Pick *DAT_0034b5d8;
extern int DAT_0034179c;
extern void FUN_001b1c44(int *, int);
extern void FUN_001c7d30(void *, unsigned, unsigned, int, int);
extern void FUN_001cd88c(MenuState *, int, int);
extern int FUN_002afcd0();
extern void FUN_002afce0(int);

/* State handler: leaves the state on a cancel input, or when a 1-based (col,row) pick is made and
   differs from the current config, forwards the 0-based pair to FUN_001c7d30. */
void FUN_001c2ea8(MenuState *self)
{
  if (FUN_002afcd0() != 0) {
    FUN_002afce0(0);
    FUN_001cd88c(self, 0, 1);
    FUN_001b1c44(&DAT_0034179c, 4);
  }
  if (DAT_0034b5d8 != 0 && DAT_0034b5d8->active != 0) {
    FUN_002afce0(0);
    FUN_001cd88c(self, 0, 1);
    unsigned char row1 = DAT_0034b5d8->row;
    Cfg *cfg = DAT_0034a114;
    unsigned col = (unsigned char)(DAT_0034b5d8->col - 1);
    if (col != cfg->col || (unsigned char)(row1 - 1) != cfg->row) {
      FUN_001c7d30(self->parent, col, (unsigned char)(row1 - 1), -1, 1);
    }
  }
}

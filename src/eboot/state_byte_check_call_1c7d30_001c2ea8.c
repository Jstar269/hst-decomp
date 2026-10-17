/* HSTMATCH module=EBOOT.BIN start=0x001c2ea8 end=0x001c2f90 symbol=FUN_001c2ea8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the two DAT pointers as structs, FUN_002afcd0 as int and &DAT_0034179c as the address; kept the byte read as a uchar local and the second pointer in a local (matching idioms for register colours); exact match verified; names and types await human review. */
typedef struct Obj { char pad[0x18]; int f18; } Obj;
typedef struct State { char pad[0x169]; unsigned char f169; unsigned char f16a; unsigned char f16b; } State;
typedef struct Cfg { char pad[0xcc]; unsigned f_cc; unsigned f_d0; } Cfg;

extern Cfg *DAT_0034a114;
extern State *DAT_0034b5d8;
extern int DAT_0034179c;
extern void FUN_001b1c44(int *, int);
extern void FUN_001c7d30(int, unsigned, unsigned, int, int);
extern void FUN_001cd88c(Obj *, int, int);
extern int FUN_002afcd0();
extern void FUN_002afce0(int);

void FUN_001c2ea8(Obj *param_1)
{
  if (FUN_002afcd0() != 0) {
    FUN_002afce0(0);
    FUN_001cd88c(param_1, 0, 1);
    FUN_001b1c44(&DAT_0034179c, 4);
  }
  if (DAT_0034b5d8 != 0 && DAT_0034b5d8->f169 != 0) {
    FUN_002afce0(0);
    FUN_001cd88c(param_1, 0, 1);
    unsigned char y = DAT_0034b5d8->f16b;
    Cfg *c = DAT_0034a114;
    unsigned x = (unsigned char)(DAT_0034b5d8->f16a - 1);
    if (x != c->f_cc || (unsigned char)(y - 1) != c->f_d0) {
      FUN_001c7d30(param_1->f18, x, (unsigned char)(y - 1), -1, 1);
    }
  }
}

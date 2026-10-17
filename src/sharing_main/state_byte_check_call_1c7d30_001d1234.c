/* HSTMATCH module=hstp_trans_main.prx start=0x001d1234 end=0x001d131c symbol=FUN_001d1234 lang=c99 */
/* Clone of src/eboot/state_byte_check_call_1c7d30_001c2ea8.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the two DAT pointers as structs, FUN_002bf720 as int and &DAT_003eaad8 as the address; kept the byte read as a uchar local and the second pointer in a local (matching idioms for register colours); exact match verified; names and types await human review. */
typedef struct Obj { char pad[0x18]; int f18; } Obj;
typedef struct State { char pad[0x169]; unsigned char f169; unsigned char f16a; unsigned char f16b; } State;
typedef struct Cfg { char pad[0xcc]; unsigned f_cc; unsigned f_d0; } Cfg;

extern Cfg *DAT_003f344c;
extern State *DAT_003f4918;
extern int DAT_003eaad8;
extern void FUN_001bfc3c(int *, int);
extern void FUN_001d61c4(int, unsigned, unsigned, int, int);
extern void FUN_001dbf68(Obj *, int, int);
extern int FUN_002bf720();
extern void FUN_002bf730(int);

void FUN_001d1234(Obj *param_1)
{
  if (FUN_002bf720() != 0) {
    FUN_002bf730(0);
    FUN_001dbf68(param_1, 0, 1);
    FUN_001bfc3c(&DAT_003eaad8, 4);
  }
  if (DAT_003f4918 != 0 && DAT_003f4918->f169 != 0) {
    FUN_002bf730(0);
    FUN_001dbf68(param_1, 0, 1);
    unsigned char y = DAT_003f4918->f16b;
    Cfg *c = DAT_003f344c;
    unsigned x = (unsigned char)(DAT_003f4918->f16a - 1);
    if (x != c->f_cc || (unsigned char)(y - 1) != c->f_d0) {
      FUN_001d61c4(param_1->f18, x, (unsigned char)(y - 1), -1, 1);
    }
  }
}

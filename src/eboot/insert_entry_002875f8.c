/* HSTMATCH module=EBOOT.BIN start=0x002875f8 end=0x002876a0 symbol=FUN_002875f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 24-byte record struct, !(0 < param_3) condition, and exact local declaration order; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern int DAT_0034a2e0;
extern void FUN_00225b00(int, int, int, int, int);
extern int FUN_00288f2c(int, int *);
extern int FUN_00289544(void *, int, void *, void *);

struct Rec {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
  int f14;
};

void FUN_002875f8(int param_1, int param_2, uint param_3, int param_4)
{
  int local_4;
  struct Rec rec;
  int out;
  int p28;

  if (param_4 <= 0) {
    local_4 = 0;
    int r = FUN_00288f2c(param_1, &local_4);
    if (r < 0) {
      return;
    }
    if (local_4 == 0) {
      return;
    }
    FUN_00225b00(DAT_0034a2e0, param_2, local_4, r, !(0 < param_3));
    return;
  }

  rec.fc = param_3 & 0xff;
  rec.f0 = 61;
  rec.f4 = param_4;
  p28 = param_1 + 104;
  rec.f8 = param_2;
  FUN_00289544(&out, param_1 + 100, &p28, &rec);
}

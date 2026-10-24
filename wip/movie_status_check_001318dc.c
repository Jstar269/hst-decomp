/* HSTMATCH module=EBOOT.BIN start=0x001318dc end=0x00131a88 symbol=FUN_001318dc lang=c99 */
/* NEAR MISS 103/107 words, 17 differing (measured; first diff +0x88): the 5-case chain is a `switch` written
   ascending (MWCC emits the compares in reverse, 9..5), the float lookup table and the (int) trunc.w.s conversion
   match. The tail handle test is a sparse `switch` (one case per constant) so retail's per-constant
   `li v1,N; beq a0,v1,0x131a68` chain is reproduced, and the `i == 0` select is written `if (i != 0) ... else`
   to get retail's `beqzl` rather than `bnezl`. Residue: four commutative `addu` operand orders and the tail's
   ascending-versus-descending compare order, both compiler choice (a descending `if` chain measured 105/107,
   differ 35 and was rejected). */
extern float DAT_002db1bc;
extern float DAT_002db1c0;
extern float DAT_002db1c4;
extern float DAT_002db1c8;
extern int *DAT_003386b0;
extern int *DAT_00338b44;

int FUN_001318dc(int param_1, int param_2)
{
  float t[4];
  int obj;
  int i;
  int r;

  r = 0;
  obj = 0;
  t[0] = DAT_002db1bc;
  t[1] = DAT_002db1c0;
  t[2] = DAT_002db1c4;
  t[3] = DAT_002db1c8;

  switch (param_2) {
  case 5:
    obj = (int)((int **)DAT_003386b0)[*(int *)(param_1 + 0x128) + 0x1c];
    break;
  case 6:
    obj = (int)((int **)DAT_003386b0)[*(int *)(param_1 + 300) + 0x1c];
    break;
  case 7:
    obj = (int)((int **)DAT_003386b0)[DAT_00338b44[0x50 / 4] + 0x1c];
    break;
  case 8:
    obj = (int)((int **)DAT_003386b0)[(int)t[DAT_00338b44[0x50 / 4]] + 0x1c];
    break;
  case 9:
    obj = (int)((int **)DAT_003386b0)[*(int *)(param_1 + 0x130) + 0x1c];
    break;
  }

  if (obj != 0 && *(int *)(obj + 0x5bc) != 0) {
    i = *(int *)(*(int *)(obj + 0x5bc) + 0x58);
    if (i != 0)
      i = *(int *)(i + 0xf0);
    else
      i = -1;
    switch (i) {
    case 0xe1:
      r = 1;
      break;
    case 0xe0:
    case 0x3d:
    case 0x3c:
    case 0x3b:
    case 0x3a:
      r = 1;
      break;
    }
  }
  return r;
}
// near miss from lane fm7 (unreviewed)
// improved by lane fm10 (unreviewed): 37 -> 17 differing words

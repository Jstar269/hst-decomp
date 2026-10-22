/* HSTMATCH module=EBOOT.BIN start=0x002821a0 end=0x00282214 symbol=FUN_002821a0 lang=c99 */
extern char DAT_002fe988;
extern void FUN_002803d8(void *);

int FUN_002821a0(int param_1)
{
  if (*(int *)(param_1 + 0x5c) == 0) return 2;
  switch (*(int *)(param_1 + 0x80)) {
  case 3:
  case 2:
    return 2;
  case 1:
    return 3;
  case 0:
    return 4;
  default:
    FUN_002803d8(&DAT_002fe988);
    return 4;
  }
}

// NEAR MISS: 5 words differ (29/29 words).
// Retail loads the switch value into a1 (`lw a1,128(a0)` in the bnezl delay slot) and tests it
// with beqzl/beql; ours puts it in v1 (`lw v1,128(a0)`) and is otherwise identical.
// Ruled out: int/unsigned/struct-member/pointer-param spellings of the value, a separate `state`
// local, grouped vs separate case bodies (grouped `case 3: case 2:` is required for the beql/beq
// test order), C++ vs C99, `switch (*(int*)(p+0x80))` inline (also gives v1 once the cases are
// grouped), declaring/assigning the value before or after the state test.
// near miss from lane fm2 (unreviewed)

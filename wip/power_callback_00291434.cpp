/* HSTMATCH module=EBOOT.BIN start=0x00291434 end=0x002914c0 symbol=FUN_00291434 lang=c++ */
extern "C" {
extern unsigned char DAT_0034a80c;
extern char DAT_002ff8e8[];
extern char DAT_002ff928[];
extern char DAT_002ff968[];
void FUN_0028fb44(...);

int FUN_00291434(int param_1, unsigned param_2)
{
  if ((param_2 & 0x80000) != 0 || (param_2 & 0x10000) != 0) {
    DAT_0034a80c = 1;
    if ((param_2 & 0x80000) != 0) {
      FUN_0028fb44(DAT_002ff8e8);
    }
    else {
      FUN_0028fb44(DAT_002ff928);
    }
  }
  else {
    if ((param_2 & 0x40000) != 0) {
      DAT_0034a80c = 0;
      FUN_0028fb44(DAT_002ff968);
    }
  }
  return 0;
}
}

// NEAR MISS, 4 words off, all in the last block (0x40000 case): retail schedules
//   lui a0,0x30 / lui v0,0x35 / addiu a0,a0,-1688 / jal 0x28fb44 / sb zero,-22516(v0)   (store in the jal slot)
// ours gives lui v0 / lui a0 / sb zero / jal / addiu (addiu in the slot). Retail's IR order must be [string address]
// [flag store] [call], which no source form produced. Ruled out: local copy of the string pointer before the store,
// volatile flag, const char arrays, `const char *, ...` prototype, inline Rep(flag, msg) / Rep(msg, flag) helpers taking
// the store and call together, passing param_2 as an extra logger argument, C vs C++ (lang=c99 gives the same words),
// a file-static flag (header bss=0x0034a80c) with the call before the store (MWCC never hoists a store above a call:
// `call; store` leaves the store after the jal, 2 words off), an empty stub defined earlier in the same file,
// a string literal instead of the DAT_ symbol. The layout of the two other blocks and the rest match: the whole
// condition is written positive-first (`(p&0x80000)!=0 || (p&0x10000)!=0` as the if, the 0x40000 test as the else arm)
// because Ghidra's negated form puts the 0x40000 block first.

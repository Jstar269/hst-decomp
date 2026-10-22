/* HSTMATCH module=EBOOT.BIN start=0x0022ca58 end=0x0022ca9c symbol=FUN_0022ca58 lang=c99 */
typedef unsigned char byte;
typedef unsigned char bool;
typedef unsigned char undefined;

extern undefined *DAT_00341ccc;

bool FUN_0022ca58(int param_1)
{
  byte *pbVar1;

  if (param_1 < 0) {
    pbVar1 = (byte *)0;
  }
  else {
    if (param_1 < 0xf) {
      pbVar1 = (byte *)(DAT_00341ccc + param_1 * 0x38 + 4);
    }
    else {
      pbVar1 = (byte *)0;
    }
  }
  return (unsigned)(*pbVar1 - 4) < 2;
}

// NEAR MISS: 17/17 words, 9 words differ.
// Retail: `lui v0,0x34; bltz a0,ZERO; lw v1,7372(v0)` (the table base is hoisted into the bltz
// delay slot), `slti at,a0,15; beqzl at,JOIN; move v0,zero`, compute with `addu v0,v1,v0`,
// `b JOIN; addiu v0,v0,4`, then ONE shared `move v0,zero` block at 0x22ca88 that falls into JOIN.
// Ours tests with `bgezl a0` over its own inline `move v0,zero` block, so the base is loaded late
// (`lui/lw` + `addu v0,v0,v1`) and the CLAMP/lbu tail shifts. Ruled out: if/else-if/else in source
// order, nested if in the else, `if (a<0||a>=0xf)` (bltzl/bnezl, 18 words), the same as a ternary
// (bltzl, 20 words), the inverted `if (a>=0&&a<0xf)` (bltzl, 18 words), a `pBase` local (fixes the
// tail but keeps the bgez polarity), `pbVar1=0; if(a>=0){if(a<0xf)..}` (16 words).
// near miss from lane fm2 (unreviewed)

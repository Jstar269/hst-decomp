/* HSTMATCH module=EBOOT.BIN start=0x001f7584 end=0x001f76e4 symbol=FUN_001f7584 lang=c++ helpers=FUN_001ef3f8@0x001ef3f8-0x001ef424 rodata=0x002c9118 */
extern "C" {
extern char DAT_002eeb48[];
extern char DAT_002eeb54[];
extern char DAT_002eeb60[];
extern char DAT_002eeb74[];
}
// NEAR 17/88 words, best after 15 hstmatch compiles. The same-file empty variadic logger and the
// six-entry rodata switch table are required; code from the switch body through the final conversion
// matches exactly. Remaining differences are the `span + 9` temp/registers (v0/f0/f1 vs t0/f1/f2),
// the integer registers used for 75.0f/24.0f/1.0f, and the order of the table-base addiu and mode shift.
// Ruled out: an outer mode-range guard adds a second check; a local inline Step helper changes one
// more word; an ordinary register local and a denominator temporary leave the prologue unchanged.
// MWCC rejects `asm("$8")` register bindings, so no fixed-register source was retained.

extern "C" {
static void FUN_001ef3f8(...)
{
}
}

extern "C" int FUN_001f7584(int total, int span, unsigned int mode)
{
    float denominator;
    float step;
    float rate;
    float factor;
    register int span_plus_nine = span + 9;

    denominator = (float)span_plus_nine;
    step = 24.0f / denominator;
    factor = 1.0f;
    rate = 75.0f / (float)total;
    unsigned int selected_mode = mode;
    switch (selected_mode) {
    case 0: factor = 0.1f; break;
    case 1: factor = 0.2f; break;
    case 2: factor = 0.3f; break;
    case 3: factor = 0.8f; break;
    case 4: factor = 1.0f; break;
    case 5: factor = 1.5f; break;
    default: break;
    }

    FUN_001ef3f8(DAT_002eeb48);
    FUN_001ef3f8(DAT_002eeb54, (double)factor);
    FUN_001ef3f8(DAT_002eeb60, (double)step);
    FUN_001ef3f8(DAT_002eeb74, (double)rate);

    return (int)(10000.0f * (factor * (1.0f / (step + rate))));
}
// near miss from lane lnm2 (unreviewed)

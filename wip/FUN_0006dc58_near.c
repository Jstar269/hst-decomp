/* HSTMATCH module=EBOOT.BIN start=0x0006dc58 end=0x0006ddb4 symbol=FUN_0006dc58 lang=c99 */
void FUN_0006dc58(int param_1, int param_2, float *param_3)
{
    unsigned char c;
    int off;

    off = param_2 * 0x1c;
    c = (unsigned char)param_3[0];
    *(unsigned char *)(*(int *)(param_1 + *(int *)(param_1 + 0x54) * 4 + 100) + off) = c;
    c = (unsigned char)param_3[1];
    *(unsigned char *)(*(int *)(param_1 + *(int *)(param_1 + 0x54) * 4 + 100) + off + 1) = c;
    c = (unsigned char)param_3[2];
    *(unsigned char *)(*(int *)(param_1 + *(int *)(param_1 + 0x54) * 4 + 100) + off + 2) = c;
    c = (unsigned char)(param_3[3] * 1.9921875f);
    *(unsigned char *)(*(int *)(param_1 + *(int *)(param_1 + 0x54) * 4 + 100) + off + 3) = c;
}

// PARKED (dsn2). 87/87 words, only FIVE words differ -- all `addu` operand order:
//   ours `addu a1,a0,a1` / `addu a1,v1,a1`  vs retail `addu a1,a1,a0` / `addu a1,a1,v1`
//   (4 base adds + the 4th block's a0 variant). Everything else, including the two-path
//   (unsigned char) float conversion with the `or 0xFFFF8000` fixup, the `lw a3,84(a0)` reload
//   per block and the offset CSE in v1, is word-identical.
// Learned: the conversion must be a PLAIN `(unsigned char)param_3[i]` cast -- the Ghidra
// `if (f < 2^31) c = (unsigned char)(int)f; else ...` double-converts and bloats the code, and
// `(unsigned char)(param_3[3] * 1.9921875f)` for the 4th. An `int off = param_2 * 0x1c;` local
// (vs reassigning the parameter) is what nailed the whole schedule; without it 24 words differed.
// Ruled out for the operand order: swapping the base sum's source order, an array-index form
// `((int *)(param_1 + 100))[idx]` (adds `addiu base`), and a struct member-array form
// (`self->bufs[self->slot]`, changes the whole schedule, +1 word).
// near miss from lane dsn2 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0022cd78 end=0x0022cdd0 symbol=FUN_0022cd78 lang=c99 */
/* Unresolved leaf copy loop (16 words differing due to temporary register allocation):
 * Retail uses contiguous temporary registers $v1, $a0, $a1, $a2, $a3, $t0:
 * - src pointer in $a3, dst pointer in $a2, loop induction counter in $t0.
 * - copy temporaries batched as 3 words ($a1, $a0, $v1), then 2 words ($a0, $v1).
 * Instruction scheduling, loop bounds, offsets, and increments match retail line-for-line.
 */

extern int DAT_002c9b38[];
extern int DAT_0034a318[];

void FUN_0022cd78(void)
{
  int *src = DAT_002c9b38;
  int *dst = DAT_0034a318;
  int i = 0;
  do {
    int w0 = src[0];
    int w1 = src[1];
    int w2 = src[2];
    dst[0] = w0;
    dst[1] = w1;
    dst[2] = w2;
    int w3 = src[3];
    int w4 = src[4];
    i += 5;
    dst[3] = w3;
    dst[4] = w4;
    src += 5;
    dst += 5;
  } while (i < 15);
}
// near miss from lane u6fr1-1 (unreviewed)

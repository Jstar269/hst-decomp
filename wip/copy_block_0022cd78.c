/* HSTMATCH module=EBOOT.BIN start=0x0022cd78 end=0x0022cdd0 symbol=FUN_0022cd78 lang=c99 */
/* Unresolved leaf copy loop (best is 15 of 22 words differing):
 * Retail uses src=$a3, dst=$a2, counter=$t0 and copy temporaries $a1,$a0,$v1 then $a0,$v1.
 * The best candidate gets src=$a3 and counter=$t0, but dst=$t1 and temporaries $v1,$a2,$a0 then $a0,$a1.
 * Copy body order, loop bounds, offsets and branch delay-slot fill otherwise match.
 */

extern int DAT_002c9b38[];
extern int DAT_0034a318[];

void FUN_0022cd78(void)
{
  int *dst = DAT_0034a318;
  int i = 0;
  int *src = DAT_002c9b38;
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
// lnm1 attempted all six declaration orders, multiple orderings of the five copied values, const src, a typed
// five-word Block, Cursor wrappers, and an inline CopyFive helper. Best remains 15 differing words; preserve this
// natural dst/i/src declaration order and do not repeat the rejected variants.
// improved by lane lnm1 (unreviewed): 19 -> 15 differing words

/* HSTMATCH module=hstp_trans_main.prx start=0x0023ce78 end=0x0023ced0 symbol=FUN_0023ce78 lang=c99 */
/* Unresolved leaf copy loop (best is 15 of 22 words differing):
 * Retail uses src=$a3, dst=$a2, counter=$t0 and copy temporaries $a1,$a0,$v1 then $a0,$v1.
 * The best candidate gets src=$a3 and counter=$t0, but dst=$t1 and temporaries $v1,$a2,$a0 then $a0,$a1.
 * Copy body order, loop bounds, offsets and branch delay-slot fill otherwise match.
 */

extern int DAT_002da0f8[];
extern int DAT_003f3648[];

void FUN_0023ce78(void)
{
  int *dst = DAT_003f3648;
  int i = 0;
  int *src = DAT_002da0f8;
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
// Sharing twin of 0x0022cd78; same retail register shape (dst a2, src a3, counter t0).
// lnm1 attempted all six declaration orders, multiple orderings of the five copied values, const src, a typed
// five-word Block, Cursor wrappers, and an inline CopyFive helper. Best remains 15 differing words; preserve this
// natural dst/i/src declaration order and do not repeat the rejected variants.
// improved by lane lnm1 (unreviewed): 19 -> 15 differing words
// First reconstruction (wip-less queue item, Sharing). 22/22 words, 15 differ: identical to the
// EBOOT twin 0x0022cd78's residue (dst a2 vs t1, same load/store order), so no independent fix.
// near miss from lane dsm1 (unreviewed)

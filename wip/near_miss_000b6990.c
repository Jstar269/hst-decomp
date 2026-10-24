/* STATUS CORRECTION 2026-10-24 (two-record frame): 63/63 words, 58 differ, frame 176 (retail 192).
   Was 52/63, differ 51, frame 80. Retail copies the KEY record into sp+16 AND the mid record into
   sp+96 (ten 2-word moves each) and compares field +56 of the two copies. Source now declares both
   copies as distinct Rec objects; the compared field was f[10] (+40) and is really +56 = f[14].
   FINAL 2026-10-24: 63/63 words, 58 differ (first +0x0, masked), frame 176 (retail 192).
   `volatile int fbase = (int)first;` then the difference off fbase emits retail's sw a1,184 / lw
   round trip; without the volatile it measured 61/63. */
/* HSTMATCH module=EBOOT.BIN start=0x000b6990 end=0x000b6a8c symbol=FUN_000b6990 lang=c99 */
typedef struct {
    float f[20];
} Rec;

void FUN_000b6990(Rec **out, Rec *first, Rec *last, Rec *key)
{
    volatile int fbase = (int)first;
    int n = ((char *)last - (char *)fbase) / 0x50;

    if (n < 1) {
        *out = first;
        return;
    }
    Rec keyCopy = *key;
    Rec midCopy;
    while (n > 0) {
        int half = n / 2;
        midCopy = first[half];

        if (midCopy.f[14] < keyCopy.f[14]) {
            first += half + 1;
            n = n - (half + 1);
        } else {
            n = half;
        }
    }
    *out = first;
}
// Near miss: upper_bound twin of 0x000b6894; the key/mid compare order differs from retail and the
// copy temps again sit in the wrong frame slots.
// near miss from lane ds8 (unreviewed)
// improved by lane fm10 (unreviewed): 62 -> 58 differing words

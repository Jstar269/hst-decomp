/* STATUS CORRECTION 2026-10-24 (two-record frame): 63/63 words, 58 differ, frame 176 (retail 192).
   Was 52/63, differ 51, frame 80. Same pair of 80-byte record copies as 0x000b6990, opposite
   polarity: option element at sp+96, probe at sp+16, compare field +56 (f[14], not f[10]).
   FINAL 2026-10-24: 63/63 words, 58 differ (first +0x0, masked), frame 176 (retail 192).
   Same volatile-base spelling as 0x000b6990 for retail's saved argument at 184. */
/* HSTMATCH module=EBOOT.BIN start=0x000b6894 end=0x000b6990 symbol=FUN_000b6894 lang=c99 */
typedef struct {
    float f[20];
} Rec;

void FUN_000b6894(Rec **out, Rec *first, Rec *last, Rec *key)
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

        if (midCopy.f[14] <= keyCopy.f[14]) {
            first += half + 1;
            n = n - (half + 1);
        } else {
            n = half;
        }
    }
    *out = first;
}
// Near miss: 20-byte (0x50) element copies through two stack temps land at different frame slots
// than retail's local_b0/local_60 pair.
// near miss from lane ds8 (unreviewed)
// improved by lane fm10 (unreviewed): 62 -> 58 differing words

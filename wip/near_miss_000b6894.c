/* HSTMATCH module=EBOOT.BIN start=0x000b6894 end=0x000b6990 symbol=FUN_000b6894 lang=c99 */
typedef struct {
    float f[20];
} Rec;

void FUN_000b6894(Rec **out, Rec *first, Rec *last, Rec *key)
{
    int n = ((char *)last - (char *)first) / 0x50;

    if (n < 1) {
        *out = first;
        return;
    }
    while (n > 0) {
        int half = n / 2;
        Rec mid = first[half];

        if (key->f[10] <= mid.f[10]) {
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

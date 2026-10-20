/* HSTMATCH module=EBOOT.BIN start=0x000b6990 end=0x000b6a8c symbol=FUN_000b6990 lang=c99 */
typedef struct {
    float f[20];
} Rec;

void FUN_000b6990(Rec **out, Rec *first, Rec *last, Rec *key)
{
    int n = ((char *)last - (char *)first) / 0x50;

    if (n < 1) {
        *out = first;
        return;
    }
    while (n > 0) {
        int half = n / 2;
        Rec mid = first[half];

        if (mid.f[10] < key->f[10]) {
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

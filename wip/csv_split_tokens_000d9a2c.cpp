/* HSTMATCH module=EBOOT.BIN start=0x000d9a2c end=0x000d9b1c symbol=FUN_000d9a2c lang=c++ */
/* Hand-written reconstruction attempt; exact match not yet verified. */
extern "C" char DAT_002d6acc[];

extern "C" void FUN_0005da00(void *, char **, char);

extern "C" void FUN_000d9a2c(int *vec, char *s) {
    char *local = 0;
    char *start = 0;
    char c = *s;
    unsigned char uc;
    if (c == 0) return;
    do {
        uc = (unsigned char)c;
        if (uc == ',' || uc == '\r' || uc == '\n') {
            *s = 0;
            s++;
            if (local == 0) local = DAT_002d6acc;
            if ((unsigned)vec[1] < (unsigned)vec[2]) {
                vec[1] = vec[1] + 1;
                *(char **)(vec[0] + vec[1] * 4 - 4) = local;
            } else {
                FUN_0005da00(vec, &local, 0);
            }
            local = 0;
            start = 0;
        } else {
            if (start == 0) {
                local = s;
                start = s;
            }
        }
        s++;
        c = *s;
    } while (c != 0);
}
// NEAR (35/60 words differ); best source is the unsigned-byte comparison form.
// Retail normalizes the input byte into a1 after saving vec in s1; this source
// keeps it in v1/a0 and saves vec later. The append helper and loop branches
// then differ in register placement. Tried: direct pseudocode with shared labels,
// three pointer-state variables, alias and const-alias forms, a struct vector,
// a reference parameter, register qualifiers, C99 mode, a by-value Tag, and
// a local zero arg; none improved on this source.
// improved by lane lnm1 (unreviewed): 52 -> 35 differing words

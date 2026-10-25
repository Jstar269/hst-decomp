/* HSTMATCH module=EBOOT.BIN start=0x0001cc60 end=0x0001cd38 symbol=FUN_0001cc60 lang=c99 */

struct Entry {
    unsigned char len;
    unsigned char val;
};

unsigned char * FUN_0001cc60(unsigned char *p, struct Entry *table)
{
    int code = 0;
    int len = 1;
    int count_minus_1;
    unsigned int rev;
    unsigned int c;
    int k;
    int one = 1;
    int n = *p++;

    if (n > 0) {
        do {
            int count = *p++;
            count_minus_1 = count - 1;
            if (count > 0) {
                unsigned int step = one << len;
                do {
                    c = code;
                    rev = 0;
                    k = len - 1;
                    if (len > 0) {
                        do {
                            rev = (rev << 1) | (c & 1);
                            c >>= 1;
                        } while (k-- > 0);
                    }
                    unsigned char val = *p++;
                    if (rev < 1024) {
                        struct Entry *entry = &table[rev];
                        do {
                            entry->len = len;
                            rev += step;
                            entry->val = val;
                            entry += step;
                        } while (rev < 1024);
                    }
                    if (len < 11) {
                        code++;
                    }
                } while (count_minus_1-- > 0);
            }
            len++;
            code <<= 1;
        } while (len <= n);
    }

    if ((unsigned int)p & 1) {
        p++;
    }
    return p;
}
// Near miss: 18 words differ out of 54.
// Structure, instructions, control flow, loops, and immediates are exact.
// Only temporary register allocation differs: retail has n in t2, one in t1, step in t0,
// whereas ours has n in t1, one in t0, step in a3 (and step2 in t2).
// Ruled out: direct array indexing vs pointer stepping, explicit step2 local vs struct pointer math.
// near miss from lane ag5 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00002408 end=0x0000259c symbol=FUN_00002408 lang=c99 */
typedef struct { unsigned value; unsigned len; unsigned data; } Entry;

typedef struct {
    unsigned key;
    unsigned cur;
    unsigned next;
    unsigned begin;
    unsigned end;
} Out;

extern int FUN_000026d8(Out *, unsigned);
extern int FUN_00002688(unsigned);
extern unsigned FUN_00001040(unsigned, int *);

void FUN_00002408(unsigned key, Out *out)
{
    int hi;
    int lo;
    int i;
    Entry *e;
    unsigned key2;
    unsigned v;
    unsigned rem;
    unsigned total;
    int c;
    int b;
    int a;
    unsigned n;

    out->cur = 0;
    out->next = 0;
    if (FUN_000026d8(out, key) == 0)
        return;
    key2 = key & ~1u;
    hi = (int)(out->end - out->begin) / 12 - 1;
    lo = 0;
    e = 0;
    while (lo <= hi) {
        i = (lo + hi) >> 1;
        e = (Entry *)(out->begin + i * 12);
        if (key2 < e->value) {
            hi = i - 1;
            e = 0;
        } else if (e->value + (e->len & ~1u) < key2) {
            lo = i + 1;
            e = 0;
        } else {
            break;
        }
    }
    if (e != 0) {
        if ((e->len & 1) == 0)
            out->cur = e->data;
        else
            out->cur = (unsigned)(e + 2);
        out->key = e->value;
        v = e->value;
        n = FUN_00002688(out->cur);
        total = 0;
        rem = key2 - v;
        do {
            n = FUN_00001040(n, &c);
            if (c == 0)
                return;
            n = FUN_00001040(n, &b);
            n = FUN_00001040(n, &a);
            if (rem < total + c)
                return;
            total = total + c + b;
        } while (total < rem);
        out->next = out->cur + a;
    }
}
// 0x00002408: 102/101 words, 79 differ. Structure complete: out->cur/out->next = 0;
// if (FUN_000026d8(out,key)==0) return; key2 = key & ~1; hi = (end-begin)/12 - 1;
// binary search over 12-byte {value,len,data} entries (do-while, hi/lo), found entry:
// out->cur = (len&1) ? (unsigned)(e+2) : e->data; out->key = e->value;
// n = FUN_00002688(out->cur); rem = key2 - e->value; loop FUN_00001040(n,&c/&b/&a):
// if (c==0) return; if (rem < total+c) return; total += c+b; while (total < rem);
// out->next = out->cur + a.
// Remainder: `out` lands in s2 in ours and s1 in retail (retail: key=s0, out=s1, total=s2),
// and the whole search loop is one register class off (ours a1/a3/t0/t1/t2 vs ret a2/a3/t1/t2/t3).
// near miss from lane fm11 (unreviewed)

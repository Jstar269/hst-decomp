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
    int i;
    Entry *e;
    int lo;
    int hi;
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
    while (lo <= hi) {
        i = (lo + hi) >> 1;
        e = (Entry *)(out->begin + i * 12);
        if (key2 < e->value) {
            hi = i - 1;
        } else if (e->value + (e->len & ~1u) < key2) {
            lo = i + 1;
        } else {
            goto found;
        }
    }
    e = 0;
found:
    if (e != 0) {
        if (e->len & 1)
            out->cur = (unsigned)&e->data;
        else
            out->cur = e->data;
        out->key = e->value;
        v = e->value;
        rem = key2 - v;
        n = FUN_00002688(out->cur);
        total = 0;
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
// NEAR (lane sx1): 100/101 words, 67 differ (was 102/101, 79 differ). Findings: (1) key2 is a temp (v1) when `rem = key2 - e->value` is computed BEFORE the
// FUN_00002688 call (retail's subu sits in that jal's slot); (2) the search leaves e = the last probed entry and sets `e = 0` only after the loop exits by
// range (`else goto found;` out of the loop, `e = 0; found:`), which gives retail's `move t3,zero` + `beqz t3`; (3) hi/e registers (t1/t3) follow the
// declaration order `Entry *e; int lo; int hi;`; (4) out->cur is `(len & 1) ? (unsigned)&e->data : e->data` as an if/else with the &e->data arm first
// (field address, +8, not e+2).
// Still open: retail keeps a duplicate of each likely-branch slot instruction at the branch target (`beqzl at,L; lw a0,4(t3)` ... L: lw a0,4(t3)), twice
// (bsearch compare and the cur select), so retail has 101 words and ours 100; and out/total land in s2/s1 here vs s1/s2 in retail.
// improved by lane sx1 (unreviewed): 79 -> 67 differing words

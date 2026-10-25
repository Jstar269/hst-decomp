/* HSTMATCH module=EBOOT.BIN start=0x00279f64 end=0x0027a190 symbol=FUN_00279f64 lang=c++ */
struct Rec { char pad0[16]; int key; char pad1[28]; };
struct Less {};
struct It {
    Rec *p;
    It() {}
    It(Rec *q) : p(q) {}
};
struct Pred { Less cmp; Rec *pivot; Pred(Less c, Rec *p) : cmp(c), pivot(p) {} };

extern int DAT_002fe6a8;
extern "C" {
void FUN_0027a658(Rec *a, Rec *b, Rec *c);
void FUN_0027a7a0(It *ret, It first, It last, Pred *pred);
void FUN_0027abac(It *ret, It first, It last, Pred *pred);
void FUN_0027ae64(Rec *first, Rec *last);
void FUN_0027a190(Rec *a, Rec *b);
Rec *FUN_0027a2ec(It *it);
void FUN_00279f64(Rec *first, Rec *last);
}

static inline void IterSwap(It a, It b)
{
    FUN_0027a190(FUN_0027a2ec(&a), FUN_0027a2ec(&b));
}

extern "C" void FUN_00279f64(Rec *first, Rec *last)
{
    for (;;) {
        int n = last - first;
        if (n <= 1) return;
        if (n < 21) {
            FUN_0027ae64(first, last);
            return;
        }
        int q1 = n / 4;
        Rec *m1 = first + (q1 + DAT_002fe6a8 % 5);
        DAT_002fe6a8 = DAT_002fe6a8 + 1;
        if (DAT_002fe6a8 >= 5) DAT_002fe6a8 = -4;
        int q2 = (n * 3) / 4;
        Rec *m2 = first + (q2 + DAT_002fe6a8 % 5);
        DAT_002fe6a8 = DAT_002fe6a8 + 1;
        if (DAT_002fe6a8 >= 5) DAT_002fe6a8 = -4;
        Rec *lm = last - 1;
        FUN_0027a658(m1, m2, lm);
        Less c1;
        Pred pr(c1, lm);
        It r;
        FUN_0027a7a0(&r, It(first), It(lm), &pr);
        Rec *mid = r.p;
        if (mid == first) {
            IterSwap(It(mid), It(lm));
            Less c2;
            Pred pr2(c2, first);
            It r2;
            FUN_0027abac(&r2, It(mid + 1), It(last), &pr2);
            first = r2.p;
        } else if (mid - first < last - mid) {
            FUN_00279f64(first, mid);
            first = mid;
        } else {
            FUN_00279f64(mid, last);
            last = mid;
        }
    }
}
// NEAR 0x00279f64: 52 of 139 words differ (best, d9f64c).
// differs: s-reg colouring (retail first=s1,last=s0,mid=s2,lm=s3; ours first=s2,last=s1,mid=s0), frame 96 vs 112 (retail has 16 extra bytes of locals),
//   retail loads r.p twice after the partition call (lw s2,96; lw v0,96; bne v0,s1) - plain 'mid=r.p; if(r.p==first)' is CSE'd away,
//   retail IterSwap temps: mid temp 44 -> home 52 (swc1), lm temp 48 passed by address (const It& style); ours copies both (32/36).
//   retail stores It(mid+1) temp to sp+44 (dead sw a1,44) before the abac call.
// ruled out: trailing False tag param (moves slots up, worse), IterSwap(It, const It&) (right shape for b but home placed lowest), Less param passed to recursion.
// near miss from lane sn8 (unreviewed)

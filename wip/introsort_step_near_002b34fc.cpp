/* HSTMATCH module=EBOOT.BIN start=0x002b34fc end=0x002b3738 symbol=FUN_002b34fc lang=c++ */
struct Rec { char pad[100]; };
struct Less {};
struct It {
    Rec *p;
    It() {}
    It(Rec *q) : p(q) {}
};
struct Pred { Less cmp; Rec *pivot; Pred(Less c, Rec *p) : cmp(c), pivot(p) {} };

extern int DAT_003030e8;
extern "C" {
void FUN_002b3c6c(Rec *a, Rec *b, Rec *c);
void FUN_002b3db4(It *ret, It first, It last, Pred *pred);
void FUN_002b42c8(It *ret, It first, It last, Pred *pred);
void FUN_002b4580(Rec *first, Rec *last);
void FUN_002b3738(Rec *a, Rec *b);
Rec *FUN_002b39d8(It *it);
void FUN_002b34fc(Rec *first, Rec *last);
}

static inline void IterSwap(It a, It b)
{
    FUN_002b3738(FUN_002b39d8(&a), FUN_002b39d8(&b));
}

extern "C" void FUN_002b34fc(Rec *first, Rec *last)
{
    for (;;) {
        int n = last - first;
        if (n <= 1) return;
        if (n < 21) {
            FUN_002b4580(first, last);
            return;
        }
        int q1 = n / 4;
        Rec *m1 = first + (q1 + DAT_003030e8 % 5);
        DAT_003030e8 = DAT_003030e8 + 1;
        if (DAT_003030e8 >= 5) DAT_003030e8 = -4;
        int q2 = (n * 3) / 4;
        Rec *m2 = first + (q2 + DAT_003030e8 % 5);
        DAT_003030e8 = DAT_003030e8 + 1;
        if (DAT_003030e8 >= 5) DAT_003030e8 = -4;
        Rec *lm = last - 1;
        FUN_002b3c6c(m1, m2, lm);
        Less c1;
        Pred pr(c1, lm);
        It r;
        FUN_002b3db4(&r, It(first), It(lm), &pr);
        Rec *mid = r.p;
        if (mid == first) {
            IterSwap(It(mid), It(lm));
            Less c2;
            Pred pr2(c2, first);
            It r2;
            FUN_002b42c8(&r2, It(mid + 1), It(last), &pr2);
            first = r2.p;
        } else if (mid - first < last - mid) {
            FUN_002b34fc(first, mid);
            first = mid;
        } else {
            FUN_002b34fc(mid, last);
            last = mid;
        }
    }
}
// NEAR 0x002b34fc: 52 of 143 words differ. Same template as 0x00279f64 (48-byte records), here 100-byte records.
// Learned (see also wip/introsort_step_near_00279f64.cpp): retail tag slot copy needs 'struct Less { unsigned char z; }' (an empty Less elides the lbu/sb);
//   declare 'R16 r; Pred pr; Less c1;' in that order with 'R16 { Rec *p; int pad[3]; }' as the partition result type (96..111) and 'pr.cmp = c1' to get r@96, pred@88/92, tag@84, r2@80, pred2@72/76, tag2@68 exactly.
//   wip variant with those slots: try/lane-work/d9f64o.cpp style (frame matches in the first and second groups).
// still differs: s-reg colouring (first=s1,last=s0,mid=s2,lm=s3 in retail), the double load of r.p (lw s2,96; lw v0,96; bne v0,s1), and IterSwap:
//   retail a = temp@44 copied (lwc1/swc1) to a home@52 (16-byte hole 52..67), b = const-ref style temp@48 (not copied); the dead sw a1,44 of It(mid+1) before the abac call.
// near miss from lane sn8 (unreviewed)

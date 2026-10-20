/* HSTMATCH module=EBOOT.BIN start=0x001c6f70 end=0x001c70c0 symbol=FUN_001c6f70 lang=c99 */
// NEAR MISS (34/84 words, first differ at +0x0): the control flow is understood but retail's frame is built
// from by-value struct copies we have not reproduced yet.
// Retail logic (confirmed): p->beg (0x70) / p->count (0x74); end = beg + count.  If n > 0 -> two-key search
// (key == elem->0x30 && n == elem->0x34), else single-key search (key == elem->0x30); `return *it` if the
// loop broke, else 0.  The `xor/sltiu/xori` trio at the tail is MWCC's `it != end`.
// What is missing (the 50 words): retail keeps both searches' locals in the frame and copies them around in
// 3-word / 4-word blocks through $f0/$f1/$f2 (`sw a1,44(sp); lwc1 $f0,44(sp); swc1 $f0,16(sp)` ...), i.e. the
// search locals are STRUCTS taken by value (1-key form = {key, end, cur}; 2-key form = {key, n, end, cur}).
// That is the shape of an inlined template/helper taking a range + a by-value predicate.  Written as plain
// loops over `it`, MWCC keeps everything in registers (34 words) and never builds the frame.
// Ruled out: plain `for`/`while` loop forms with the two searches selected by `n < 1` / `n > 0` (34 and 33
// words, first differ at +0x0).
struct Elem {
    char pad[0x30];
    int f30;
    int f34;
};

struct Owner {
    char pad[0x70];
    struct Elem **beg;
    int count;
};

struct Elem *FUN_001c6f70(struct Owner *p, int key, int n)
{
    struct Elem **beg = p->beg;
    struct Elem **end = beg + p->count;
    struct Elem **it;

    if (n < 1) {
        for (it = beg; it != end && key != (*it)->f30; it++)
            ;
    } else {
        for (it = beg; it != end; it++) {
            int found = 0;
            if (key == (*it)->f30)
                found = (n == (*it)->f34);
            if (found) break;
        }
    }
    if (it != end) return *it;
    return 0;
}
// near miss from lane ds2 (unreviewed)

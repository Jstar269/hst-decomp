/* HSTMATCH module=EBOOT.BIN start=0x00164d00 end=0x00164e24 symbol=FUN_00164d00 lang=c++ */
struct Elem {
    int pad0;
    float key;
    int pad8[3];
};

struct Table {
    Elem *data;
    unsigned size;
};

extern Table *DAT_00341510;
extern float DAT_002e0390;
extern float DAT_002e0394;
extern int DAT_002e03b4;

extern "C" float FUN_00163bec(float, int, int, int, int);

static inline float ClampF(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

static inline unsigned ClampU(const int &v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" unsigned FUN_00164d00(int param_1, int param_2)
{
    float t = FUN_00163bec(100.0f, param_1, param_2, 1, 0);
    Table *tab = DAT_00341510;
    Elem *data = tab->data;
    unsigned size = tab->size;
    float first = data[0].key;
    int last = size - 1;
    float num = t - first;
    float den = ((Elem *)((char *)data + last * 0x14))->key - first;
    float f = num / den;
    f = ClampF(f, DAT_002e0390, DAT_002e0394);
    int idx = (int)((1.0f - f) * (float)(size - 1));
    return ClampU(idx, DAT_002e03b4, size - 2);
}
// Near miss (11 words, sn5; everything from the ratio clamp on is exact): retail schedules lwc1 $f3 (first key) before the second load of
// the low clamp bound, computes the numerator (t - first) into a NEW register $f2 right after addiu v1,a0,-1 (t stays $f0, the last key
// is then loaded into $f0), and divides $f2 / $f0; ours loads the last key into $f2, subtracts in place in $f0 and divides $f0 / $f2.
// Matching idioms found: `int last = size - 1;` as a separate local (without it MWCC folds (size-1)*20 into size*20-16), the element
// address as (Elem *)((char *)data + last * 0x14) (base-first addu; data[last] gives offset-first), the float clamp as v < lo ? lo : (v > hi ? hi : v)
// with const-reference parameters (double global load), the integer clamp as ClampU(const int &, const int &, const unsigned &),
// and (float)(size - 1) recomputed from the unsigned size for the unsigned-to-float conversion.
// Ruled out for the numerator: statement order (num/den/last), separate lastKey local, inline Ratio(v,a,b), data[0].key re-reads, separate ratio local,
// ClampF(num/den, ...) inline argument, t copied through another local.
// near miss from lane sn5 (unreviewed)

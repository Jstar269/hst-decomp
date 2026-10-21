/* HSTMATCH module=EBOOT.BIN start=0x00164d00 end=0x00164e24 symbol=FUN_00164d00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
    float lastKey = ((Elem *)((char *)data + last * 0x14))->key;
    float f = t - first;
    f /= lastKey - first;
    f = ClampF(f, DAT_002e0390, DAT_002e0394);
    int idx = (int)((1.0f - f) * (float)(size - 1));
    return ClampU(idx, DAT_002e03b4, size - 2);
}

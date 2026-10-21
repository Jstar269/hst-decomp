/* HSTMATCH module=hstp_trans_main.prx start=0x00170ef0 end=0x00171014 symbol=FUN_00170ef0 lang=c++ */
/* Clone of src/eboot/table_ratio_index_00164d00.cpp (hstclone.py tag c21rt1s): addresses substituted; exact match verified; names and types await human review. */
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

extern Table *DAT_003ea850;
extern float DAT_0038794c;
extern float DAT_00387950;
extern int DAT_00387970;

extern "C" float FUN_0017020c(float, int, int, int, int);

static inline float ClampF(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

static inline unsigned ClampU(const int &v, const int &lo, const unsigned &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" unsigned FUN_00170ef0(int param_1, int param_2)
{
    float t = FUN_0017020c(100.0f, param_1, param_2, 1, 0);
    Table *tab = DAT_003ea850;
    Elem *data = tab->data;
    unsigned size = tab->size;
    float first = data[0].key;
    int last = size - 1;
    float lastKey = ((Elem *)((char *)data + last * 0x14))->key;
    float f = t - first;
    f /= lastKey - first;
    f = ClampF(f, DAT_0038794c, DAT_00387950);
    int idx = (int)((1.0f - f) * (float)(size - 1));
    return ClampU(idx, DAT_00387970, size - 2);
}

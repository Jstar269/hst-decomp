/* HSTMATCH module=EBOOT.BIN start=0x000ab458 end=0x000ab6a4 symbol=FUN_000ab458 lang=c++ */

struct Vec4 {
    float x, y, z, w;
};

extern "C" {
extern float DAT_002d46a4;
extern float DAT_002d46a8;
void FUN_00022434(Vec4 *);
int FUN_000ab044(void *self, Vec4 *);
void *FUN_000b3c68(void *self);
}

template <class T>
inline const T& my_max(const T& a, const T& b) {
    return (b < a) ? a : b;
}

template <class T>
inline const T& my_min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

static inline bool check_sub(const Vec4 &v, float limit) {
    if (!(v.y > -limit * 0.01f))
        return false;
    return v.y < 0.0f;
}

extern "C" bool FUN_000ab458(void *self, int dummy1, int dummy2, bool flag) {
    Vec4 v3;
    Vec4 v2;
    Vec4 v1;
    FUN_00022434(&v1);
    v2 = v1;

    if (flag == (*(int *)((char *)self + 0x150) == 0)) {
        v2.x = my_max(v2.x, DAT_002d46a4);
    } else {
        v2.x = my_min(v2.x, DAT_002d46a8);
    }

    const char *src = (char *)&v2 + 4;
    char *dst = (char *)&v3 + 4;
    int n = 6;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    } while (--n > 0);

    if (FUN_000ab044(self, &v3)) {
        if (!check_sub(v3, *(float *)((char *)FUN_000b3c68(self) + 0x24))) {
            bool b = false;
            if (v3.y > -*(float *)((char *)FUN_000b3c68(self) + 0x3c) * 0.01f) {
                if (!check_sub(v3, *(float *)((char *)FUN_000b3c68(self) + 0x24))) {
                    b = (v3.y < 0.0f);
                }
            }
            return b;
        }
    }

    return false;
}
// near miss from lane ag4 (unreviewed)

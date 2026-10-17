/* HSTMATCH module=hstp_trans_main.prx start=0x000ac53c end=0x000ac714 symbol=FUN_000ac53c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003e19f0;
extern const float DAT_0037acac;
extern const float DAT_0037acb0;

extern void FUN_0002245c(void *dst);
extern void *FUN_000b6e80(void *obj);
extern float fabsf(float);
}

template <typename T>
static inline const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

template <typename T>
static inline const T &min(const T &a, const T &b) {
    return (b < a) ? b : a;
}

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Obj {
    char pad[0x150];
    int f_150;
} Obj;

static inline bool check_range(float y, float lim2) {
    if (y > lim2 && y < 0.0f) {
        return true;
    }
    return false;
}

extern "C" int FUN_000ac53c(Obj *param_1, int param_2, int param_3, unsigned char param_4, int param_5) {
    if (param_5 == 1) {
        void *ptr1 = *(void **)((char *)DAT_003e19f0 + 0x88);
        float val = *(float *)((char *)ptr1 + 0x24);
        if (val < 0.0f) {
            Vec4 local_10;
            Vec4 local_20;
            FUN_0002245c(&local_20);

            local_10 = local_20;

            if (param_4 == (param_1->f_150 == 0)) {
                local_10.x = max(DAT_0037acac, local_10.x);
            } else {
                local_10.x = min(DAT_0037acb0, local_10.x);
            }

            float x = local_10.x;
            float y = local_10.y;

            void *sub1 = FUN_000b6e80(param_1);
            float limit1 = *(float *)((char *)sub1 + 0x2c) * 0.01f;
            bool cond1 = fabsf(x) < limit1;
            if (cond1) {
                void *sub2 = FUN_000b6e80(param_1);
                float neg = -(*(float *)((char *)sub2 + 0x24) * 0.01f);
                void *sub3 = FUN_000b6e80(param_1);
                float lim2 = neg * *(float *)((char *)sub3 + 0x1c4) * 0.01f;
                if (check_range(y, lim2)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

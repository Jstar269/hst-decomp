/* HSTMATCH module=hstp_trans_main.prx start=0x000e5f98 end=0x000e62f0 symbol=FUN_000e5f98 lang=c++ */
/* Clone of src/eboot/trail_update_000e19d0.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_0037d910;
extern float DAT_0037d914;

extern void FUN_0002245c(void *out, const void *a, const void *b);
extern void FUN_00022540(void *out, const void *in);
extern float FUN_0001d58c(const void *a, const void *b);
extern float FUN_00022500(const void *a, const void *b);
extern float FUN_00022e6c(float f);
}

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Config {
    char pad[4];
    float min_dot;
    float min_len;
};

struct Trail {
    char pad[0x3c];
    Config *cfg;
    char pad40[0x4c - 0x40];
    int max_count;
    char pad50[0x54 - 0x50];
    Vec4 *buf;
    char pad58[0x60 - 0x58];
    unsigned char f60;
    unsigned char f61;
    char pad62[0x64 - 0x62];
    int count;
    int start;
    int head;
    char pad70[0x74 - 0x70];
    float f74;
    char pad78[0x90 - 0x78];
    int f90;
    char pad94[0xa0 - 0x94];
    Vec4 cur_pos;
};

inline float clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" void FUN_000e5f98(Trail *param_1)
{
    Vec4 local_10;
    Vec4 local_20;
    Vec4 local_30;
    Vec4 local_40;
    Vec4 local_50;
    Vec4 local_60;
    Vec4 local_70;
    Vec4 local_80;

    if (param_1->f60 == 0) return;

    if (param_1->f61 == 0) {
        if (param_1->f90 < 1 && param_1->f74 > 0.0f) {
            param_1->f74 = param_1->f74 - 0.2f;
            param_1->f74 = clamp(param_1->f74, DAT_0037d910, DAT_0037d914);
        }
    }

    int count = param_1->count;
    bool bVar1 = true;

    if (count > 1) {
        int iVar3 = param_1->head - 1;
        if (iVar3 < 0) {
            iVar3 = param_1->max_count - 1;
        }
        iVar3--;
        if (iVar3 < 0) {
            iVar3 = param_1->max_count - 1;
        }

        if (count > 2) {
            int iVar5 = iVar3 - 1;
            if (iVar5 < 0) {
                iVar5 = param_1->max_count - 1;
            }

            FUN_0002245c(&local_50, &param_1->cur_pos, &param_1->buf[iVar3]);
            local_10 = local_50;

            FUN_0002245c(&local_80, &param_1->buf[iVar3], &param_1->buf[iVar5]);
            local_30 = local_80;

            FUN_00022540(&local_60, &local_30);
            local_20 = local_60;

            local_60.w = 0.0f;
            local_20.w = 0.0f;

            float dot = FUN_0001d58c(&local_10, &local_20);
            if (dot < param_1->cfg->min_dot) {
                bVar1 = false;
            }
        }

        if (bVar1) {
            FUN_0002245c(&local_70, &param_1->cur_pos, &param_1->buf[iVar3]);
            local_40 = local_70;

            float len_sq = FUN_00022500(&local_40, &local_40);
            float len = FUN_00022e6c(len_sq);
            if (len < param_1->cfg->min_len) {
                bVar1 = false;
            }
        }
    }

    if (bVar1) {
        param_1->buf[param_1->head] = param_1->cur_pos;
        int head = param_1->head + 1;
        param_1->head = head;
        if (head == param_1->max_count) {
            param_1->head = 0;
        }
        int max = param_1->max_count;

        if (param_1->count < max) {
            param_1->count++;
        } else {
            if (++param_1->start == max) {
                param_1->start = 0;
            }
        }
    } else {
        int last = param_1->head - 1;
        if (last < 0) {
            last = param_1->max_count - 1;
        }
        param_1->buf[last] = param_1->cur_pos;
    }

    if (param_1->f60) {
        if (--param_1->f90 <= 0) param_1->f61 = 0;
    } else {
        param_1->f74 = 0.0f;
    }
}

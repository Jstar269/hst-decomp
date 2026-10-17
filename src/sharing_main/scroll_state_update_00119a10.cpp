/* HSTMATCH module=hstp_trans_main.prx start=0x00119a10 end=0x00119e24 symbol=FUN_00119a10 lang=c++ */
/* Clone of src/eboot/scroll_state_update_00110bfc.cpp (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct GlobalState {
    char pad[0x86bd0];
    int diff_mode;
};

struct Sub;

extern "C" {
extern GlobalState *DAT_003ea8e8;
extern int DAT_003eaae0;
extern void FUN_00108a2c(void *);
extern void FUN_00113a50(Sub *);
}

struct Sub {
    char pad[0xfc];
    short fc;
    short fe;
    short f100;
    short f102;
    char pad104[4];
    float f108;
    float f10c;
};

struct Obj {
    char pad[0x58];
    Sub *s58;
    Sub *s5c;
    int f60;
    char pad64[4];
    int f68;
    float f6c;
    float f70;
    float f74;
    float f78;
};

static inline void update_sub(Sub *s, float f, short val)
{
    short new_fc = (short)(int)f;
    short old_fc = s->fc;
    s->fc = new_fc;
    s->f100 += (new_fc - old_fc);
    short diff_fe = val - s->fe;
    s->fe = val;
    s->f102 += diff_fe;
}

extern "C" void FUN_00119a10(Obj *param_1)
{
    int d = DAT_003ea8e8->diff_mode;
    float step;
    if (d == 2) goto L4;
    if (d == 1) goto L3;
    switch (d) {
    case 0:
        step = 2.0f;
        goto Ldone;
    default:
        goto L3;
    }
L3:
    step = 3.0f;
    goto Ldone;
L4:
    step = 4.0f;
Ldone:

    FUN_00108a2c(param_1);

    switch (param_1->f60) {
    case 0: {
        param_1->f6c = 480.0f;
        param_1->f70 = param_1->f74 + 480.0f;
        int cnt = param_1->f68 - 1;
        param_1->f68 = cnt;
        if (cnt <= 0) {
            param_1->f68 = 0;
            param_1->f60 = 1;
        }
        break;
    }
    case 1: {
        float f = param_1->f6c * 0.5f + 10.0f;
        param_1->f6c = f;
        param_1->f70 = f + param_1->f74;
        if (param_1->f6c < 20.1f) {
            param_1->f6c = 20.1f;
            param_1->f68 = 30;
            param_1->f60 = 2;
        }
        break;
    }
    case 2: {
        int cnt = param_1->f68 - 1;
        param_1->f68 = cnt;
        if (cnt <= 0 && param_1->f78 >= 460.0f) {
            param_1->f68 = 0;
            param_1->f60 = 3;
        }
        break;
    }
    case 3:
        param_1->f6c -= step;
        param_1->f70 -= step;
        break;
    }

    switch (DAT_003eaae0) {
    case 9: {
        Sub *s = param_1->s58;
        s->f108 = 0.8f;
        s->f10c = 0.8f;
        FUN_00113a50(s);
        s = param_1->s5c;
        s->f108 = 0.8f;
        s->f10c = 0.8f;
        FUN_00113a50(s);
        update_sub(param_1->s58, param_1->f6c, 2);
        update_sub(param_1->s5c, param_1->f70, 2);
        break;
    }
    case 10:
        update_sub(param_1->s58, param_1->f6c, 0);
        update_sub(param_1->s5c, param_1->f70, 0);
        break;
    default:
        update_sub(param_1->s58, param_1->f6c, 1);
        update_sub(param_1->s5c, param_1->f70, 1);
        break;
    }

    if (param_1->f6c + param_1->f78 < 0.0f) {
        param_1->f6c = param_1->f70 + param_1->f74;
    }
    if (param_1->f70 + param_1->f78 < 0.0f) {
        param_1->f70 = param_1->f6c + param_1->f74;
    }
}

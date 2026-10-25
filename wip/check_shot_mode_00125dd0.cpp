/* HSTMATCH module=EBOOT.BIN start=0x00125dd0 end=0x0012603c symbol=FUN_00125dd0 lang=c++ */

struct Item {
    char pad[74];
    char c1; // 74 (0x4a)
    char c2; // 75 (0x4b)
    char c3; // 76 (0x4c)
};

struct Sub {
    char pad[88];
    int type; // 88 (0x58)
};

struct GlobalData {
    char pad[128];
    Sub *sub80; // 128 (0x80)
    char pad2[8];
    int mode; // 140 (0x8c)
};

struct LimitObj {
    char pad[88];
    int limit; // 88 (0x58)
};

struct LimitSub {
    char pad[156];
    LimitObj *obj; // 156 (0x9c)
};

struct Param1 {
    char pad[144];
    Item **item_ptr; // 144 (0x90)
    int val94;       // 148 (0x94)
};

extern "C" {
    extern GlobalData *DAT_00340284;
    extern LimitSub *DAT_003386b0;

    int FUN_00131a78(GlobalData *data, int arg);
    void FUN_00124bf8(Sub *sub, int val, Item *item);
    void FUN_0012603c(Param1 *p1, Item *item);
}

extern "C" void FUN_00125dd0(Param1 *param_1, int param_2) {
    Item *item = *param_1->item_ptr;
    Sub *sub = DAT_00340284->sub80;

    bool is_special = (sub->type == 4 || sub->type == 7);

    if (item == 0) {
        return;
    }

    char c1 = item->c1;
    char c2 = item->c2;

    int b = is_special | (c1 == 15);
    int cond = (b != 0) | (c2 == 15);

    if (DAT_00340284->mode != 2) {
        if (!cond) {
            int lim = DAT_003386b0->obj->limit;
            if (FUN_00131a78(DAT_00340284, 5) < lim) {
                return;
            }
        }
    }

    if (c1 == 1 || c2 == 1 || c1 == 2 || c2 == 2 || c1 == 15 || c2 == 15) {
        int lim = DAT_003386b0->obj->limit;
        if (FUN_00131a78(DAT_00340284, 5) < lim) {
            if (!cond) {
                goto done;
            }
        }
        FUN_00124bf8(sub, param_1->val94, *param_1->item_ptr);
    } else if (c1 == 5 || c2 == 5 || c1 == 6 || c2 == 6 || c1 == 7 || c2 == 7 ||
               c1 == 8 || c2 == 8 || c1 == 9 || c2 == 9 || item->c3 != 0) {
        if (DAT_00340284->mode != 2) {
            if (!cond) {
                int lim = DAT_003386b0->obj->limit;
                if (FUN_00131a78(DAT_00340284, 5) < lim) {
                    goto done;
                }
            }
        }
        FUN_00124bf8(sub, param_1->val94, *param_1->item_ptr);
    }

done:
    if (param_2 != 0) {
        FUN_0012603c(param_1, item);
    }
}
// near miss from lane ag4 (unreviewed)

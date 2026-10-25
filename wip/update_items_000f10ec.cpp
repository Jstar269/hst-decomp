/* HSTMATCH module=EBOOT.BIN start=0x000f10ec end=0x000f13a8 symbol=FUN_000f10ec lang=c++ */

struct Item {
    char pad_00[0x60];
    float f60;
    float f64;
    char pad_68[0x10];
    float f78;
};

struct Obj {
    char pad_00[0x54];
    unsigned char f54;
    char pad_55[3];
    Item *items[3];
    char pad_64[0x2c];
    float f90;
    unsigned char f94;
    char pad_95[0xb];
    unsigned char fa0;
};

extern "C" {
    float fabsf(float);
    void FUN_00102c54(Item *item);
    void FUN_00103128(Obj *self);
}

extern "C" void FUN_000f10ec(Obj *self) {
    if (self->f54 != 0) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        Item *item = self->items[i];
        float target_y = (self->fa0 != 0) ? 0.0f : -14.0f;
        if (item != 0) {
            bool flag = true;
            if (self->f94 != 0) {
                bool moved = (item->f60 != 0.0f || item->f64 != 0.0f);
                if (!moved) {
                    if (item->f78 == 1.0f) {
                        flag = false;
                    }
                }
                float target_x = 0.0f;
                float diff_x = target_x - item->f60;
                if (fabsf(diff_x) >= 1.0f) {
                    item->f60 += diff_x * 0.2f;
                }
                float diff_y = target_y - item->f64;
                if (fabsf(diff_y) >= 1.0f) {
                    item->f64 += diff_y * 0.2f;
                }
                float target_z = 1.0f;
                float diff_z = target_z - item->f78;
                if (fabsf(diff_z) >= 0.01f) {
                    item->f78 += diff_z * 0.2f;
                }
            } else {
                bool moved = (item->f60 != 0.0f || item->f64 != 0.0f);
                if (!moved) {
                    if (item->f78 == 0.0f) {
                        flag = false;
                    }
                }
                float target_x = 0.0f;
                float diff_x = target_x - item->f60;
                if (fabsf(diff_x) >= 1.0f) {
                    item->f60 += diff_x * 1.0f;
                }
                float diff_y = target_y - item->f64;
                if (fabsf(diff_y) >= 1.0f) {
                    item->f64 += diff_y * 1.0f;
                }
                float target_z = 0.0f;
                float diff_z = target_z - item->f78;
                if (fabsf(diff_z) >= 0.01f) {
                    item->f78 += diff_z * 1.0f;
                }
            }
            if (flag) {
                FUN_00102c54(item);
            }
            self->f90 = item->f78;
        }
    }
    FUN_00103128(self);
}
// near miss from lane ag4 (unreviewed)

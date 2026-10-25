/* HSTMATCH module=EBOOT.BIN start=0x000a7874 end=0x000a7aa0 symbol=FUN_000a7874 lang=c++ */
#pragma opt_strength_reduction off

struct Vec4 {
    float x, y, z, w;
};

struct TargetRecord {
    int id;
    unsigned char flag;
    char pad[3];
    int f8;
    int pad2;
    Vec4 pos;
};

struct ArrayHolder {
    TargetRecord *data;
    int count;
};

struct TargetList {
    char pad[0x268];
    int start_idx;
    ArrayHolder entries;
};

struct Self_000a7874 {
    char pad[0x5a8];
    float f5a8;
};

extern "C" {
void *FUN_000b3c68(Self_000a7874 *self);
void FUN_00022434(Vec4 *diff, const Vec4 *a, const Vec4 *b);
int FUN_000a8080(Self_000a7874 *self, const Vec4 *pos, int arg);
}

extern "C" int FUN_000a7874(Self_000a7874 *self, TargetRecord *out_record, TargetList *list, const Vec4 *target_pos_in, int param_5, int param_6) {
    Vec4 target_pos = *target_pos_in;
    float best_dist = 3.4028235e+38f;
    int cur = list->start_idx;
    int count = list->entries.count;
    int found = 0;

    if (cur < count) {
        ArrayHolder *entries = &list->entries;
        do {
            unsigned int idx = cur;
            if (idx >= (unsigned int)entries->count)
                idx = entries->count - 1;
            TargetRecord *entry = &entries->data[idx];

            TargetRecord local_record;
            local_record.id = entry->id;
            local_record.flag = entry->flag;
            local_record.f8 = entry->f8;
            local_record.pos = entry->pos;

            if (local_record.flag != 0) {
                if (local_record.pos.z * self->f5a8 < -2.0f) {
                    void *sub = FUN_000b3c68(self);
                    float lim = -(*(float *)((char *)sub + 0x3c) * 0.95f * 0.01f);
                    if (local_record.pos.y >= lim) {
                        Vec4 diff;
                        FUN_00022434(&diff, &target_pos, &local_record.pos);
                        float dist = diff.x * diff.x + diff.z * diff.z;
                        if (dist < best_dist) {
                            if (param_5 == 0 || FUN_000a8080(self, &local_record.pos, local_record.id + param_6) >= 0) {
                                best_dist = dist;
                                found = 1;
                                out_record->id = local_record.id;
                                out_record->flag = local_record.flag;
                                out_record->f8 = local_record.f8;
                                out_record->pos = local_record.pos;
                            }
                        }
                    }
                }
            }
            cur++;
        } while (cur < entries->count);
    }

    return found;
}
// Differing words: 109 / 139
// Identified as target search over clamped array holder entries, evaluating squared distance,
// checking pitch and y bounds, checking validation helper 0xa8080, and copying best record.
// Frame size 112 matched, stack layout (diff at 48, local_record at 64, target_pos at 96) matched,
// all 21 prologue instructions matched.
// Differs in register allocation (s0..s6 permutation) and member copy schedule for TargetRecord.
// near miss from lane ag4 (unreviewed)

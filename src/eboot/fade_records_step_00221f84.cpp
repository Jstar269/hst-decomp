/* HSTMATCH module=EBOOT.BIN start=0x00221f84 end=0x00222098 symbol=FUN_00221f84 lang=c++ */
/* Clone of src/sharing_main/fade_records_step_002314f8.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Steps 16 fading records (0x30 bytes from +0x20): count up, move by vel, fade alpha in over 15 frames and out after 30; after 45 the record is cleared and FUN_00221ac0(self, 1) is called. Records are indexed directly (an element-pointer local adds an addiu base register). */
struct Rec {
    unsigned char active;
    char pad1[7];
    int count;
    float alpha;
    char pad10[4];
    float pos;
    char pad18[0x14];
    float vel;
};

struct Obj {
    char pad0[0x20];
    Rec recs[16];
};

extern "C" {
void FUN_00221ac0(Obj *, int);
}

extern "C" void FUN_00221f84(Obj *self)
{
    for (int i = 0; i < 16; i++) {
        if (self->recs[i].active) {
            self->recs[i].count++;
            self->recs[i].pos += self->recs[i].vel;
            float t = (float)self->recs[i].count;
            if (t > 45.0f) {
                self->recs[i].active = 0;
                FUN_00221ac0(self, 1);
            } else if (t > 30.0f) {
                self->recs[i].alpha = 1.0f - (t - 30.0f) / 15.0f;
            } else if (t > 15.0f) {
                self->recs[i].alpha = 1.0f;
            } else if (self->recs[i].count > 0) {
                self->recs[i].alpha = t / 15.0f;
            }
        }
    }
}

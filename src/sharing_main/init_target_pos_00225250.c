/* HSTMATCH module=hstp_trans_main.prx start=0x00225250 end=0x002252e0 symbol=FUN_00225250 lang=c99 */
/* Clone of src/eboot/init_target_pos_0021624c.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed float structs, field-by-field copy, early return on byte flag; exact match verified; names and types await human review. */

extern float FUN_001760cc(void *a, void *b);
extern float FUN_001760e8(void *a, void *b);

struct Vec3_00225250 {
    float x;
    float y;
    float z;
};

struct Obj_00225250 {
    struct Vec3_00225250 pos;      // +0, +4, +8
    unsigned char flag;            // +12
    char pad13[3];                 // +13..+15
    int f10;                       // +16
    char pad14[12];                // +20..+31
    float f20;                     // +32
    float f24;                     // +36
    float f28;                     // +40
    float f2c;                     // +44
    float f30;                     // +48
    float f34;                     // +52
    struct Vec3_00225250 target;   // +56, +60, +64
};

void FUN_00225250(struct Obj_00225250 *self, void *param_2, void *param_3)
{
    if (self->flag != 0) {
        return;
    }
    self->f10 = 0;
    self->f20 = 0.0f;
    self->f24 = 0.0f;
    self->f28 = 0.0f;
    self->f2c = 1.0f;
    self->f30 = FUN_001760cc(param_2, param_3);
    self->f34 = FUN_001760e8(param_2, param_3);
    self->target.x = self->pos.x;
    self->target.y = self->pos.y;
    self->target.z = self->pos.z;
}

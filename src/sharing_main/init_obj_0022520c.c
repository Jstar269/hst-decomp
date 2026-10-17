/* HSTMATCH module=hstp_trans_main.prx start=0x0022520c end=0x00225250 symbol=FUN_0022520c lang=c99 */
/* Clone of src/eboot/init_obj_00216208.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct with Vec3 floats; exact match verified; names and types await human review. */

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    struct Vec3 pos;
    unsigned char b12;
    char pad13[3];
    float f16;
    char pad14[12];
    int w20;
    int w24;
    int w28;
    float f2c;
    int w30;
    int w34;
    struct Vec3 target;
};

void FUN_0022520c(struct Obj *param_1)
{
    param_1->b12 = 0;
    param_1->f16 = -1.0f;
    param_1->w20 = 0;
    param_1->w24 = 0;
    param_1->w28 = 0;
    param_1->f2c = 1.0f;
    param_1->w30 = 0;
    param_1->w34 = 0;
    param_1->target.x = param_1->pos.x;
    param_1->target.y = param_1->pos.y;
    param_1->target.z = param_1->pos.z;
}

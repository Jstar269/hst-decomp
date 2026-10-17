/* HSTMATCH module=hstp_trans_main.prx start=0x0005ff00 end=0x0005ffd8 symbol=FUN_0005ff00 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v10) corrected by hand: float parameter and struct layout with wrap/clamp loops; exact match verified; names and types await human review. */
typedef struct {
    char pad[0x10];
    float f10;
} Sub_0005ff00;

typedef struct {
    char pad00[0xa4];
    Sub_0005ff00 *sub_a4;
    char pada8[0xc0 - 0xa8];
    unsigned char flag_c0;
    char padc1[0xc8 - 0xc1];
    float fc8;
    float fcc;
} Obj_0005ff00;

void FUN_0005ff00(Obj_0005ff00 *self, float val)
{
    self->fcc = val;
    if (self->sub_a4 != 0) {
        float lim = self->sub_a4->f10;
        if (self->flag_c0 != 0 && lim != 0.0f) {
            if (self->fcc >= lim) {
                do {
                    self->fcc -= lim;
                } while (self->fcc >= lim);
            } else {
                while (self->fcc < 0.0f) {
                    self->fcc += lim;
                }
            }
        } else {
            if (self->fcc > lim) {
                self->fcc = lim;
            } else if (self->fcc < 0.0f) {
                self->fcc = 0.0f;
            }
        }
        self->fc8 = self->fcc;
    }
}

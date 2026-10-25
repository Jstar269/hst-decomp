/* HSTMATCH module=hstp_trans_main.prx start=0x00044c88 end=0x00044de0 symbol=FUN_00044c88 lang=c99 */
/* Clone of src/eboot/text_layout_height_00044ae4.c (hstclone.py tag ag56c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct TextStyle {
    char pad_00[16];
    float scale;
    char pad_14[4];
    float base_height;
    char fixed_height;
};

extern int FUN_0004495c(void *ctx, unsigned short *tag, const char *str);
extern int FUN_0004401c(void *ctx, unsigned short tag, float *box, float *size, float *align);

float FUN_00044c88(void *ctx, const char *str, struct TextStyle *style)
{
    float line_height = 16.0f;
    float total_height = 0.0f;
    float extra;
    int adv;
    unsigned short tag;
    float box[2];
    float size[2];
    float align[2];

    if (*str != '\0') {
        do {
            adv = FUN_0004495c(ctx, &tag, str);
            if (tag == 9 && str[1] == 'Y') {
                total_height += (float)(str[2] - '0');
                str += 2;
            } else if (tag == 10) {
                total_height += line_height;
                line_height = 0.0f;
            } else {
                extra = 0.0f;
                if (FUN_0004401c(ctx, *(volatile unsigned short *)&tag, box, size, align)) {
                    if (style->fixed_height != 0) {
                        extra = (float)style->fixed_height;
                    } else {
                        extra = size[1] * style->scale;
                    }
                }
                float h = style->base_height + extra;
                if (line_height < h) {
                    line_height = h;
                }
            }
            str += adv;
        } while (*str != '\0');
    }

    if (tag != 10) {
        total_height += line_height;
    }
    return total_height;
}

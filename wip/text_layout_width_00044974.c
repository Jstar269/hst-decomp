/* HSTMATCH module=EBOOT.BIN start=0x00044974 end=0x00044ae4 symbol=FUN_00044974 lang=c99 */

struct TextStyle {
    char pad_00[12];
    float scale_x;
    float scale_y;
    float base_width;
    float base_height;
    char fixed_size;
};

extern int FUN_000447b8(void *ctx, unsigned short *tag, const char *str);
extern int FUN_00043f38(void *ctx, unsigned short tag, float *box, float *size, float *align);
extern int FUN_00044c3c(void *ctx, unsigned short tag);

float FUN_00044974(void *ctx, const char *str, struct TextStyle *style)
{
    float line_width = 0.0f;
    float max_width = 0.0f;
    float extra;
    int adv;
    unsigned short tag_val;
    unsigned short tag;
    float box[2];
    float size[2];
    float align[2];

    if (*str != '\0') {
        do {
            adv = FUN_000447b8(ctx, &tag, str);
            if (tag == 10) {
                if (max_width < line_width) {
                    max_width = line_width;
                }
                line_width = 0.0f;
            } else {
                tag_val = tag;
                extra = 0.0f;
                if (FUN_00043f38(ctx, tag_val, box, size, align)) {
                    if (style->fixed_size != 0) {
                        if (FUN_00044c3c(ctx, tag_val)) {
                            extra = (float)style->fixed_size / 2.0f;
                        } else {
                            extra = (float)style->fixed_size;
                        }
                    } else {
                        extra = size[0] * style->scale_x;
                    }
                }
                line_width += style->base_width + extra;
            }
            str += adv;
        } while (*str != '\0');
    }

    if (tag != 10) {
        if (max_width < line_width) {
            max_width = line_width;
        }
    }
    return max_width;
}
// Near miss: 66 words differ out of 92 (90/92 words match size).
// Control flow, branches, arithmetic, float comparisons, call sequence, and stack layout match retail.
// Difference is saved register coloring: retail assigns s4=tag_val, s3=ctx, s2=str, s1=style, s0=adv,
// whereas MWCC default parameter-first assignment assigns s4=ctx, s3=str, s2=style, s1=tag_val, s0=adv.
// Ruled out: C++ class member methods, inline helper wrappers, register keyword on tag_val.
// near miss from lane ag5 (unreviewed)

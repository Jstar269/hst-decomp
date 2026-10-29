/* HSTMATCH module=hstp_trans_main.prx start=0x00044b18 end=0x00044c88 symbol=FUN_00044b18 lang=c99 */
/* Clone of src/eboot/text_line_width_00044974.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag ag5 draft, wip/text_layout_width_00044b18.c) corrected by hand: the extra-width ternary replaces the nested if/else and the second read of the decoded character goes through a volatile access; exact match verified; names and types await human review. */
/* Measures the widest line of a string: per character, advance by the style's base width plus the glyph extra (fixed size, halved for some glyphs, or glyph width * scale). Matching idioms: `extra = F() ? fixed / 2.0f : fixed` as a ternary (an if/else threads the join away and drops the `b; nop`), and `tag_val = *(volatile unsigned short *)&tag` (retail reads the decoded character again after the newline test instead of reusing the compare's load). */

struct TextStyle {
    char pad_00[12];
    float scale_x;
    float scale_y;
    float base_width;
    float base_height;
    char fixed_size;
};

extern int FUN_0004495c(void *ctx, unsigned short *tag, const char *str);
extern int FUN_0004401c(void *ctx, unsigned short tag, float *box, float *size, float *align);
extern int FUN_00044de0(void *ctx, unsigned short tag);

float FUN_00044b18(void *ctx, const char *str, struct TextStyle *style)
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
            adv = FUN_0004495c(ctx, &tag, str);
            if (tag == 10) {
                if (max_width < line_width) {
                    max_width = line_width;
                }
                line_width = 0.0f;
            } else {
                tag_val = *(volatile unsigned short *)&tag;
                extra = 0.0f;
                if (FUN_0004401c(ctx, tag_val, box, size, align)) {
                    if (style->fixed_size != 0) {
                        extra = FUN_00044de0(ctx, tag_val) ? (float)style->fixed_size / 2.0f : (float)style->fixed_size;
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

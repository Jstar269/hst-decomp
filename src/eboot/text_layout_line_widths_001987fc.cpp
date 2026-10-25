/* HSTMATCH module=EBOOT.BIN start=0x001987fc end=0x00198aa8 symbol=FUN_001987fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct TextContext {
    void * volatile font;
    char pad_04[92];
    float scale_x;
    float scale_y;
    char pad_68[8];
    float pad_20;
    float pad_24;
    char pad_78[12];
    int pad_28;
};

struct Style {
    float field_0;
    float field_4;
    unsigned short field_8;
    float scale_x;
    float scale_y;
    float pad_20;
    float pad_24;
    char pad_28;
    short pad_30;
    short pad_32;
    short pad_34;
    short pad_36;
};

extern "C" int FUN_000447b8(void *, unsigned short *, const char *);
extern "C" int FUN_00198cb8(TextContext *, unsigned short *);
extern "C" void FUN_001982d8(TextContext *, int *, int *, unsigned short, const char *, Style *);
extern "C" float FUN_00044858(void *, unsigned short, Style *);

extern "C" int FUN_001987fc(TextContext *ctx, const char *str, const Style *style_in, int *out_widths)
{
    int max_width = 0;
    unsigned short tag;
    int current_line_width = 0;
    Style style;
    style.scale_x = 1.0f;
    style.scale_y = 1.0f;
    style.pad_34 = -32;
    style.field_0 = 0.0f;
    style.field_4 = 0.0f;
    style.field_8 = 0;
    style.pad_20 = 0.0f;
    style.pad_24 = 0.0f;
    style.pad_28 = 0;
    style.pad_30 = 0;
    style.pad_32 = 0;
    style.pad_36 = 16;

    int line_count = 0;
    int adv;

    if (style_in != 0) {
        style = *style_in;
    } else {
        style.scale_x = ctx->scale_x;
        style.scale_y = ctx->scale_y;
        style.pad_20 = ctx->pad_20;
        style.pad_24 = ctx->pad_24;
        style.pad_28 = (char)ctx->pad_28;
    }

    if (*str != '\0') {
        int *out_ptr = out_widths;
        do {
            adv = FUN_000447b8(ctx->font, &tag, str);
            if (tag == 10) {
                if (max_width < current_line_width) {
                    max_width = current_line_width;
                }
                if (out_widths != 0) {
                    *out_ptr = current_line_width;
                }
                out_ptr++;
                current_line_width = 0;
                line_count++;
            } else {
                switch (adv) {
                case 1:
                    if (FUN_00198cb8(ctx, &tag)) {
                        FUN_001982d8(ctx, &current_line_width, &adv, *(volatile unsigned short *)&tag, str, &style);
                        break;
                    } else {
                        float w = FUN_00044858(ctx->font, *(volatile unsigned short *)&tag, &style);
                        float t = (float)(int)((float)current_line_width + w);
                        current_line_width = (int)(t + style.pad_20);
                        break;
                    }
                case 2:
                case 3:
                    {
                        float w = FUN_00044858(ctx->font, *(volatile unsigned short *)&tag, &style);
                        float t = (float)(int)((float)current_line_width + w);
                        current_line_width = (int)(t + style.pad_20);
                    }
                    break;
                default:
                    break;
                }
            }
            str += adv;
        } while (*str != '\0');
    }

    if (tag != 10) {
        if (max_width < current_line_width) {
            max_width = current_line_width;
        }
    }

    if (out_widths != 0) {
        out_widths[line_count] = current_line_width;
    }

    return max_width;
}

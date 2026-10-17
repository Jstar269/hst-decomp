/* HSTMATCH module=hstp_trans_main.prx start=0x001a49ec end=0x001a4b7c symbol=FUN_001a49ec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies a text string token by token (the neighbour of text_layout_string_001a4184.cpp): FUN_0004495c returns the token length and code; codes 11, 12 and 7 are copied as two bytes, code 8 as three, everything else as `len` bytes by the (8x unrolled) copy loop. Labels are written 8, 7, 12, 11 because MWCC tests them in reverse order. */
struct Font;
struct Text { Font *font; };
extern "C" int FUN_0004495c(Font *font, unsigned short *code, const char *s);
extern "C" void FUN_001a49ec(Text *self, const char *src, char *dst);

void FUN_001a49ec(Text *self, const char *src, char *dst)
{
    while (*src != 0) {
        unsigned short code;
        int len = FUN_0004495c(self->font, &code, src);
        switch (code) {
        case 8:
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            src += 3;
            dst += 3;
            break;
        case 7:
        case 12:
        case 11:
            dst[0] = src[0];
            dst[1] = src[1];
            src += 2;
            dst += 2;
            break;
        default:
            for (int i = 0; i < len; i++)
                *dst++ = *src++;
            break;
        }
    }
    *dst = 0;
}

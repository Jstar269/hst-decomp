/* HSTMATCH module=hstp_trans_main.prx start=0x000449fc end=0x00044ab0 symbol=FUN_000449fc lang=c++ */
/* Hand-written reconstruction from the disassembly (matching idiom: the fixed-pitch case is a `static inline` helper with early returns; written inline in the caller its if/else loses retail's own join block, 16 words); exact match verified; names and types await human review. */
/* gf_string.cpp (the callee's assert names the file): width of one character code. FUN_0004401c
   looks the code up and fills three float pairs (named as in text_layout_height_00044c88.c); with a
   fixed pitch set (signed byte at +0x1c) the width is that pitch, halved when FUN_00044de0 classes
   the code as half-width (high byte 0, or 0xff with a low byte in 0x60..0x9f); otherwise it is the
   looked-up width scaled by the float at +0xc. Both callees read the code as an unsigned short. */
struct TextStyle {
  char pad_00[0xc];
  float scale_x;
  char pad_10[0xc];
  signed char fixed_pitch;
};

extern "C" {
int FUN_0004401c(void *ctx, unsigned short code, float *box, float *size, float *align);
int FUN_00044de0(void *ctx, unsigned short code);
}

static inline float FixedPitchWidth(void *ctx, unsigned short code, TextStyle *style)
{
  if (FUN_00044de0(ctx, code) != 0) {
    return (float)style->fixed_pitch / 2.0f;
  }
  return (float)style->fixed_pitch;
}

extern "C" float FUN_000449fc(void *ctx, unsigned short code, TextStyle *style)
{
  float w = 0.0f;
  float box[2];
  float size[2];
  float align[2];

  if (FUN_0004401c(ctx, code, box, size, align) != 0) {
    if (style->fixed_pitch != 0) {
      w = FixedPitchWidth(ctx, code, style);
    } else {
      w = size[0] * style->scale_x;
    }
  }
  return w;
}

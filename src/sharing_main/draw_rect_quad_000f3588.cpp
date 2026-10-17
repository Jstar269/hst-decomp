/* HSTMATCH module=hstp_trans_main.prx start=0x000f3588 end=0x000f3750 symbol=FUN_000f3588 lang=c++ */
/* Clone of src/eboot/draw_rect_quad_000edec0.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Color { unsigned char r, g, b, a; };
struct Rect { unsigned color; short x0, y0, x1, y1, z; };

extern "C" void FUN_00051e30(void *tex, int a, int b, int w, int h, int c, int d);
extern "C" void FUN_00052354(void *tex, Color col, float u0, float v0, float x0, float y0, float u1, float v1,
                             float x1, float y1, float z);
extern "C" void FUN_000522c0(void *tex);

extern "C" void FUN_000f3588(float px, float py, float scale, float ax, float ay, void *tex, Rect *r, int u, int v)
{
  unsigned c = r->color;
  Color col;
  col.r = c;
  col.g = c >> 8;
  col.b = c >> 16;
  col.a = c >> 24;
  int w = r->x1 - r->x0;
  int h = r->y1 - r->y0;
  int ix = (int)(px + (float)r->x0 + ((1.0f - ax) * (float)w) / 2.0f);
  int iy = (int)(py + (float)r->y0 + ((1.0f - ay) * (float)h) / 2.0f);
  FUN_00051e30(tex, 0, 0, 480, 272, 0, 0);
  FUN_00052354(tex, col, (float)u, (float)v, (float)ix, (float)iy, (float)(u + w), (float)(v + h),
               (float)ix + ax * ((float)w * scale), (float)iy + ay * ((float)h * scale), (float)r->z);
  FUN_000522c0(tex);
}

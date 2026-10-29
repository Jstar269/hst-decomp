/* HSTMATCH module=EBOOT.BIN start=0x0008e984 end=0x0008ea50 symbol=FUN_0008e984 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Buffer { int unused; int value; };

struct ModeObj {
  char pad00[4];
  int unk4;            /* 0x004 */
  char pad08[0x1d4 - 8];
  int unk1d4;          /* 0x1d4 */
  char pad1d8[0x22c - 0x1d8];
  int mode;            /* 0x22c */
  int unk230;          /* 0x230 */
  int unk234;          /* 0x234 */
  int unk238;          /* 0x238 */
  int unk23c;          /* 0x23c */
  char unk240;         /* 0x240 */
  char pad241[3];
  int unk244;          /* 0x244 bit pattern of 1.0f */
  int unk248;          /* 0x248 */
  char pad24c[0x264 - 0x24c];
  int unk264;          /* 0x264 */
  int unk268;          /* 0x268 */
  Buffer first;        /* 0x26c */
  char pad274[4];
  Buffer second;       /* 0x278 */
  char pad280[4];
  char unk284;         /* 0x284 */
  char pad285[3];
  int unk288;          /* 0x288 */
};

extern "C" void FUN_00091080(void *, int, Tag);

/* Switches to a new mode; only mode 1 resets the state (the other modes just record themselves). */
extern "C" void FUN_0008e984(ModeObj *self, int mode)
{
  if (self->mode == mode) return;
  self->mode = mode;
  if (mode == 4) return;
  if (mode == 3) return;
  if (mode == 2) return;
  if (mode != 1) {
    if (mode == 0) return;
    return;
  }
  self->unk264 = 0;
  self->unk230 = -1;
  self->unk234 = -1;
  self->unk238 = 3;
  self->unk23c = 13;
  self->unk240 = 0;
  self->unk244 = 0x3f800000;
  self->unk248 = 0;
  self->unk268 = 0;
  self->unk284 = 0;
  self->unk288 = 0;
  self->unk4 = 3;
  self->unk1d4 = 0;
  FUN_00091080(&self->first, self->first.value, Tag());
  Buffer *second = &self->second;
  FUN_00091080(second, second->value, Tag());
}

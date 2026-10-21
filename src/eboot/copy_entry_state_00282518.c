/* HSTMATCH module=EBOOT.BIN start=0x00282518 end=0x00282664 symbol=FUN_00282518 lang=c99 */
/* Hand-written reconstruction from the disassembly (finished from an earlier lane's near-miss wip): the two trailing floats are one 2-float struct copy (`entry.v = src->v`, batched lwc1/lwc1/swc1/swc1); exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

typedef struct {
  char c[32];
} Str32;

typedef struct {
  char c[16];
} Str16;

typedef struct {
  float x, y;
} V2;

struct SubSrc {
  char pad_00[200];
  unsigned char b0, b1, b2, b3; // 200..203
  Str32 str32;                  // 204..235
  unsigned char c0, c1, c2, c3, c4; // 236..240
  char pad_f1[3];
  int i_f4;                     // 244
  int i_f8;                     // 248
  float f_fc;                   // 252
  unsigned char d0, d1;         // 256, 257
  char pad_102[2];
  int i_104;                    // 260
  Str16 str16;                  // 264..279
  V2 v;
};

struct Entry {
  char flag;                    // 0 (6836)
  char pad_01[43];
  char sub_1ae0[1];             // 44 (6880)
  char pad_2d[199];
  unsigned char b0, b1, b2, b3; // 244 (7080)
  Str32 str32;                  // 248 (7084)
  unsigned char c0, c1, c2, c3, c4; // 280 (7116)
  char pad_11d[3];
  int i_f4;                     // 284 (7124)
  int i_f8;                     // 288 (7128)
  float f_fc;                   // 292 (7132)
  unsigned char d0, d1;         // 296, 297 (7136, 7137)
  char pad_12a[2];
  int i_104;                    // 300 (7140)
  Str16 str16;                  // 304 (7144)
  V2 v;
  char pad_end[780];            // sizeof(Entry) == 1112
};

struct Obj {
  char pad_00[6836];
  struct Entry entries[];
};

extern void FUN_00259a1c(void *dst, const struct SubSrc *src);

void FUN_00282518(struct Obj *self, int index, int target_index, int flag, const struct SubSrc *src)
{
  if (index == target_index || flag == 0) {
    self->entries[index].flag = (char)flag;
    FUN_00259a1c(self->entries[index].sub_1ae0, src);

    self->entries[index].b0 = src->b0;
    self->entries[index].b1 = src->b1;
    self->entries[index].b2 = src->b2;
    self->entries[index].b3 = src->b3;
    self->entries[index].str32 = src->str32;

    self->entries[index].c0 = src->c0;
    self->entries[index].c1 = src->c1;
    self->entries[index].c2 = src->c2;
    self->entries[index].c3 = src->c3;
    self->entries[index].c4 = src->c4;
    self->entries[index].i_f4 = src->i_f4;
    self->entries[index].i_f8 = src->i_f8;
    self->entries[index].f_fc = src->f_fc;
    self->entries[index].d0 = src->d0;
    self->entries[index].d1 = src->d1;
    self->entries[index].i_104 = src->i_104;
    self->entries[index].str16 = src->str16;

    self->entries[index].v = src->v;
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x001e05d4 end=0x001e0748 symbol=FUN_001e05d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_unroll_loops off

#include "hst/result_scene.h"

/* Pointer chain walked from the 100-byte part object: +4, +4, +0x10, +4. */
typedef struct Chain3 { char pad0[4]; void *at4; } Chain3;
typedef struct Chain2 { char pad0[16]; Chain3 *at10; } Chain2;
typedef struct Chain1 { char pad0[4]; Chain2 *at4; } Chain1;
typedef struct Chain0 { char pad0[4]; Chain1 *at4; } Chain0;

extern void *FUN_00000bcc(int size);
extern void *FUN_001dd0a4(void *p);
extern void *FUN_001dd28c(void *p);
extern void *FUN_00102e38(void *p);
extern void FUN_00217614(void *p, void *q);
extern void FUN_001e248c(ResultScene *self);
extern void FUN_001e185c(ResultScene *self);
extern void FUN_001e1c40(ResultScene *self);
extern void FUN_001e25c0(ResultScene *self);

/* Constructor body: clear the part pointers, create the first parts and let the page setup functions fill the rest. */
void FUN_001e05d4(ResultScene *self)
{
  int i;
  void *p;

  self->part3c = 0;
  self->part40 = 0;
  self->partd4 = 0;
  self->part1f4 = 0;
  self->part9b4 = 0;
  self->part810 = 0;
  self->part175c = 0;
  self->part1d68 = 0;
  self->part1958 = 0;
  self->part195c = 0;
  self->part21e4 = 0;
  self->part235c = 0;
  self->part2464 = 0;
  self->part250c = 0;
  self->part25b8 = 0;
  self->part1954 = 0;

  /* matching idiom: the int table at +0x1adc is cleared with a FLAT index that
     steps by 7 (the retail loop counter), which needs the seven stores spelled
     out and the loop kept rolled (#pragma opt_unroll_loops off). */
  for (i = 0; i < RESULT_GRID_COUNT; i += 7) {
    self->grid[i + 0] = 0;
    self->grid[i + 1] = 0;
    self->grid[i + 2] = 0;
    self->grid[i + 3] = 0;
    self->grid[i + 4] = 0;
    self->grid[i + 5] = 0;
    self->grid[i + 6] = 0;
  }

  p = FUN_00000bcc(156);
  if (p != 0) {
    self->part3c = FUN_001dd0a4(p);
  } else {
    self->part3c = p;
  }

  p = FUN_00000bcc(100);
  if (p != 0) {
    p = FUN_001dd28c(p);
    self->part40 = p;
  } else {
    self->part40 = p;
  }

  FUN_00217614(&self->anim48, ((Chain0 *)p)->at4->at4->at10->at4);

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->part9b4 = FUN_00102e38(p);
  } else {
    self->part9b4 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->partd4 = FUN_00102e38(p);
  } else {
    self->partd4 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->part2464 = FUN_00102e38(p);
  } else {
    self->part2464 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->part25b8 = FUN_00102e38(p);
  } else {
    self->part25b8 = p;
  }

  FUN_001e248c(self);
  FUN_001e185c(self);
  FUN_001e1c40(self);
  FUN_001e25c0(self);
}

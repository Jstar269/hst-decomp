/* HSTMATCH module=hstp_trans_main.prx start=0x000a2b84 end=0x000a2d44 symbol=FUN_000a2b84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the state reload for the FUN_001c31b4 argument needs a cast to an identical-layout struct view (Self2); a plain self->state is CSE'd with the 0xd0 compare. */
typedef struct Node { char pad[0xf0]; int code; } Node;
typedef struct Link { char pad[0x58]; Node *node; } Link;
typedef struct Global95c4 { char pad[0x8c]; int mode; char pad1[0x128 - 0x90]; int target; } Global95c4;
typedef struct Global19f0 { char pad[0xa8]; void *handle; } Global19f0;
typedef struct Self {
  char pad[0x148];
  int id;
  char pad1[0x4f4 - 0x14c];
  unsigned char pending;
  char pad2[3];
  int state;
  char pad3[0x5bc - 0x4fc];
  Link *link;
} Self;
typedef struct Self2 { char pad[0x4f8]; int state; } Self2;
extern Global95c4 *DAT_003e95c4;
extern Global19f0 *DAT_003e19f0;
extern int FUN_00095a24(Link *l, int a);
extern void FUN_000b52a4(float f, Self *s, int a, int b);
extern int FUN_001c31b4(void *h, int a, int b, int c);

void FUN_000a2b84(Self *self)
{
  Link *link;
  int code;
  if (self->pending != 0) {
    self->pending = 0;
    if (self->state != 0xd0) {
      int target;
      if (DAT_003e95c4->mode == 2) {
        target = DAT_003e95c4->target;
      } else {
        target = -1;
      }
      if (self->id == target) {
        FUN_001c31b4(DAT_003e19f0->handle, self->id, ((Self2 *)self)->state, 1);
      }
      self->state = 0xd0;
    }
  }
  link = self->link;
  if (link->node != 0) {
    code = link->node->code;
  } else {
    code = -1;
  }
  switch (code) {
  case 0x9e:
  case 0xa0:
  case 0xa2:
  case 0xa4:
  case 0xa6:
  case 0xa8:
  case 0xaa:
  case 0xac:
  case 0xae:
  case 0xb0:
  case 0xb2:
  case 0xb4:
  case 0xb6:
  case 0xb8:
  case 0xba:
  case 0xbc:
  case 0xbe:
  case 0xc0:
  case 0xc2:
  case 0xc4:
    if (FUN_00095a24(link, -1) != 0) {
      FUN_000b52a4(0.0f, self, code + 1, 1);
    }
    break;
  }
}

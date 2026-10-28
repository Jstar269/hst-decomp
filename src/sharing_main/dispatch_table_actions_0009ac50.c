/* HSTMATCH module=hstp_trans_main.prx start=0x0009ac50 end=0x0009ada8 symbol=FUN_0009ac50 lang=c99 */
/* Clone of src/eboot/dispatch_table_actions_00098a0c.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: share the action path and jump rejected states to the loop increment. */
typedef int code();

extern char DAT_002ceb64[];
extern void *DAT_003e1e48;
extern void FUN_00058090(void *, int, int, int);
extern void FUN_00094eb8(void *);
extern void FUN_0009ada8(void *);

typedef struct StateInfo {
  char pad[0x62];
  signed char mode;
} StateInfo;

extern StateInfo *FUN_000dca74(void *, int, int);

typedef struct ItemDevice {
  char pad[0x58];
  void *handle;
  char pad2[8];
  void *secondary;
} ItemDevice;

typedef struct Self {
  char pad[0x150];
  int mode;
  short *type_code;
  char pad2[0x5bc - 0x158];
  ItemDevice *device;
  int *items;
} Self;

#pragma opt_strength_reduction off

void FUN_0009ac50(Self *self)
{
  StateInfo *state;
  void *handle;
  int use_mode;
  int index;
  char *row;

  FUN_00094eb8(self->device);
  handle = self->device->handle;
  if (handle != 0) {
    state = FUN_000dca74(DAT_003e1e48, 0, *self->type_code);
    use_mode = self->mode == 1;
    index = 0;
    row = DAT_002ceb64;
    do {
      if (row[4] != 0) {
        int nibble = ((int)state->mode << 28) >> 28;
        int code = nibble == 0 ? 1 : 2;
        if (code != row[4]) goto NEXT_ITEM;
      }
      FUN_00058090(handle, index, self->items[index], use_mode);
      if (index >= 0x9e && index < 0xe0 && row[0] < 2) {
        int value = self->items[index];
        if (value != 0 && self->device->secondary != 0) {
          FUN_00058090(self->device->secondary, index, value, use_mode);
        }
      }
NEXT_ITEM:
      index++;
      row += 0x10;
    } while (index < 0x115);
    FUN_0009ada8(self);
  }
}

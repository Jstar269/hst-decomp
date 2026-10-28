/* HSTMATCH module=EBOOT.BIN start=0x00098a0c end=0x00098b64 symbol=FUN_00098a0c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: share the action path and jump rejected states to the loop increment. */
typedef int code();

extern char DAT_002beb78[];
extern void *DAT_00338b08;
extern void FUN_0005743c(void *, int, int, int);
extern void FUN_00093024(void *);
extern void FUN_00098b64(void *);

typedef struct StateInfo {
  char pad[0x62];
  signed char mode;
} StateInfo;

extern StateInfo *FUN_000d8c24(void *, int, int);

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

void FUN_00098a0c(Self *self)
{
  StateInfo *state;
  void *handle;
  int use_mode;
  int index;
  char *row;

  FUN_00093024(self->device);
  handle = self->device->handle;
  if (handle != 0) {
    state = FUN_000d8c24(DAT_00338b08, 0, *self->type_code);
    use_mode = self->mode == 1;
    index = 0;
    row = DAT_002beb78;
    do {
      if (row[4] != 0) {
        int nibble = ((int)state->mode << 28) >> 28;
        int code = nibble == 0 ? 1 : 2;
        if (code != row[4]) goto NEXT_ITEM;
      }
      FUN_0005743c(handle, index, self->items[index], use_mode);
      if (index >= 0x9e && index < 0xe0 && row[0] < 2) {
        int value = self->items[index];
        if (value != 0 && self->device->secondary != 0) {
          FUN_0005743c(self->device->secondary, index, value, use_mode);
        }
      }
NEXT_ITEM:
      index++;
      row += 0x10;
    } while (index < 0x115);
    FUN_00098b64(self);
  }
}

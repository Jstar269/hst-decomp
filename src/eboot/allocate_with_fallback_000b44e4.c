/* HSTMATCH module=EBOOT.BIN start=0x000b44e4 end=0x000b4578 symbol=FUN_000b44e4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: initialize the allocation before the positive-size retry loop. */

extern int DAT_002d47bc;
extern unsigned char DAT_0030a038;
extern void *FUN_00000b14(int, const void *);

typedef struct AllocationResult {
  void *allocation;
  int size;
} AllocationResult;

void FUN_000b44e4(AllocationResult *result, int requested)
{
  AllocationResult *output = result;
  void *allocation = 0;
  int actual_size = DAT_002d47bc;
  if (requested > 0) {
    do {
      allocation = FUN_00000b14(requested * 0x50, &DAT_0030a038);
      if (allocation != 0) {
        actual_size = requested;
        break;
      }
      requested = requested / 2;
    } while (requested > 0);
  }
  output->allocation = allocation;
  output->size = actual_size;
}

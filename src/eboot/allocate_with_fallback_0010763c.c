/* HSTMATCH module=EBOOT.BIN start=0x0010763c end=0x001076c8 symbol=FUN_0010763c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: initialize the allocation before the positive-size retry loop. */

extern int DAT_002d8db8;
extern unsigned char DAT_0030a038;
extern void *FUN_00000b14(int, const void *);

typedef struct AllocationResult {
  void *allocation;
  int size;
} AllocationResult;

void FUN_0010763c(AllocationResult *result, int requested)
{
  AllocationResult *output = result;
  void *allocation = 0;
  int actual_size = DAT_002d8db8;
  if (requested > 0) {
    do {
      allocation = FUN_00000b14(requested << 2, &DAT_0030a038);
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

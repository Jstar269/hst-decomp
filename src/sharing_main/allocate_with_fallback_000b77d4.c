/* HSTMATCH module=hstp_trans_main.prx start=0x000b77d4 end=0x000b7868 symbol=FUN_000b77d4 lang=c99 */
/* Clone of src/eboot/allocate_with_fallback_000b44e4.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: initialize the allocation before the positive-size retry loop. */

extern int DAT_0037b040;
extern unsigned char DAT_003b3308;
extern void *FUN_00000b14(int, const void *);

typedef struct AllocationResult {
  void *allocation;
  int size;
} AllocationResult;

void FUN_000b77d4(AllocationResult *result, int requested)
{
  AllocationResult *output = result;
  void *allocation = 0;
  int actual_size = DAT_0037b040;
  if (requested > 0) {
    do {
      allocation = FUN_00000b14(requested * 0x50, &DAT_003b3308);
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

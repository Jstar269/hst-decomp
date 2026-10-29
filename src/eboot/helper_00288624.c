/* HSTMATCH module=EBOOT.BIN start=0x00288624 end=0x0028867c symbol=FUN_00288624 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modelled adjacent call fields as a 16-byte-aligned record (matching idiom: aligned local record); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* The object carries a request list header at +0x64 whose sentinel node is at +0x68. */
#define QUEUE_LIST_OFFSET 100
#define QUEUE_SENTINEL_OFFSET 0x68
#define REQUEST_TAG_QUEUED 0x23

extern u32 DAT_0034a114;
extern void FUN_001cc6cc();
extern u32 FUN_00289544();

/* Frame of the queue call: list position (sentinel address), out-iterator slot and the queued record. */
struct WorkArgs_288624 {
  int sentinel;
  u8 result[4];
  int tag;
  int count;
  u32 id;
} __attribute__((aligned(16)));

/* count < 1: call FUN_001cc6cc on the global; otherwise queue a record. */
void FUN_00288624(int self,u32 id,int count)
{
  struct WorkArgs_288624 args;
  
  if (count < 1) {
    FUN_001cc6cc(DAT_0034a114);
  }
  else {
    args.tag = REQUEST_TAG_QUEUED;
    args.sentinel = self + QUEUE_SENTINEL_OFFSET;
    args.count = count;
    args.id = id;
    FUN_00289544(args.result,self + QUEUE_LIST_OFFSET,&args.sentinel,&args.tag);
  }
}

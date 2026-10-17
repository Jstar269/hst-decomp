/* HSTMATCH module=EBOOT.BIN start=0x00288414 end=0x00288470 symbol=FUN_00288414 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed Request struct layout with aligned(16) and float parameter; exact match verified; names and types await human review. */
struct Request {
  int *local_20;
  char buffer[4];
  int tag;
  int count;
  float f;
  int value;
} __attribute__((aligned(16)));

extern "C" void *DAT_0034a114;
extern "C" void FUN_001c7e58(void *);
extern "C" void FUN_00289544(char *, int *, int **, int *);

extern "C" void FUN_00288414(void *self, int value, int count, float f)
{
  struct Request request;
  if (count < 1) {
    FUN_001c7e58(DAT_0034a114);
  } else {
    request.tag = 0x4e;
    request.value = value;
    request.count = count;
    request.f = f;
    request.local_20 = (int *)((char *)self + 0x68);
    FUN_00289544(request.buffer, (int *)((char *)self + 0x64), &request.local_20, &request.tag);
  }
}

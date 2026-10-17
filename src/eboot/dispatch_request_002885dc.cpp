/* HSTMATCH module=EBOOT.BIN start=0x002885dc end=0x00288624 symbol=FUN_002885dc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Request {
  int *local_20;
  char buffer[4];
  int tag;
  int count;
  int value;
  float f;
} __attribute__((aligned(16)));

extern "C" void FUN_00289544(char *, int *, int **, int *);

extern "C" void FUN_002885dc(void *self, int value, int count, float f)
{
  struct Request request;
  if (count > 0) {
    request.tag = 0x57;
    request.value = value;
    request.count = count;
    request.f = f;
    request.local_20 = (int *)((char *)self + 0x68);
    FUN_00289544(request.buffer, (int *)((char *)self + 0x64), &request.local_20, &request.tag);
  }
}

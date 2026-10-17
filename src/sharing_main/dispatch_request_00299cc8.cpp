/* HSTMATCH module=hstp_trans_main.prx start=0x00299cc8 end=0x00299d10 symbol=FUN_00299cc8 lang=c++ */
/* Clone of src/eboot/dispatch_request_00288594.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Request {
  int *local_20;
  char buffer[4];
  int tag;
  int count;
  int value;
  float f;
} __attribute__((aligned(16)));

extern "C" void FUN_0029ace0(char *, int *, int **, int *);

extern "C" void FUN_00299cc8(void *self, int value, int count, float f)
{
  struct Request request;
  if (count > 0) {
    request.tag = 0x56;
    request.value = value;
    request.count = count;
    request.f = f;
    request.local_20 = (int *)((char *)self + 0x68);
    FUN_0029ace0(request.buffer, (int *)((char *)self + 0x64), &request.local_20, &request.tag);
  }
}

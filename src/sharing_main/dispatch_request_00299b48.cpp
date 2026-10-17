/* HSTMATCH module=hstp_trans_main.prx start=0x00299b48 end=0x00299ba4 symbol=FUN_00299b48 lang=c++ */
/* Clone of src/eboot/dispatch_request_00288414.cpp (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed Request struct layout with aligned(16) and float parameter; exact match verified; names and types await human review. */
struct Request {
  int *local_20;
  char buffer[4];
  int tag;
  int count;
  float f;
  int value;
} __attribute__((aligned(16)));

extern "C" void *DAT_003f344c;
extern "C" void FUN_001d62ec(void *);
extern "C" void FUN_0029ace0(char *, int *, int **, int *);

extern "C" void FUN_00299b48(void *self, int value, int count, float f)
{
  struct Request request;
  if (count < 1) {
    FUN_001d62ec(DAT_003f344c);
  } else {
    request.tag = 0x4e;
    request.value = value;
    request.count = count;
    request.f = f;
    request.local_20 = (int *)((char *)self + 0x68);
    FUN_0029ace0(request.buffer, (int *)((char *)self + 0x64), &request.local_20, &request.tag);
  }
}

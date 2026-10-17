/* HSTMATCH module=EBOOT.BIN start=0x00288350 end=0x00288414 symbol=FUN_00288350 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: modeled the virtual interface and aligned request context; exact match verified; names and types await human review. */
struct Device {
  virtual int unused0(); virtual int unused1(); virtual int unused2(); virtual int unused3();
  virtual int unused4(); virtual int unused5(); virtual int unused6(); virtual int unused7();
  virtual int unused8(); virtual int unused9(); virtual int unused10(); virtual int mode();
};
struct Request {
  int *local_20;
  char buffer[4];
  int tag;
  int index;
  int value;
} __attribute__((aligned(16)));
extern "C" int *FUN_00288a84(Device *);
extern "C" void FUN_00127a68(int *, int, int);
extern "C" void FUN_00289544(char *, int *, int **, int *);
extern "C" void FUN_00288350(Device *self, int param_2, int param_3)
{
  bool matched;
  int mode;
  struct Request request;
  mode = self->mode();
  matched = mode == 2;
  if (!matched) {
    mode = self->mode();
    matched = mode == 3;
  }
  if (matched) {
    if (param_3 < 1) {
      int *value = FUN_00288a84(self);
      FUN_00127a68(value, param_2, 1);
    } else {
      request.tag = 0x52;
      request.local_20 = (int *)((char *)self + 0x68);
      request.index = param_3;
      request.value = param_2;
      FUN_00289544(request.buffer, (int *)((char *)self + 0x64), &request.local_20, &request.tag);
    }
  }
}





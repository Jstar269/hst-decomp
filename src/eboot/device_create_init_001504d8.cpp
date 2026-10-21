/* HSTMATCH module=EBOOT.BIN start=0x001504d8 end=0x001505c4 symbol=FUN_001504d8 lang=c++ */
/* Hand-written reconstruction from the disassembly (started from the Sharing-twin wip of lane u6cr2-0, wip/device_init_0015c510.cpp); exact match verified; names and types await human review. */
extern "C" unsigned char DAT_003402f0;
extern "C" int DAT_0034a114;
extern "C" char DAT_002dc3e0[];
extern "C" char DAT_003083cc;
extern "C" char DAT_00308f14;
extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_0014d044(void *);
extern "C" void FUN_0014fd94(char *, int, int);
extern "C" void FUN_001cb7d0(int, int);

struct Context {
  char padding[8];
  int first;
  int second;
};
struct Resource {};
struct Device {
  virtual ~Device();
  virtual int initialize(float, Resource *);
  Context *context;
};

extern "C" Device *FUN_001504d8(Context *context, float progress, Resource *resource)
{
  Device *device;
  int result;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(resource);
    FUN_0014fd94(DAT_002dc3e0, context->first, context->second);
  }
  FUN_001cb7d0(DAT_0034a114, context->first);
  if ((device = (Device *)FUN_00000bcc(8)) != 0) {
    *(char **)device = &DAT_003083cc;
    *(char **)device = &DAT_00308f14;
    device->context = context;
  }
  result = device->initialize(progress, resource);
  if (result != 0) {
    if (device != 0) delete device;
    return 0;
  }
  return device;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0015c510 end=0x0015c5fc symbol=FUN_0015c510 lang=c++ */
/* Clone of src/eboot/device_create_init_001504d8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (started from the Sharing-twin wip of lane u6cr2-0, wip/device_init_0015c510.cpp); exact match verified; names and types await human review. */
extern "C" unsigned char DAT_003e9630;
extern "C" int DAT_003f344c;
extern "C" char DAT_003838c8[];
extern "C" char DAT_003b1698;
extern "C" char DAT_003b21e0;
extern "C" void *FUN_00000bcc(int);
extern "C" void FUN_00158b2c(void *);
extern "C" void FUN_0015bb68(char *, int, int);
extern "C" void FUN_001d9fa0(int, int);

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

extern "C" Device *FUN_0015c510(Context *context, float progress, Resource *resource)
{
  Device *device;
  int result;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(resource);
    FUN_0015bb68(DAT_003838c8, context->first, context->second);
  }
  FUN_001d9fa0(DAT_003f344c, context->first);
  if ((device = (Device *)FUN_00000bcc(8)) != 0) {
    *(char **)device = &DAT_003b1698;
    *(char **)device = &DAT_003b21e0;
    device->context = context;
  }
  result = device->initialize(progress, resource);
  if (result != 0) {
    if (device != 0) delete device;
    return 0;
  }
  return device;
}

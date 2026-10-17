/* HSTMATCH module=hstp_trans_main.prx start=0x0015c510 end=0x0015c5fc symbol=FUN_0015c510 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

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
  virtual int destroy(int);
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
  if (result == 0) return device;
  if (device != 0) device->destroy(1);
  return 0;
}
// Near miss: six differing words remain in the status/null cleanup branch after virtual initialize. The two virtual dispatch offsets, float/resource argument registers, allocation, and vptr stores match; direct cleanup returns and a separate result pointer did not close the branch layout.
// near miss from lane u6cr2-0 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00252ed0 end=0x00252fbc symbol=FUN_00252ed0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { virtual void release(int flag); };
struct C { E *child; };
extern char DAT_0030992C[];
extern char DAT_0034179C[];
extern C *DAT_0034A794;
extern int DAT_0034A798;
extern "C" void FUN_00000a00(void *p);
extern "C" void FUN_0001f0f0(void *a, int b);
extern "C" void FUN_001943b4(void);
extern "C" void FUN_001b2f78(void *p);
extern "C" void FUN_001b338c(void *p, int n);

extern "C" void *FUN_00252ed0(char *self, short flag)
{
  C *c;

  if (self != 0) {
    *(char **)self = DAT_0030992C;
    DAT_0034A798 = 0;
    c = DAT_0034A794;
    if (c != 0) {
      if (c != 0) {
        DAT_0034A794 = 0;
        if (c->child != 0) {
          if (c->child) c->child->release(1);
          c->child = 0;
        }
        FUN_001b338c(DAT_0034179C, 2);
        FUN_001b2f78(DAT_0034179C);
        FUN_001943b4();
        FUN_00000a00(c);
      }
      DAT_0034A794 = 0;
    }
    FUN_0001f0f0(self, 0);
    if (flag > 0) FUN_00000a00(self);
  }
  return self;
}

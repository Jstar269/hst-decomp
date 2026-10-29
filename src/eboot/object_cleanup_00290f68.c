/* HSTMATCH module=EBOOT.BIN start=0x00290f68 end=0x00290ff0 symbol=FUN_00290f68 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/player_service.h"

extern char DAT_00309dc0;
extern char DAT_002cac10[];
extern void FUN_00000a00(void *);
extern void FUN_0028fb44(const char *, int);
extern int FUN_002b7900(int);
/* Destructor of an embedded sub-object: terminates and deletes its thread; frees it when release is positive. */
ServiceSock *FUN_00290f68(ServiceSock *self, short release)
{
    if (self != 0) {
        self->vtable = (unsigned int)&DAT_00309dc0;
        int handle = self->handle;
        if (handle >= 0) {
            int result = FUN_002b7900(handle);
            if (result != 0)
                FUN_0028fb44(DAT_002cac10, result);
            self->handle = -1;
        }
        if (release > 0)
            FUN_00000a00(self);
    }
    return self;
}


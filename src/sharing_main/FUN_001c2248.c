/* HSTMATCH module=hstp_trans_main.prx start=0x001c2248 end=0x001c2274 symbol=FUN_001c2248 */
/* Clone of src/eboot/FUN_001b4104.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x7ac]; int handle; } Owner7ac;
typedef struct { Owner7ac *owner; } Ref7ac;
extern void FUN_000637a8(int handle, int mode);

void FUN_001c2248(Ref7ac *r)
{
    int h = r->owner->handle;
    if (h >= 0) FUN_000637a8(h, 0);
}

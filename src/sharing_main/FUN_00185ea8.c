/* HSTMATCH module=hstp_trans_main.prx start=0x00185ea8 end=0x00185ef0 symbol=FUN_00185ea8 lang=c99 */
/* Clone of src/eboot/FUN_001797b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_host.h"

extern void FUN_00189578();
extern void FUN_0018d5d0();

void FUN_00185ea8(ListHost *host)
{
  u32 value;
  
  if (0 < host->unk6c) {
    value = host->callback();
    FUN_0018d5d0(host->sub174,value);
    FUN_00189578(host->sub178);
  }
}

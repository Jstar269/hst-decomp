/* HSTMATCH module=EBOOT.BIN start=0x0005febc end=0x0005ffb0 symbol=FUN_0005febc lang=c++ */
/* Hand-written reconstruction from the disassembly (written together with the exact Sharing twin src/sharing_main/tim2_get_image_00060cac.cpp, EBOOT addresses); exact match verified; names and types await human review. */
/* TIM2 picture image lookup (the layout of the TIM2 texture format: 48-byte picture header with HeaderSize at +0xc and
   MipMapTextures at +0x11, followed by the mipmap header whose MMImageSize[] table starts at +0x10): returns the image
   data of mipmap level `mipmap`, or 0 when the picture has fewer levels. Both builds compile it as C++ (the
   unrolled loop's guard flag is a bool: `andi a3,a2,0xff`); the mipmap-header pointer formed before the loop keeps
   retail's `addiu a0,a0,48` base instead of folding the table offset. */
struct Tim2PictureHeader {
  unsigned int totalSize;
  unsigned int clutSize;
  unsigned int imageSize;
  unsigned short headerSize;
  unsigned short clutColors;
  unsigned char pictFormat;
  unsigned char mipMapTextures;
  unsigned char clutType;
  unsigned char imageType;
  unsigned short imageWidth;
  unsigned short imageHeight;
  unsigned int gsTex0[2];
  unsigned int gsTex1[2];
  unsigned int gsRegs;
  unsigned int gsTexClut;
};

struct Tim2MipMapHeader {
  unsigned int gsMiptbp1[2];
  unsigned int gsMiptbp2[2];
  int mmImageSize[1];
};

extern "C" unsigned char *FUN_0005febc(Tim2PictureHeader *ph, int mipmap)
{
  Tim2MipMapHeader *pm;
  int i;
  unsigned char *image;

  if (mipmap >= ph->mipMapTextures)
    return 0;
  image = (unsigned char *)ph + ph->headerSize;
  if (ph->mipMapTextures == 1)
    return image;
  pm = (Tim2MipMapHeader *)((unsigned char *)ph + sizeof(Tim2PictureHeader));
  for (i = 0; i < mipmap; i++)
    image += pm->mmImageSize[i];
  return image;
}

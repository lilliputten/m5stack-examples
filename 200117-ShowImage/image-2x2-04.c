/*******************************************************************************
* image
* filename: unsaved
* name: image-2x2
*
* preset name: Color R5G6B5
* data block size: 16 bit(s), uint16_t
* RLE compression enabled: no
* conversion type: Grayscale, not_used not_used
* bits per pixel: 16
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: no
*******************************************************************************/
/*
typedef struct {
  const uint16_t *data;
  uint16_t width;
  uint16_t height;
  uint8_t dataSize;
} tImage;
*/
#include <stdint.h>
static const uint16_t image_data_image2x2[4] = {
  /* 0x0000, 0x52aa, // black, red */
  /* 0x7bef, 0xffff // green, white */
  0x7bef, 0x7bef,
  0x7bef, 0x7bef
};
// const tImage image2x2 = { image_data_image2x2, 2, 2, 16 };

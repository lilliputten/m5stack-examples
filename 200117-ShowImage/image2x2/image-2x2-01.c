
/*******************************************************************************
* image
* filename: D:/Work/M5Stack/mp3stack-examples/200117-ShowImage/image-2x2.xml
* name: image-2x2
*
* preset name:
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Diffuse Dither 128
* bits per pixel: 24
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: no
*******************************************************************************/
/*
 * typedef struct {
 *     const uint8_t *data;
 *     uint16_t width;
 *     uint16_t height;
 *     uint8_t dataSize;
 *     } tImage;
 * #include <stdint.h>
 */
static const unsigned char image_data_image2x2[12] = {
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00
};
// const tImage image2x2 = { image_data_image2x2, 2, 2, 8 };

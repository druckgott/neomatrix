# neomatrix
Example for NeoMatrix Library | Adafruit NeoPixel Überguide | Adafruit Learning | own Image | running Mario | Arduino

Video
https://youtu.be/EIHNVNH15jA

I have generated a Excel File (Macro) where you can generate Images for the neo matrix Arduino Libary if you use the function display_rgbBitmap

You can import pictues which have the same pixel size as your matrix led.

I did not find a easy way how to generate own pictures in a fast way. Now I can generate a picture with some klicks.

In the Example you will se a animation form a running Mario.

<img src="https://github.com/druckgott/neomatrix/blob/master/Mario_8x8_Matrix_LED.jpg" alt="Arduino Neo Matrix Running Mario">

To import the bmp Files to the Excel Macro you have to save it as a 24 Bit bmp
<img src="https://github.com/druckgott/neomatrix/blob/master/24bit_bmp.JPG" alt="Arduino Neo Matrix Excel Macro">

The Result of the Matrix is the 4Bit Image Code with red,gren,blue values.

//Mario 1
{
0x000,  0x000,  0x000,  0x50F,  0x50F,  0x50F,  0xEEF,  0x000,
0x50F,  0x50F,  0x50F,  0x50F,  0x50F,  0x000,  0x000,  0x000,
0x000,  0x000,  0x35A,  0xACF,  0x35A,  0x000,  0xACF,  0x000,
0xACF,  0x35A,  0x35A,  0xACF,  0xACF,  0x35A,  0x000,  0x000,
0x000,  0x000,  0x000,  0x35A,  0xACF,  0xACF,  0xACF,  0x000,
0x000,  0x0AF,  0xFA2,  0xFA2,  0x2FF,  0x50F,  0x50F,  0x000,
0xEEF,  0x000,  0xFA2,  0xFA2,  0xFA2,  0xFA2,  0x532,  0x978,
0x000,  0x527,  0x000,  0x000,  0x000,  0x35A,  0x000,  0x000,

},

You can also adjust colors after importing a picture to the excel tabel, or draw directly your image in excel without importing a image.

The Main things about the NeoMatrix you can finde here:
https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library

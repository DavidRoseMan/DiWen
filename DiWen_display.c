#include "variable.h"
#include "transmit.h"
#include "DiWen_display.h"

extern unsigned int code PictureData[][5];

void myDisplayFace(Uart_type *uart_use, unsigned char face)
{
    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x70);
    sendbyte_UART(uart_use, face);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
}

void myDisplayPicture(Uart_type *uart_use, bit Attribute, uint x, uint y, uchar Picture)
{
    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x71);
    sendbyte_UART(uart_use, PictureData[Picture][0]);
    sendbyte_UART(uart_use, PictureData[Picture][1] >> 8);
    sendbyte_UART(uart_use, PictureData[Picture][1] >> 0);
    sendbyte_UART(uart_use, PictureData[Picture][2] >> 8);
    sendbyte_UART(uart_use, PictureData[Picture][2] >> 0);
    sendbyte_UART(uart_use, PictureData[Picture][3] >> 8);
    sendbyte_UART(uart_use, PictureData[Picture][3] >> 0);
    sendbyte_UART(uart_use, PictureData[Picture][4] >> 8);
    sendbyte_UART(uart_use, PictureData[Picture][4] >> 0);
    sendbyte_UART(uart_use, x >> 8);
    sendbyte_UART(uart_use, x >> 0);
    sendbyte_UART(uart_use, y >> 8);
    sendbyte_UART(uart_use, y >> 0);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
    if (!Attribute)
    {
        sendbyte_UART(uart_use, 0xAA);
        sendbyte_UART(uart_use, 0x5C);
        sendbyte_UART(uart_use, x >> 8);
        sendbyte_UART(uart_use, x >> 0);
        sendbyte_UART(uart_use, y >> 8);
        sendbyte_UART(uart_use, y >> 0);
        sendbyte_UART(uart_use, (x + PictureData[Picture][3] - PictureData[Picture][1]) >> 8);
        sendbyte_UART(uart_use, (x + PictureData[Picture][3] - PictureData[Picture][1]) >> 0);
        sendbyte_UART(uart_use, (y + PictureData[Picture][4] - PictureData[Picture][2]) >> 8);
        sendbyte_UART(uart_use, (y + PictureData[Picture][4] - PictureData[Picture][2]) >> 0);
        sendbyte_UART(uart_use, 0xCC);
        sendbyte_UART(uart_use, 0x33);
        sendbyte_UART(uart_use, 0xC3);
        sendbyte_UART(uart_use, 0x3C);
    }
}

void myDisplayIcon(Uart_type *uart_use, uint x, uint y, uchar Lib_ID, uchar mode, uint Icon_ID)
{
    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x97);
    sendbyte_UART(uart_use, x >> 8);
    sendbyte_UART(uart_use, x >> 0);
    sendbyte_UART(uart_use, y >> 8);
    sendbyte_UART(uart_use, y >> 0);
    sendbyte_UART(uart_use, Lib_ID);
    sendbyte_UART(uart_use, mode);
    sendbyte_UART(uart_use, Icon_ID >> 8);
    sendbyte_UART(uart_use, Icon_ID >> 0);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
}

void myDisplayString(Uart_type *uart_use, uint x, uint y, uchar Lib_ID, uchar mode,
                     uchar Dots, uint Fcolor, uint Bcolor, char *Strings, ...) reentrant
{
    va_list ap;

    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x98);
    sendbyte_UART(uart_use, x >> 8);
    sendbyte_UART(uart_use, x >> 0);
    sendbyte_UART(uart_use, y >> 8);
    sendbyte_UART(uart_use, y >> 0);
    sendbyte_UART(uart_use, Lib_ID);
    sendbyte_UART(uart_use, mode);
    sendbyte_UART(uart_use, Dots);
    sendbyte_UART(uart_use, Fcolor >> 8);
    sendbyte_UART(uart_use, Fcolor >> 0);
    sendbyte_UART(uart_use, Bcolor >> 8);
    sendbyte_UART(uart_use, Bcolor >> 0);
    va_start(ap, Strings);
    vmyprintf(uart_use, Strings, ap);
    va_end(ap);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
}

void myDiWinBuzz(Uart_type *uart_use, uchar length)
{
    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x79);
    sendbyte_UART(uart_use, length);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
}

void myDisplayString_setdigits(Uart_type *uart_use, uint x, uint y, uchar Lib_ID, uchar mode,
                               uchar Dots, uint Fcolor, uint Bcolor, char *Strings, ...) reentrant
{
    va_list ap;

    sendbyte_UART(uart_use, 0xAA);
    sendbyte_UART(uart_use, 0x98);
    sendbyte_UART(uart_use, x >> 8);
    sendbyte_UART(uart_use, x >> 0);
    sendbyte_UART(uart_use, y >> 8);
    sendbyte_UART(uart_use, y >> 0);
    sendbyte_UART(uart_use, Lib_ID);
    sendbyte_UART(uart_use, mode);
    sendbyte_UART(uart_use, Dots);
    sendbyte_UART(uart_use, Fcolor >> 8);
    sendbyte_UART(uart_use, Fcolor >> 0);
    sendbyte_UART(uart_use, Bcolor >> 8);
    sendbyte_UART(uart_use, Bcolor >> 0);
    va_start(ap, Strings);
    vmyprintf_setdigits(uart_use, Strings, ap);
    va_end(ap);
    sendbyte_UART(uart_use, 0xCC);
    sendbyte_UART(uart_use, 0x33);
    sendbyte_UART(uart_use, 0xC3);
    sendbyte_UART(uart_use, 0x3C);
}

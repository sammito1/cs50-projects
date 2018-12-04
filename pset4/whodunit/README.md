# Questions

## What's `stdint.h`?

`stdint.h` is a header file that defines various unsigned and signed types (such as `u_int32_t`), which enable us to specify
a fixed amount of memory we want to allocate for a type of data, such as using 32 bits for an integer. This will enable
consistency and portability when running programs in various platforms.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The simple data type `int`, can be interpreted differently (in regards to memory allocation) from machine to machine.
Instead of leaving this interpretation to the machine, we simply define the exact amount of data we want to allocate for certain
data types. For example, we can set initialize a variable of type `int32_t `, which is a signed integer with a maximum size of
32 bits.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 byte, 4 bytes, 4 bytes, and 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of any BMP file must be `B` and `M`.

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the total size of file (in bytes) including pixels, padding, and headers.
`biSize` is the total size of the actual image, not including padding or headers.

## What does it mean if `biHeight` is negative?

According to MSDN, "if biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner".


## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file doesn't exist or we don't have permission to open it.

## Why is the third argument to `fread` always `1` in our code?

The structure of usage for `fread()` goes something like: `fread(<buffer>, <size>, <qty>, <file pointer>);`
So, we always want to read `1` unit of size `sizeof(RGBTRIPLE)` from the infile.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;`
This evaluates to 3, as `sizeof(RGBTRIPLE) ==  '3'`.

## What does `fseek` do?

`fseek()` essentially enables us to rewind or fast-forward through a file, without necessarily having read every byte within it.

## What is `SEEK_CUR`?

If `whence` is set to `SEEK_CUR` in the `fseek()` function, the offset is measured starting from the
current position indicator.

## Whodunit?

It was professor plum with the candlestick in the library.

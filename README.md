# PSXACT

This project aims to emulate the PlayStation&trade; 1 console in an accurate
fashion. No hacks or proprietary software will be used to accomplish this goal.

This emulator is designed to work "out of the box", no plug-in hell required!

## Current Status

Currently, the emulator can get through the BIOS, but hasn't booted any
commercial games yet. A software rasterizer is used to attempt pixel accurate
graphical output, the results are quite nice!

![Current status](images/current.png)

## Usage

The emulator requires a BIOS file, which can be dumped from a physical console.

Once you have a BIOS file, PSXACT can be invoked via command line, using the
following simple interface:

```
$ psxact <bios file here> <game file here>
```

## Building

This project uses CMake for builds, and requires SDL2.

I personally use the `FindSDL2.cmake` script available
[here](https://github.com/tcbrindle/sdl2-cmake-scripts).

## Contributing

If you'd like to contribute, please create a fork and issue pull requests! I am
very open to newcomers, and will need all the help I can get to make the best
PS1 emulator available.

However, do try and follow the syntax used by the project when contributing, I
**will** rewrite any code to make it match the project style before accepting.

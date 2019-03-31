# Installation of ST LINK utility 

```bash
sudo apt install libusb-1.0.0-dev
git clone https://github.com/texane/stlink stlink.git
cd stlink
make
# Install binaries
sudo cp build/Debug/st-* /usr/local/bin
# Install udev rules
sudo cp etc/udev/rules.d/49-stlinkv* /etc/udev/rules.d/
# Restart udev
sudo restart udev
```

# Prep for cross-compilation

```bash
# GNU ARM gcc toolchain installation
sudo apt install gcc-arm-none-eabi
```

# Debugging

```bash
# Start STlink utility
st-util
# Connect to the GDB server created on port: 4242
arm-none-eabi-gdb --eval-command="target remote localhost:4242" openground.elf
# Upload the program
load
# Reset GDB monitor
monitor reset
# Create breakpoint
b main.c:12
b main.c:14
# Continue program after breakpoint have been hit with:
c


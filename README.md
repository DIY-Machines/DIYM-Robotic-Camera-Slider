# DIY 3D Printable Motorised Camera Slider

A 3D printable robotic camera slider with a custom touchscreen interface, motorised linear movement, and a motorised rotating camera head.

This project is designed for smooth product shots, live video work, B-roll, and motion timelapses. The slider can be built to different track lengths using 20x40 aluminium extrusion, and the touchscreen interface allows you to program speed, acceleration, movement time, and motion style.

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/GgVlCD2qOv8/0.jpg)](https://www.youtube.com/watch?v=GgVlCD2qOv8)

DIY Machines Camera Slider

## Project Links

- Full project video: https://youtu.be/GgVlCD2qOv8
- 3D printable parts: https://diymachines.etsy.com/listing/4516449862
- Written project page: https://www.diymachines.co.uk/diy-3d-printable-motorised-camera-slider
- DIY Machines YouTube channel: https://www.youtube.com/@DIYMachines

## Features

- 3D printable mechanical parts
- Adjustable track length
- 2.8" touchscreen control interface
- Motorised X-axis slider movement
- Motorised Y-axis camera rotation
- Programmable speed and acceleration
- Set movement by speed or total time
- Motion styles for live video and timelapse use
- Optional tripod mounting
- Optional Ryobi 18V battery power
- Optional electronics cooling fan
- Designed to be low-cost and maker-friendly

## Project Overview

The slider is built around a length of 20x40 aluminium extrusion with a 3D printed carriage running on POM V-wheels. A GT2 belt drives the linear axis, while a second stepper motor controls the rotating camera platform.

The electronics use an ESP32-based “Cheap Yellow Display” as the main touchscreen controller, with a Wemos D1 Mini acting as the motion co-processor. Two TMC2209 stepper drivers control the two NEMA 17 stepper motors.

The 3D printable files are available separately here:

https://diymachines.etsy.com/listing/4516449862

## Bill of Materials

Some links below are affiliate links. They help support the project at no extra cost to you.

### Electronics and Main Components

| Item | Qty | Link / Notes |
|---|---:|---|
| 2.8" “Cheap Yellow Display” - ESP32-2432S028 | 1 | https://geni.us/CYD-2-8 |
| Mini560 5V buck converter | 1 | https://geni.us/Mini560 |
| TMC2209 Stepper Driver | 2 | https://geni.us/TMC2209 |
| Wemos D1 Mini ESP8266 | 1 | https://geni.us/wemosD1 |
| Contact Switch | 2 | https://geni.us/ContactSwitch |
| Panel mountable power switch | 1 | https://geni.us/Power-Switch |
| Female DC Power Barrel | 2 | https://geni.us/FemalePowerBarrel |
| 100uF 35V Low ESR Capacitor | 3 | https://geni.us/Capacitor100uF35vESR |
| PCB | 1 | https://diymachines.etsy.com/uk/listing/4516518337/robotic-camera-slider-pcb-only |
| Stepper Motor | 2 | https://geni.us/StepperMotor |
| Contact Spring - Keystone Electronics 209 | 2 | https://geni.us/KeystoneElec209Contact |
| Short DC Barrel Lead or DIY Male Connectors | 1 lead or 2 connectors | https://geni.us/DCBarrel-MaleToMale |
| Wire | As required | https://geni.us/22AWGWire |
| 3D Printing Filament | As required | PETG recommended: https://geni.us/3DJake |

### Motion Components

| Item | Qty | Link / Notes |
|---|---:|---|
| 20x40 Aluminium extrusion with both ends M5 threaded | 1 | I used a 50cm length: https://geni.us/Extrusion-2040 |
| GT2 20T 6mm timing pulley, 5mm bore | 2 | For stepper motor shafts: https://geni.us/TimingBelt5m |
| GT2 idler wheel, 6mm belt, 5mm bore, toothed | 1 | https://geni.us/6mmIdler5mmBoreToothed |
| GT2 Timing belt, 6mm wide | 1 | Needs to be twice the length of the extrusion plus 25cm: https://geni.us/TimingBelt5m |
| POM Pulley 625zz Linear Bearing, 5mm bore | 4 | https://geni.us/625zzBearing-5mm |
| 6mm GT2 250mm Circular Belt Loop | 1 | https://geni.us/GT2BeltLoop-250mm |

### Optional Screw Terminals

If you want to screw your wires to the PCB instead of soldering them directly:

| Item | Qty | Link |
|---|---:|---|
| Screw Wire Terminal - Through Hole Mount - 4 Pole | 3 | https://geni.us/PCBScrewTerminals |
| Screw Wire Terminal - Through Hole Mount - 2 Pole | 5 | https://geni.us/PCBScrewTerminals |

### Nuts, Bolts, and Bearings

You can buy a kit of the below nuts, bolts, and bearings on Etsy for convenience.

| Item | Qty |
|---|---:|
| 1/4-20 Locking Nut | 3 |
| 1/4-20 x 1 1/4" Machine Screw | 1 |
| M2.5 x 8mm Bolt | 4 |
| M5 x 30 Countersunk Bolt | 6 |
| M5 x 20 Countersunk Bolt | 7 |
| M5 x 14 Countersunk Bolt | 8 |
| M3 x 6 Bolt | 13 |
| M3 x 8 Bolt | 12 |
| M5 Nut | 8 |
| Drop-in M5 T Slot Nut | 6 |
| F8-16M 8 x 16 x 5mm Axial Ball Bearing | 1 |
| Thrust Ball Bearing 20mm x 35mm x 10mm | 1 |

Thrust bearing link:

https://geni.us/ThrustBearing-51104

### Optional Tripod Mounting

To attach the slider to tripods using universal photography quick release plates:

| Item | Qty | Link |
|---|---:|---|
| Photography Quick Release Plate | 1 or 2 | https://geni.us/PhotoQuickReleasePlate |

### Optional Battery Power

| Item | Qty | Link |
|---|---:|---|
| Ryobi 18V Battery | 1 | https://geni.us/Ryobi18v |

### Optional Electronics Cooling Fan

The fan is useful in hot environments, or if you are running fast movements for long periods of time.

| Item | Qty | Link / Notes |
|---|---:|---|
| 5V 40mm Fan | 1 | https://geni.us/40mmFan |
| M4 x 16 Bolts | 4 | For mounting the optional fan |

## 3D Printing

I printed the parts in PETG.

PETG is a good choice because it is tougher and more temperature-resistant than PLA, especially if the slider may be used near lights, in a warm room, or outdoors.

General printing recommendations:

- Material: PETG recommended
- Layer height: 0.2mm
- Infill: 20–40% depending on part
- Perimeters/walls: 4 or more recommended
- Supports: designed to minimise support material where possible - none should be required
- Check fitment before final assembly

The 3D printable files are available here:

https://diymachines.etsy.com/listing/4516449862

## Firmware

This project uses two microcontrollers:

1. ESP32 Cheap Yellow Display  
   Runs the touchscreen interface and sends movement commands.

2. Wemos D1 Mini ESP8266  
   Acts as the motion co-processor and handles stepper movement.

The exact libraries may vary depending on the version of the code in this repository, but the project uses typical Arduino/ESP32/ESP8266 display, touch, serial, and stepper-control libraries.

## Wiring

The project uses a custom PCB to simplify wiring between:

- ESP32 touchscreen display
- Wemos D1 Mini motion co-processor
- TMC2209 stepper drivers
- Stepper motors
- Limit/contact switches
- Power input
- Optional fan
- Optional battery input

PCB: https://diymachines.etsy.com/uk/listing/4516518337/robotic-camera-slider-pcb-only

Before powering the project, check:

- Stepper driver orientation
- Power polarity
- Buck converter output voltage
- Capacitor polarity
- Limit switch wiring
- No shorts between power rails

## Power

The project can be powered from a suitable 18v DC power supply, or optionally from an 18V Ryobi battery.

The Mini560 buck converter provides 5V for the logic electronics.

Do not connect the ESP32, Wemos D1 Mini, or display directly to the full motor/battery voltage.

## Assembly Notes

A full build walkthrough is shown in the project video:

https://youtu.be/GgVlCD2qOv8

## First Power-On Checklist

Before using the slider with a camera attached:

- Power it from a current-limited supply if possible.
- Confirm both stepper drivers are installed correctly.
- Confirm the carriage moves freely by hand when motors are disabled.
- Confirm the contact switches trigger correctly.
- Test movement slowly before increasing speed.
- Keep fingers, cables, and camera straps clear of the moving carriage.

## Safety Notes

This is a DIY motorised camera slider. Use it carefully.

- Do not leave the slider running unattended.
- Make sure the camera is securely mounted.
- Do not exceed the weight the printed parts, bearings, tripod plates, or extrusion can safely support.
- Keep cables away from the belt and moving carriage.
- Check all bolts before use.
- Be especially careful when using battery power.
- Use suitable fuses or protection where appropriate.

## Known Notes

- The PCB link will be added soon.
- The printable parts are hosted separately.
- Different extrusion lengths may require different belt lengths.
- Belt length should be roughly twice the extrusion length plus 25cm.

## Support and Community

For more project details, visit:

https://www.diymachines.co.uk/diy-3d-printable-motorised-camera-slider

You can also find more DIY Machines projects here:

https://www.diymachines.co.uk


## Licence

This project uses separate licences for different parts of the project.

### Firmware

The firmware in this repository is licensed under the MIT License unless otherwise stated.

### Documentation

The written documentation, images, diagrams, and project notes are copyright © Lewis Aburrow / DIY Machines. They may not be reused commercially without permission.

### 3D Printable Files

The 3D printable design files are not open source and are not licensed for redistribution.

They are sold separately under a Personal Use Only licence.

You may print the parts for your own personal use and you may modify the files privately for your own build.

You may not redistribute, upload, share, resell, or publish the original files or modified versions of the files. You may not sell printed parts made from these files without written permission from DIY Machines.

3D printable files are available here:

https://ko-fi.com/s/9e1b03c6d8

## Credits

Designed and built by Lewis at DIY Machines.

YouTube: https://www.youtube.com/@DIYMachines  
Website: https://www.diymachines.co.uk

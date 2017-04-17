/*!
   \file mainpage.h
   \brief doxygen main page
*/

/*!
\mainpage

\section intro Introduction
The EC-Salinity I2C device can measure electrical conductivity in the range of
0.5 - 62mS and salinity from 2 - 42.

\section characteristics Characteristics
- EC range: 0.5 - 62mS
- Salinity range: 2 - 42
- Temperature range: -2 - 35C
- Interface: I2C
- Current use: 20mA peak
- Voltage range: 2.7 - 5.5V
- Operating temperature range: -65 - 125C

It uses the standard Arduino Wire library to interface with the device.
It's operating principle is based on sending a very short-duration DC pulse
from one probe pin and reading the voltage on the second probe pin. The voltage
is then converted to a temperature compensated Siemen measure. Salinity is also derived
from the measure and is in PSU.

\section setup Setup
When the device is powered for the first time, it will be un-calibrated and must
be calibrated to provide accurate readings. The calibration constant
of the probe is referred to as the cell constant and represented by
#EC_Salinity::K. An uncalibrated device will show K = -1. To begin the calibration process,
place the thermometer and probe in a calibration solution then call the
#EC_Salinity::calibrateProbe function.

For best results, the probe should be cleaned with distilled water and then placed
in the solution for 5-10 minutes before the probe is used. Note that any
turbidity, air bubbles, large particles, etc will effect readings. An unstable
temperature will decrease accuracy as well.

\section probe Probe Selection
Any probe can be attached to the device. Polirity doesn't matter. Keep in mind
that metal, water, and electricity don't cooperate. The probe will not last
forever, regardless of how little it is used. Things that effect the lifespan
include the chemicals it is exposed to, if it is occasionally exposed to air,
the number of measurments taken, the types of metal used, and the connections between
portions of the probe. Deposit buildup will effect readings as well as
chemical reactions that take place on the probe surface. If the probe is meant
to stay fully submerged, all these factors should be taken into account. It is
very likley that it will require regular maintanence in the form of cleaning
or recalibration.

\section use Use
Once the probe has been calibrated, a reading can be taken. The probe should
be placed in the solution to be measured and #EC_Salinity::measureEC called to
start a measurement. For best results, the probe should be cleaned with distilled
water and left in the solution for 5 - 10 minutes. Be sure no air bubbles or debris
are on the probe points.

If the solution to be measured is seawater, be sure to
use the temperature compensation coefficient #EC_Salinity::tempCoefSalinity,
otherwise use #EC_Salinity::tempCoefEC as the parameter. If another compensation
value is desired, it can be provided as a regular float value.

After the measurement is taken, the following class variables are updated:

- #EC_Salinity::uS
- #EC_Salinity::mS
- #EC_Salinity::dS
- #EC_Salinity::S
- #EC_Salinity::PPM_500
- #EC_Salinity::PPM_640
- #EC_Salinity::PPM_700
- #EC_Salinity::salinityPSU
- #EC_Salinity::salinityPPT
- #EC_Salinity::tempC
- #EC_Salinity::tempF
- #EC_Salinity::K

\section notes Notes on Measuring Seawater
Salinity can be accurately measured between a range of 2 - 42, between the -2 - 35 C.

\section references References
- Concept: https://www.element14.com/community/community/design-challenges/vertical-farming/blog/2015/09/13/automated-green-house-blogs-main-page
- Temperature coefficients: http://www.posiva.fi/files/2094/POSIVA-2001-15_Working-report_web.pdf
- EC to PSU conversion: https://www.mwa.co.th/download/file_upload/SMWW_1000-3000.pdf
*/

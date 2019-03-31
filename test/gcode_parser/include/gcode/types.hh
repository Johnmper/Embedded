#ifndef __GCODE_TYPES_HEADER
#define __GCODE_TYPES_HEADER

#include<iostream>
#include<sstream>
namespace gcode{

    struct Command{
        char address='\0';
        int ikey=0;
        float fkey=0;
        bool is_float = false;
        Command(char a, int i) : address(a), ikey(i), fkey(0), is_float(false){};
        Command(char a, float f) : address(a), ikey(0), fkey(f), is_float(true){};
        void print(){
            std::cout << address;
            std::cout << (is_float ? fkey : ikey) << std::endl;
        }
    };


    enum command : unsigned short{
        G0  = 0,    ///< Coordinated Motion at Rapid Rate
        G1  = 1,    ///< Coordinated Motion at Feed Rate
        G2  = 2,    ///< Clockwise Coordinated Helical Motion at Feed Rate
        G3  = 3,    ///< Counter-Clockwise Coordinated Helical Motion at Feed Rate
        G4  = 4,    ///< Dwell
        G5  = 5,    ///< Cubic spline
        G6  = 6,    ///< Non Uniform rational B-Spline
        G7  = 7,    ///< Imaginary axis designation
        G10 = 10,   ///< Setting offsets in the program
        G11 = 11,   ///< Data write cancel
        G17 = 17,   ///< X-Y plane for arc machining, with live tooling
        G18 = 18,   ///< Z-X plane for arc machining, with live tooling
        G19 = 19,   ///< Z-Y plane for arc machining, with live tooling
        G20 = 20,   ///< Set Inch units
        G21 = 21,   ///< Set Metric units
        G28 = 28,   ///< Automatic return Home through reference point
        G30 = 30,   ///< Return to secundary Home Position
        G31 = 31,   ///< Feed until skip function
        G33 = 33,   ///< Constant Pitch Threading
        G34 = 34,   ///< Variable Pitch Threading
        G40 = 40,   ///< Tool Radius Compensation OFF
        G41 = 41,   ///< Tool Raidus Compensation Left
        G42 = 42,   ///< Tool Radius Compensation Right
        G43 = 43,   ///< Tool Length Offset Compensation (Negative)
        G44 = 44,   ///< Tool Length Offset Compensation (Positive)
        G45 = 45,   ///< Axis Offset Single increase
        G46 = 46,   ///< Axis Offset Single decrease
        G47 = 47,   ///< Axis Offset Double increase
        G48 = 48,   ///< Axis Offset Double decrease
        G49 = 49,   ///< Cancels Tool Length Compensation
        G50 = 50,   ///< Scaling function cancel
        G52 = 52,   ///< Local coordinate system setting
        G53 = 53,   ///< Machine coordinate system setting
        G54 = 54,   ///< Select coordinate system 1
        G55 = 55,   ///< Select coordinate system 2
        G56 = 56,   ///< Select coordinate system 3
        G57 = 57,   ///< Select coordinate system 4
        G58 = 58,   ///< Select coordinate system 5
        G59 = 59,   ///< Select coordinate system 6
        G61 = 61,   ///< Exact-Stop-Check Mode
        G62 = 62,   ///< Automatic corner override
        G64 = 64,   ///< Default Cutting Mode
        G68 = 68,   ///< Turns ON rotation of current coordinate system
        G69 = 69,   ///< Turns OFF rotation of current coordinate system
        G73 = 73,   ///< Peck Driling cycle for milling - high speed (NO full retraction from pecks)
        G74 = 74,   ///< Peck Drilling Cycle for milling - Lefthand thread!
        G76 = 76,   ///< Fine Boring cycle for milling
        G80 = 80,   ///< Cancel canned cycle
        G81 = 81,   ///< Simple drill cycle
        G82 = 82,   ///< Drill cycle with dwell
        G83 = 83,   ///< Peck drilling cycle
        G84 = 84,   ///< Tapping cycle Righthand thread
        G85 = 85,   ///< Bore in, bore out
        G86 = 86,   ///< Bore in, rapid out
        G87 = 87,   ///< Back boring cycle
        G90 = 90,   ///< Absolute programming
        G91 = 91,   ///< Incremental programming
        G92 = 92,   ///< Reposition origin point
        G94 = 94,   ///< Per minute feed
        G95 = 95,   ///< Per revolution feed
        G97 = 97,   ///< Constant Spindle Speed
        G98 = 98,   ///< Return no initial Z level in canned cycle
        G99 = 99,   ///< Return to R level in canned cycle
        G100=100,   ///< Tool length measurement
    };

    enum miscellaneous : unsigned short{
        M0  = 0,    ///< Compulsory Stop
        M1  = 1,    ///< Optional Stop
        M2  = 2,    ///< End of program
        M3  = 3,    ///< Spindle ON (clockwise)
        M4  = 4,    ///< Spindle ON (counter-clockwise)
        M5  = 5,    ///< Spindle STOP
        M6  = 6,    ///< Automatic Tool Change
        M7  = 7,    ///< Coolant ON (mist)
        M8  = 8,    ///< Coolant ON (flood)
        M9  = 9,    ///< Coolant OFF
        M10 = 10,   ///< Pallet ON
        M11 = 11,   ///< Pallet OFF
        M13 = 13,   ///< Spindle ON (clockwise) & Coolant ON (flood)
        M19 = 19,   ///< Spindle Orientation
        M21 = 21,   ///< Mirror X axis
        M22 = 22,   ///< Mirror Y Axis
        M30 = 30,   ///< End of program return TOP
        M48 = 48,   ///< Feedrate Override Allowed
        M49 = 49,   ///< Feedrate Override NOT Allowed
        M52 = 52,   ///< Unload Last Tool from Spindle
        M60 = 60,   ///< Automatic Pallet Change
        M98 = 98,   ///< Subprogram Call
        M99 = 99    ///< Subprogram END
    };




}


#endif // __GCODE_TYPES_HEADER

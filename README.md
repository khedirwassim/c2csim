Project Setup Guide </br>
⚠️ Warning: Absolute Paths
There are some absolute paths hardcoded in the project that you need to adjust:

In Main.qml: 

source = "file://" + "/your/path/to/project/images/generated/car_modified_" + modelData.id + ".svg"

In the applyColorToSVG() function of SumoInterface.cpp:
QString originalFilePath = "/your/path/to/project/images/car-cropped.svg";
QString uniqueFileName = "/your/path/to/project/images/generated/car_modified_" + id + ".svg";
Make sure to update these paths according to your project setup.

🛠️ Work Environment Initialization
1. Update Paths to libsumo.h:
Modify the #include directive in Sumo.h:
#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"

Similarly, update the path in compound.h:
#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"

 Compile the Project:
Run the following cmake command (replace the path with your Qt6 installation path):
cmake -DCMAKE_PREFIX_PATH=/your/path/to/Qt/6.6.0/gcc_64/lib/cmake/Qt6 CMakeLists.txt

Then, compile the project using: make


🚗 Start the SUMO Simulation
To run the SUMO simulation, execute one of the following commands after generating the executable:

For SUMO with GUI:
sumo-gui --remote-port 6066 -c ./sumofiles/osm.sumocfg
sumo-gui --remote-port 6066 -c ./sumofiles/osm.sumocfg

Or use the shortcut defined in the Makefile: make run


🚀 Launch the Application
Open a different terminal and run the application: ./appsumotest

Ensure the simulation is running at the same time.

Start the Simulation in SUMO:
Click on the "Play/Run" button in SUMO to begin the simulation.

Note: You can modify the remote port by adjusting its value in SumoInterface.cpp.

🔧 Additional Commands in Makefile
Run the simulation:    make run
Restart the project (clean and rebuild without repeating commands): make restart
.PHONY: run restart









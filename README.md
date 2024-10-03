Project Setup Guide </br>
⚠️ Warning: Absolute Paths</br>
There are some absolute paths hardcoded in the project that you need to adjust:

In Main.qml: </br>

source = "file://" + "/your/path/to/project/images/generated/car_modified_" + modelData.id + ".svg"</br>

In the applyColorToSVG() function of SumoInterface.cpp:</br>
QString originalFilePath = "/your/path/to/project/images/car-cropped.svg";</br>
QString uniqueFileName = "/your/path/to/project/images/generated/car_modified_" + id + ".svg";</br>
Make sure to update these paths according to your project setup.</br></br>

🛠️ Work Environment Initialization</br>
1. Update Paths to libsumo.h:</br>
Modify the #include directive in Sumo.h:</br>
#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"</br></br>

Similarly, update the path in compound.h:</br>
#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"</br></br>

 Compile the Project:</br>
Run the following cmake command (replace the path with your Qt6 installation path):</br>
cmake -DCMAKE_PREFIX_PATH=/your/path/to/Qt/6.6.0/gcc_64/lib/cmake/Qt6 CMakeLists.txt</br>

Then, compile the project using: make</br></br>


🚗 Start the SUMO Simulation</br>
To run the SUMO simulation, execute one of the following commands after generating the executable:</br></br>

For SUMO with GUI:</br>
sumo-gui --remote-port 6066 -c ./sumofiles/osm.sumocfg</br>
sumo-gui --remote-port 6066 -c ./sumofiles/osm.sumocfg</br></br>

Or use the shortcut defined in the Makefile: make run</br></br></br


🚀 Launch the Application</br>
Open a different terminal and run the application: ./appsumotest</br></br>

Ensure the simulation is running at the same time.</br>

Start the Simulation in SUMO:</br>
Click on the "Play/Run" button in SUMO to begin the simulation.</br>

Note: You can modify the remote port by adjusting its value in SumoInterface.cpp.</br></br>

🔧 Additional Commands in Makefile</br></br>
Run the simulation:    make run</br>
Restart the project (clean and rebuild without repeating commands): make restart</br>
.PHONY: run restart</br>









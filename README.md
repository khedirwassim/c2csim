<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project Setup Guide</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
        }
        h1, h2 {
            color: #2C3E50;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
            border: 1px solid #ddd;
            overflow-x: auto;
        }
        .warning {
            color: #e74c3c;
        }
        .tip {
            color: #3498db;
        }
        .note {
            background-color: #f9edbe;
            border-left: 6px solid #ffeb3b;
            padding: 10px;
            margin: 10px 0;
            border-radius: 5px;
        }
    </style>
</head>
<body>

    <h1>Project Setup Guide</h1>

    <h2 class="warning">⚠️ Warning: Absolute Paths</h2>
    <p>There are some absolute paths hardcoded in the project that you need to adjust:</p>
    
    <ul>
        <li><strong>In <code>Main.qml</code>:</strong></li>
    </ul>
    <pre><code>source = "file://" + "/your/path/to/project/images/generated/car_modified_" + modelData.id + ".svg"</code></pre>

    <ul>
        <li><strong>In the <code>applyColorToSVG()</code> function of <code>SumoInterface.cpp</code>:</strong></li>
    </ul>
    <pre><code>QString originalFilePath = "/your/path/to/project/images/car-cropped.svg";
QString uniqueFileName = "/your/path/to/project/images/generated/car_modified_" + id + ".svg";</code></pre>

    <p>Make sure to update these paths according to your project setup.</p>

    <hr>

    <h2>🛠️ Work Environment Initialization</h2>

    <h3>1. Update Paths to <code>libsumo.h</code>:</h3>
    <ul>
        <li>Modify the <code>#include</code> directive in <strong>Sumo.h</strong>:</li>
    </ul>
    <pre><code>#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"</code></pre>

    <ul>
        <li>Similarly, update the path in <strong>compound.h</strong>:</li>
    </ul>
    <pre><code>#include "/your/path/to/project/sumo-integrator-master/lib/sumo/libsumo.h"</code></pre>

    <h3>2. Compile the Project:</h3>
    <p>Run the following <code>cmake</code> command (replace the path with your Qt6 installation path):</p>
    <pre><code>cmake -DCMAKE_PREFIX_PATH=/your/path/to/Qt/6.6.0/gcc_64/lib/cmake/Qt6 CMakeLists.txt</code></pre>

    <p>Then, compile the project using:</p>
    <pre><code>make</code></pre>

    <hr>

    <h2>🚗 Start the SUMO Simulation</h2>

    <p>To run the SUMO simulation, execute one of the following commands after generating the executable:</p>

    <ul>
        <li>For SUMO with GUI:</li>
    </ul>
    <pre><code>sumo-gui --remote-port 6066 -c ./sumofiles/osm.sumocfg</code></pre>

    <ul>
        <li>Or use the shortcut defined in the Makefile:</li>
    </ul>
    <pre><code>make run</code></pre>

    <hr>

    <h2>🚀 Launch the Application</h2>

    <ol>
        <li>Open a different terminal and run the application:</li>
    </ol>
    <pre><code>./appsumotest</code></pre>

    <ol start="2">
        <li>Ensure the simulation is running at the same time.</li>
    </ol>

    <h3>Start the Simulation in SUMO:</h3>
    <ul>
        <li>Click on the "Play/Run" button in SUMO to begin the simulation.</li>
    </ul>

    <div class="note">
        <p><strong>Note:</strong> You can modify the remote port by adjusting its value in <code>SumoInterface.cpp</code>.</p>
    </div>

    <hr>

    <h2>🔧 Additional Commands in Makefile</h2>

    <ul>
        <li><strong>Run the simulation:</strong></li>
    </ul>
    <pre><code>make run</code></pre>

    <ul>
        <li><strong>Restart the project</strong> (clean and rebuild without repeating commands):</li>
    </ul>
    <pre><code>make restart</code></pre>

    <pre><code>.PHONY: run restart</code></pre>

</body>
</html>

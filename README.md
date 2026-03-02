# Semi-Automatic AED Plus GUI Simulator

## Project Overview

This project is a comprehensive software simulation of a Semi-Automatic AED Plus device. Developed using **C++** and the **Qt Framework**, the application replicates both the graphical user interface (GUI) and the underlying medical logic required to guide a user through a cardiac emergency.

## Team Members (Team #26)

* **Hamza Alsarakbi**
* **Abdullah Aswad**
* **Saad Sheikh**

## Purpose

The primary goal was to utilize C++ and Qt to develop a program that accurately simulates the operational flow, patient analysis, and shock delivery logic of a real-world AED device.

## Core Architecture

The simulator is built with a focus on multithreading and modularity:

- **Multithreading:** Uses `AEDWorker` and separate threads for the Heart and Pulse classes to ensure the GUI remains responsive while performing real-time heart rhythm analysis.
- **Logic Handling:** Implements a robust state machine to transition between patient connection, heart analysis, CPR coaching, and shock delivery.
- **MVC Pattern:** Separates the UI layer (`MainWindow`) from the underlying `AED` and `Patient` models.

## Contributions Breakdown

### Documents & Diagrams
- **Use Cases & UC Diagram:** Abdullah Aswad
- **Class Diagram:** Hamza Alsarakbi
- **Sequence Diagrams:** Hamza Alsarakbi, Abdullah Aswad, Saad Sheikh
- **State Diagrams:** Hamza Alsarakbi
- **Traceability Matrix:** Saad Sheikh
- **README:** Abdullah Aswad

### Implementation
- **UI Design & Main Window:** Hamza Alsarakbi, Abdullah Aswad
- **AED Logic & State Machine:** Hamza Alsarakbi, Abdullah Aswad
- **Patient & Heart Simulation:** Hamza Alsarakbi, Saad Sheikh
- **Testing & QA:** Hamza Alsarakbi, Abdullah Aswad, Saad Shekh
- **Video Demo:** Saad Sheikh

## Directory Structure

```text
AedSimulator/
├── aed/
│   ├── mainWindow.ui/cpp/h    # UI-to-Logic interface
│   ├── main.cpp               # Application entry point
│   ├── img/                   # Device icons and ECG diagrams
│   └── model/
│       ├── aed/               # AED state logic and Worker classes
│       └── patient/           # Patient, Heart, and Pulse data models
├── docs/
│   ├── Main Documentation/    # Use cases, Class/Sequence/State diagrams
│   ├── Other Documentation/   # Supplemental research and notes
│   └── videos/                # Functional testing and demo videos
└── README.md                  # Project guide
```

## Setup and Installation

1. Ensure **Qt Creator** and the **Qt 5.15+** SDK are installed.

2. Clone the repository:

```bash
git clone https://github.com/HamzaAlsarakbi/AEDSimulator.git
```

3. Open `AedSimulator.pro` in Qt Creator.

4. Build and Run the project.

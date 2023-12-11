Title: 
Semi Automatic AED Plus GUI 

Authors: Team #26							
- Hamza Alsarakbi						
- Abdullah Aswad					
- Saad Sheikh							

Purpose:
Utilizing C++ and Qt languages to develop a program replicating the GUI and logic of a Semi Automatic AED Plus device 

Contributions:
	Documents & Diagrams:
		Use Cases: Abdullah Aswad
		Use Case Diagram: Abdullah Aswad
		Class Diagram: Hamza Alsarakbi
		Sequence Diagrams: Hamza Alsarakbi - Abdullah Aswad - Saad Sheikh	*Battery check and heart-related event loops omitted from sequence diagrams for easier readability
		State Diagrams: Hamza Alsarakbi
		Traceability Matrix: Saad Sheikh
		README: Abdullah Aswad
	
	Implementation:
		Documentation: Abdullah Aswad
		Testing: Hamza Alsarakbi - Abdullah Aswad - Saad Sheikh
		Video Demo: Saad Sheikh
		UI: Hamza Alsarakbi
		MainWindow: Hamza Alsarakbi - Abdullah Aswad
		AED: Hamza Alsarakbi - Abdullah Aswad
		Patient: Hamza Alsarakbi - Saad Sheikh
		Heart & Pulse: Hamza Alsarakbi - Saad Sheikh
		

Submission:								*Note: some files were omitted from this breakdown as they're made automatically for supplemental reasons
	AedSimulator:
		aed:
			mainWindow files				// Handles the relationship between the ui and AED logic
			main.cpp					// Calls for the program to open
			test files					// Files made to test the heart and patient before connecting them to the other code
			img						// Folder containing the icons for the machine as well as the ECG diagrams
			model:
				aed:
					AED files			// Handles the logic of the machine between each step
					AEDWorker.h			// Helper class for the AED that allows for multithreading
				patient:
					Patient files			// Container for information about the patient as well as connection between heart and AED
					heart:
						Heart files		// Keeps track of the heart rate in a constantly update thread
						pulse:
							Pulse files	// keeps track of the pulse in the heart

		docs:
			Main Documentation:
				Use cases				// Contains the use cases and the UC diagram for the device
				class diagram				// contains teh class diagram of the program
				sequence diagrams			// Contains 4 safety scenarios and 3 success scenarios in sequence diagrams
				state diagrams				// Contains state diagrams for the heart and AED
				tracability matrix			// Contains the tracability matrix for the device
			Other Documentation				// Contains supplemental notes and diagrams made to help with our understanding and making of the project

		test video						// A video testing and presenting our program's functions

		README							// A guide to the contents of the submission
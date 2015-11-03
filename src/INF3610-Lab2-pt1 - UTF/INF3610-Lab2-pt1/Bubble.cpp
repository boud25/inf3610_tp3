///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Bubble.h"
#include <vector>


///////////////////////////////////////////////////////////////////////////////
//
//	Constructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::Bubble( sc_module_name name )
{
	/*
	
	À compléter
	
	*/
	SC_THREAD(thread);
}


///////////////////////////////////////////////////////////////////////////////
//
//	Destructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::~Bubble()
{
}


///////////////////////////////////////////////////////////////////////////////
//
//	thread
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::thread(void)
{
	/*
	
	À compléter
	
	*/
	while (1)

	{
		// Read amount of elements to sort
		unsigned int nbElements = readPort->Read(0);
		
		// Read those elements
		unsigned int* elements;
		elements = new unsigned int[nbElements];
		for (unsigned int i = 0; i < nbElements; i++)
		{
			elements[i] = readPort->Read((i + 1) * 4);
		}

		// Sort those value
		bubbleSort(elements, nbElements);

		// Write them in mermory
		for (unsigned int i = 0; i < nbElements; i++)
		{
			writePort->Write((i + 1) * 4, elements[i]);
		}

		// Free memory
		delete []elements;
		elements = nullptr;

		// Stopping the app
		sc_stop();
		wait();
	}
}


///////////////////////////////////////////////////////////////////////////////
//
//	bubbleSort
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::bubbleSort(unsigned int *ptr, int counter)
{
	// Variable
	unsigned int tmp = 0;
	
	for (int i = 1; i < counter; ++i){
		for (int j = 0; j < counter - i; ++j){
			if (ptr[j] > ptr[j + 1]){
				// Changing position
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
	
		}
	}
	// Display
	for (int i = 0; i < counter; i++)
		cout << ptr[i] << endl;
}

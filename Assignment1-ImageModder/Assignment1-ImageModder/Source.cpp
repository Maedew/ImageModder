//Assignment 1: Image Modder	Due: 09/12/2018
//Program converts color images to grayscale, invert red/green/blue/all in an output image file (.ppm)
//Jessica Ng

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
//file opening----------------------------------------------------------------------
	string fileName, outFile;
	ifstream imageFile;
	ofstream outputImage;

	cout << "Enter image file name (PPM): ";
	cin >> fileName;

	imageFile.open(fileName);
	if (!imageFile)
	{
		cout << "Failed to open file." << endl;
		return 0;
	}

	cout << "Enter output image file name: ";	
	cin >> outFile;
													
//check file------------------------------------------------------------------------

	string magicNumber;
	int row, col, mcv, magicNum;	//mcv= maximum color value

	imageFile >> magicNumber;
	imageFile >> row >> col >>mcv;

	cout << "Magic Number: " << magicNumber << endl;
	cout << "Width and Height: " << row << ", " << col << endl;
	cout << "Maximum Color Value: " << mcv << endl;;

	if (row > 1000 || col > 1000)
	{
		cout << "Image contains more than 1000 pixels in either width or height.";
		imageFile.close();
		return 0;
	}
	if (magicNumber == "P3")
		magicNum = 3;
	else if (magicNumber == "P2")
		magicNum = 2;
	else if (magicNumber == "P1")
		magicNum = 1;
	else
	{
		imageFile.close();
		return 0;
	}

	outputImage.open(outFile);					//create output image
	outputImage << magicNumber << endl;			//ppm header
	outputImage << row << " " << col << endl;
	outputImage << mcv << endl;

//Menu and Menu Options-------------------------------------------------------------

	int choice;
	const int GRAYSCALE_CHOICE = 1,
			  INVRED_CHOICE = 2,
		      INVGREEN_CHOICE = 3,
		      INVBLUE_CHOICE = 4,
		      INVALL_CHOICE = 5;

	//Menu----------------------------------------------------------
	cout << "\nImage Processing Choices: " << endl;
	cout << "1. Convert to grayscale" << endl;
	cout << "2. Invert Red" << endl;
	cout << "3. Invert Green" << endl;
	cout << "4. Invert Blue" << endl;
	cout << "5. Invert All" << endl;
	cout << "6. Quit Menu" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice > 6 || choice < 1)
	{
		cout << "Enter a choice between 1 and 6: ";
		cin >> choice;
	}

	//1. Grayscale--------------------------------------------------

	if (choice == GRAYSCALE_CHOICE)
	{
		int count = 0;
		int r, g, b, avg;
		while (count != row*col*magicNum)
		{
			imageFile >> r >> g >> b;
			avg = (r + g + b) / 3;	//average values
			outputImage << avg << " " << avg << " " << avg << " ";
			count += 3;
		}

		cout << "\nGrayscale image created at: " << outFile << endl;
	}

	//2. Invert Red-------------------------------------------------

	else if (choice == INVRED_CHOICE)
	{
		int count = 0;
		int r, g, b;
		while (count != row*col*magicNum)
		{
			imageFile >> r >> g >> b;
			r = 255 - r;	//invert value
			outputImage << r << " " << g << " " << b << " ";
			count += 3;
		}

		cout << "\nInverted red image created at: " << outFile << endl;
	}

	//3. Invert Green-----------------------------------------------

	else if (choice == INVGREEN_CHOICE)
	{
		int count = 0;
		int r, g, b;
		while (count != row*col*magicNum)
		{
			imageFile >> r >> g >> b;
			g = 255 - g;	//invert value
			outputImage << r << " " << g << " " << b << " ";
			count += 3;
		}

		cout << "\nInverted green image created at: " << outFile << endl;
	}

	//4. Invert Blue------------------------------------------------

	else if (choice == INVBLUE_CHOICE)
	{
		int count = 0;
		int r, g, b;
		while (count != row*col*magicNum)
		{
			imageFile >> r >> g >> b;
			b = 255 - b;	//invert value
			outputImage << r << " " << g << " " << b << " ";
			count += 3;
		}

		cout << "\nInverted blue image created at: " << outFile << endl;
	}

	//5. Invert All-------------------------------------------------

	else if (choice == INVALL_CHOICE)
	{
		int count = 0;
		int r, g, b;
		while (count != row*col*magicNum)
		{
			imageFile >> r >> g >> b;
			r = 255 - r;	//invert value
			g = 255 - g;
			b = 255 - b;
			outputImage << r << " " << g << " " << b << " ";
			count += 3;
		}

		cout << "\nInverted image created at: " << outFile << endl;
	}

//file closing and end program------------------------------------------------------

	imageFile.close();
	outputImage.close();
	return 0;
}
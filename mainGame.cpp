//Author :

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                       //
//    ##########  #########    ###      ### ###########   #########  ###      ### ######### ###   ###	 //
//    ###    ###  ###	   ### ###      ###     ###     ###    	     ###      ### ###	    ###  ###	 //
//    ###    ###  ###	   ### ###	###     ###     ###	     ###      ### ###       ### ###	 //
//    ##########  #########    ############     ###       #########  ############ ######### ######	 //
//    ###    ###  ###	   ### ###      ###     ###              ### ###      ### ###       ### ###	 //
//    ###    ###  ###	   ### ###      ###     ###              ### ###      ### ###       ###  ###	 //
//    ###    ###  #########    ###	### ###########  #########   ###      ### ######### ###   ###    //
//                                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//prototype declaration

#include <iostream>
#include <windows.h>

//function declaration

int mainGame();
void getBoard();
int checkWin();
int checkInput();

using namespace std;

//global variable declaration

int rowNumber;
int columnNumber;
int numOfTurns;
char columnNumberCharacter;

char mainBoard[6][7] = {{' ',' ',' ',' ',' ',' ',' '},
						{' ',' ',' ',' ',' ',' ',' '},
						{' ',' ',' ',' ',' ',' ',' '},
						{' ',' ',' ',' ',' ',' ',' '},
						{' ',' ',' ',' ',' ',' ',' '},
						{' ',' ',' ',' ',' ',' ',' '},};

int main() {

	system("cls");
	cout<<"This is a program to play plot-4..." << endl;
	cout<<"Each player has to enter the column number according to their choice and their turn..." << endl;
	cout<<"Player 1 possesses the char : 'X' and player 2 possesses the char : 'O'" << endl;
	cout<<"The first one to make a continuous 4, (diagonally/horizantally/vertically) is the winner." << endl;
	cout<<"If you enter column number '4'(say), then the topmost position vacant in that column will be occupied by your character.";
	cout<<"If you enter a string while entering your choice, then the first character will be taken..." << endl;
	system("pause");
	system("cls");
	mainGame();

}


int mainGame() {

	int result1;
	int result2;
	
	for (numOfTurns = 1 ; numOfTurns <= 42 ; numOfTurns ++ ) {
		
		getBoard();
		
		cout<<"Player " << (numOfTurns - 1) % 2 + 1 << " , please enter the column number of your choice : " << endl;
		cin >> columnNumberCharacter;

		result2 = checkInput();

		while (result2) {
			getBoard();
			cout<<"Player " << (numOfTurns - 1) % 2 + 1 << " , please reenter a VALID column number: " << endl;
			cin >> columnNumberCharacter;
			result2 = checkInput();
		}

		
		
		columnNumber = columnNumberCharacter - 49;
		for (rowNumber = 5 ; rowNumber >= 0 ; rowNumber --) {

			
			if (mainBoard[rowNumber][columnNumber] == ' ') {

				if ( ( (numOfTurns - 1) % 2 + 1) == 1 ) 
					mainBoard[rowNumber][columnNumber] = 'X';
				else
					mainBoard[rowNumber][columnNumber] = 'O';

				break;	

			}


		}	


		if (numOfTurns >= 7) {
			/*
				function calling for the condition check for winning :
			*/
			result1 = checkWin();
			if (result1 == 0) {

				
				getBoard();
		
				
				cout << "Respected Player " <<  (numOfTurns - 1) % 2 + 1 << ", you are the winner !" << endl;
				cout << "Poor Player " <<  (numOfTurns    ) % 2 + 1 << ", better luck next time...!" << endl;

				return 0;
			}

		}	

	}


	
	getBoard();

	cout <<"Result : Match tied between the two players..." << endl;
	return 0;


}



void getBoard() {

	system("cls");
	cout << endl << endl << endl << endl;

	char standCharacter = 92;
	system("cls");
	cout << endl << endl << endl << endl ;

	//variable tempRowNum is there to be used in the for loop for printing the mainBoard[][] ...
	int tempRowNum;
	cout<<"     1   2   3   4   5   6   7" << endl << endl;
	for (tempRowNum = 0 ; tempRowNum <= 5 ; tempRowNum ++) {

		cout<<"   |   |   |   |   |   |   |   |    " << endl;
		cout<<"   | "<<mainBoard[tempRowNum][0]<<" | "<<mainBoard[tempRowNum][1]<<" | "<<mainBoard[tempRowNum][2]<<" | "<<mainBoard[tempRowNum][3]<<" | "<<mainBoard[tempRowNum][4]<<" | "<<mainBoard[tempRowNum][5]<<" | "<<mainBoard[tempRowNum][6]<<" |    "<< endl;
		cout<<"   |___|___|___|___|___|___|___|    "<< endl;
	}
	cout<<" // "<<standCharacter<<""<<standCharacter<<"                        //"<<standCharacter<<""<<standCharacter<<" "<< endl; 
    cout<<"//   "<<standCharacter<<""<<standCharacter<<"                      //  "<<standCharacter<<""<<standCharacter<<""<< endl;
    cout<<"------------------------------------" << endl;
    cout<<"------------------------------------" << endl;

    cout<< endl << endl << endl << endl << endl;

}

int checkWin() {

//In this functinon, if any case is satisfied, then return a value of 0. else return 1, at the last of the function

/*
	case type 1:

		@ @ X @  or  @ X @ @
		
*/

	if 
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber - 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber + 1]) &&
			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber - 2] ||
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber + 2])

	  	) 
		
		return 0; 

/*
	case type 2:

		@ @ @ X or X @ @ @

*/	

	else if 
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber - 1] && 
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber - 2] &&
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber - 3]) ||

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber + 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber + 2] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber][columnNumber + 3])
		)

		return 0;

/*
	case type 3:

		X

		@

		@

		@
*/	

	else if
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 1][columnNumber] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 2][columnNumber] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 3][columnNumber])

		)

		return 0;

/*
	case type 4:

	@				@
						
		@				X
				or  		
	    	X				@

	    		@				@

*/		


	else if
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 1][columnNumber - 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 1][columnNumber + 1]) &&
			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 2][columnNumber - 2] ||
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 2][columnNumber + 2])			

		)

		return 0;

/*
	case type 5:


				@				@

			@				X
					or
		X				@

	@				@
*/		
		

	else if


		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 1][columnNumber + 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 1][columnNumber - 1]) &&
			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 2][columnNumber + 2] ||
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 2][columnNumber - 2])			

		)

		return 0;	

/*
	case type 6:

		@				X

			@				@
					or
				@				@

					X				@

*/		

else if 
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 1][columnNumber - 1] && 
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 2][columnNumber - 2] &&
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 3][columnNumber - 3]) ||

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 1][columnNumber + 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 2][columnNumber + 2] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 3][columnNumber + 3])
		)

		return 0;

/*
	case type 7:

					@				X

				@				@
					or
			@				@

		X				@
*/					

else if 
		(

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 1][columnNumber + 1] && 
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 2][columnNumber + 2] &&
             mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber - 3][columnNumber + 3]) ||

			(mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 1][columnNumber - 1] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 2][columnNumber - 2] &&
			 mainBoard[rowNumber][columnNumber] == mainBoard[rowNumber + 3][columnNumber - 3])
		)

		return 0;


//Ultimately, if no case evaluates to true;


		return 1;

}

int checkInput() {

	//if successfully entered a valid column number, return 0
	//else if failed to enter a valid column number, return 1
	int score = 0; //to increase score on each matching of a desired case...
	
	if (columnNumberCharacter >= 49 && columnNumberCharacter <= 55)
		score += 1;

	if (mainBoard[0][columnNumberCharacter - 49] == ' ')
		score += 1;

	if (score == 2)
		return 0;
	else 
		return 1;

}

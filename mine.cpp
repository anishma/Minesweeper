#include "mine.h"
int main()
{
	unsigned size;
	double mineProb;
	while(cin>>size>>mineProb)
	{
	vector<vector<bool>> mines(size,vector<bool>(size)); // creates 2 dimensional vector mines
	vector<vector<unsigned>> counts(size,vector<unsigned>(size)); //creates 2 dimensional vector counts.
	buildMineField(mines, mineProb); 
	cout << "Mine Locations: size = " << mines.size() << " x " << mines.size() << "," << " " << "prob of mine " << "=" << " " <<mineProb<< endl;
	displayMineLocations(mines);
	fixCounts(mines, counts);
	cout<<endl;
	displayMineCounts(counts);
	cout<<endl;
	}
    return 0;
}
/**********************************************************
Function Name:buildMineField()
Arguments: vector mines and double mineProb
Return Type:void.
This routine basically assigns true or false to each location in the vector.
It assigns true if the random value is less than the mineProbability or else it assigns false.
**********************************************************/
void buildMineField(vector<vector<bool>>& mines, const double& mineProb)
{
	double rnd;
	srand(1); //initialising the random generator.
	unsigned n = mines.size(); 
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < n; j++)
		{
			rnd = rand() / (double(RAND_MAX) + 1); // calculating the random values.
			if (rnd < mineProb)
			{
				mines[i][j] = true;
			}
			else
			{
				mines[i][j] = false;
			}
		}
	}
}
/**********************************************************
Function Name:displayMineLocations
Arguments:constant vector mines.
Return Type:void
This routine displays X in grid where there is a mine.
**********************************************************/
void displayMineLocations(const vector<vector<bool>>& mines)
{
	unsigned numbers = mines.size() * 5 + (mines.size() - 1);// calculating a value to print the number of "-"
	
	for (unsigned k = 0; k < mines.size(); k++)
	{
		cout << " ";
		for (unsigned i = 0; i < numbers; i++) // loop for printing "-"
		{
			cout << "-";
		}
		cout << " " << endl;

		for (unsigned i = 0; i < mines.size(); i++) //loop for printing pipe symbols.
		{
			cout << "|" << " " << " " << " " << " " << " ";
		}

		cout << "|" << endl;
		for (unsigned l = 0; l < mines.size(); l++)
		{
			if(mines[k][l]==1)
			cout << "|" << " " << " " << "X" << " " << " "; //prints value "X" if there is a mine
			else
			cout << "|" << " " << " " << " " << " " << " "; 

		}
		cout << "|" << endl;
		for (unsigned i = 0; i < mines.size(); i++)
		{
			cout << "|" << " " << " " << " " << " " << " ";
		}

		cout << "|" << endl;
	}
	cout << " ";
	for (unsigned i = 0; i < numbers; i++) // printing "-" for last row.
	{
		cout << "-";
	}
	cout << " " << endl;
}
/**********************************************************
Function Name: fixCounts
Arguments:vectors mines and counts
Return Type:void
This function checks the adjacent mines and increments count value if there is a mine.
**********************************************************/
void fixCounts(const vector<vector<bool>>& mines, vector<vector<unsigned>>& counts)
{
	
	unsigned c;
	if (mines.size() == 1) // for mine size 1
	{
		c = mines[0][0];
		counts[0][0] = c;
	}
	
	else
	{
		for (unsigned i = 0; i < mines.size(); i++)
		{
			for (unsigned j = 0; j < mines.size(); j++)
			{
				c = mines[i][j];
				if (i == 0 && j == 0 && mines.size()>1) //adjacent mines for [0][0] location.
				{
					if (mines[i][j + 1] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
					if (mines[i + 1][j + 1] == 1)
						c++;
				}
				if ((j >= 1 && j < mines.size() - 1) && i == 0) //adjacent mines for locations where row value is zero.
				{
					if (mines[i][j - 1] == 1)
						c++;
					if (mines[i + 1][j - 1] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
					if (mines[i + 1][j + 1] == 1)
						c++;
					if (mines[i][j + 1] == 1)
						c++;
				}
				if (i == 0 && j == mines.size() - 1)//adjacent mines for location which is end of the row.
				{
					if (mines[i][j - 1] == 1)
						c++;
					if (mines[i + 1][j - 1] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
				}
				if ((i >= 1 && i < mines.size() - 1) && j == mines.size() - 1)//checking adjacent mines for middle elements of the last column.
				{
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i - 1][j - 1] == 1)
						c++;
					if (mines[i][j - 1] == 1)
						c++;
					if (mines[i + 1][j - 1] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
				}
				if (i == mines.size() - 1 && j == mines.size() - 1) //checking adjacent mines for last element of the last column
				{
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i - 1][j - 1] == 1)
						c++;
					if (mines[i][j - 1] == 1)
						c++;
				}

				if (i == mines.size() - 1 && j == 0)//checking adjacent mines for last element of first column
				{
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i - 1][j + 1] == 1)
						c++;
					if (mines[i][j + 1] == 1)
						c++;
				}
				if (i == mines.size() - 1 && (j >= 1 && j < mines.size() - 1))//checking adjacent mines for middle elements of last row.
				{
					if (mines[i][j + 1] == 1)
						c++;
					if (mines[i][j - 1] == 1)
						c++;
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i - 1][j + 1] == 1)
						c++;
					if (mines[i - 1][j - 1] == 1)
						c++;
				}
				if (j == 0 && (i >= 1 && i < mines.size() - 1)) //checking adjacent mines for middle elements of first column.
				{
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
					if (mines[i - 1][j + 1] == 1)
						c++;
					if (mines[i][j + 1] == 1)
						c++;
					if (mines[i + 1][j + 1] == 1)
						c++;
				}
				if ((i >= 1 && i < mines.size() - 1) && (j >= 1 && j < mines.size() - 1)) //checking adjacent mines for the middle elements of middle rows.
				{
					if (mines[i - 1][j] == 1)
						c++;
					if (mines[i + 1][j] == 1)
						c++;
					if (mines[i][j - 1] == 1)
						c++;
					if (mines[i][j + 1] == 1)
						c++;
					if (mines[i - 1][j - 1] == 1)
						c++;
					if (mines[i - 1][j + 1] == 1)
						c++;
					if (mines[i + 1][j - 1] == 1)
						c++;
					if (mines[i + 1][j + 1] == 1)
						c++;
				}
				counts[i][j] = c;

				
			}

		}
	}
	
}
/**********************************************************
Function Name: displayMineCounts
Arguments: vector counts
Return Type:void
This function displays the minecounts in a grid.
**********************************************************/
void displayMineCounts(const vector<vector<unsigned>>& counts)
{
	unsigned numbers = counts.size() * 5+(counts.size()-1);
	cout << "Mine Counts:" << endl;
	for (unsigned k = 0; k < counts.size(); k++)
	{
		cout << " ";
		for (unsigned i = 0; i < numbers; i++) //loop for printing "-"
		{
			cout << "-";
		}
		cout << " " << endl;
		
			for (unsigned i = 0; i < counts.size(); i++) //loop for printing pipes.
			{
				cout << "|" << " " << " " << " " << " " << " ";
			}
	
		cout << "|" << endl;
		for (unsigned l = 0; l < counts.size(); l++) //loop for printing mine counts.
		{
			
				cout<<"|"<<" "<<" "<< counts[k][l]<<" "<<" ";
				
		}
		
		cout << "|" << endl;
		for (unsigned i = 0; i < counts.size(); i++)
		{
			cout << "|" << " " << " " << " " << " " << " ";
		}

		cout << "|" << endl;
	}
	cout << " ";
	for (unsigned i = 0; i < numbers; i++)
	{
		cout << "-";
	}
	cout << " " << endl;
	
}

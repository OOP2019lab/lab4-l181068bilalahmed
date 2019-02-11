#include <iostream>

using namespace std;

class CricketTeam{
	string * membernames;
	int no_of_members;
	char * teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	//Getter Functions
	string getCaptain();
	int getRank();
	string getTeamName();
	int getno_of_members();
	//Setter Functions
	void setCaptain(string CapName);
	void setRank(int rankno);
	void setTeamName(string tname);
	void setno_of_members(int noMembers);
	
	CricketTeam(); //Default Constructor;
	CricketTeam(string name, int no_of_members); //Parameterized Constructor
	CricketTeam (string filename);//Parameterized Constructor with file name as parameter
	~CricketTeam();

	//Input Functions
	void inputTeamMember(string name);
	void InputScore(int score);
	int AverageScore();
	void print();
	void printInfo();
	void Compare(CricketTeam A, CricketTeam B);
};
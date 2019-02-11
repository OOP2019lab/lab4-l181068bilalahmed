#include <iostream>
#include <string>
#include "CricketTeam.h"`

using namespace std;

int main(){
	string filename;
	cout << "Enter file address: " << endl;
	cin >> filename;
	filename = "C:\\Users\\Bilal Ahmed\\Desktop\\sample.txt";
	CricketTeam Other;
	CricketTeam Pakistan ("C:\\Users\\Bilal Ahmed\\Desktop\\sample.txt");

	Pakistan.printInfo(); // Printing Team Info
	Pakistan.print(); // Print

	//Captain
	string captain = "Imran";
	Pakistan.setCaptain(captain);
	Pakistan.getCaptain();

	//Rank
	int Rank = 0;
	Pakistan.setRank(2);
	 Pakistan.getRank();

	//TeamName
	string teamName = "Pakistan";
	Pakistan.setTeamName(teamName);
	Pakistan.getTeamName();

	//Members
	int members = 10;
	Pakistan.setno_of_members(members);
	Pakistan.getno_of_members();

	//Input new Member
	string name = "Akmal";
	Pakistan.inputTeamMember(name);

	//Input new score
	int score = 100;
	Pakistan.InputScore(score);

	//Calculating Average Score
	int AverageScore = Pakistan.AverageScore();


	system("pause");
}
 
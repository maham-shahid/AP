													// Advanced Programming Assignment 1
   										// 		     --RPI Calculation and March Madness--

   										// 			Code Written By: 	Maham Shahid
   										// 								00733
   										// 								BESE-3B
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Team
{
	private:
		string id;
		string name;
	public:
		Team()
		{

		}
		void setId(string x)
		{
			id=x;
		}
		void setName(string x)
		{
			name=x;
		}
		string getId()
		{
			return id;
		}
		string getName()
		{
			return name;
		}
};

class Seasons
{
	private:
		string season_id;
		string year;
	public:
		Seasons()
		{

		}
		void setSeasonId(string x)
		{
			season_id=x;
		}
		void setYear(string x)
		{
			year=x;
		}
		string getSeasonId()
		{
			return season_id;
		}
		string getYear()
		{
			return year;
		}
};

class Results
{
	private:
		string season_id;
		string day;
		string wteam;
		string wscore;
		string lteam;
		string lscore;
		string wloc;
	public:
		Results()
		{

		}
		void setSeasonId(string x)
		{
			season_id=x;
		}
		void setDay(string x)
		{
			day=x;
		}
		void setWTeam(string x)
		{
			wteam=x;
		}
		void setWScore(string x)
		{
			wscore=x;
		}
		void setLTeam(string x)
		{
			lteam=x;
		}
		void setLScore(string x)
		{
			lscore=x;
		}
		void setWLoc(string x)
		{
			wloc=x;
		}
		string getSeasonId()
		{
			return season_id;
		}
		string getDay()
		{
			return day;
		}
		string getWTeam()
		{
			return wteam;
		}
		string getWScore()
		{
			return wscore;
		}
		string getLTeam()
		{
			return lteam;
		}
		string getLScore()
		{
			return lscore;
		}
		string getWLoc()
		{
			return wloc;
	
		}
};

class OpponentDetails
{
	private:
		string opp_id;
		int percentage;
	public:
		void setOppID(string x)
		{
			opp_id=x;
		}
		void setPerc(int x)
		{
			percentage=x;
		}
		string getOppID()
		{
			return opp_id;
		}
		int getPerc()
		{
			return percentage;
		}
};

class OpponentsOpponentDetails
{
	private:
		string opp_op_id;
		int percentage;
	public:
		void setOpp_opID(string x)
		{
			opp_op_id=x;
		}
		void setPerc(int x)
		{
			percentage=x;
		}
		string getOpp_opID()
		{
			return opp_op_id;
		}
		int getPerc()
		{
			return percentage;
		}
};

int main(int argc,char* argv[])
{
	string line,id,name,print_id,print_name,arg;
	map<string,string> team_map;
	map<string,string> season_map;
	map<string,Results> result_map;
	Team t;
	Seasons s;
	Results r;
	int i=0;
	if(argc<2)
	{
		cout<<endl<<"Wrong arguments. Program exiting..."<<endl;
		return 0;
	}
	arg=argv[1];

	// getting input from teams.csv file, parsing and storing in map.
	ifstream teamFile("teams.csv");

	while(getline(teamFile,line))
	{
		istringstream str(line);
		getline(str, id, ',');
		getline(str, name);
		if(i!=0)
		{
			t.setId(id);
			t.setName(name);
			print_id=t.getId();
			print_name=t.getName();
			team_map[print_id]=print_name;	
		}
		i++;
	}
	teamFile.close();
	//teams populated.

	// getting input from seasons.csv file, parsing and storing in map.
	ifstream seasonFile("seasons.csv");
	i=0;
	while(getline(seasonFile,line))
	{
		istringstream str(line);
		getline(str, id, ',');
		getline(str, name, ' ');
		if(i!=0)
		{
			s.setSeasonId(id);
			s.setYear(name);
			print_id=s.getSeasonId();
			print_name=s.getYear();
			season_map[print_id]=print_name;
		}
		i++;
	}
	seasonFile.close();
	//seasons populated.

	// getting input from regular_tourney_combined_results.csv file, parsing and storing in map.
	ifstream resultFile("regular_tourney_combined_results.csv");
	i=0;
	string daynum,wteam,wscore,lteam,lscore,wloc;
	while(getline(resultFile,line))
	{
		istringstream str(line);
		getline(str, id, ',');
		getline(str, daynum, ',');
		getline(str, wteam, ',');
		getline(str, wscore, ',');
		getline(str, lteam, ',');
		getline(str, lscore, ',');
		getline(str, wloc, ' ');
		if(i!=0)
		{
			r.setSeasonId(id);
			r.setDay(daynum);
			r.setWTeam(wteam);
			r.setWScore(wscore);
			r.setLTeam(lteam);
			r.setLScore(lscore);
			r.setWLoc(wloc);
			print_id=r.getSeasonId();
			// line 226-228 are for (int to string) conversion
			stringstream x;
			x<<i;
			string n= x.str();
			print_id.append(n);
			result_map[print_id]=r;
		}
		i++;
	}
	resultFile.close();
	//results populated.

	if(arg=="rpiChampion")
	{
		int i;
		OpponentDetails detail;
		OpponentsOpponentDetails details;
		string season,seasonid,teamid,oppid,highest_id;
		season=argv[2];
		vector<string> v;
		vector<OpponentDetails> v2;
		vector<OpponentDetails>::iterator opponent_iter;
		vector<OpponentsOpponentDetails> op_op;
		vector<OpponentsOpponentDetails>::iterator op_op_iter;
		float won=0,total=0,perc=1,max=0,rpi,sum=0,n=0;
		map<string,float> rpi_map;
		map<string,int> teamWin;
		vector<string>::iterator it_vec;
		vector<string>::iterator string_iter;
		map<string,string>::iterator it_s;
		map<string,float>::iterator rpi_iter;
		map<string,string>::iterator it_team;
		map<string,Results>::iterator it_res;
		map<string,vector<string> > opponent_map;
		map<string,vector<OpponentDetails> > oppWin;
		map<string,vector<string> >::iterator it_opp;
		map<string,vector<OpponentsOpponentDetails> > opp_opWin;

		//getting season id
		for(it_s=season_map.begin();it_s!=season_map.end();++it_s)
		{
			if(it_s->second==season)
			{
				seasonid=it_s->first;
				break;
			}
		}
		//filling in opponent map which stores a vector of opponents against each team_id
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			teamid=it_team->first;
			for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
			{
				if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid))
				{
					v.push_back(it_res->second.getLTeam());
				}
				else if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getLTeam()==teamid))
				{
					v.push_back(it_res->second.getWTeam());
				}
			}
			opponent_map[teamid]=v;
			v.clear();
			//v is the vector which is used to compiling a list of all opponents of a team and then storing this vector against team id in map
		}

		// calculating win percentage for all teams in the team_map, storing perc against team id in teamWin map
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			teamid=it_team->first;
			for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
			{
				// for a single record: in a specific season, if winning team is the same as team id being checked, add to wins
				if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid))
				{
					won++;
					total++;
				}
				// otherwise, just increment total games played.
				else if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getLTeam()==teamid))
				{
					total++;
				}
			}
			if(total==0)
			{
				perc=0;
			}
			else
			{
				perc= (won/total)*100;
			}
			teamWin[teamid]=(int)perc;
		}

		// checking opponent map and retrieving win percentage of opponents (by using teamWin map) and storing in
		// oppWin map. opponents' id and percentage are stored in objects of OpponentDetails. OpponentDetails objects are stored
		// in the form of a vector against team id in the map.
		for(it_opp=opponent_map.begin();it_opp!=opponent_map.end();++it_opp)
		{
			teamid=it_opp->first;
			for(it_vec=it_opp->second.begin();it_vec!=it_opp->second.end();++it_vec)
			{
				detail.setOppID(*it_vec);
				detail.setPerc(teamWin[*it_vec]);
				v2.push_back(detail);
			}
			oppWin[teamid]=v2;
			v2.clear();
			// v2 is the vector which holds all opponent objects
		}
		
		// finding Opponents' opponents and storing their win percentage in opp_opWin map
		// op_op is the vector which holds the OpponentsOpponentDetails objects
		for(it_opp=opponent_map.begin();it_opp!=opponent_map.end();++it_opp)
		{
			teamid=it_opp->first;
			for(it_vec=it_opp->second.begin();it_vec!=it_opp->second.end();++it_vec)
			{
				oppid=*it_vec;
				v=opponent_map[oppid];
				for(string_iter=v.begin();string_iter!=v.end();++string_iter)
				{
					details.setOpp_opID(*string_iter);
					details.setPerc(teamWin[*string_iter]);
					op_op.push_back(details);
				}
				opp_opWin[teamid]=op_op;
				op_op.clear();
			}
		}
		// calculating rpi for each team given the formula in the handout and storing in rpi_map.
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			teamid=it_team->first;
			rpi= 0.25*teamWin[teamid];
			v2=oppWin[teamid];
			i=0;sum=0;n=0;
			while(i < v2.size())
			{
				sum+=v2[i].getPerc();
				n++;
				i++;
			}
			rpi+=(0.5*(sum/n));

			op_op=opp_opWin[teamid];
			i=0;sum=0;n=0;
			while(i < op_op.size())
			{
				sum+=op_op[i].getPerc();
				n++;
				i++;
			}
			rpi+=(0.25*(sum/n));
			rpi_map[teamid]=rpi;
		}

		// iterating rpi map and finding team with the highest rpi value
		for(rpi_iter=rpi_map.begin();rpi_iter!=rpi_map.end();++rpi_iter)
		{
			if(rpi_iter->second > max)
			{
				highest_id=rpi_iter->first; 
				max=rpi_iter->second;
			}
		}
		cout<<endl<<team_map[highest_id]<<endl;
	}
	else if(arg=="list")
	{
		//displays list of all results for games played by a team in a specific season
		string season,team,teamid,seasonid;
		season=argv[2];
		team=argv[3];

		// getting team id from team name entered
		map<string,string>::iterator it_team;
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			if(it_team->second==team)
			{
				teamid=it_team->first;
				break;
			}
		}

		// getting season id from season name
		map<string,string>::iterator it_s;
		for(it_s=season_map.begin();it_s!=season_map.end();++it_s)
		{
			if(it_s->second==season)
			{
				seasonid=it_s->first;
				break;
			}
		}

		map<string,Results>::iterator it_res;
		for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
		{
			//if season is the same as season entered
			if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid || it_res->second.getLTeam()==teamid))
			{
				// if winning team is the same as team being checked
				if(it_res->second.getWTeam()==teamid)
				{
					cout<<endl<<"W "<<team_map[it_res->second.getLTeam()]<<" "<<it_res->second.getWScore()<<"-"<<it_res->second.getLScore();
				}
				// if losing team is the same as team being checked
				else if(it_res->second.getLTeam()==teamid)
				{
					cout<<endl<<"L "<<team_map[it_res->second.getWTeam()]<<" "<<it_res->second.getLScore()<<"-"<<it_res->second.getWScore();
				}
			}
		}
		cout<<endl;
	}
	else if(arg=="finalRecord")
	{
		string season,team,teamid,seasonid;
		season=argv[2];
		team=argv[3];
		int won=0,lost=0;

		// getting team id from team name
		map<string,string>::iterator it_team;
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			if(it_team->second==team)
			{
				teamid=it_team->first;
				break;
			}
		}

		// getting season id from season name
		map<string,string>::iterator it_s;
		for(it_s=season_map.begin();it_s!=season_map.end();++it_s)
		{
			if(it_s->second==season)
			{
				seasonid=it_s->first;
				break;
			}
		}

		map<string,Results>::iterator it_res;
		for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
		{
			if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid || it_res->second.getLTeam()==teamid))
			{
				if(it_res->second.getWTeam()==teamid)
				{
					won++;
				}
				else if(it_res->second.getLTeam()==teamid)
				{
					lost++;
				}
			}
		}
		cout<<won<<"-"<<lost<<endl;
	}
	else if(arg=="bestWinPercentage")
	{
		string season= argv[2];
		string teamid,highest_id,seasonid;
		int max=0;
		float won=0,total=0,perc=1;
		map<string,int> perc_map;
		map<string,string>::iterator it_team;
		map<string,Results>::iterator it_res;
		map<string,int>::iterator it_perc;
		map<string,string>::iterator it_s;

		for(it_s=season_map.begin();it_s!=season_map.end();++it_s)
		{
			if(it_s->second==season)
			{
				seasonid=it_s->first;
				break;
			}
		}

		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			teamid=it_team->first;
			for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
			{
				if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid)) //match won
				{
					won++;
					total++;
				}
				else if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getLTeam()==teamid)) //match lost
				{
					total++;
				}
			}
			if(total==0)
			{
				perc=0;
			}
			else
			{
				perc=(won/total)*100;	
			}
			// store WP in map
			perc_map[teamid]=(int)perc;
			perc=1;
			won=0;
			total=0;
		}
		// iterate map to find team with highest WP
		for(it_perc=perc_map.begin();it_perc!=perc_map.end();++it_perc)
		{
			if(it_perc->second > max)
			{
				highest_id=it_perc->first;
				max=it_perc->second;
			}
		}
		cout<<endl<<team_map[highest_id]<<endl;
	}
	else if(arg=="largestMargin")
	{
		string season,seasonid,teamid,highest_id,str;
		season=argv[2];
		int max=0,score=0;
		float pointScored=0,numGames=0,pointAllowed=0,perc=1;
		map<string,int> margin_map;
		map<string,string>::iterator it_s;
		map<string,string>::iterator it_team;
		map<string,Results>::iterator it_res;
		map<string,int>::iterator it_marg;

		for(it_s=season_map.begin();it_s!=season_map.end();++it_s)
		{
			if(it_s->second==season)
			{
				seasonid=it_s->first;
				break;
			}
		}

		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			teamid=it_team->first;
			// itering the result map
			for(it_res=result_map.begin();it_res!=result_map.end();++it_res)
			{
				if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid))
				{
					str= it_res->second.getWScore();
					istringstream (str) >> score; //converting string to integer
					pointScored+=score;
					str=it_res->second.getLScore(); //converting string to integer
					istringstream (str) >> score;
					pointAllowed+=score;
					numGames++;
				}
				else if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getLTeam()==teamid))
				{
					str= it_res->second.getLScore();
					istringstream (str) >> score;
					pointScored+=score;
					str=it_res->second.getWScore();
					istringstream (str) >> score;
					pointAllowed+=score;
					numGames++;
				}
			}
			if(numGames==0)
			{
				perc=0;
			}
			else
			{
				perc=(pointScored-pointAllowed)/numGames;	
			}

			// store in map
			margin_map[teamid]=(int)perc;
			perc=1;
			pointScored=0;
			pointAllowed=0;
			numGames=0;
		}

		// iterate map to find highest value
		for(it_marg=margin_map.begin();it_marg!=margin_map.end();++it_marg)
		{
			if(it_marg->second > max)
			{
				highest_id=it_marg->first;
				max=it_marg->second;
			}
		}
		cout<<endl<<team_map[highest_id]<<endl;
	}

	return 0;
}
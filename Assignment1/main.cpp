#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
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

int main(int argc,char* argv[])
{
	string line,id,name,print_id,print_name,arg;
	map<string,string> team_map;
	map<string,string> season_map;
	map<string,Results> result_map;
	Team t[357];
	Seasons s;
	Results r;
	int i=0;
	if(argc<2)
	{
		cout<<endl<<"Wrong arguments. Program exiting...";
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
			t[i].setId(id);
			t[i].setName(name);
			print_id=t[i].getId();
			print_name=t[i].getName();
			team_map[print_id]=print_name;	
			// cout<<endl<<print_id<<"    "<<print_name;
		}
		i++;
	}
	// cout<<endl<<"Size of map: "<<team_map.size();
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
			// cout<<endl<<print_id<<"    "<<print_name;	
		}
		i++;
	}
	// cout<<endl<<"Size of map: "<<season_map.size();
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
			stringstream x;
			x<<i;
			string n= x.str();
			print_id.append(n);
			result_map[print_id]=r;
		}
		i++;
	}
	// cout<<endl<<"Size of map: "<<result_map.size();
	resultFile.close();
	//results populated.

	//displays list of all results for games played by a team in a specific season
	if(arg=="list")
	{
		string season,team,teamid,seasonid;
		season=argv[2];
		team=argv[3];

		map<string,string>::iterator it_team;
		for(it_team=team_map.begin();it_team!=team_map.end();++it_team)
		{
			if(it_team->second==team)
			{
				teamid=it_team->first;
				break;
			}
		}

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
			// cout<<endl<<it->first<<"  "<<it->second.getWTeam();
			if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid || it_res->second.getLTeam()==teamid))
			{
				if(it_res->second.getWTeam()==teamid)
				{
					cout<<endl<<"W "<<team_map[it_res->second.getLTeam()]<<" "<<it_res->second.getWScore()<<"-"<<it_res->second.getLScore();
				}
				else if(it_res->second.getLTeam()==teamid)
				{
					cout<<endl<<"L "<<team_map[it_res->second.getWTeam()]<<" "<<it_res->second.getLScore()<<"-"<<it_res->second.getWScore();
				}
			}
		}
		cout<<endl;
	}
	else if(arg=="bestWinPercentage")
	{
		string season= argv[2];
		string teamid,highest_id,seasonid;
		int max=0;
		float won=0,total=0,perc=1;
		// int perc=1;
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
				if((it_res->second.getSeasonId()==seasonid) && (it_res->second.getWTeam()==teamid))
				{
					won++;
					total++;
				}
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
				perc=(won/total)*100;	
			}
			// cout<<endl<<teamid<<" "<<won<<" "<<total<<" "<<perc;
			// cout<<perc<<endl;
			perc_map[teamid]=(int)perc;
			perc=1;
			won=0;
			total=0;
		}
		for(it_perc=perc_map.begin();it_perc!=perc_map.end();++it_perc)
		{
			if(it_perc->second > max)
			{
				highest_id=it_perc->first;
				max=it_perc->second;
			}
			// cout<<endl<<it_perc->first<<" "<<it_perc->second;
		}
		cout<<endl<<team_map[highest_id]<<endl;
	}
	
	

	return 0;
}
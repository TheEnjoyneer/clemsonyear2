/* lab7.c
 * Christopher Brant
 * cbrant
 * ECE 2220, Fall 2016
 * MP7
 *
 * Purpose: The purpose of this machine problem is to
 * learn how to utilize the functions fork(), wait(),
 * pause(), alarm(), signal(), and kill(). As well as to 
 * be able to synthesize different techniques we have learned
 * throughout the semester to create a game that functions
 * across multiple terminals and controls different "Spacecrafts"
 * as they travel to, around, and back from Mars, giving them 
 * waypoints as they run out of waypoints, because of their
 * limited memory, so that they don't go off course or crash
 * on Mars. 
 *
 * Assumptions: We assume the user already has 4 terminals 
 * open and knows the terminal numbers for those terminals
 *
 * Command line arguments: The four terminal numbers of your open terminals
 *   
 * Known bugs: None as of now
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define NUMTERMS 4
#define strDevLen 100

int waypoints = 10;
int alarmclock;
int launched;
int returned;
int arrived;
int fromearth;
int dist;
int result;

void SpaceCraft(int CraftNum, FILE **termtoprint, int index);
void MissionControl(int Craft1, int Craft2, int Craft3);
void DoParent(int exitcode, int CraftNum, int *AllCraft);
void Launch(int signum);
void Refuel(int signum);
void Alarm(int signum);

int main(int argc, char *argv[])
{
	FILE *fpt[NUMTERMS];
	int ttyindex, wait_ret;
	char strDev[strDevLen];
	int PID[NUMTERMS];
	int term_ct = 0;
	int MC, SC1, SC2, SC3;
	int exitcode;

	if (argc != NUMTERMS + 1)
	{
		printf("Usage: ./lab7 1 2 3 4, where the numbers are terminal pts values\n");
		exit(1);
	}

	for (term_ct = 1; term_ct < NUMTERMS; term_ct++)
	{
		ttyindex = -1;
		ttyindex = atoi(argv[term_ct+1]);
		if (ttyindex < 1)
		{
			printf("Invalid terminal number %s\n", argv[term_ct+1]);
			exit(1);
		}

		sprintf(strDev, "/dev/pts/%d", ttyindex);

		if ((fpt[term_ct-1] = fopen(strDev, "w")) != NULL);
		else 
		{
			printf("Failed to open terminal %s\n", strDev);
			exit(1);
		}
	}

	term_ct = 0;
	ttyindex = -1;
	ttyindex = atoi(argv[term_ct+1]);
	if (ttyindex < 1)
	{
		printf("Invalid terminal number %s\n", argv[term_ct+1]);
		exit(1);
	}

	sprintf(strDev, "/dev/pts/%d", ttyindex);

	if ((fpt[3] = fopen(strDev, "w")) != NULL);
	else 
	{
		printf("Failed to open terminal %s\n", strDev);
		exit(1);
	}

	if ((SC1 = fork()) != 0)
	{
		if ((SC2 = fork()) != 0)
		{
			if ((SC3 = fork()) != 0)
			{
				if ((MC = fork()) != 0)
				{
					PID[0] = MC;
					PID[1] = SC1;
					PID[2] = SC2;
					PID[3] = SC3;

					wait_ret = wait(&exitcode);
					DoParent(exitcode, wait_ret, PID);

					wait_ret = wait(&exitcode);
					DoParent(exitcode, wait_ret, PID);

					wait_ret = wait(&exitcode);
					DoParent(exitcode, wait_ret, PID);
					kill(MC, SIGKILL);
				}
				else
					MissionControl(SC1, SC2, SC3);
			}
			else
				SpaceCraft(SC3, fpt, 3);
		}
		else
			SpaceCraft(SC2, fpt, 2);
	}
	else SpaceCraft(SC1, fpt, 1);

	if (result == 3)
		printf("Congratulations Team! Mission Successful\n");
	else if (MC != 0)
	{
		wait(NULL);
		printf("Mission Failed, we'll get 'em next time.\n");
	}

	for (ttyindex = 0; ttyindex < term_ct; ttyindex++)
		fclose(fpt[ttyindex]);

	return 0;
}

// Spacecraft function used by each child
void SpaceCraft(int CraftNum, FILE **termtoprint, int index)
{
	srand(time(NULL));
	dist = (rand() % 30) + 30;

	signal(SIGUSR1, Launch);
	signal(SIGUSR2, Refuel);
	signal(SIGALRM, Alarm);

	fprintf(termtoprint[index-1], "\nSpace Craft %d initiating mission. Distance to Mars %d\n", index, dist);
	
	alarm(1);
	while (1==1)
	{
		pause();
		if (launched == 1 && dist == fromearth)
		{
			fprintf(termtoprint[index-1], "Space Craft %d beginning return. Distance to Earth %d\n", index, fromearth);
			returned = 1;
			launched = 0;
		}
		else if (launched == 1 && fromearth != 0 && dist != fromearth)
		{
			fprintf(termtoprint[index-1], "Restarting launch now is highly illogical, Captain");
			exit(0);
		}
		else if (returned == 0 && dist == fromearth && arrived == 0)
		{
			fprintf(termtoprint[index-1], "Space Craft %d to Mission Control: entered orbit. Please signal when to launch rover.\n", index);
			arrived = 1;
		}

		if (alarmclock == 0)
		{
			if (waypoints == 4 && returned == 0)
			{
				fprintf(termtoprint[index-1], "Houston we have a problem!\n");
				
				if (dist != fromearth)
					fprintf(termtoprint[index-1], "Waypoints left: %d. Distance to Mars %d.\n", waypoints, dist - fromearth);
			}
			else if (waypoints == 4 && returned == 1)
			{
				fprintf(termtoprint[index-1], "Houston we have a problem!\n");
				fprintf(termtoprint[index-1], "Waypoints left: %d. Distance to Earth %d.\n", waypoints, fromearth);
			}
			else if (waypoints == 0 && fromearth != 0)
			{
				fprintf(termtoprint[index-1], "Space Craft %d. Lost in Space.\n", index);
				exit(0);
			}
			else if (dist != fromearth && fromearth != 0 && returned == 0)
				fprintf(termtoprint[index-1], "Waypoints left %d. Distance to Mars %d.\n", waypoints, dist - fromearth);
			else if (dist != fromearth && fromearth != 0 && returned == 1)
				fprintf(termtoprint[index-1], "Waypoints left: %d. Distance to Earth %d.\n", waypoints, fromearth);
			else if (dist == fromearth && returned == 0)
				fprintf(termtoprint[index-1], "Waypoints left %d.\nStill waiting for rover launch signal...\n", waypoints);
		}
		
		if (returned == 1 && fromearth == 0)
		{
			fprintf(termtoprint[index-1], "Ya did good, men. Ya did good.\n");
			fprintf(termtoprint[index-1], "You succesfully brought Space Craft %d home.\n", index);
			exit(1);
		}
		
		alarm(1);
	}

}

// MC function that sends signals to the spacecrafts
void MissionControl(int Craft1, int Craft2, int Craft3)
{
	while (1==1)
	{
		char line[100], command[3];
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%s", command);

		if (command[0] == 'l' && command[2] == '\0')
		{
			if (command[1] == '1')
				kill(Craft1, SIGUSR1);
			else if (command[1] == '2')
				kill(Craft2, SIGUSR1);
			else if (command[1] == '3')
				kill(Craft3, SIGUSR1);
			else
				printf("Command not found\n");
		}
		else if (command[0] == 'k' && command[2] == '\0')
		{
			if (command[1] == '1')
			{
				kill(Craft1, SIGKILL);
				printf("Terminated Space Craft 1\n");
			}
			else if (command[1] == '2')
			{
				kill(Craft2, SIGKILL);
				printf("Terminated Space Craft 2\n");
			}
			else if (command[1] == '3')
			{
				kill (Craft3, SIGKILL);
				printf("Terminated Space Craft 3\n");
			}
			else
				printf("Command not found\n");
		}
		else if (command[0] == 't' && command[2] == '\0')
		{
			if (command[1] == '1')
				kill(Craft1, SIGUSR2);
			else if (command[1] == '2')
				kill(Craft2, SIGUSR2);
			else if (command[1] == '3')
				kill(Craft3, SIGUSR2);
			else
				printf("Command not found\n");
		}
		else if (command[0] == 'q' && command[2] == '\0')
			exit(0);
		else
			printf("Command not found\n");
	} 

}

// Parent process's response when a child exits and returns
void DoParent(int exitcode, int CraftNum, int *AllCraft)
{
	int i = 0;
	if (AllCraft[0] == CraftNum)
	{
		kill(AllCraft[1], SIGKILL);
		kill(AllCraft[2], SIGKILL);
		kill(AllCraft[3], SIGKILL);
		exit(0);
	}

	for (i = 0; i < NUMTERMS; i++)
	{
		if (CraftNum == AllCraft[i])
			break;
	}


	exitcode = exitcode >> 8;

	if (exitcode == 0)
		printf("Vaya Con Dios, Space Craft %d\n", i);
	else
	{
		printf("Welcome home, Space Craft %d!\n", i);
		result++;
	}
}

// Launch function that attempts to launch a space craft's rover.
void Launch(int signum)
{
	if (launched == 0)
		launched = 1;
}

// Refuel function that increases waypoint total
void Refuel(int signum)
{
		waypoints += 10;
}

// Alarm function that decrements waypoints and changes distance from earth
void Alarm(int signum)
{
	if (alarmclock == 0)
		alarmclock = 1;
	else
	{
		alarmclock = 0;
			waypoints--;
	}

	if (returned == 0 && dist != fromearth)
		fromearth++;
	else if (returned == 1)
		fromearth--;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct team {
   char name[50];
   char players[11][50];
};

struct date {
   int day;
   int month;
   int year;
};

void display_teams(struct team *teams, int num_teams) 
{
	int i,j;
    printf("<------List of all teams and their players:------>\n");
    printf("\n------------------------------------------------\n\n");
    for (i = 0; i < num_teams; i++) {
        printf("%d. %s\n", i+1, teams[i].name);
        printf("   Players: ");
        for (j = 0; j < 11; j++) {
            printf("%s, ", teams[i].players[j]);
        }
        printf("\n");
    }
}

void add_team(struct team *teams, int *num_teams) 
{
	int i;
    printf("Enter the name of the team: ");
    scanf("%s", teams[*num_teams].name);
    printf("Enter the names of the 11 players:\n");
    for (i = 0; i < 11; i++) {
        scanf("%s", teams[*num_teams].players[i]);
    }
    (*num_teams)++;
}

void delete_team(struct team *teams, int *num_teams) 
{
	int i;
    char team_name[50];
    printf("Enter the name of the team you want to delete: ");
    scanf("%s", team_name);
    int index = -1;
    for (i = 0; i < *num_teams; i++) {
        if (strcmp(teams[i].name, team_name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Team not found.\n");
    } else {
        for (i = index; i < *num_teams-1; i++) {
            teams[i] = teams[i+1];
        }
        (*num_teams)--;
        printf("<-----Team deleted successfully.----->\n");
    }
}

void update_team(struct team *teams, int num_teams) 
{
	int i;
    char team_name[50];
    printf("Enter the name of the team you want to update: ");
    scanf("%s", team_name);
    int index = -1;
    for (i = 0; i < num_teams; i++) {
        if (strcmp(teams[i].name, team_name) == 0) {
        index = i;
        break;
    }
}
if (index == -1) {
    printf("<-----Team not found.----->\n");
} else {
    printf("Enter the new name of the team: ");
    scanf("%s", teams[index].name);
    printf("Enter the names of the 11 players:\n");
    for (i = 0; i < 11; i++) {
        scanf("%s", teams[index].players[i]);
    }
    printf("<-----Team updated successfully.----->\n");
}
}

void generate_schedule(struct team *teams, int num_teams, struct date *start_date, int num_days) 
{
	int i;
struct date *dates = (struct date *) malloc(num_days * sizeof(struct date));
for (i = 0; i < num_days; i++) {
dates[i].day = start_date->day + i;
dates[i].month = start_date->month;
dates[i].year = start_date->year;
}
printf("\n\n*** IPL CRICKET TOURNAMENT SCHEDULE ***\n");
FILE *fp = fopen("schedule.txt", "w");

for (i = 0; i < num_days; i++) {
    printf("Day %d - %d/%d/%d: ", i+1, dates[i].day, dates[i].month, dates[i].year);
    fprintf(fp, "Day %d - %d/%d/%d: ", i+1, dates[i].day, dates[i].month, dates[i].year);
    int team1_index = rand() % num_teams;
    int team2_index;
    do {
        team2_index = rand() % num_teams;
    } while (team2_index == team1_index);
    printf("%s vs %s\n", teams[team1_index].name, teams[team2_index].name);
    fprintf(fp, "%s vs %s\n", teams[team1_index].name, teams[team2_index].name);
}
fclose(fp);
}

//void update_schedule() {
//// TODO: Implement schedule update logic
//printf("Schedule updated successfully.\n");
//}
void update_schedule(struct team *teams, int num_teams, struct date *start_date, int num_days) 
{
	int i;
struct date *dates = (struct date *) malloc(num_days * sizeof(struct date));
for (i = 0; i < num_days; i++) {
dates[i].day = start_date->day + i;
dates[i].month = start_date->month;
dates[i].year = start_date->year;
}
printf("\n\n*** IPL CRICKET TOURNAMENT SCHEDULE ***\n");
FILE *fp = fopen("schedule.txt", "w+");

for (i = 0; i < num_days; i++) {
    printf("Day %d - %d/%d/%d: ", i+1, dates[i].day, dates[i].month, dates[i].year);
    fprintf(fp, "Day %d - %d/%d/%d: ", i+1, dates[i].day, dates[i].month, dates[i].year);
    int team1_index = rand() % num_teams;
    int team2_index;
    do {
        team2_index = rand() % num_teams;
    } while (team2_index == team1_index);
    printf("%s vs %s\n", teams[team1_index].name, teams[team2_index].name);
    fprintf(fp, "%s vs %s\n", teams[team1_index].name, teams[team2_index].name);
}
printf("<-----Schedule updated successfully.----->\n");
fclose(fp);
}

int main() {
struct team teams[20];
int num_teams = 0;
struct date start_date;
int num_days;
srand(time(0)); // Seed random number generator with current time

int choice;
do {
    printf("\n\n*** IPL CRICKET TOURNAMENT SCHEDULER ***\n");
    printf("1. Display all teams\n");
    printf("2. Add a team\n");
    printf("3. Delete a team\n");
    printf("4. Update a team\n");
    printf("5. Generate schedule\n");
    printf("6. Update schedule\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display_teams(teams, num_teams);
            break;
        case 2:
            add_team(teams, &num_teams);
            break;
        case 3:
            delete_team(teams, &num_teams);
            break;
        case 4:
            update_team(teams, num_teams);
            break;
        case 5:
            printf("Enter the start date of the tournament (dd mm yyyy): ");
            scanf("%d %d %d", &start_date.day, &start_date.month, &start_date.year);
            printf("Enter the number of days for the tournament to run: ");
            scanf("%d", &num_days);
            generate_schedule(teams, num_teams, &start_date, num_days);
            break;
        case 6:
        	printf("Enter the new start date of the tournament (dd mm yyyy): ");
            scanf("%d %d %d", &start_date.day, &start_date.month, &start_date.year);
            printf("Enter the new number of days for the tournament to run: ");
            scanf("%d", &num_days);
            update_schedule(teams, num_teams, &start_date, num_days);
            break;
        case 7:
            printf("Thank you for using IPL Cricket Tournament Scheduler.\n");
            printf("<---------GOOD BYE!-------->");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
} while (choice != 7);

return 0;
}


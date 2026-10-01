#include <stdio.h>
#define MAX_DISKS 10
void printTowers(int towerA[], int towerB[], int towerC[], int numDisks) {
printf("Tower A: ");
for (int i = 0; i < numDisks; i++) {
if (towerA[i] != 0) {
printf("%d ", towerA[i]);
} }
printf("\n");
printf("Tower B: ");
for (int i = numDisks-1; i >=0; i--) {
if (towerB[i] != 0) {
printf("%d ", towerB[i]);
} }
printf("\n");
printf("Tower C: ");
for (int i = numDisks-1; i >=0; i--) {
if (towerC[i] != 0) {
printf("%d ", towerC[i]);
} }
printf("\n");

}

int moveDisk(int from[], int to[], int numDisks) {
int fromIndex = -1, toIndex = -1;

for (int i = numDisks - 1; i >= 0; i--) {
if (from[i] != 0) {
fromIndex = i;
break;
}
}
for (int i = numDisks - 1; i >= 0; i--) {
if (to[i] == 0) {
toIndex = i;
break;
} }
// If there is a disk to move
if (fromIndex != -1) {
int disk = from[fromIndex];

// Check if we can place the disk on the 'to' tower
if (toIndex != -1 && (to[toIndex] > disk)) {
printf("Cannot move disk %d to the target tower (smaller disk on top).\n", disk);
return 0; // Move failed
} else {
// Move the disk
to[toIndex] = disk;
from[fromIndex] = 0; // Remove the disk from the 'from' tower
return 1;

} }
return 0; }
int main() {
int numDisks;
int moves = 0,completed;
int from,to;
int steps=1;
int towerA[MAX_DISKS] = {0};
int towerB[MAX_DISKS] = {0};
int towerC[MAX_DISKS] = {0};

char str[100];

FILE *file = fopen("tower_of_hanoi.txt", "r");
if (file == NULL) {
printf("Error creating the file to write the rules.\n");
return 1;
}
while(fgets(str, sizeof(str), file)){
printf("%s", str); // Print the line
}
fclose(file); // Close the file

printf("\n\nEnter the number of disks (1 to %d): ", MAX_DISKS);
scanf("%d", &numDisks);

if (numDisks < 1 || numDisks > MAX_DISKS) {
printf("Invalid number of disks.\n");
return 1;

}
for (int i = numDisks; i >= 1; i--) {
towerA[numDisks - i] = i;
}
while (1) {
printf("\nCurrent Towers:\n");
printTowers(towerA, towerB, towerC, numDisks);

printf("\nMoves: %d\n\n",moves);
completed=1;
for (int i = numDisks-1; i >=0 ; i--) {
if (towerC[i] != i + 1) {
completed = 0;
break;
} }
if (completed) {
break; }

printf("Enter the tower to move from (1 for A, 2 for B, 3 for C): ");
scanf("%d", &from);
printf("Enter the tower to move to (1 for A, 2 for B, 3 for C): ");
scanf("%d", &to);

if (from == 1 && to == 2) {
if (moveDisk(towerA, towerB, numDisks))

moves++;
} else if (from == 1 && to == 3) {
if (moveDisk(towerA, towerC, numDisks))

moves++;
} else if (from == 2 && to == 1) {
if (moveDisk(towerB, towerA, numDisks))

moves++;
} else if (from == 2 && to == 3) {
if (moveDisk(towerB, towerC, numDisks))

moves++;
} else if (from == 3 && to == 1) {
if (moveDisk(towerC, towerA, numDisks))

moves++;
} else if (from == 3 && to == 2) {
if (moveDisk(towerC, towerB, numDisks))

moves++;
} }
for(int n=1;n<=numDisks;n++){
steps*=2; }
steps-=1;
printf("\n GAME OVER.\n");
printf("\n You have solved the Tower of Hanoi puzzle in %d moves.\n", moves);
if(moves==steps){
printf("\nThe problem was solved in the most effecient way with %d moves",steps); }
else
printf("\n The problem could have been solved better in %d moves.", steps);
return 0; }
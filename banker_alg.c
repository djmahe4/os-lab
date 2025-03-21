#include <stdio.h> 

void main() { 

int work[10], avail[101, alloc[10][10], need[10][10], max[10][10]; 

int n, m, i, j, k, count, fcount = 0, pr[10]; 

char finish[10]; 

printf("Enter the number of processes: "); 

scanf("%d", &n); 

printf("Enter the number of resources: "); 

scanf("%d", &m); 

printf("Enter the total available resources:\n"); 

for (i = 0; i < m; i++) { 

scanf("%d", &avail[i]); 

work[i] = avail[i];
}
printf("Enter the maximum resources required by each process (max matrix):\n"); 

for (i = 0; i <n; i++) { 

for (j = 0; j< m; j++) { 

scanf("%d", &max[i][j]);
}
}
printf("Enter the resource allocation matrix (alloc matrix):\n"): 

for (i = 0; i < n; i++) { 

for (j = 0; j < m; j++) { 

scanf("%d", &alloc[i][j]); 
}}
for (i = 0; i <n; i++) { 

for (j = 0; j < m; j++) { 

need[i][j]= max[i][j] - alloc[i][j]; 
}}
for (i = 0; i < n; i++) { 

finish[i] = 'f'; 
}
for (k = 0; k<n; k++) { 

for (i = 0; i <n; i++) { 

if (finish[i] =='f') {

count =0; 
}
for (j = 0; j < m; j++) { 

if (need[i][j] <= work[j]) { 

count++;
if (count == m) { 

for (j = 0;j<m; j++) { work[j] += alloc[i][j];

} 

finish[i] = 't';

pr[fcount++] = i;
}}}
} 

if (fcount == n) { 

printf("The system is in a safe state.\nSafe sequence is:\n"); 

for (i = 0; i <n; i++) { 

printf("P%d ", pr[i]); 
}
printf("\n"); 
}
} else { 

printf("The system is not ina safe state.\n");
}}

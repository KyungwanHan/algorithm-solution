#include <stdio.h>

#define M_MAX 1000
#define N_MAX 1000
#define MAX(x,y) (x) > (y) ? (x) : (y)

int stone[M_MAX + 1];
int target[N_MAX + 1];

int visited[N_MAX];
int M, N;

int solution(int idx)
{

	int max = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 1) continue;
		if (target[i] > stone[idx]) continue;
		visited[i] = 1;
		int t = solution(idx + 1) + target[i];
		max = MAX(max, t);
		visited[i] = 0;
	}
	
	return max;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d", &M, &N);

		for (int i = 0; i < M; i++)
			scanf("%d", &stone[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &target[i]);
		
		printf("%d\n",solution(0));	
	}

	return 0;
}
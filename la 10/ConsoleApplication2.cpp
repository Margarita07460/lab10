#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale.h>
#include <queue>
#include <iostream>



using namespace std;
queue<int>Q;
void centor_tiajesti(vector < vector < int>> G) {
	vector<int> vis(G.size() + 1);
	int s = 1;
	for (int p = 1; p <= G.size(); p++) {
		vector<int> dist(G.size() + 1, -1);
		Q.push(s);
		dist[s] = 0;


		while (!Q.empty()) {
			s = Q.front();
			Q.pop();
			//printf("%d\n", s);
			for (int i = 1; i < G.size(); ++i) {
				if (G[s][i] > 0 and dist[i] == -1) {
					Q.push(i);
					dist[i] = dist[s] + G[s][i];
				}
			}
		}

		int dist_max = 0;
		for (int c : dist) {
			if (c != -1) {
				dist_max = max(dist_max, c);
			}
		}
		vis[p] = dist_max;
	}

	int min_eccentricity = INT_MAX;
	int centroid = -1;
	for (int v = 1; v <= G.size(); ++v) {
		if (vis[v] < min_eccentricity) {
			min_eccentricity = vis[v];
			centroid = v;
		}
	}
	printf("центр тяжести графа: %d\n", centroid);
	

	
}


void BFSD_rad(vector < vector < int>> G, int  num_vertices) {
	vector<int> vis(G.size() + 1, 0);
	int rad = INT_MAX;
	int diam = INT_MIN;
	int s = 1;
	for (int p = 1; p <= G.size()-1; p++) {
		vector<int> dist(G.size() + 1, -1);
		Q.push(s);
		dist[s] = 0;


		while (!Q.empty()) {
			s = Q.front();
			Q.pop();
			//printf("%d\n", s);
			for (int i = 1; i < G.size(); i++) {
				if (G[s][i] > 0 and dist[i] == -1) {
					Q.push(i);
					dist[i] = dist[s] + G[s][i];
				}
			}
		}

		int dist_max = 0;
		for (int c : dist) {
			if (c != -1) {
				dist_max = max(dist_max, c);
			}
		}
		vis[p] = dist_max;
		rad = min(rad, dist_max);


		for (int i = 1; i <= G.size(); i++) {
			dist[i] = 1000;
		}
	}
	printf("Радиус графа: %d\n", rad);


	printf("Центральные вершины: ");
	for (int i = 1; i <= G.size()-1; i++) {
		if (vis[i] == rad) {
			printf("%d ", i);

		}
	}
	printf("\n");
	
}


void BFSD_diam(vector < vector < int>> G) {
	vector<int> vis(G.size() +1, 0);
	int rad = INT_MAX;
	int diam = INT_MIN;
	int s = 1;
	for (int p = 1; p <= G.size(); p++) {
		vector<int> dist(G.size() + 1, -1);
		Q.push(s);
		dist[s] = 0;


		while (!Q.empty()) {
			s = Q.front();
			Q.pop();
			//printf("%d\n", s);
			for (int i = 1; i < G.size(); i++) {
				if (G[s][i] > 0 and dist[i] == -1) {
					Q.push(i);
					dist[i] = dist[s] + G[s][i];
				}
			}
		}

		int dist_max = 0;
		for (int c : dist) {
			if (c != -1) {
				dist_max = max(dist_max, c);
			}
		}
		vis[p] = dist_max;
		diam = max(diam, dist_max);
		//rad = min(rad, dist_max);
	}
	printf("Диаметр графа: %d\n", diam);
	//printf("Радиус графа: %d\n", rad);


	
	printf("\n");
	printf("Периферийные вершины: ");
	for (int i = 1; i <= G.size()-1; i++) {
		if (vis[i] == diam) {
			printf("%d ", i);
		}
	}
}





void BFSD1_or(vector < vector < int>> G_or, int s, vector<int>& dist_or, int d) {
	clock_t start = clock();
	int c = s;
	Q.push(s);
	dist_or[s] = 0;

	while (!Q.empty()) {
		s = Q.front();
		Q.pop();
		//printf("%d\n", s);
		for (int i = 1; i < G_or.size(); ++i) {
			if (G_or[s][i] > 0 and dist_or[i] == -1) {
				Q.push(i);
				dist_or[i] = dist_or[s] + G_or[s][i];
			}
		}
	}
	clock_t end = clock();
	if (dist_or[d] == -1) {
		printf("======================\n");
		printf("Пути отсутствуют!\n");
		printf("======================\n");
	}

	else {
		printf("========================================\n");
		printf("Путь %d-> %d по МАТРИЦЕ(обход в ширину): %d\n", c, d, dist_or[d]);
		printf("========================================\n");

	}
	printf("Время работы алгоритма: \n");
	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("\n\n");
}

void BFSD1(vector < vector < int>> G, int s, vector<int>& dist, int d) {
	clock_t start = clock();
	int c = s;
	Q.push(s);
	dist[s] = 0;


	for (int i = 1; i <= G.size(); i++) {

		while (!Q.empty()) {
			s = Q.front();
			Q.pop();
			//printf("%d\n", s);
			for (int i = 1; i < G.size(); ++i) {
				if (G[s][i] > 0 and dist[i] == -1) {
					Q.push(i);
					dist[i] = dist[s] + G[s][i];
				}
			}
		}
	}
	clock_t end = clock();
	if (dist[d] == -1) {
		printf("======================\n");
		printf("Пути отсутствуют!\n");
		printf("======================\n");
	}

	else {
		printf("========================================\n");
		printf("Путь %d-> %d по МАТРИЦЕ(обход в ширину): %d\n", c, d, dist[d]);
		printf("========================================\n");

	}
	printf("Время работы алгоритма: ");
	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("\n\n");

}



int swt = 0;


vector<vector<int>> cmej_mat_orient(int num_vertices, double veroj) {
	vector<vector<int>> cmej_mat_orient(num_vertices + 1, vector<int>(num_vertices + 1, 0));
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = i + 1; j <= num_vertices; ++j) {

			if (i!=j and static_cast<double>(rand()) / RAND_MAX < veroj)
			{
	
				int r = rand() % 10 + 1;
				int t = rand() % 10 + 1;
				cmej_mat_orient[i][j] =r;
				cmej_mat_orient[j][i] = t;
				//cont++;
			}
		}
	}

	//if (cont == 0) {
		//swt = 1;
	//}
	printf("Матрица смежности:\n");
	printf("-------------------\n");
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = 1; j <= num_vertices; ++j) {
			printf("%d ", cmej_mat_orient[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return cmej_mat_orient;
}




vector<vector<int>> cmej_mat(int num_vertices, double veroj) {
	vector < vector < int>> cmej_mat(num_vertices + 1, vector<int>(num_vertices + 1, 0));
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = i + 1; j <= num_vertices; ++j) {
			if (i != j and static_cast<double>(rand()) / RAND_MAX < veroj) {
				int t = rand() % 10 + 1;
				cmej_mat[i][j] = t;
				cmej_mat[j][i] = t;

			}
		}
	}

	/*if (cont == 0) {
		swt = 1;
	}*/
	printf("Матрица смежности:\n");
	printf("-------------------\n");
	for (int i = 1; i <= num_vertices; ++i) {
		for (int j = 1; j <= num_vertices; ++j) {
			printf("%d ", cmej_mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return cmej_mat;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RUS");
	srand(static_cast<unsigned int>(time(0)));
	int num_vertices, operation;
	double veroj = 0.7;
	int s, d, v, r;
	printf("Введите количество вершин: ");
	if (argc > 1) {
		r = atoi(argv[1]);
		printf("%d", r);

		num_vertices = r;

	}

	
	



























	

	while (true) {
		printf("Выберите операцию:\n 1 - Сгенерировать графы\n 2 - поиск расстояний в неориентированном графе\n 3 -поиск расстояний в ориентированном графе\n 4 - нахождения радиуса,  диаметра, центра тяжести в ориентированном графе\n 5 - Нахождение радиуса, диаметра, центра тяжести в неориентированном графе\n 6 - Выход\n");
		if (scanf("%d", &operation) != 1) {
			printf("Ошибка: ожидался ввод числа.\n");
			while (getchar() != '\n'); // Очистка ввода
			continue;
		}

		if (operation == 6) {
			break;
		}

		switch (operation) {
		case 1: {
			
			auto G = cmej_mat(num_vertices, veroj);
			auto G_or = cmej_mat_orient(num_vertices, veroj);
			break;
		}
		case 2: {
			printf("Введите количество вершин: ");
			scanf("%d", &num_vertices);
			auto G = cmej_mat(num_vertices, veroj);
			vector<int> dist(G.size(), -1);
			printf("Введите номер вершины из которой хотите попасть в другую ");
			scanf("%d", &s);
			printf("Введите номер вершины, в которую хотите попасть  ");
			scanf("%d", &d);
			printf("\n\n");
			if (swt == 1) {
				printf("\n Обход произвести нельзя!\n");
			}
			else {

				BFSD1(G, s, dist, d);
				break;
			}
		}
		case 3: {
			printf("Введите количество вершин: ");
			scanf("%d", &num_vertices);
			auto G_or = cmej_mat_orient(num_vertices, veroj);
			vector<int> dist(G_or.size(), -1);
			printf("Введите номер вершины из которой хотите попасть в другую ");
			scanf("%d", &s);
			printf("Введите номер вершины, в которую хотите попасть  ");
			scanf("%d", &d);
			printf("\n\n");
			if (swt == 1) {
				printf("\n Обход произвести нельзя!\n");
			}
			else {

				BFSD1_or(G_or, s, dist, d);
				break;
			}

		}
		case 4: {
			printf("Введите количество вершин: ");
			scanf("%d", &num_vertices);
			auto G_or = cmej_mat_orient(num_vertices, veroj);
			vector<int>dist_or(G_or.size(), -1);
			BFSD_diam(G_or);
			BFSD_rad(G_or, num_vertices);
			centor_tiajesti(G_or);

		}
		case 5: {
			printf("Введите количество вершин: ");
			scanf("%d", &num_vertices);
			auto G = cmej_mat(num_vertices, veroj);
			vector<int>dist_or(G.size(), -1);
			BFSD_diam(G);
			BFSD_rad(G, num_vertices);
			centor_tiajesti(G);


		}


			  return 0;



		}
	}
}




			

		
		
	

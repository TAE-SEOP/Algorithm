#include <vector>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int gm; int gn;
int area_cnt;
int re_max;
int dx[4];
int dy[4];
queue<pair<int,int>> check;
bool visit[103][103];

void bfs(int a, int b, vector<vector<int>> picture){
    int color = picture[a][b];
    int area_max = 1;
    area_cnt++;
    visit[a][b] = true;
    check.push(make_pair(a,b));
    
    while(!check.empty()){
        int x = check.front().first;
        int y = check.front().second;
        check.pop();
        
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < gm && 0 <= ny && ny < gn){
                if(visit[nx][ny] == false && picture[nx][ny] == color){
                    area_max++;
                    visit[nx][ny] = true;
                    check.push(make_pair(nx,ny));
                }
            }
        }
    }
    if(area_max > re_max) re_max = area_max;
    return;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    gm = m; gn = n;
    area_cnt =0;
    re_max=0;
    dx[0] = 0; dx[1] = 0; dx[2] = 1; dx[3] = -1;
    dy[0] = 1; dy[1] = -1; dy[2] = 0; dy[3] = 0;
    memset(visit, false, sizeof(visit));
    for(int i = 0; i< m; i++){
        for(int j=0; j<n;j++){
            if(picture[i][j] == 0) visit[i][j] = true;
            else if(visit[i][j] == false) bfs(i,j,picture);
        }
    }
    
    vector<int> answer(2);
    answer[0] = area_cnt;
    answer[1] = re_max;
    return answer;
}

//문제가 이상하게 전역변수인 것들을 solution 안에서 초기화 해줬어야 함.
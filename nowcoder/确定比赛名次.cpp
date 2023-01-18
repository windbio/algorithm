#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 501
int n;                 // n 个节点
int m;                 // m 条边
int indegree[N];       // 存储每个节点的入度
vector<int> team[N];   // 邻接表
queue<int> teamRank;   // 存储排序结果

int main() {
    while(cin >> n >> m) {
        
        // 数据录入
        
        for (int i = 1; i <= n; i ++) {
            indegree[i] = 0;
            team[i].clear();
        }
        int i, j;
        while (m --) {
            cin >> i >> j;
            team[i].push_back(j);
            indegree[j] ++;
        }
        
        // 拓扑排序
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (indegree[j] == 0) {
                    teamRank.push(j);
                    indegree[j] = -1;
                    for (auto k: team[j]) indegree[k] --;
                    break;
                }
            }
        }
        
        // 结果输出
        
        int count = n;
        while (!teamRank.empty()) {
            count --;
            if (count > 0) cout << teamRank.front() << " ";
            else cout << teamRank.front() <<endl;
            teamRank.pop();
        }
        
    }
    return 0;
}
